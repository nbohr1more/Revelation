/*
===========================================================================

Doom 3 GPL Source Code
Copyright (C) 1999-2011 id Software LLC, a ZeniMax Media company.

This file is part of the Doom 3 GPL Source Code (?Doom 3 Source Code?).

Doom 3 Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Doom 3 Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Doom 3 Source Code.  If not, see <http://www.gnu.org/licenses/>.

In addition, the Doom 3 Source Code is also subject to certain additional terms. You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Doom 3 Source Code.  If not, please request a copy in writing from id Software at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/
#include "../idlib/precompiled.h"
#pragma hdrstop

#include "tr_local.h"

/*
================
RB_SetStageTexGen
================
*/
static void RB_SetStageTexGen( const drawSurf_t *surf ) {
	glEnable( GL_TEXTURE_GEN_S );
	glEnable( GL_TEXTURE_GEN_T );
	glEnable( GL_TEXTURE_GEN_Q );
	float	mat[16], plane[4];
	myGlMultMatrix( surf->space->modelViewMatrix, backEnd.viewDef->projectionMatrix, mat );
	plane[0] = mat[0 * 4 + 0];
	plane[1] = mat[1 * 4 + 0];
	plane[2] = mat[2 * 4 * 0];
	plane[3] = mat[3 * 4 + 0];
	glTexGenfv( GL_S, GL_OBJECT_PLANE, plane );
	plane[0] = mat[0 * 4 + 1];
	plane[1] = mat[1 * 4 + 1];
	plane[2] = mat[2 * 4 + 1];
	plane[3] = mat[3 * 4 + 1];
	glTexGenfv( GL_T, GL_OBJECT_PLANE, plane );
	plane[0] = mat[0 * 4 + 3];
	plane[1] = mat[1 * 4 + 3];
	plane[2] = mat[2 * 4 + 3];
	plane[3] = mat[3 * 4 + 3];
	glTexGenfv( GL_Q, GL_OBJECT_PLANE, plane );
}

/*
================
RB_PrepareStageTexturing
================
*/
static void RB_PrepareStageTexturing( const shaderStage_t *pStage,  const drawSurf_t *surf, idDrawVert *ac ) {
	// set privatePolygonOffset if necessary
	if( pStage->privatePolygonOffset ) {
		glEnable( GL_POLYGON_OFFSET_FILL );
		glPolygonOffset( r_offsetFactor.GetFloat(), r_offsetUnits.GetFloat() * pStage->privatePolygonOffset );
	}
	// set the texture matrix if needed
	if( pStage->texture.hasMatrix ) {
		RB_LoadShaderTextureMatrix( surf->shaderRegisters, &pStage->texture );
	}
	// texgens
	if( pStage->texture.texgen == TG_DIFFUSE_CUBE ) {
		glTexCoordPointer( 3, GL_FLOAT, sizeof( idDrawVert ), ac->normal.ToFloatPtr() );
	}
	if( pStage->texture.texgen == TG_SKYBOX_CUBE || pStage->texture.texgen == TG_WOBBLESKY_CUBE ) {
		glTexCoordPointer( 3, GL_FLOAT, 0, vertexCache.Position( surf->dynamicTexCoords ) );
	}
	if( pStage->texture.texgen == TG_SCREEN ) {
		RB_SetStageTexGen( surf );
	}
	if( pStage->texture.texgen == TG_SCREEN2 ) {
		RB_SetStageTexGen( surf );
	}
	if( pStage->texture.texgen == TG_GLASSWARP ) {
		if( glConfig.ARBVertexProgramAvailable && tr.backEndRenderer == BE_ARB2 ) {
			glBindProgramARB( GL_FRAGMENT_PROGRAM_ARB, FPROG_GLASSWARP );
			glEnable( GL_FRAGMENT_PROGRAM_ARB );
			GL_SelectTexture( 2 );
			globalImages->scratchImage->Bind();
			GL_SelectTexture( 1 );
			globalImages->scratchImage2->Bind();
			RB_SetStageTexGen( surf );
			GL_SelectTexture( 0 );
		}
	}
	if( pStage->texture.texgen == TG_REFLECT_CUBE ) {
		if( glConfig.ARBVertexProgramAvailable && tr.backEndRenderer == BE_ARB2 ) {
			// see if there is also a bump map specified
			const shaderStage_t *bumpStage = surf->material->GetBumpStage();
			if( bumpStage ) {
				// per-pixel reflection mapping with bump mapping
				GL_SelectTexture( 1 );
				bumpStage->texture.image->Bind();
				GL_SelectTexture( 0 );
				glNormalPointer( GL_FLOAT, sizeof( idDrawVert ), ac->normal.ToFloatPtr() );
				glVertexAttribPointerARB( 10, 3, GL_FLOAT, false, sizeof( idDrawVert ), ac->tangents[1].ToFloatPtr() );
				glVertexAttribPointerARB( 9, 3, GL_FLOAT, false, sizeof( idDrawVert ), ac->tangents[0].ToFloatPtr() );
				glEnableVertexAttribArrayARB( 9 );
				glEnableVertexAttribArrayARB( 10 );
				glEnableClientState( GL_NORMAL_ARRAY );
				// Program env 5, 6, 7, 8 have been set in RB_SetProgramEnvironmentSpace
				glBindProgramARB( GL_FRAGMENT_PROGRAM_ARB, FPROG_BUMPY_ENVIRONMENT );
				glEnable( GL_FRAGMENT_PROGRAM_ARB );
				glBindProgramARB( GL_VERTEX_PROGRAM_ARB, VPROG_BUMPY_ENVIRONMENT );
				glEnable( GL_VERTEX_PROGRAM_ARB );
			} else {
				// per-pixel reflection mapping without a normal map
				glNormalPointer( GL_FLOAT, sizeof( idDrawVert ), ac->normal.ToFloatPtr() );
				glEnableClientState( GL_NORMAL_ARRAY );
				glBindProgramARB( GL_FRAGMENT_PROGRAM_ARB, FPROG_ENVIRONMENT );
				glEnable( GL_FRAGMENT_PROGRAM_ARB );
				glBindProgramARB( GL_VERTEX_PROGRAM_ARB, VPROG_ENVIRONMENT );
				glEnable( GL_VERTEX_PROGRAM_ARB );
			}
		} else {
			glEnable( GL_TEXTURE_GEN_S );
			glEnable( GL_TEXTURE_GEN_T );
			glEnable( GL_TEXTURE_GEN_R );
			glTexGenf( GL_S, GL_TEXTURE_GEN_MODE, GL_REFLECTION_MAP_EXT );
			glTexGenf( GL_T, GL_TEXTURE_GEN_MODE, GL_REFLECTION_MAP_EXT );
			glTexGenf( GL_R, GL_TEXTURE_GEN_MODE, GL_REFLECTION_MAP_EXT );
			glEnableClientState( GL_NORMAL_ARRAY );
			glNormalPointer( GL_FLOAT, sizeof( idDrawVert ), ac->normal.ToFloatPtr() );
			glMatrixMode( GL_TEXTURE );
			float	mat[16];
			R_TransposeGLMatrix( backEnd.viewDef->worldSpace.modelViewMatrix, mat );
			glLoadMatrixf( mat );
			glMatrixMode( GL_MODELVIEW );
		}
	}
}

/*
================
RB_FinishStageTexturing
================
*/
static void RB_FinishStageTexturing( const shaderStage_t *pStage, const drawSurf_t *surf, idDrawVert *ac ) {
	// unset privatePolygonOffset if necessary
	if( pStage->privatePolygonOffset && !surf->material->TestMaterialFlag( MF_POLYGONOFFSET ) ) {
		glDisable( GL_POLYGON_OFFSET_FILL );
	}
	if( pStage->texture.texgen == TG_DIFFUSE_CUBE || pStage->texture.texgen == TG_SKYBOX_CUBE || pStage->texture.texgen == TG_WOBBLESKY_CUBE ) {
		glTexCoordPointer( 2, GL_FLOAT, sizeof( idDrawVert ), ( void * )&ac->st );
	}
	if( pStage->texture.texgen == TG_SCREEN ) {
		glDisable( GL_TEXTURE_GEN_S );
		glDisable( GL_TEXTURE_GEN_T );
		glDisable( GL_TEXTURE_GEN_Q );
	}
	if( pStage->texture.texgen == TG_SCREEN2 ) {
		glDisable( GL_TEXTURE_GEN_S );
		glDisable( GL_TEXTURE_GEN_T );
		glDisable( GL_TEXTURE_GEN_Q );
	}
	if( pStage->texture.texgen == TG_GLASSWARP ) {
		if( glConfig.ARBVertexProgramAvailable && tr.backEndRenderer == BE_ARB2 ) {
			GL_SelectTexture( 2 );
			globalImages->BindNull();
			GL_SelectTexture( 1 );
			if( pStage->texture.hasMatrix ) {
				RB_LoadShaderTextureMatrix( surf->shaderRegisters, &pStage->texture );
			}
			glDisable( GL_TEXTURE_GEN_S );
			glDisable( GL_TEXTURE_GEN_T );
			glDisable( GL_TEXTURE_GEN_Q );
			glDisable( GL_FRAGMENT_PROGRAM_ARB );
			globalImages->BindNull();
			GL_SelectTexture( 0 );
		}
	}
	if( pStage->texture.texgen == TG_REFLECT_CUBE ) {
		if( glConfig.ARBVertexProgramAvailable && tr.backEndRenderer == BE_ARB2 ) {
			// see if there is also a bump map specified
			const shaderStage_t *bumpStage = surf->material->GetBumpStage();
			if( bumpStage ) {
				// per-pixel reflection mapping with bump mapping
				GL_SelectTexture( 1 );
				globalImages->BindNull();
				GL_SelectTexture( 0 );
				glDisableVertexAttribArrayARB( 9 );
				glDisableVertexAttribArrayARB( 10 );
			}
			// per-pixel reflection mapping without bump mapping
			glDisableClientState( GL_NORMAL_ARRAY );
			glDisable( GL_FRAGMENT_PROGRAM_ARB );
			glDisable( GL_VERTEX_PROGRAM_ARB );
		} else {
			glDisable( GL_TEXTURE_GEN_S );
			glDisable( GL_TEXTURE_GEN_T );
			glDisable( GL_TEXTURE_GEN_R );
			glTexGenf( GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR );
			glTexGenf( GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR );
			glTexGenf( GL_R, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR );
			glDisableClientState( GL_NORMAL_ARRAY );
			glMatrixMode( GL_TEXTURE );
			glLoadIdentity();
			glMatrixMode( GL_MODELVIEW );
		}
	}
	if( pStage->texture.hasMatrix ) {
		glMatrixMode( GL_TEXTURE );
		glLoadIdentity();
		glMatrixMode( GL_MODELVIEW );
	}
}

/*
=============================================================================================

FILL DEPTH BUFFER

=============================================================================================
*/

/*
==================
RB_T_FillDepthBuffer
==================
*/
static void RB_T_FillDepthBuffer( const drawSurf_t *surf ) {
	int						stage;
	const idMaterial		*shader;
	const shaderStage_t		*pStage;
	const float				*regs;
	float					color[4];
	const srfTriangles_t	*tri;
	tri = surf->geo;
	shader = surf->material;
	// update the clip plane if needed
	if( backEnd.viewDef->numClipPlanes && surf->space != backEnd.currentSpace ) {
		GL_SelectTexture( 1 );
		idPlane	plane;
		R_GlobalPlaneToLocal( surf->space->modelMatrix, backEnd.viewDef->clipPlanes[0], plane );
		plane[3] += 0.5;	// the notch is in the middle
		glTexGenfv( GL_S, GL_OBJECT_PLANE, plane.ToFloatPtr() );
		GL_SelectTexture( 0 );
	}
	if( !shader->IsDrawn() ) {
		return;
	}
	// some deforms may disable themselves by setting numIndexes = 0
	if( !tri->numIndexes ) {
		return;
	}
	// translucent surfaces don't put anything in the depth buffer and don't
	// test against it, which makes them fail the mirror clip plane operation
	if( shader->Coverage() == MC_TRANSLUCENT ) {
		return;
	}
	if( !tri->ambientCache ) {
		common->Printf( "RB_T_FillDepthBuffer: !tri->ambientCache\n" );
		return;
	}
	// get the expressions for conditionals / color / texcoords
	regs = surf->shaderRegisters;
	// if all stages of a material have been conditioned off, don't do anything
	for( stage = 0; stage < shader->GetNumStages() ; stage++ ) {
		pStage = shader->GetStage( stage );
		// check the stage enable condition
		if( regs[ pStage->conditionRegister ] != 0 ) {
			break;
		}
	}
	if( stage == shader->GetNumStages() ) {
		return;
	}
	// set polygon offset if necessary
	if( shader->TestMaterialFlag( MF_POLYGONOFFSET ) ) {
		glEnable( GL_POLYGON_OFFSET_FILL );
		glPolygonOffset( r_offsetFactor.GetFloat(), r_offsetUnits.GetFloat() * shader->GetPolygonOffset() );
	}
	// subviews will just down-modulate the color buffer by overbright
	if( shader->GetSort() == SS_SUBVIEW ) {
		GL_State( GLS_SRCBLEND_DST_COLOR | GLS_DSTBLEND_ZERO | GLS_DEPTHFUNC_LESS );
		color[0] =
		color[1] =
		color[2] = ( 1.0f / backEnd.overBright );
		color[3] = 1.0f;
	} else {
		// others just draw black
		color[0] = 0.0f;
		color[1] = 0.0f;
		color[2] = 0.0f;
		color[3] = 1.0f;
	}
	idDrawVert *ac = ( idDrawVert * )vertexCache.Position( tri->ambientCache );
	glVertexPointer( 3, GL_FLOAT, sizeof( idDrawVert ), ac->xyz.ToFloatPtr() );
	glTexCoordPointer( 2, GL_FLOAT, sizeof( idDrawVert ), reinterpret_cast<void *>( &ac->st ) );
	bool drawSolid = false;
	if( shader->Coverage() == MC_OPAQUE ) {
		drawSolid = true;
	}
	// we may have multiple alpha tested stages
	if( shader->Coverage() == MC_PERFORATED ) {
		// if the only alpha tested stages are condition register omitted,
		// draw a normal opaque surface
		bool	didDraw = false;
		glEnable( GL_ALPHA_TEST );
		// perforated surfaces may have multiple alpha tested stages
		for( stage = 0; stage < shader->GetNumStages() ; stage++ ) {
			pStage = shader->GetStage( stage );
			if( !pStage->hasAlphaTest ) {
				continue;
			}
			// check the stage enable condition
			if( regs[ pStage->conditionRegister ] == 0 ) {
				continue;
			}
			// if we at least tried to draw an alpha tested stage,
			// we won't draw the opaque surface
			didDraw = true;
			// set the alpha modulate
			color[3] = regs[ pStage->color.registers[3] ];
			// skip the entire stage if alpha would be black
			if( color[3] <= 0 ) {
				continue;
			}
			glColor4fv( color );
			glAlphaFunc( GL_GREATER, regs[ pStage->alphaTestRegister ] );
			// bind the texture
			pStage->texture.image->Bind();
			// set texture matrix and texGens
			RB_PrepareStageTexturing( pStage, surf, ac );
			// draw it
			RB_DrawElementsWithCounters( tri );
			RB_FinishStageTexturing( pStage, surf, ac );
		}
		glDisable( GL_ALPHA_TEST );
		if( !didDraw ) {
			drawSolid = true;
		}
	}
	// draw the entire surface solid
	if( drawSolid ) {
		glColor4fv( color );
		globalImages->whiteImage->Bind();
		// draw it
		RB_DrawElementsWithCounters( tri );
	}
	// reset polygon offset
	if( shader->TestMaterialFlag( MF_POLYGONOFFSET ) ) {
		glDisable( GL_POLYGON_OFFSET_FILL );
	}
	// reset blending
	if( shader->GetSort() == SS_SUBVIEW ) {
		GL_State( GLS_DEPTHFUNC_LESS );
	}
}

/*
=====================
RB_STD_FillDepthBuffer

If we are rendering a subview with a near clip plane, use a second texture
to force the alpha test to fail when behind that clip plane
=====================
*/
static void RB_STD_FillDepthBuffer( drawSurf_t **drawSurfs, int numDrawSurfs ) {
	// if we are just doing 2D rendering, no need to fill the depth buffer
	if( !backEnd.viewDef->viewEntitys ) {
		return;
	}
	// enable the second texture for mirror plane clipping if needed
	if( backEnd.viewDef->numClipPlanes ) {
		GL_SelectTexture( 1 );
		globalImages->alphaNotchImage->Bind();
		glDisableClientState( GL_TEXTURE_COORD_ARRAY );
		glEnable( GL_TEXTURE_GEN_S );
		glTexCoord2f( 1, 0.5 );
	}
	// the first texture will be used for alpha tested surfaces
	GL_SelectTexture( 0 );
	glEnableClientState( GL_TEXTURE_COORD_ARRAY );
	// decal surfaces may enable polygon offset
	glPolygonOffset( r_offsetFactor.GetFloat(), r_offsetUnits.GetFloat() );
	GL_State( GLS_DEPTHFUNC_LESS );
	// Enable stencil test if we are going to be using it for shadows.
	// If we didn't do this, it would be legal behavior to get z fighting
	// from the ambient pass and the light passes.
	glEnable( GL_STENCIL_TEST );
	glStencilFunc( GL_ALWAYS, 1, 255 );
	RB_RenderDrawSurfListWithFunction( drawSurfs, numDrawSurfs, RB_T_FillDepthBuffer );
	if( backEnd.viewDef->numClipPlanes ) {
		GL_SelectTexture( 1 );
		globalImages->BindNull();
		glDisable( GL_TEXTURE_GEN_S );
		GL_SelectTexture( 0 );
	}
}

/*
=============================================================================================

SHADER PASSES

=============================================================================================
*/

/*
==================
RB_SetProgramEnvironment

Sets variables that can be used by all vertex programs
==================
*/
static void RB_SetProgramEnvironment( void ) {
	float	parm[4];
	int		pot;
	// completely skip the stage if we don't have the capability
	if( !glConfig.ARBVertexProgramAvailable || tr.backEndRenderer != BE_ARB2 ) {
		return;
	}
	// screen power of two correction factor, assuming the copy to _currentRender
	// also copied an extra row and column for the bilerp
	int	 w = backEnd.viewDef->viewport.x2 - backEnd.viewDef->viewport.x1 + 1;
	pot = globalImages->currentRenderImage->uploadWidth;
	parm[0] = ( float )w / pot;
	int	 h = backEnd.viewDef->viewport.y2 - backEnd.viewDef->viewport.y1 + 1;
	pot = globalImages->currentRenderImage->uploadHeight;
	parm[1] = ( float )h / pot;
	parm[2] = 0.0f;
	parm[3] = 1.0f;
	glProgramEnvParameter4fvARB( GL_VERTEX_PROGRAM_ARB, 0, parm );
	glProgramEnvParameter4fvARB( GL_FRAGMENT_PROGRAM_ARB, 0, parm );
	// window coord to 0.0 to 1.0 conversion
	parm[0] = 1.0f / w;
	parm[1] = 1.0f / h;
	parm[2] = 0.0f;
	parm[3] = 1.0f;
	glProgramEnvParameter4fvARB( GL_FRAGMENT_PROGRAM_ARB, 1, parm );
	//
	// set eye position in global space
	//
	parm[0] = backEnd.viewDef->renderView.vieworg[0];
	parm[1] = backEnd.viewDef->renderView.vieworg[1];
	parm[2] = backEnd.viewDef->renderView.vieworg[2];
	parm[3] = 1.0f;
	glProgramEnvParameter4fvARB( GL_VERTEX_PROGRAM_ARB, 1, parm );
}

/*
==================
RB_SetProgramEnvironmentSpace

Sets variables related to the current space that can be used by all vertex programs
==================
*/
static void RB_SetProgramEnvironmentSpace( void ) {
	// completely skip the stage if we don't have the capability
	if( !glConfig.ARBVertexProgramAvailable || tr.backEndRenderer != BE_ARB2 ) {
		return;
	}
	const struct viewEntity_s	*space = backEnd.currentSpace;
	float						parm[4];
	// set eye position in local space
	R_GlobalPointToLocal( space->modelMatrix, backEnd.viewDef->renderView.vieworg, *( idVec3 * )parm );
	parm[3] = 1.0f;
	glProgramEnvParameter4fvARB( GL_VERTEX_PROGRAM_ARB, 5, parm );
	// we need the model matrix without it being combined with the view matrix
	// so we can transform local vectors to global coordinates
	parm[0] = space->modelMatrix[0];
	parm[1] = space->modelMatrix[4];
	parm[2] = space->modelMatrix[8];
	parm[3] = space->modelMatrix[12];
	glProgramEnvParameter4fvARB( GL_VERTEX_PROGRAM_ARB, 6, parm );
	parm[0] = space->modelMatrix[1];
	parm[1] = space->modelMatrix[5];
	parm[2] = space->modelMatrix[9];
	parm[3] = space->modelMatrix[13];
	glProgramEnvParameter4fvARB( GL_VERTEX_PROGRAM_ARB, 7, parm );
	parm[0] = space->modelMatrix[2];
	parm[1] = space->modelMatrix[6];
	parm[2] = space->modelMatrix[10];
	parm[3] = space->modelMatrix[14];
	glProgramEnvParameter4fvARB( GL_VERTEX_PROGRAM_ARB, 8, parm );
}

/*
==================
RB_STD_T_RenderShaderPassesStage1

Stage rendering for vertex programs
==================
*/
static void RB_STD_T_RenderShaderPassesStage1( const drawSurf_t *surf, const srfTriangles_t *tri, idDrawVert *ac, const shaderStage_t *pStage, const float *regs ) {
	// completely skip the stage if we don't have the capability
	if( !glConfig.ARBVertexProgramAvailable || tr.backEndRenderer != BE_ARB2 ) {
		return;
	}
	if( r_skipNewAmbient.GetBool() ) {
		return;
	}
	newShaderStage_t *newStage = pStage->newStage;
	glColorPointer( 4, GL_UNSIGNED_BYTE, sizeof( idDrawVert ), ( void * )&ac->color );
	glVertexAttribPointerARB( 9, 3, GL_FLOAT, false, sizeof( idDrawVert ), ac->tangents[0].ToFloatPtr() );
	glVertexAttribPointerARB( 10, 3, GL_FLOAT, false, sizeof( idDrawVert ), ac->tangents[1].ToFloatPtr() );
	glNormalPointer( GL_FLOAT, sizeof( idDrawVert ), ac->normal.ToFloatPtr() );
	glEnableClientState( GL_COLOR_ARRAY );
	glEnableVertexAttribArrayARB( 9 );
	glEnableVertexAttribArrayARB( 10 );
	glEnableClientState( GL_NORMAL_ARRAY );
	GL_State( pStage->drawStateBits );
	glBindProgramARB( GL_VERTEX_PROGRAM_ARB, newStage->vertexProgram );
	glEnable( GL_VERTEX_PROGRAM_ARB );
	// megaTextures bind a lot of images and set a lot of parameters
	if( newStage->megaTexture ) {
		newStage->megaTexture->SetMappingForSurface( tri );
		idVec3	localViewer;
		R_GlobalPointToLocal( surf->space->modelMatrix, backEnd.viewDef->renderView.vieworg, localViewer );
		newStage->megaTexture->BindForViewOrigin( localViewer );
	}
	for( int i = 0 ; i < newStage->numVertexParms ; i++ ) {
		float	parm[4];
		parm[0] = regs[ newStage->vertexParms[i][0] ];
		parm[1] = regs[ newStage->vertexParms[i][1] ];
		parm[2] = regs[ newStage->vertexParms[i][2] ];
		parm[3] = regs[ newStage->vertexParms[i][3] ];
		glProgramLocalParameter4fvARB( GL_VERTEX_PROGRAM_ARB, i, parm );
	}
	for( int i = 0 ; i < newStage->numFragmentProgramImages ; i++ ) {
		if( newStage->fragmentProgramImages[i] ) {
			GL_SelectTexture( i );
			newStage->fragmentProgramImages[i]->Bind();
		}
	}
	glBindProgramARB( GL_FRAGMENT_PROGRAM_ARB, newStage->fragmentProgram );
	glEnable( GL_FRAGMENT_PROGRAM_ARB );
	// draw it
	RB_DrawElementsWithCounters( tri );
	for( int i = 1 ; i < newStage->numFragmentProgramImages ; i++ ) {
		if( newStage->fragmentProgramImages[i] ) {
			GL_SelectTexture( i );
			globalImages->BindNull();
		}
	}
	if( newStage->megaTexture ) {
		newStage->megaTexture->Unbind();
	}
	GL_SelectTexture( 0 );
	glDisable( GL_VERTEX_PROGRAM_ARB );
	glDisable( GL_FRAGMENT_PROGRAM_ARB );
	glDisableClientState( GL_COLOR_ARRAY );
	glDisableVertexAttribArrayARB( 9 );
	glDisableVertexAttribArrayARB( 10 );
	glDisableClientState( GL_NORMAL_ARRAY );
}

/*
==================
RB_STD_T_RenderShaderPassesStage2

Old style stage rendering
==================
*/
static void RB_STD_T_RenderShaderPassesStage2( const drawSurf_t *surf, const srfTriangles_t *tri, idDrawVert *ac, const shaderStage_t *pStage, const float *regs ) {
	// set the color
	const GLfloat color[] =	{
		regs[pStage->color.registers[0]],
		regs[pStage->color.registers[1]],
		regs[pStage->color.registers[2]],
		regs[pStage->color.registers[3]]
	};
	// skip the entire stage if an add would be black
	if( ( pStage->drawStateBits & ( GLS_SRCBLEND_BITS | GLS_DSTBLEND_BITS ) ) == ( GLS_SRCBLEND_ONE | GLS_DSTBLEND_ONE ) && color[0] <= 0 && color[1] <= 0 && color[2] <= 0 ) {
		return;
	}
	// skip the entire stage if a blend would be completely transparent
	if( ( pStage->drawStateBits & ( GLS_SRCBLEND_BITS | GLS_DSTBLEND_BITS ) ) == ( GLS_SRCBLEND_SRC_ALPHA | GLS_DSTBLEND_ONE_MINUS_SRC_ALPHA )	&& color[3] <= 0 ) {
		return;
	}
	// select the vertex color source
	if( pStage->vertexColor == SVC_IGNORE ) {
		glColor4fv( color );
	} else {
		glColorPointer( 4, GL_UNSIGNED_BYTE, sizeof( idDrawVert ), ( void * )&ac->color );
		glEnableClientState( GL_COLOR_ARRAY );
		if( pStage->vertexColor == SVC_INVERSE_MODULATE ) {
			GL_TexEnv( GL_COMBINE_ARB );
			glTexEnvi( GL_TEXTURE_ENV, GL_COMBINE_RGB_ARB, GL_MODULATE );
			glTexEnvi( GL_TEXTURE_ENV, GL_SOURCE0_RGB_ARB, GL_TEXTURE );
			glTexEnvi( GL_TEXTURE_ENV, GL_SOURCE1_RGB_ARB, GL_PRIMARY_COLOR_ARB );
			glTexEnvi( GL_TEXTURE_ENV, GL_OPERAND0_RGB_ARB, GL_SRC_COLOR );
			glTexEnvi( GL_TEXTURE_ENV, GL_OPERAND1_RGB_ARB, GL_ONE_MINUS_SRC_COLOR );
			glTexEnvi( GL_TEXTURE_ENV, GL_RGB_SCALE_ARB, 1 );
		}
		// for vertex color and modulated color, we need to enable a second
		// texture stage
		if( color[0] != 1 || color[1] != 1 || color[2] != 1 || color[3] != 1 ) {
			GL_SelectTexture( 1 );
			globalImages->whiteImage->Bind();
			GL_TexEnv( GL_COMBINE_ARB );
			glTexEnvfv( GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, color );
			glTexEnvi( GL_TEXTURE_ENV, GL_COMBINE_RGB_ARB, GL_MODULATE );
			glTexEnvi( GL_TEXTURE_ENV, GL_SOURCE0_RGB_ARB, GL_PREVIOUS_ARB );
			glTexEnvi( GL_TEXTURE_ENV, GL_SOURCE1_RGB_ARB, GL_CONSTANT_ARB );
			glTexEnvi( GL_TEXTURE_ENV, GL_OPERAND0_RGB_ARB, GL_SRC_COLOR );
			glTexEnvi( GL_TEXTURE_ENV, GL_OPERAND1_RGB_ARB, GL_SRC_COLOR );
			glTexEnvi( GL_TEXTURE_ENV, GL_RGB_SCALE_ARB, 1 );
			glTexEnvi( GL_TEXTURE_ENV, GL_COMBINE_ALPHA_ARB, GL_MODULATE );
			glTexEnvi( GL_TEXTURE_ENV, GL_SOURCE0_ALPHA_ARB, GL_PREVIOUS_ARB );
			glTexEnvi( GL_TEXTURE_ENV, GL_SOURCE1_ALPHA_ARB, GL_CONSTANT_ARB );
			glTexEnvi( GL_TEXTURE_ENV, GL_OPERAND0_ALPHA_ARB, GL_SRC_ALPHA );
			glTexEnvi( GL_TEXTURE_ENV, GL_OPERAND1_ALPHA_ARB, GL_SRC_ALPHA );
			glTexEnvi( GL_TEXTURE_ENV, GL_ALPHA_SCALE, 1 );
			GL_SelectTexture( 0 );
		}
	}
	// bind the texture
	RB_BindVariableStageImage( &pStage->texture, regs );
	// set the state
	GL_State( pStage->drawStateBits );
	RB_PrepareStageTexturing( pStage, surf, ac );
	// draw it
	RB_DrawElementsWithCounters( tri );
	// done
	RB_FinishStageTexturing( pStage, surf, ac );
	if( pStage->vertexColor != SVC_IGNORE ) {
		glDisableClientState( GL_COLOR_ARRAY );
		GL_SelectTexture( 1 );
		GL_TexEnv( GL_MODULATE );
		globalImages->BindNull();
		GL_SelectTexture( 0 );
		GL_TexEnv( GL_MODULATE );
	}
}

/*
==================
RB_STD_T_RenderShaderPasses

This is also called for the generated 2D rendering
==================
*/
static void RB_STD_T_RenderShaderPasses( const drawSurf_t *surf ) {
	int						stage;
	const idMaterial		*shader;
	const shaderStage_t		*pStage;
	const float				*regs;
	const srfTriangles_t	*tri;
	tri = surf->geo;
	shader = surf->material;
	if( !shader->HasAmbient() ) {
		return;
	}
	if( shader->IsPortalSky() ) {
		return;
	}
	// change the matrix if needed
	if( surf->space != backEnd.currentSpace ) {
		backEnd.currentSpace = surf->space;
		glLoadMatrixf( surf->space->modelViewMatrix );
		RB_SetProgramEnvironmentSpace();
	}
	// change the scissor if needed
	if( r_useScissor.GetBool() && !backEnd.currentScissor.Equals( surf->scissorRect ) ) {
		backEnd.currentScissor = surf->scissorRect;
		glScissor( backEnd.viewDef->viewport.x1 + backEnd.currentScissor.x1,
				   backEnd.viewDef->viewport.y1 + backEnd.currentScissor.y1,
				   backEnd.currentScissor.x2 + 1 - backEnd.currentScissor.x1,
				   backEnd.currentScissor.y2 + 1 - backEnd.currentScissor.y1 );
	}
	// some deforms may disable themselves by setting numIndexes = 0
	if( !tri->numIndexes ) {
		return;
	}
	if( !tri->ambientCache ) {
		common->Printf( "RB_T_RenderShaderPasses: !tri->ambientCache\n" );
		return;
	}
	// get the expressions for conditionals / color / texcoords
	regs = surf->shaderRegisters;
	// set face culling appropriately
	GL_Cull( shader->GetCullType() );
	// set polygon offset if necessary
	if( shader->TestMaterialFlag( MF_POLYGONOFFSET ) ) {
		glEnable( GL_POLYGON_OFFSET_FILL );
		glPolygonOffset( r_offsetFactor.GetFloat(), r_offsetUnits.GetFloat() * shader->GetPolygonOffset() );
	}
	if( surf->space->weaponDepthHack ) {
		RB_EnterWeaponDepthHack();
	}
	if( surf->space->modelDepthHack != 0.0f ) {
		RB_EnterModelDepthHack( surf->space->modelDepthHack );
	}
	idDrawVert *ac = ( idDrawVert * )vertexCache.Position( tri->ambientCache );
	glVertexPointer( 3, GL_FLOAT, sizeof( idDrawVert ), ac->xyz.ToFloatPtr() );
	glTexCoordPointer( 2, GL_FLOAT, sizeof( idDrawVert ), reinterpret_cast<void *>( &ac->st ) );
	for( stage = 0; stage < shader->GetNumStages() ; stage++ ) {
		pStage = shader->GetStage( stage );
		// check the enable condition
		if( regs[ pStage->conditionRegister ] == 0 ) {
			continue;
		}
		// skip the stages involved in lighting
		if( pStage->lighting != SL_AMBIENT ) {
			continue;
		}
		// skip if the stage is ( GL_ZERO, GL_ONE ), which is used for some alpha masks
		if( ( pStage->drawStateBits & ( GLS_SRCBLEND_BITS | GLS_DSTBLEND_BITS ) ) == ( GLS_SRCBLEND_ZERO | GLS_DSTBLEND_ONE ) ) {
			continue;
		}
		// see if we are a new-style stage
		if( pStage->newStage ) {
			RB_STD_T_RenderShaderPassesStage1( surf, tri, ac, pStage, regs );
		} else {
			RB_STD_T_RenderShaderPassesStage2( surf, tri, ac, pStage, regs );
		}
	}
	// reset polygon offset
	if( shader->TestMaterialFlag( MF_POLYGONOFFSET ) ) {
		glDisable( GL_POLYGON_OFFSET_FILL );
	}
	if( surf->space->weaponDepthHack || surf->space->modelDepthHack != 0.0f ) {
		RB_LeaveDepthHack();
	}
}

/*
=====================
RB_STD_DrawShaderPasses

Draw non-light dependent passes
=====================
*/
static int RB_STD_DrawShaderPasses( drawSurf_t **drawSurfs, int numDrawSurfs ) {
	int	shaderPasses;
	// only obey skipAmbient if we are rendering a view
	if( backEnd.viewDef->viewEntitys && r_skipAmbient.GetBool() ) {
		return numDrawSurfs;
	}
	// if we are about to draw the first surface that needs
	// the rendering in a texture, copy it over
	if( drawSurfs[0]->material->GetSort() >= SS_POST_PROCESS ) {
		if( r_skipPostProcess.GetBool() ) {
			return 0;
		}
		// only dump if in a 3d view
		if( backEnd.viewDef->viewEntitys && ( tr.backEndRenderer == BE_ARB2 || tr.backEndRenderer == BE_GLSL ) ) {
			globalImages->currentRenderImage->CopyFramebuffer( backEnd.viewDef->viewport.x1,
			backEnd.viewDef->viewport.y1,  backEnd.viewDef->viewport.x2 -  backEnd.viewDef->viewport.x1 + 1,
			backEnd.viewDef->viewport.y2 -  backEnd.viewDef->viewport.y1 + 1, true );
		}
		backEnd.currentRenderCopied = true;
	}
	GL_SelectTexture( 1 );
	globalImages->BindNull();
	GL_SelectTexture( 0 );
	glEnableClientState( GL_TEXTURE_COORD_ARRAY );
	RB_SetProgramEnvironment();
	// we don't use RB_RenderDrawSurfListWithFunction()
	// because we want to defer the matrix load because many
	// surfaces won't draw any ambient passes
	backEnd.currentSpace = NULL;
	for( shaderPasses = 0  ; shaderPasses < numDrawSurfs ; shaderPasses++ ) {
		if( drawSurfs[shaderPasses]->material->SuppressInSubview() ) {
			continue;
		}
		if( backEnd.viewDef->isXraySubview && drawSurfs[shaderPasses]->space->entityDef ) {
			if( drawSurfs[shaderPasses]->space->entityDef->parms.xrayIndex != 2 ) {
				continue;
			}
		}
		// we need to draw the post process shaders after we have drawn the fog lights
		if( drawSurfs[shaderPasses]->material->GetSort() >= SS_POST_PROCESS && !backEnd.currentRenderCopied ) {
			break;
		}
		RB_STD_T_RenderShaderPasses( drawSurfs[shaderPasses] );
	}
	GL_Cull( CT_FRONT_SIDED );
	glColor3f( 1, 1, 1 );
	return shaderPasses;
}

/*
==============================================================================

BACK END RENDERING OF STENCIL SHADOWS

==============================================================================
*/

/*
=====================
RB_T_Shadow

the shadow volumes face INSIDE
=====================
*/
static void RB_T_Shadow( const drawSurf_t *surf ) {
	const srfTriangles_t	*tri;
	// set the light position if we are using a vertex program to project the rear surfaces
	if( tr.backEndRendererHasVertexPrograms && r_useShadowVertexProgram.GetBool() && surf->space != backEnd.currentSpace ) {
		idVec4 localLight;
		R_GlobalPointToLocal( surf->space->modelMatrix, backEnd.vLight->globalLightOrigin, localLight.ToVec3() );
		localLight.w = 0.0f;
		// Only the Arb2 backend can use this so make sure its set
		if( glConfig.ARBVertexProgramAvailable && tr.backEndRenderer == BE_ARB2 ) {
			glProgramEnvParameter4fvARB( GL_VERTEX_PROGRAM_ARB, PP_LIGHT_ORIGIN, localLight.ToFloatPtr() );
		} else if( glConfig.ARBShadingLanguageAvailable && tr.backEndRenderer == BE_GLSL ) {
			glUniform4fvARB( stencilShadowShader.localLightOrigin, 1, localLight.ToFloatPtr() );
		}
	}
	tri = surf->geo;
	if( !tri->shadowCache ) {
		return;
	}
	glVertexPointer( 4, GL_FLOAT, sizeof( shadowCache_t ), vertexCache.Position( tri->shadowCache ) );
	// we always draw the sil planes, but we may not need to draw the front or rear caps
	int		numIndexes;
	bool	external = false;
	if( !r_useExternalShadows.GetInteger() ) {
		numIndexes = tri->numIndexes;
	} else if( r_useExternalShadows.GetInteger() == 2 ) {  // force to no caps for testing
		numIndexes = tri->numShadowIndexesNoCaps;
	} else if( !( surf->dsFlags & DSF_VIEW_INSIDE_SHADOW ) ) {
		// if we aren't inside the shadow projection, no caps are ever needed needed
		numIndexes = tri->numShadowIndexesNoCaps;
		external = true;
	} else if( !backEnd.vLight->viewInsideLight && !( surf->geo->shadowCapPlaneBits & SHADOW_CAP_INFINITE ) ) {
		// if we are inside the shadow projection, but outside the light, and drawing
		// a non-infinite shadow, we can skip some caps
		if( backEnd.vLight->viewSeesShadowPlaneBits & surf->geo->shadowCapPlaneBits ) {
			// we can see through a rear cap, so we need to draw it, but we can skip the
			// caps on the actual surface
			numIndexes = tri->numShadowIndexesNoFrontCaps;
		} else {
			// we don't need to draw any caps
			numIndexes = tri->numShadowIndexesNoCaps;
		}
		external = true;
	} else {
		// must draw everything
		numIndexes = tri->numIndexes;
	}
	// Moved depthbounds test here
	if( r_useDepthBoundsTest.GetBool() ) {
		GL_DepthBoundsTest( surf->scissorRect.zmin, surf->scissorRect.zmax );
	}
	// debug visualization
	if( r_showShadows.GetInteger() ) {
		if( r_showShadows.GetInteger() == 3 ) {
			if( external ) {
				glColor3f( 0.1 / backEnd.overBright, 1 / backEnd.overBright, 0.1 / backEnd.overBright );
			} else {
				// these are the surfaces that require the reverse
				glColor3f( 1 / backEnd.overBright, 0.1 / backEnd.overBright, 0.1 / backEnd.overBright );
			}
		} else {
			// draw different color for turboshadows
			if( surf->geo->shadowCapPlaneBits & SHADOW_CAP_INFINITE ) {
				if( numIndexes == tri->numIndexes ) {
					glColor3f( 1 / backEnd.overBright, 0.1 / backEnd.overBright, 0.1 / backEnd.overBright );
				} else {
					glColor3f( 1 / backEnd.overBright, 0.4 / backEnd.overBright, 0.1 / backEnd.overBright );
				}
			} else {
				if( numIndexes == tri->numIndexes ) {
					glColor3f( 0.1 / backEnd.overBright, 1 / backEnd.overBright, 0.1 / backEnd.overBright );
				} else if( numIndexes == tri->numShadowIndexesNoFrontCaps ) {
					glColor3f( 0.1 / backEnd.overBright, 1 / backEnd.overBright, 0.6 / backEnd.overBright );
				} else {
					glColor3f( 0.6 / backEnd.overBright, 1 / backEnd.overBright, 0.1 / backEnd.overBright );
				}
			}
		}
		glStencilOp( GL_KEEP, GL_KEEP, GL_KEEP );
		glDisable( GL_STENCIL_TEST );
		GL_Cull( CT_TWO_SIDED );
		RB_DrawShadowElementsWithCounters( tri, numIndexes );
		GL_Cull( CT_FRONT_SIDED );
		glEnable( GL_STENCIL_TEST );
		return;
	}
	// patent-free work arounds
	if( glConfig.glVersion >= 2.0f && r_useTwoSidedStencil.GetBool() ) {
		// GL 2.0+ two-sided stencil
		GL_Cull( CT_TWO_SIDED );
		if( !external )	{
			glStencilOpSeparate( backEnd.viewDef->isMirror ? GL_FRONT : GL_BACK, GL_KEEP, tr.stencilDecr, GL_KEEP );
			glStencilOpSeparate( backEnd.viewDef->isMirror ? GL_BACK : GL_FRONT, GL_KEEP, tr.stencilIncr, GL_KEEP );
			RB_DrawShadowElementsWithCounters( tri, numIndexes );
		} else {
			glStencilOpSeparate( backEnd.viewDef->isMirror ? GL_FRONT : GL_BACK, GL_KEEP, GL_KEEP, tr.stencilIncr );
			glStencilOpSeparate( backEnd.viewDef->isMirror ? GL_BACK : GL_FRONT, GL_KEEP, GL_KEEP, tr.stencilDecr );
			RB_DrawShadowElementsWithCounters( tri, numIndexes );
		}
	} else if( glConfig.atiTwoSidedStencilAvailable && r_useTwoSidedStencil.GetBool() ) {
		GL_Cull( CT_TWO_SIDED );
		if( !external )	{
			glStencilOpSeparateATI( backEnd.viewDef->isMirror ? GL_FRONT : GL_BACK, GL_KEEP, tr.stencilDecr, tr.stencilDecr );
			glStencilOpSeparateATI( backEnd.viewDef->isMirror ? GL_BACK : GL_FRONT, GL_KEEP, tr.stencilIncr, tr.stencilIncr );
			RB_DrawShadowElementsWithCounters( tri, numIndexes );
		}
		glStencilOpSeparateATI( backEnd.viewDef->isMirror ? GL_FRONT : GL_BACK, GL_KEEP, GL_KEEP, tr.stencilIncr );
		glStencilOpSeparateATI( backEnd.viewDef->isMirror ? GL_BACK : GL_FRONT, GL_KEEP, GL_KEEP, tr.stencilDecr );
		RB_DrawShadowElementsWithCounters( tri, numIndexes );
	} else if( glConfig.twoSidedStencilAvailable && r_useTwoSidedStencil.GetBool() ) {
		GL_Cull( CT_TWO_SIDED );
		glEnable( GL_STENCIL_TEST_TWO_SIDE_EXT );
		if( !external ) {
			glActiveStencilFaceEXT( backEnd.viewDef->isMirror ? GL_FRONT : GL_BACK );
			glStencilOp( GL_KEEP, tr.stencilDecr, tr.stencilDecr );
			glActiveStencilFaceEXT( backEnd.viewDef->isMirror ? GL_BACK : GL_FRONT );
			glStencilOp( GL_KEEP, tr.stencilIncr, tr.stencilIncr );
			RB_DrawShadowElementsWithCounters( tri, numIndexes );
		}
		glActiveStencilFaceEXT( backEnd.viewDef->isMirror ? GL_FRONT : GL_BACK );
		glStencilOp( GL_KEEP, GL_KEEP, tr.stencilIncr );
		glActiveStencilFaceEXT( backEnd.viewDef->isMirror ? GL_BACK : GL_FRONT );
		glStencilOp( GL_KEEP, GL_KEEP, tr.stencilDecr );
		RB_DrawShadowElementsWithCounters( tri, numIndexes );
		glDisable( GL_STENCIL_TEST_TWO_SIDE_EXT );
	} else {
		if( !external ) {
			// "preload" the stencil buffer with the number of volumes
			// that get clipped by the near or far clip plane
			glStencilOp( GL_KEEP, tr.stencilDecr, tr.stencilDecr );
			GL_Cull( CT_FRONT_SIDED );
			RB_DrawShadowElementsWithCounters( tri, numIndexes );
			glStencilOp( GL_KEEP, tr.stencilIncr, tr.stencilIncr );
			GL_Cull( CT_BACK_SIDED );
			RB_DrawShadowElementsWithCounters( tri, numIndexes );
		}
		// traditional depth-pass stencil shadows
		glStencilOp( GL_KEEP, GL_KEEP, tr.stencilIncr );
		GL_Cull( CT_FRONT_SIDED );
		RB_DrawShadowElementsWithCounters( tri, numIndexes );
		glStencilOp( GL_KEEP, GL_KEEP, tr.stencilDecr );
		GL_Cull( CT_BACK_SIDED );
		RB_DrawShadowElementsWithCounters( tri, numIndexes );
	}
	// restore cull the same as the original GPL code
	// revelator dont it breaks rendering.
	GL_Cull( CT_FRONT_SIDED );
	// Moved depthbounds test here
	if( r_useDepthBoundsTest.GetBool() ) {
		GL_DepthBoundsTest( 0.0f, 0.0f );
	}
}

/*
=====================
RB_StencilShadowPass

Stencil test should already be enabled, and the stencil buffer should have
been set to 128 on any surfaces that might receive shadows
=====================
*/
void RB_StencilShadowPass( const drawSurf_t *drawSurfs ) {
	if( !r_shadows.GetBool() ) {
		return;
	}
	if( !drawSurfs ) {
		return;
	}
	globalImages->BindNull();
	glDisableClientState( GL_TEXTURE_COORD_ARRAY );
	// for visualizing the shadows
	if( r_showShadows.GetInteger() ) {
		if( r_showShadows.GetInteger() == 2 ) {
			// draw filled in
			GL_State( GLS_DEPTHMASK | GLS_SRCBLEND_ONE | GLS_DSTBLEND_ONE | GLS_DEPTHFUNC_LESS );
		} else {
			// draw as lines, filling the depth buffer
			GL_State( GLS_SRCBLEND_ONE | GLS_DSTBLEND_ZERO | GLS_POLYMODE_LINE | GLS_DEPTHFUNC_ALWAYS );
		}
	} else {
		// don't write to the color buffer, just the stencil buffer
		GL_State( GLS_DEPTHMASK | GLS_COLORMASK | GLS_ALPHAMASK | GLS_DEPTHFUNC_LESS );
	}
	if( r_shadowPolygonFactor.GetFloat() || r_shadowPolygonOffset.GetFloat() ) {
		glPolygonOffset( r_shadowPolygonFactor.GetFloat(), -r_shadowPolygonOffset.GetFloat() );
		glEnable( GL_POLYGON_OFFSET_FILL );
	}
	glStencilFunc( GL_ALWAYS, 1, 255 );
	RB_RenderDrawSurfChainWithFunction( drawSurfs, RB_T_Shadow );
	if( r_shadowPolygonFactor.GetFloat() || r_shadowPolygonOffset.GetFloat() ) {
		glDisable( GL_POLYGON_OFFSET_FILL );
	}
	glEnableClientState( GL_TEXTURE_COORD_ARRAY );
	glStencilFunc( GL_GEQUAL, 128, 255 );
	glStencilOp( GL_KEEP, GL_KEEP, GL_KEEP );
}

/*
=============================================================================================

BLEND LIGHT PROJECTION

=============================================================================================
*/

/*
=====================
RB_T_BlendLight
=====================
*/
static void RB_T_BlendLight( const drawSurf_t *surf ) {
	const srfTriangles_t *tri;
	tri = surf->geo;
	if( backEnd.currentSpace != surf->space ) {
		idPlane	lightProject[4];
		int		i;
		for( i = 0 ; i < 4 ; i++ ) {
			R_GlobalPlaneToLocal( surf->space->modelMatrix, backEnd.vLight->lightProject[i], lightProject[i] );
		}
		GL_SelectTexture( 0 );
		glTexGenfv( GL_S, GL_OBJECT_PLANE, lightProject[0].ToFloatPtr() );
		glTexGenfv( GL_T, GL_OBJECT_PLANE, lightProject[1].ToFloatPtr() );
		glTexGenfv( GL_Q, GL_OBJECT_PLANE, lightProject[2].ToFloatPtr() );
		GL_SelectTexture( 1 );
		glTexGenfv( GL_S, GL_OBJECT_PLANE, lightProject[3].ToFloatPtr() );
	}
	// this gets used for both blend lights and shadow draws
	if( tri->ambientCache ) {
		idDrawVert	*ac = ( idDrawVert * )vertexCache.Position( tri->ambientCache );
		glVertexPointer( 3, GL_FLOAT, sizeof( idDrawVert ), ac->xyz.ToFloatPtr() );
	} else if( tri->shadowCache ) {
		shadowCache_t	*sc = ( shadowCache_t * )vertexCache.Position( tri->shadowCache );
		glVertexPointer( 3, GL_FLOAT, sizeof( shadowCache_t ), sc->xyz.ToFloatPtr() );
	}
	RB_DrawElementsWithCounters( tri );
}


/*
=====================
RB_BlendLight

Dual texture together the falloff and projection texture with a blend
mode to the framebuffer, instead of interacting with the surface texture
=====================
*/
static void RB_BlendLight( const drawSurf_t *drawSurfs,  const drawSurf_t *drawSurfs2 ) {
	const idMaterial	*lightShader;
	const shaderStage_t	*stage;
	const float			*regs;
	int					i;
	if( !drawSurfs ) {
		return;
	}
	if( r_skipBlendLights.GetBool() ) {
		return;
	}
	lightShader = backEnd.vLight->lightShader;
	regs = backEnd.vLight->shaderRegisters;
	// texture 1 will get the falloff texture
	GL_SelectTexture( 1 );
	glDisableClientState( GL_TEXTURE_COORD_ARRAY );
	glEnable( GL_TEXTURE_GEN_S );
	glTexCoord2f( 0, 0.5 );
	backEnd.vLight->falloffImage->Bind();
	// texture 0 will get the projected texture
	GL_SelectTexture( 0 );
	glDisableClientState( GL_TEXTURE_COORD_ARRAY );
	glEnable( GL_TEXTURE_GEN_S );
	glEnable( GL_TEXTURE_GEN_T );
	glEnable( GL_TEXTURE_GEN_Q );
	for( i = 0 ; i < lightShader->GetNumStages() ; i++ ) {
		stage = lightShader->GetStage( i );
		if( !regs[ stage->conditionRegister ] ) {
			continue;
		}
		GL_State( GLS_DEPTHMASK | stage->drawStateBits | GLS_DEPTHFUNC_EQUAL );
		GL_SelectTexture( 0 );
		stage->texture.image->Bind();
		if( stage->texture.hasMatrix ) {
			RB_LoadShaderTextureMatrix( regs, &stage->texture );
		}
		// get the modulate values from the light, including alpha, unlike normal lights
		backEnd.lightColor[0] = regs[ stage->color.registers[0] ];
		backEnd.lightColor[1] = regs[ stage->color.registers[1] ];
		backEnd.lightColor[2] = regs[ stage->color.registers[2] ];
		backEnd.lightColor[3] = regs[ stage->color.registers[3] ];
		glColor4fv( backEnd.lightColor );
		RB_RenderDrawSurfChainWithFunction( drawSurfs, RB_T_BlendLight );
		RB_RenderDrawSurfChainWithFunction( drawSurfs2, RB_T_BlendLight );
		if( stage->texture.hasMatrix ) {
			GL_SelectTexture( 0 );
			glMatrixMode( GL_TEXTURE );
			glLoadIdentity();
			glMatrixMode( GL_MODELVIEW );
		}
	}
	GL_SelectTexture( 1 );
	glDisable( GL_TEXTURE_GEN_S );
	globalImages->BindNull();
	GL_SelectTexture( 0 );
	glDisable( GL_TEXTURE_GEN_S );
	glDisable( GL_TEXTURE_GEN_T );
	glDisable( GL_TEXTURE_GEN_Q );
}


//========================================================================

static idPlane	fogPlanes[4];

/*
=====================
RB_T_BasicFog

=====================
*/
static void RB_T_BasicFog( const drawSurf_t *surf ) {
	if( backEnd.currentSpace != surf->space ) {
		idPlane	local;
		GL_SelectTexture( 0 );
		R_GlobalPlaneToLocal( surf->space->modelMatrix, fogPlanes[0], local );
		local[3] += 0.5;
		glTexGenfv( GL_S, GL_OBJECT_PLANE, local.ToFloatPtr() );
		local[0] =
		local[1] =
		local[2] = 0;
		local[3] = 0.5;
		glTexGenfv( GL_T, GL_OBJECT_PLANE, local.ToFloatPtr() );
		GL_SelectTexture( 1 );
		// GL_S is constant per viewer
		R_GlobalPlaneToLocal( surf->space->modelMatrix, fogPlanes[2], local );
		local[3] += FOG_ENTER;
		glTexGenfv( GL_T, GL_OBJECT_PLANE, local.ToFloatPtr() );
		R_GlobalPlaneToLocal( surf->space->modelMatrix, fogPlanes[3], local );
		glTexGenfv( GL_S, GL_OBJECT_PLANE, local.ToFloatPtr() );
	}
	RB_T_RenderTriangleSurface( surf );
}

/*
==================
RB_FogPass
==================
*/
static void RB_FogPass( const drawSurf_t *drawSurfs,  const drawSurf_t *drawSurfs2 ) {
	const srfTriangles_t	*frustumTris;
	drawSurf_t				ds;
	const idMaterial		*lightShader;
	const shaderStage_t		*stage;
	const float				*regs;
	// create a surface for the light frustom triangles, which are oriented drawn side out
	frustumTris = backEnd.vLight->frustumTris;
	// if we ran out of vertex cache memory, skip it
	if( !frustumTris->ambientCache ) {
		return;
	}
	memset( &ds, 0, sizeof( ds ) );
	ds.space = &backEnd.viewDef->worldSpace;
	ds.geo = frustumTris;
	ds.scissorRect = backEnd.viewDef->scissor;
	// find the current color and density of the fog
	lightShader = backEnd.vLight->lightShader;
	regs = backEnd.vLight->shaderRegisters;
	// assume fog shaders have only a single stage
	stage = lightShader->GetStage( 0 );
	backEnd.lightColor[0] = regs[ stage->color.registers[0] ];
	backEnd.lightColor[1] = regs[ stage->color.registers[1] ];
	backEnd.lightColor[2] = regs[ stage->color.registers[2] ];
	backEnd.lightColor[3] = regs[ stage->color.registers[3] ];
	glColor3fv( backEnd.lightColor );
	// calculate the falloff planes
	float	a;
	// if they left the default value on, set a fog distance of 500
	if( backEnd.lightColor[3] <= 1.0 ) {
		a = -0.5f / DEFAULT_FOG_DISTANCE;
	} else {
		// otherwise, distance = alpha color
		a = -0.5f / backEnd.lightColor[3];
	}
	GL_State( GLS_DEPTHMASK | GLS_SRCBLEND_SRC_ALPHA | GLS_DSTBLEND_ONE_MINUS_SRC_ALPHA | GLS_DEPTHFUNC_EQUAL );
	// texture 0 is the falloff image
	GL_SelectTexture( 0 );
	globalImages->fogImage->Bind();
	glDisableClientState( GL_TEXTURE_COORD_ARRAY );
	glEnable( GL_TEXTURE_GEN_S );
	glEnable( GL_TEXTURE_GEN_T );
	glTexCoord2f( 0.5f, 0.5f );		// make sure Q is set
	fogPlanes[0][0] = a * backEnd.viewDef->worldSpace.modelViewMatrix[2];
	fogPlanes[0][1] = a * backEnd.viewDef->worldSpace.modelViewMatrix[6];
	fogPlanes[0][2] = a * backEnd.viewDef->worldSpace.modelViewMatrix[10];
	fogPlanes[0][3] = a * backEnd.viewDef->worldSpace.modelViewMatrix[14];
	fogPlanes[1][0] = a * backEnd.viewDef->worldSpace.modelViewMatrix[0];
	fogPlanes[1][1] = a * backEnd.viewDef->worldSpace.modelViewMatrix[4];
	fogPlanes[1][2] = a * backEnd.viewDef->worldSpace.modelViewMatrix[8];
	fogPlanes[1][3] = a * backEnd.viewDef->worldSpace.modelViewMatrix[12];
	// texture 1 is the entering plane fade correction
	GL_SelectTexture( 1 );
	globalImages->fogEnterImage->Bind();
	glDisableClientState( GL_TEXTURE_COORD_ARRAY );
	glEnable( GL_TEXTURE_GEN_S );
	glEnable( GL_TEXTURE_GEN_T );
	// T will get a texgen for the fade plane, which is always the "top" plane on unrotated lights
	fogPlanes[2][0] = 0.001f * backEnd.vLight->fogPlane[0];
	fogPlanes[2][1] = 0.001f * backEnd.vLight->fogPlane[1];
	fogPlanes[2][2] = 0.001f * backEnd.vLight->fogPlane[2];
	fogPlanes[2][3] = 0.001f * backEnd.vLight->fogPlane[3];
	// S is based on the view origin
	float s = backEnd.viewDef->renderView.vieworg * fogPlanes[2].Normal() + fogPlanes[2][3];
	fogPlanes[3][0] = 0;
	fogPlanes[3][1] = 0;
	fogPlanes[3][2] = 0;
	fogPlanes[3][3] = FOG_ENTER + s;
	glTexCoord2f( FOG_ENTER + s, FOG_ENTER );
	// draw it
	RB_RenderDrawSurfChainWithFunction( drawSurfs, RB_T_BasicFog );
	RB_RenderDrawSurfChainWithFunction( drawSurfs2, RB_T_BasicFog );
	// the light frustum bounding planes aren't in the depth buffer, so use depthfunc_less instead
	// of depthfunc_equal
	GL_State( GLS_DEPTHMASK | GLS_SRCBLEND_SRC_ALPHA | GLS_DSTBLEND_ONE_MINUS_SRC_ALPHA | GLS_DEPTHFUNC_LESS );
	GL_Cull( CT_BACK_SIDED );
	RB_RenderDrawSurfChainWithFunction( &ds, RB_T_BasicFog );
	GL_Cull( CT_FRONT_SIDED );
	GL_SelectTexture( 1 );
	glDisable( GL_TEXTURE_GEN_S );
	glDisable( GL_TEXTURE_GEN_T );
	globalImages->BindNull();
	GL_SelectTexture( 0 );
	glDisable( GL_TEXTURE_GEN_S );
	glDisable( GL_TEXTURE_GEN_T );
}


/*
==================
RB_STD_FogAllLights
==================
*/
static void RB_STD_FogAllLights( void ) {
	viewLight_t	*vLight;
	/* dont fog in xray mode*/
	if( r_skipFogLights.GetBool() || r_showOverDraw.GetInteger() != 0 || backEnd.viewDef->isXraySubview ) {
		return;
	}
	glDisable( GL_STENCIL_TEST );
	for( vLight = backEnd.viewDef->viewLights ; vLight ; vLight = vLight->next ) {
		backEnd.vLight = vLight;
		if( !vLight->lightShader->IsFogLight() && !vLight->lightShader->IsBlendLight() ) {
			continue;
		}
		if( vLight->lightShader->IsFogLight() ) {
			RB_FogPass( vLight->globalInteractions, vLight->localInteractions );
		} else if( vLight->lightShader->IsBlendLight() ) {
			RB_BlendLight( vLight->globalInteractions, vLight->localInteractions );
		}
		glDisable( GL_STENCIL_TEST );
	}
	glEnable( GL_STENCIL_TEST );
}

//=========================================================================================

/*
==================
RB_STD_LightScale

Perform extra blending passes to multiply the entire buffer by
a floating point value
==================
*/
static void RB_STD_LightScale( void ) {
	float	v, f;
	if( backEnd.overBright == 1.0f ) {
		return;
	}
	if( r_skipLightScale.GetBool() ) {
		return;
	}
	// the scissor may be smaller than the viewport for subviews
	if( r_useScissor.GetBool() ) {
		glScissor( backEnd.viewDef->viewport.x1 + backEnd.viewDef->scissor.x1,
				   backEnd.viewDef->viewport.y1 + backEnd.viewDef->scissor.y1,
				   backEnd.viewDef->scissor.x2 - backEnd.viewDef->scissor.x1 + 1,
				   backEnd.viewDef->scissor.y2 - backEnd.viewDef->scissor.y1 + 1 );
		backEnd.currentScissor = backEnd.viewDef->scissor;
	}
	// full screen blends
	glLoadIdentity();
	glMatrixMode( GL_PROJECTION );
	glPushMatrix();
	glLoadIdentity();
	glOrtho( 0, 1, 0, 1, -1, 1 );
	GL_State( GLS_SRCBLEND_DST_COLOR | GLS_DSTBLEND_SRC_COLOR );
	GL_Cull( CT_TWO_SIDED );	// so mirror views also get it
	globalImages->BindNull();
	glDisable( GL_DEPTH_TEST );
	glDisable( GL_STENCIL_TEST );
	v = 1;
	while( idMath::Fabs( v - backEnd.overBright ) > 0.01f ) {	// a little extra slop
		f = backEnd.overBright / v;
		f /= 2;
		if( f > 1 ) {
			f = 1;
		}
		glColor3f( f, f, f );
		v = v * f * 2;
		glBegin( GL_QUADS );
		glVertex2f( 0, 0 );
		glVertex2f( 0, 1 );
		glVertex2f( 1, 1 );
		glVertex2f( 1, 0 );
		glEnd();
	}
	glPopMatrix();
	glEnable( GL_DEPTH_TEST );
	glMatrixMode( GL_MODELVIEW );
	GL_Cull( CT_FRONT_SIDED );
}

//=========================================================================================

/*
=============
RB_STD_DrawView

=============
*/
void RB_STD_DrawView( void ) {
	drawSurf_t	 **drawSurfs;
	int			numDrawSurfs;
	backEnd.depthFunc = GLS_DEPTHFUNC_EQUAL;
	drawSurfs = ( drawSurf_t ** )&backEnd.viewDef->drawSurfs[0];
	numDrawSurfs = backEnd.viewDef->numDrawSurfs;
	// clear the z buffer, set the projection matrix, etc
	RB_BeginDrawingView();
	// decide how much overbrighting we are going to do
	RB_DetermineLightScale();
	// fill the depth buffer and clear color buffer to black except on
	// subviews
	RB_STD_FillDepthBuffer( drawSurfs, numDrawSurfs );
	// main light renderer
	switch( tr.backEndRenderer ) {
	case BE_ARB:
		RB_ARB_DrawInteractions();
		break;
	case BE_ARB2:
		RB_ARB2_DrawInteractions();
		break;
	case BE_GLSL:
		RB_GLSL_DrawInteractions();
		break;
	case BE_NV20:
		RB_NV20_DrawInteractions();
		break;
	case BE_NV10:
		RB_NV10_DrawInteractions();
		break;
	case BE_R200:
		RB_R200_DrawInteractions();
		break;
	}
	// disable stencil shadow test
	glStencilFunc( GL_ALWAYS, 128, 255 );
	// uplight the entire screen to crutch up not having better blending range
	RB_STD_LightScale();
	// now draw any non-light dependent shading passes
	int	processed = RB_STD_DrawShaderPasses( drawSurfs, numDrawSurfs );
	// fob and blend lights
	RB_STD_FogAllLights();
	// now draw any post-processing effects using _currentRender
	if( processed < numDrawSurfs ) {
		RB_STD_DrawShaderPasses( drawSurfs + processed, numDrawSurfs - processed );
	}
	RB_RenderDebugTools( drawSurfs, numDrawSurfs );
}
