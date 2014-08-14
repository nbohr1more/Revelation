/*
===========================================================================

Doom 3 BFG Edition GPL Source Code
Copyright (C) 1993-2012 id Software LLC, a ZeniMax Media company.
Copyright (C) 2012 Robert Beckebans

This file is part of the Doom 3 BFG Edition GPL Source Code ("Doom 3 BFG Edition Source Code").

Doom 3 BFG Edition Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Doom 3 BFG Edition Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Doom 3 BFG Edition Source Code.  If not, see <http://www.gnu.org/licenses/>.

In addition, the Doom 3 BFG Edition Source Code is also subject to certain additional terms. You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Doom 3 BFG Edition Source Code.  If not, please request a copy in writing from id Software at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/
#ifndef SYS_DEFINES_H
#define SYS_DEFINES_H

/*
===============================================================================

	Non-portable system services.

===============================================================================
*/

// Revelator: If we're not using GNU C, elide __attribute__
#ifndef __GNUC__
#define __attribute__( x )				/* NOTHING */
#endif
#define id_attribute( x )				__attribute__( x )

// Revelator: workaround for msvc's missing __attribute__( ( packed ) )
// only used in snd_local.h which will need some rewriting.
#ifdef _MSC_VER
#  define PACKED( __type__ ) \
	__pragma( pack( push, 1 ) ) struct __type__ __pragma( pack( pop ) )
#elif defined(__GNUC__)
#  define PACKED( __type__ ) \
	id_attribute( ( packed ) ) struct __type__
#endif

// DG: _CRT_ALIGN seems to be MSVC specific, so provide implementation..
#ifndef _CRT_ALIGN
#if defined(__GNUC__)	// also applies for clang
#define _CRT_ALIGN(x)					id_attribute ( ( __aligned__ ( x ) ) )
#elif defined(_MSC_VER) // also for MSVC, just to be sure
#define _CRT_ALIGN(x)					__declspec( align( x ) )
#endif
#endif

// Win32
#if defined(WIN32) || defined(_WIN32)

#define	BUILD_STRING					"win-x86"
#define BUILD_OS_ID						0
#define	CPUSTRING						"x86"
#define CPU_EASYARGS					1

#define ALIGN16( x )					_CRT_ALIGN(16) x
#define ALIGN32( x )					_CRT_ALIGN(32) x
#define ALIGN64( x )					_CRT_ALIGN(64) x
#define ALIGN128( x )					_CRT_ALIGN(128) x

#define ALIGNPTR( x, a )				( ( ( x ) + ((a)-1) ) & ~((a)-1) )

#define _alloca16( x )					((void *)ALIGNPTR( (int)_alloca( ALIGNPTR( x, 16 ) + 16 ), 16 ) )
#define _alloca32( x )					((void *)ALIGNPTR( (int)_alloca( ALIGNPTR( x, 32 ) + 32 ), 32 ) )
#define _alloca64( x )					((void *)ALIGNPTR( (int)_alloca( ALIGNPTR( x, 64 ) + 64 ), 64 ) )
#define _alloca128( x )					((void *)ALIGNPTR( (int)_alloca( ALIGNPTR( x, 128 ) + 128 ), 128 ) )

#define PATHSEPERATOR_STR				"\\"
#define PATHSEPERATOR_CHAR				'\\'

#define ID_INLINE						__inline
#define ID_FORCE_INLINE					__forceinline
#define ID_STATIC_TEMPLATE				static

#define assertmem( x, y )				assert( _CrtIsValidPointer( x, y, true ) )

#endif

// Mac OSX
#if defined(MACOS_X) || defined(__APPLE__)

#define BUILD_STRING					"MacOSX-universal"
#define BUILD_OS_ID						1
#ifdef __ppc__
#define	CPUSTRING						"ppc"
#define CPU_EASYARGS					0
#elif defined(__i386__)
#define	CPUSTRING						"x86"
#define CPU_EASYARGS					1
#endif

#define ALIGN16( x )					_CRT_ALIGN(16) x
#define ALIGN32( x )					_CRT_ALIGN(32) x
#define ALIGN64( x )					_CRT_ALIGN(64) x
#define ALIGN128( x )					_CRT_ALIGN(128) x

#define ALIGNPTR( x, a )				( ( ( x ) + ((a)-1) ) & ~((a)-1) )

#ifdef __MWERKS__
#include <alloca.h>
#endif

#define _alloca							alloca
#define _alloca16( x )					((void *)ALIGNPTR( (int)_alloca( ALIGNPTR( x, 16 ) + 16 ), 16 ) )
#define _alloca32( x )					((void *)ALIGNPTR( (int)_alloca( ALIGNPTR( x, 32 ) + 32 ), 32 ) )
#define _alloca64( x )					((void *)ALIGNPTR( (int)_alloca( ALIGNPTR( x, 64 ) + 64 ), 64 ) )
#define _alloca128( x )					((void *)ALIGNPTR( (int)_alloca( ALIGNPTR( x, 128 ) + 128 ), 128 ) )

#define PATHSEPERATOR_STR				"/"
#define PATHSEPERATOR_CHAR				'/'

#define __cdecl
#define ASSERT							assert

#define ID_INLINE						__inline
#define ID_FORCE_INLINE					__forceinline
#define ID_STATIC_TEMPLATE

#define assertmem( x, y )

#endif

// Linux
#ifdef __linux__

#ifdef __i386__
#define	BUILD_STRING					"linux-x86"
#define BUILD_OS_ID						2
#define CPUSTRING						"x86"
#define CPU_EASYARGS					1
#elif defined(__ppc__)
#define	BUILD_STRING					"linux-ppc"
#define CPUSTRING						"ppc"
#define CPU_EASYARGS					0
#endif

#define ALIGN16( x )					_CRT_ALIGN(16) x
#define ALIGN32( x )					_CRT_ALIGN(32) x
#define ALIGN64( x )					_CRT_ALIGN(64) x
#define ALIGN128( x )					_CRT_ALIGN(128) x

#define ALIGNPTR( x, a )				( ( ( x ) + ((a)-1) ) & ~((a)-1) )

#define _alloca							alloca
#define _alloca16( x )					((void *)ALIGNPTR( (int)_alloca( ALIGNPTR( x, 16 ) + 16 ), 16 ) )
#define _alloca32( x )					((void *)ALIGNPTR( (int)_alloca( ALIGNPTR( x, 32 ) + 32 ), 32 ) )
#define _alloca64( x )					((void *)ALIGNPTR( (int)_alloca( ALIGNPTR( x, 64 ) + 64 ), 64 ) )
#define _alloca128( x )					((void *)ALIGNPTR( (int)_alloca( ALIGNPTR( x, 128 ) + 128 ), 128 ) )

#define PATHSEPERATOR_STR				"/"
#define PATHSEPERATOR_CHAR				'/'

#define __cdecl
#define ASSERT							assert

#define ID_INLINE						__inline
#define ID_FORCE_INLINE					__forceinline
#define ID_STATIC_TEMPLATE

#define assertmem( x, y )

#endif

#endif
