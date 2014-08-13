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
#ifndef EXTERNALS_H_
#define EXTERNALS_H_

#include "qertypes.h"
#include "select.h"

// cam
extern void		Select_ToOBJ();
extern void		Select_ToCM();
extern void		Select_RotateTexture( float amt, bool absolute );
extern void		Select_SetKeyVal( const char *key, const char *val );

// splines
extern void		glLabeledPoint( idVec4 &color, idVec3 &point, float size, const char *label );
extern void		glBox( idVec4 &color, idVec3 &point, float size );

// editorbrush
extern face_t	*Face_Alloc( void );
extern void		Face_GetScale_BrushPrimit( face_t *face, float *s, float *t, float *rot );
extern void		Face_FitTexture_BrushPrimit( face_t *f, idVec3 mins, idVec3 maxs, float nHeight, float nWidth );
extern void		Face_SetAxialScale_BrushPrimit( face_t *face, bool y );
extern void		Face_SetExplicitScale_BrushPrimit( face_t *face, float s, float t );
extern void		Face_ScaleTexture_BrushPrimit( face_t *face, float sS, float sT );
extern void		Face_RotateTexture_BrushPrimit( face_t *face, float amount, idVec3 origin );

// dlgcam
extern void		showCameraInspector();

// xywnd
extern void		DrawPathLines();
extern bool		UpdateActiveDragPoint( const idVec3 &move );
extern void		SetActiveDrag( CDragPoint *p );
extern void		UpdateSelectablePoint( brush_t *b, idVec3 v, int type );
extern void		AddSelectablePoint( brush_t *b, idVec3 v, int type, bool priority );
extern void		ClearSelectablePoints( brush_t *b );

extern void		VectorSnapGrid( idVec3 &v );
extern void		VectorRotate3Origin( const idVec3 &vIn, const idVec3 &vRotation, const idVec3 &vOrigin, idVec3 &out );

// editorbrush
extern void		DrawBrushEntityName( brush_t *b );
extern void		Brush_Resize( brush_t *b, idVec3 vMin, idVec3 vMax );
extern void		Brush_Rotate( brush_t *b, idMat3 matrix, idVec3 origin, bool bBuild );
extern void		Brush_Rotate( brush_t *b, idVec3 rot, idVec3 origin, bool bBuild );
extern void		Brush_CopyList( brush_t *pFrom, brush_t *pTo );
extern void		Brush_Resize( brush_t *b, idVec3 vMin, idVec3 vMax );
extern void		Brush_Rotate( brush_t *b, idMat3 matrix, idVec3 origin, bool bBuild );
extern void		MemFile_fprintf( CMemFile *pMemFile, const char *pText, ... );
extern void		RotateVector( idVec3 &v, idVec3 origin, float a, float c, float s );

// pmesh
extern void		Patch_AdjustSubdivisions( float hadj, float vadj );
extern void		Patch_Weld( patchMesh_t *p, patchMesh_t *p2 );
extern void		AddPatchMovePoint( idVec3 v, bool bMulti, bool bFull );
extern void		AddSlash( CString &strPath );

// editormap
extern void		Map_VerifyCurrentMap( const char *map );

// inspector
extern void		AssignModel();

#endif
