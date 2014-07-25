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
R_Dropsample

Used to resample images in a more general than quartering fashion.
Normal maps and such should not be bilerped.
================
*/
byte *R_Dropsample( const byte *in, int inwidth, int inheight, int outwidth, int outheight ) {
	int		i, j, k;
	const byte	*inrow;
	const byte	*pix1;
	byte		*out, *out_p;
	out = ( byte * )R_StaticAlloc( outwidth * outheight * 4 );
	out_p = out;
	for( i = 0 ; i < outheight ; i++, out_p += outwidth * 4 ) {
		inrow = in + 4 * inwidth * ( int )( ( i + 0.25 ) * inheight / outheight );
		for( j = 0 ; j < outwidth ; j++ ) {
			k = j * inwidth / outwidth;
			pix1 = inrow + k * 4;
			out_p[j * 4 + 0] = pix1[0];
			out_p[j * 4 + 1] = pix1[1];
			out_p[j * 4 + 2] = pix1[2];
			out_p[j * 4 + 3] = pix1[3];
		}
	}
	return out;
}


/*
===============
R_SetBorderTexels

===============
*/
void R_SetBorderTexels( byte *inBase, int width, int height, const byte border[4] ) {
	int		i;
	byte	*out;
	out = inBase;
	for( i = 0 ; i < height ; i++, out += width * 4 ) {
		out[0] = border[0];
		out[1] = border[1];
		out[2] = border[2];
		out[3] = border[3];
	}
	out = inBase + ( width - 1 ) * 4;
	for( i = 0 ; i < height ; i++, out += width * 4 ) {
		out[0] = border[0];
		out[1] = border[1];
		out[2] = border[2];
		out[3] = border[3];
	}
	out = inBase;
	for( i = 0 ; i < width ; i++, out += 4 ) {
		out[0] = border[0];
		out[1] = border[1];
		out[2] = border[2];
		out[3] = border[3];
	}
	out = inBase + width * 4 * ( height - 1 );
	for( i = 0 ; i < width ; i++, out += 4 ) {
		out[0] = border[0];
		out[1] = border[1];
		out[2] = border[2];
		out[3] = border[3];
	}
}

/*
===============
R_SetBorderTexels3D

===============
*/
void R_SetBorderTexels3D( byte *inBase, int width, int height, int depth, const byte border[4] ) {
	int		i, j;
	byte	*out;
	int		row, plane;
	row = width * 4;
	plane = row * depth;
	for( j = 1 ; j < depth - 1 ; j++ ) {
		out = inBase + j * plane;
		for( i = 0 ; i < height ; i++, out += row ) {
			out[0] = border[0];
			out[1] = border[1];
			out[2] = border[2];
			out[3] = border[3];
		}
		out = inBase + ( width - 1 ) * 4 + j * plane;
		for( i = 0 ; i < height ; i++, out += row ) {
			out[0] = border[0];
			out[1] = border[1];
			out[2] = border[2];
			out[3] = border[3];
		}
		out = inBase + j * plane;
		for( i = 0 ; i < width ; i++, out += 4 ) {
			out[0] = border[0];
			out[1] = border[1];
			out[2] = border[2];
			out[3] = border[3];
		}
		out = inBase + width * 4 * ( height - 1 ) + j * plane;
		for( i = 0 ; i < width ; i++, out += 4 ) {
			out[0] = border[0];
			out[1] = border[1];
			out[2] = border[2];
			out[3] = border[3];
		}
	}
	out = inBase;
	for( i = 0 ; i < plane ; i += 4, out += 4 ) {
		out[0] = border[0];
		out[1] = border[1];
		out[2] = border[2];
		out[3] = border[3];
	}
	out = inBase + ( depth - 1 ) * plane;
	for( i = 0 ; i < plane ; i += 4, out += 4 ) {
		out[0] = border[0];
		out[1] = border[1];
		out[2] = border[2];
		out[3] = border[3];
	}
}

/*
================
R_SetAlphaNormalDivergence

If any of the angles inside the cone would directly reflect to the light, there will be
a specular highlight.  The intensity of the highlight is inversely proportional to the
area of the spread.

Light source area is important for the base size.

area subtended in light is the divergence times the distance

Shininess value is subtracted from the divergence

Sets the alpha channel to the greatest divergence dot product of the surrounding texels.
1.0 = flat, 0.0 = turns a 90 degree angle
Lower values give less shiny specular
With mip maps, the lowest samnpled value will be retained

Should we rewrite the normal as the centered average?
================
*/
void R_SetAlphaNormalDivergence( byte *in, int width, int height ) {
	for( int y = 0 ; y < height ; y++ ) {
		for( int x = 0 ; x < width ; x++ ) {
			// the divergence is the smallest dot product of any of the eight surrounding texels
			byte	*pic_p = in + ( y * width + x ) * 4;
			idVec3	center;
			center[0] = ( float )( pic_p[0] - 128 ) / 127;
			center[1] = ( float )( pic_p[1] - 128 ) / 127;
			center[2] = ( float )( pic_p[2] - 128 ) / 127;
			center.Normalize();
			float	maxDiverge = 1.0;
			// FIXME: this assumes wrap mode, but should handle clamp modes and border colors
			for( int yy = -1 ; yy <= 1 ; yy++ ) {
				for( int xx = -1 ; xx <= 1 ; xx++ ) {
					if( yy == 0 && xx == 0 ) {
						continue;
					}
					byte	*corner_p = in + ( ( ( y + yy ) & ( height - 1 ) ) * width + ( ( x + xx )&width - 1 ) ) * 4;
					idVec3	corner;
					corner[0] = ( float )( corner_p[0] - 128 ) / 127;
					corner[1] = ( float )( corner_p[1] - 128 ) / 127;
					corner[2] = ( float )( corner_p[2] - 128 ) / 127;
					corner.Normalize();
					float	diverge = corner * center;
					if( diverge < maxDiverge ) {
						maxDiverge = diverge;
					}
				}
			}
			// we can get a diverge < 0 in some extreme cases
			if( maxDiverge < 0 ) {
				maxDiverge = 0;
			}
			pic_p[3] = maxDiverge * 255;
		}
	}
}

/*
================
R_MipMapWithAlphaSpecularity

Returns a new copy of the texture, quartered in size and filtered.
The alpha channel is taken to be the minimum of the dots of all surrounding normals.
================
*/
#define MIP_MIN(a,b) (a<b?a:b)

byte *R_MipMapWithAlphaSpecularity( const byte *in, int width, int height ) {
	int		i, j, c, x, y, sx, sy;
	const byte	*in_p;
	byte	*out, *out_p;
	int		row;
	int		newWidth, newHeight;
	float	*fbuf, *fbuf_p;
	if( width < 1 || height < 1 || ( width + height == 2 ) ) {
		common->FatalError( "R_MipMapWithAlphaMin called with size %i,%i", width, height );
	}
	// convert the incoming texture to centered floating point
	c = width * height;
	fbuf = ( float * )_alloca( c * 4 * sizeof( *fbuf ) );
	in_p = in;
	fbuf_p = fbuf;
	for( i = 0 ; i < c ; i++, in_p += 4, fbuf_p += 4 ) {
		fbuf_p[0] = ( in_p[0] / 255.0 ) * 2.0 - 1.0;	// convert to a normal
		fbuf_p[1] = ( in_p[1] / 255.0 ) * 2.0 - 1.0;
		fbuf_p[2] = ( in_p[2] / 255.0 ) * 2.0 - 1.0;
		fbuf_p[3] = ( in_p[3] / 255.0 );				// filtered divegence / specularity
	}
	row = width * 4;
	newWidth = width >> 1;
	newHeight = height >> 1;
	if( !newWidth ) {
		newWidth = 1;
	}
	if( !newHeight ) {
		newHeight = 1;
	}
	out = ( byte * )R_StaticAlloc( newWidth * newHeight * 4 );
	out_p = out;
	in_p = in;
	for( i = 0 ; i < newHeight ; i++ ) {
		for( j = 0 ; j < newWidth ; j++, out_p += 4 ) {
			idVec3	total;
			float	totalSpec;
			total.Zero();
			totalSpec = 0;
			// find the average normal
			for( x = -1 ; x <= 1 ; x++ ) {
				sx = ( j * 2 + x ) & ( width - 1 );
				for( y = -1 ; y <= 1 ; y++ ) {
					sy = ( i * 2 + y ) & ( height - 1 );
					fbuf_p = fbuf + ( sy * width + sx ) * 4;
					total[0] += fbuf_p[0];
					total[1] += fbuf_p[1];
					total[2] += fbuf_p[2];
					totalSpec += fbuf_p[3];
				}
			}
			total.Normalize();
			totalSpec /= 9.0;
		}
	}
	return out;
}

/*
================
R_MipMap

Returns a new copy of the texture, quartered in size and filtered.

If a texture is intended to be used in GL_CLAMP or GL_CLAMP_TO_EDGE mode with
a completely transparent border, we must prevent any blurring into the outer
ring of texels by filling it with the border from the previous level.  This
will result in a slight shrinking of the texture as it mips, but better than
smeared clamps...
================
*/
byte *R_MipMap( const byte *in, int width, int height, bool preserveBorder ) {
	int			i, j;
	const byte	*in_p;
	byte		*out, *out_p;
	int			row;
	byte		border[4];
	int			newWidth, newHeight;
	if( width < 1 || height < 1 || ( width + height == 2 ) ) {
		common->FatalError( "R_MipMap called with size %i,%i", width, height );
	}
	border[0] = in[0];
	border[1] = in[1];
	border[2] = in[2];
	border[3] = in[3];
	row = width * 4;
	newWidth = width >> 1;
	newHeight = height >> 1;
	if( !newWidth ) {
		newWidth = 1;
	}
	if( !newHeight ) {
		newHeight = 1;
	}
	out = ( byte * )R_StaticAlloc( newWidth * newHeight * 4 );
	out_p = out;
	in_p = in;
	width >>= 1;
	height >>= 1;
	if( width == 0 || height == 0 ) {
		width += height;	// get largest
		if( preserveBorder ) {
			for( i = 0 ; i < width ; i++, out_p += 4 ) {
				out_p[0] = border[0];
				out_p[1] = border[1];
				out_p[2] = border[2];
				out_p[3] = border[3];
			}
		} else {
			for( i = 0 ; i < width ; i++, out_p += 4, in_p += 8 ) {
				out_p[0] = ( in_p[0] + in_p[4] ) >> 1;
				out_p[1] = ( in_p[1] + in_p[5] ) >> 1;
				out_p[2] = ( in_p[2] + in_p[6] ) >> 1;
				out_p[3] = ( in_p[3] + in_p[7] ) >> 1;
			}
		}
		return out;
	}
	for( i = 0 ; i < height ; i++, in_p += row ) {
		for( j = 0 ; j < width ; j++, out_p += 4, in_p += 8 ) {
			out_p[0] = ( in_p[0] + in_p[4] + in_p[row + 0] + in_p[row + 4] ) >> 2;
			out_p[1] = ( in_p[1] + in_p[5] + in_p[row + 1] + in_p[row + 5] ) >> 2;
			out_p[2] = ( in_p[2] + in_p[6] + in_p[row + 2] + in_p[row + 6] ) >> 2;
			out_p[3] = ( in_p[3] + in_p[7] + in_p[row + 3] + in_p[row + 7] ) >> 2;
		}
	}
	// copy the old border texel back around if desired
	if( preserveBorder ) {
		R_SetBorderTexels( out, width, height, border );
	}
	return out;
}

/*
================
R_MipMap3D

Returns a new copy of the texture, eigthed in size and filtered.

If a texture is intended to be used in GL_CLAMP or GL_CLAMP_TO_EDGE mode with
a completely transparent border, we must prevent any blurring into the outer
ring of texels by filling it with the border from the previous level.  This
will result in a slight shrinking of the texture as it mips, but better than
smeared clamps...
================
*/
byte *R_MipMap3D( const byte *in, int width, int height, int depth, bool preserveBorder ) {
	int			i, j, k;
	const byte	*in_p;
	byte		*out, *out_p;
	int			row, plane;
	byte		border[4];
	int			newWidth, newHeight, newDepth;
	if( depth == 1 ) {
		return R_MipMap( in, width, height, preserveBorder );
	}
	// assume symetric for now
	if( width < 2 || height < 2 || depth < 2 ) {
		common->FatalError( "R_MipMap3D called with size %i,%i,%i", width, height, depth );
	}
	border[0] = in[0];
	border[1] = in[1];
	border[2] = in[2];
	border[3] = in[3];
	row = width * 4;
	plane = row * height;
	newWidth = width >> 1;
	newHeight = height >> 1;
	newDepth = depth >> 1;
	out = ( byte * )R_StaticAlloc( newWidth * newHeight * newDepth * 4 );
	out_p = out;
	in_p = in;
	width >>= 1;
	height >>= 1;
	depth >>= 1;
	for( k = 0 ; k < depth ; k++, in_p += plane ) {
		for( i = 0 ; i < height ; i++, in_p += row ) {
			for( j = 0 ; j < width ; j++, out_p += 4, in_p += 8 ) {
				out_p[0] = ( in_p[0] + in_p[4] + in_p[row + 0] + in_p[row + 4] +
							 in_p[plane + 0] + in_p[plane + 4] + in_p[plane + row + 0] + in_p[plane + row + 4]
						   ) >> 3;
				out_p[1] = ( in_p[1] + in_p[5] + in_p[row + 1] + in_p[row + 5] +
							 in_p[plane + 1] + in_p[plane + 5] + in_p[plane + row + 1] + in_p[plane + row + 5]
						   ) >> 3;
				out_p[2] = ( in_p[2] + in_p[6] + in_p[row + 2] + in_p[row + 6] +
							 in_p[plane + 2] + in_p[plane + 6] + in_p[plane + row + 2] + in_p[plane + row + 6]
						   ) >> 3;
				out_p[3] = ( in_p[3] + in_p[7] + in_p[row + 3] + in_p[row + 7] +
							 in_p[plane + 3] + in_p[plane + 6] + in_p[plane + row + 3] + in_p[plane + row + 6]
						   ) >> 3;
			}
		}
	}
	// copy the old border texel back around if desired
	if( preserveBorder ) {
		R_SetBorderTexels3D( out, width, height, depth, border );
	}
	return out;
}

// =======================================================================================================================================================

/*
================
BorderCheck macro. the pixels that get passed in should be pre-converted
to the YCbCr colorspace.
================
*/
#define BorderCheck(pix1, pix2, dY, dCb, dCr) ( (abs(*pix1 - *pix2) > dY) || (abs(*(pix1+1) - *(pix2+1)) > dCb) || (abs(*(pix1+2) - *(pix2+2)) > dCr) )

/*
================
LinearScale macro.
================
*/
#define LinearScale(src1, src2, pct) (( src1 * (1 - pct) ) + ( src2 * pct))

/*
================
GetOffSet macro.
================
*/
#define GetOffSet(new, start, cur) (new + (cur - ((unsigned char*)start)))

/*
================
Clamp macro.
================
*/
#define Clamp(a, b, c) (max(a, min(b, c)))

/*
================
RGBAtoTCbCrA - converts a source RGBA pixel into a destination YCbCrA pixel
================
*/
ID_FORCE_INLINE void RGBAtoYCbCrA( unsigned char *dest, unsigned char *src ) {
	unsigned char s0, s1, s2;
	s0 = *( src );
	s1 = *( src + 1 );
	s2 = *( src + 2 );
#define MIX(i,n,m0,m1,m2) (*(dest+i) = (unsigned char) (n + (((s0 * m0) + (s1 * m0) + (s2 * m2))/256.0f)))
	MIX( 0, 16.0f, 65.738f, 129.057f, 25.064f );
	MIX( 1, 128.0f, -37.945f, -74.494f, 112.439f );
	MIX( 2, 128.0f, 112.439f, -94.154f, -18.285f );
#undef MIX
	*( dest + 3 ) = *( src + 3 );
}

/*
================
R_ResampleTexture - resamples the texture given in indata, of the
dimensions inwidth by inheight to outdata, of the dimensions outwidth by
outheight, using a method based on the brief description of SmartFlt
given at http://www.hiend3d.com/smartflt.html
this could probably do with some optimizations.
================
*/
void R_ResampleTexture( void *indata, int inwidth, int inheight, void *outdata, int outwidth, int outheight ) {
	float			xstep = ( static_cast< float >( inwidth ) ) / ( static_cast< float >( outwidth ) );
	float			ystep = ( static_cast< float >( inheight ) ) / ( static_cast< float >( outheight ) );
	int				dY = r_smartflt_y.GetInteger();
	int				dCb = r_smartflt_cb.GetInteger();
	int				dCr = r_smartflt_cr.GetInteger();
	int				DestX, DestY;
	float			SrcX, SrcY;
	// buffer to stor the YCbCrA version of the input texture.
	unsigned char	*Ybuffer = static_cast< byte * >( R_StaticAlloc( inwidth * inheight * 4 ) );
	unsigned char	*id = static_cast< byte * >( indata );
	unsigned char	*od = static_cast< byte * >( outdata );
	unsigned char	*idrowstart = id;
	// convert the input texture to YCbCr into a temp buffer, for border detections.
	for( DestX = 0, idrowstart = Ybuffer; DestX < ( inwidth * inheight ); DestX++, idrowstart += 4, id += 4 ) {
		RGBAtoYCbCrA( idrowstart, id );
	}
	for( DestY = 0, SrcY = 0; DestY < outheight; DestY++, SrcY += ystep ) {
		// four "work" pointers to make code a little nicer.
		unsigned char	*w0, *w1, *w2, *w3;
		// right == clockwise, left == counter-clockwise
		unsigned char	*nearest, *left, *right, *opposite;
		float			pctnear, pctleft, pctright, pctopp;
		float			w0pct, w1pct, w2pct, w3pct;
		float			x, y, tmpx, tmpy;
		char			edges[6];
		// clamp SrcY to cover for possible float error
		// to make sure the edges fall into the special cases
		if( SrcY > ( inheight - 1.01f ) ) {
			SrcY = ( inheight - 1.01f );
		}
		// go to the start of the next row. "od" should be pointing at the right place already.
		idrowstart = ( static_cast< byte * >( indata ) ) + ( static_cast< int >( SrcY ) ) * inwidth * 4;
		for( DestX = 0, SrcX = 0; DestX < outwidth; DestX++, od += 4, SrcX += xstep ) {
			// clamp SrcY to cover for possible float error
			// to make sure that the edges fall into the special cases
			if( SrcX > ( inwidth - 1.01f ) ) {
				SrcX = inwidth - 1.01f;
			}
			id = idrowstart + ( static_cast< int >( SrcX ) ) * 4;
			x = ( static_cast< int >( SrcX ) );
			y = ( static_cast< int >( SrcY ) );
			// if we happen to be directly on a source row
			if( SrcY == y )	{
				// and also directly on a source column
				if( SrcX == x )	{
					// then we are directly on a source pixel
					// just copy it and move on.
					memcpy( od, id, 4 );
					continue;
				}
				// if there is a border between the two surrounding source pixels
				if( BorderCheck( GetOffSet( Ybuffer, indata, id ), GetOffSet( Ybuffer, indata, ( id + 4 ) ), dY, dCb, dCr ) ) {
					// if we are closer to the left
					if( x == ( static_cast< int >( SrcX + 0.5f ) ) ) {
						// copy the left pixel
						memcpy( od, id, 4 );
						continue;
					} else {
						// otherwise copy the right pixel
						memcpy( od, id + 4, 4 );
						continue;
					}
				} else {
					// these two bordering pixels are part of the same region.
					// blend them using a weighted average
					x = SrcX - x;
					w0 = id;
					w1 = id + 4;
					*od = static_cast< unsigned char >( LinearScale( *w0, *w1, x ) );
					*( od + 1 ) = static_cast< unsigned char >( LinearScale( *( w0 + 1 ), *( w1 + 1 ), x ) );
					*( od + 2 ) = static_cast< unsigned char >( LinearScale( *( w0 + 2 ), *( w1 + 2 ), x ) );
					*( od + 3 ) = static_cast< unsigned char >( LinearScale( *( w0 + 3 ), *( w1 + 3 ), x ) );
					continue;
				}
			}
			// if we aren't direcly on a source row, but we are on a source column
			if( SrcX == x ) {
				// if there is a border between this source pixel and the one on
				// the next row
				if( BorderCheck( GetOffSet( Ybuffer, indata, id ), GetOffSet( Ybuffer, indata, ( id + inwidth * 4 ) ), dY, dCb, dCr ) )	{
					// if we are closer to the top
					if( y == ( static_cast< int >( SrcY + 0.5f ) ) ) {
						// copy the top
						memcpy( od, id, 4 );
						continue;
					} else {
						// copy the bottom
						memcpy( od, ( id + inwidth * 4 ), 4 );
						continue;
					}
				} else {
					// the two pixels are part of the same region, blend them
					// together with a weighted average
					y = SrcY - y;
					w0 = id;
					w1 = id + ( inwidth * 4 );
					*od = static_cast< unsigned char >( LinearScale( *w0, *w1, y ) );
					*( od + 1 ) = static_cast< unsigned char >( LinearScale( *( w0 + 1 ), *( w1 + 1 ), y ) );
					*( od + 2 ) = static_cast< unsigned char >( LinearScale( *( w0 + 2 ), *( w1 + 2 ), y ) );
					*( od + 3 ) = static_cast< unsigned char >( LinearScale( *( w0 + 3 ), *( w1 + 3 ), y ) );
					continue;
				}
			}
			// now for the non-simple case: somewhere between four pixels.
			// w0 is top-left, w1 is top-right, w2 is bottom-left, and w3 is bottom-right
			w0 = id;
			w1 = id + 4;
			w2 = id + ( inwidth * 4 );
			w3 = w2 + 4;
			x = SrcX - x;
			y = SrcY - y;
			w0pct = 1.0f - sqrtf( x * x + y * y );
			w1pct = 1.0f - sqrtf( ( 1 - x ) * ( 1 - x ) + y * y );
			w2pct = 1.0f - sqrtf( x * x + ( 1 - y ) * ( 1 - y ) );
			w3pct = 1.0f - sqrtf( ( 1 - x ) * ( 1 - x ) + ( 1 - y ) * ( 1 - y ) );
			// set up our symbolic identification.
			// "nearest" is the pixel whose quadrant we are in.
			// "left" is counter-clockwise from "nearest"
			// "right" is clockwise from "nearest"
			// "opposite" is, well, opposite.
			if( x < 0.5f ) {
				tmpx = x;
				if( y < 0.5f ) {
					nearest = w0;
					left = w2;
					right = w1;
					opposite = w3;
					pctnear = w0pct;
					pctleft = w2pct;
					pctright = w1pct;
					pctopp = w3pct;
					tmpy = y;
				} else {
					nearest = w2;
					left = w3;
					right = w0;
					opposite = w1;
					pctnear = w2pct;
					pctleft = w3pct;
					pctright = w0pct;
					pctopp = w1pct;
					tmpy = 1.0f - y;
				}
			} else {
				tmpx = 1.0f - x;
				if( y < 0.5f ) {
					nearest = w1;
					left = w0;
					right = w3;
					opposite = w2;
					pctnear = w1pct;
					pctleft = w0pct;
					pctright = w3pct;
					pctopp = w2pct;
					tmpy = y;
				} else {
					nearest = w3;
					left = w1;
					right = w2;
					opposite = w0;
					pctnear = w3pct;
					pctleft = w1pct;
					pctright = w2pct;
					pctopp = w0pct;
					tmpy = 1.0f - y;
				}
			}
			x = tmpx;
			y = tmpy;
			w0 = GetOffSet( Ybuffer, indata, nearest );
			w1 = GetOffSet( Ybuffer, indata, right );
			w2 = GetOffSet( Ybuffer, indata, left );
			w3 = GetOffSet( Ybuffer, indata, opposite );
			edges[0] = BorderCheck( w0, w2, dY, dCb, dCr );
			edges[1] = BorderCheck( w0, w1, dY, dCb, dCr );
			edges[2] = BorderCheck( w0, w3, dY, dCb, dCr );
			edges[3] = BorderCheck( w3, w2, dY, dCb, dCr );
			edges[4] = BorderCheck( w3, w1, dY, dCb, dCr );
			edges[5] = BorderCheck( w2, w1, dY, dCb, dCr );
#undef GetOffSet
			// do the edge detections.
			if( edges[0] && edges[1] && edges[2] && !edges[5] )	{
				// borders all around, and no border between the left and right.
				// if there is no border between the opposite side and only one
				// of the two other corners, or if we are closer to the corner
				if( ( edges[3] && !edges[4] ) || ( !edges[3] && edges[4] ) || ( x + y < 0.5f ) ) {
					// closer to to the corner.
					memcpy( od, nearest, 4 );
				} else {
					// closer to the center. (note, there is a diagonal line between the nearest pixel
					// and the center of the four.)
					// exclude the "nearest" pixel
					// pctnear = 0.0f;
					// if there is a border around the opposite corner,
					// exclude it from the current pixel.
					if( edges[3] && edges[4] ) {
						// pctopp = 0.0f;
						*od = static_cast< unsigned char >( Clamp( 0, ( ( ( *left * pctleft ) + ( *right * pctright ) ) / ( pctleft + pctright ) ), 255 ) );
						*( od + 1 ) = static_cast< unsigned char >( Clamp( 0, ( ( ( *( left + 1 ) * pctleft ) + ( *( right + 1 ) * pctright ) ) / ( pctleft + pctright ) ), 255 ) );
						*( od + 2 ) = static_cast< unsigned char >( Clamp( 0, ( ( ( *( left + 2 ) * pctleft ) + ( *( right + 2 ) * pctright ) ) / ( pctleft + pctright ) ), 255 ) );
						*( od + 3 ) = static_cast< unsigned char >( Clamp( 0, ( ( ( *( left + 3 ) * pctleft ) + ( *( right + 3 ) * pctright ) ) / ( pctleft + pctright ) ), 255 ) );
					} else {
						*od = static_cast< unsigned char >( Clamp( 0, ( ( ( *left * pctleft ) + ( *right * pctright ) + ( *opposite * pctopp ) ) / ( pctleft + pctright + pctopp ) ), 255 ) );
						*( od + 1 ) = static_cast< unsigned char >( Clamp( 0, ( ( ( *( left + 1 ) * pctleft ) + ( *( right + 1 ) * pctright ) + ( *( opposite + 1 ) * pctopp ) ) / ( pctleft + pctright + pctopp ) ), 255 ) );
						*( od + 2 ) = static_cast< unsigned char >( Clamp( 0, ( ( ( *( left + 2 ) * pctleft ) + ( *( right + 2 ) * pctright ) + ( *( opposite + 2 ) * pctopp ) ) / ( pctleft + pctright + pctopp ) ), 255 ) );
						*( od + 3 ) = static_cast< unsigned char >( Clamp( 0, ( ( ( *( left + 3 ) * pctleft ) + ( *( right + 3 ) * pctright ) + ( *( opposite + 3 ) * pctopp ) ) / ( pctleft + pctright + pctopp ) ), 255 ) );
					}
				}
			} else if( edges[0] && edges[1] && edges[2] ) {
				memcpy( od, nearest, 4 );
			} else {
				float num[4], denom = pctnear;
				num[0] = ( *nearest * pctnear );
				num[1] = ( *( nearest + 1 ) * pctnear );
				num[2] = ( *( nearest + 2 ) * pctnear );
				num[3] = ( *( nearest + 3 ) * pctnear );
				if( !edges[0] )	{
					num[0] += *left * pctleft;
					num[1] += *( left + 1 ) * pctleft;
					num[2] += *( left + 2 ) * pctleft;
					num[3] += *( left + 3 ) * pctleft;
					denom += pctleft;
				}
				if( edges[1] ) {
					num[0] += *right * pctright;
					num[1] += *( right + 1 ) * pctright;
					num[2] += *( right + 2 ) * pctright;
					num[3] += *( right + 3 ) * pctright;
					denom += pctright;
				}
				if( edges[2] ) {
					num[0] += *opposite * pctopp;
					num[1] += *( opposite + 1 ) * pctopp;
					num[2] += *( opposite + 2 ) * pctopp;
					num[3] += *( opposite + 3 ) * pctopp;
					denom += pctopp;
				}
				// blend the source pixels together to get the output pixel.
				// if a source pixel doesn't affect the output, it's percent should be set to 0 in the edge check
				// code above. if only one pixel affects the output, its percentage should be set to 1 and all
				// the others set to 0. (yeah, it is ugly, but I don't see a need to optimize this code (yet)
				*od = static_cast< unsigned char >( Clamp( 0, num[0] / denom, 255 ) );
				*( od + 1 ) = static_cast< unsigned char >( Clamp( 0, num[1] / denom, 255 ) );
				*( od + 2 ) = static_cast< unsigned char >( Clamp( 0, num[2] / denom, 255 ) );
				*( od + 3 ) = static_cast< unsigned char >( Clamp( 0, num[3] / denom, 255 ) );
			}
		}
	}
	R_StaticFree( Ybuffer );
}

/*
==================
R_BlendOverTexture

Apply a color blend over a set of pixels
==================
*/
void R_BlendOverTexture( byte *data, int pixelCount, const byte blend[4] ) {
	int		i;
	int		inverseAlpha;
	int		premult[3];
	inverseAlpha = 255 - blend[3];
	premult[0] = blend[0] * blend[3];
	premult[1] = blend[1] * blend[3];
	premult[2] = blend[2] * blend[3];
	for( i = 0 ; i < pixelCount ; i++, data += 4 ) {
		data[0] = ( data[0] * inverseAlpha + premult[0] ) >> 9;
		data[1] = ( data[1] * inverseAlpha + premult[1] ) >> 9;
		data[2] = ( data[2] * inverseAlpha + premult[2] ) >> 9;
	}
}


/*
==================
R_HorizontalFlip

Flip the image in place
==================
*/
void R_HorizontalFlip( byte *data, int width, int height ) {
	int		i, j;
	int		temp;
	for( i = 0 ; i < height ; i++ ) {
		for( j = 0 ; j < width / 2 ; j++ ) {
			temp = *( ( int * )data + i * width + j );
			*( ( int * )data + i * width + j ) = *( ( int * )data + i * width + width - 1 - j );
			*( ( int * )data + i * width + width - 1 - j ) = temp;
		}
	}
}

void R_VerticalFlip( byte *data, int width, int height ) {
	int		i, j;
	int		temp;
	for( i = 0 ; i < width ; i++ ) {
		for( j = 0 ; j < height / 2 ; j++ ) {
			temp = *( ( int * )data + j * width + i );
			*( ( int * )data + j * width + i ) = *( ( int * )data + ( height - 1 - j ) * width + i );
			*( ( int * )data + ( height - 1 - j ) * width + i ) = temp;
		}
	}
}

void R_RotatePic( byte *data, int width ) {
	int		i, j;
	int		*temp;
	temp = ( int * )R_StaticAlloc( width * width * 4 );
	for( i = 0 ; i < width ; i++ ) {
		for( j = 0 ; j < width ; j++ ) {
			*( temp + i * width + j ) = *( ( int * )data + j * width + i );
		}
	}
	memcpy( data, temp, width * width * 4 );
	R_StaticFree( temp );
}

