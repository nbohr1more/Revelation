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
/*
** QGL_WIN.C
**
** This file implements the operating system binding of GL to QGL function
** pointers.  When doing a port of Doom you must implement the following
** two functions:
**
** QGL_Init() - loads libraries, assigns function pointers, etc.
** QGL_Shutdown() - unloads libraries, NULLs function pointers
*/
#include "../../idlib/precompiled.h"
#pragma hdrstop

#include "win_local.h"
#include "../../renderer/tr_local.h"

/*
** QGL_Shutdown
**
** Unloads the specified DLL then nulls out all the proc pointers.  This
** is only called during a hard shutdown of the OGL subsystem (e.g. vid_restart).
*/
void QGL_Shutdown( void ) {
	common->Printf( "...shutting down QGL\n" );
	if( win32.hinstOpenGL ) {
		common->Printf( "...unloading OpenGL DLL\n" );
		FreeLibrary( win32.hinstOpenGL );
	}
	win32.hinstOpenGL = 0;
}

/*
** QGL_Init
**
** This is responsible for binding our gl function pointers to
** the appropriate GL stuff.  In Windows this means doing a
** LoadLibrary and a bunch of calls to GetProcAddress.  On other
** operating systems we need to do the right thing, whatever that
** might be.
*/
bool QGL_Init( const char *dllname ) {
	assert( win32.hinstOpenGL == 0 );
	common->Printf( "...initializing QGL\n" );
	// check that we loaded the correct OpenGL dll.
	if( ( win32.hinstOpenGL = LoadLibrary( dllname ) ) != 0 ) {
		GLenum err = glewInit();
		// Check if glew has been initialized properly,
		// and if not print out why.
		if( err != GLEW_NO_ERROR || err != GLEW_OK ) {
			common->Printf( "OpenGL failed to initialize %s!\n", glewGetErrorString( err ) );
			return false;
		}
		common->Printf( "Using OpenGL driver dll %s\n", dllname );
	}
	return true;
}


