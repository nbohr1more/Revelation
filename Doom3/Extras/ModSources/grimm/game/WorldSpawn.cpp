// Copyright (C) 2004 Id Software, Inc.
//
/*
game_worldspawn.cpp

Worldspawn class.  Each map has one worldspawn which handles global spawnargs.

*/

#include "../idlib/precompiled.h"
#pragma hdrstop

#include "Game_local.h"

/*
================
idWorldspawn

Every map should have exactly one worldspawn.
================
*/
CLASS_DECLARATION( idEntity, idWorldspawn )
EVENT( EV_Remove,				idWorldspawn::Event_Remove )
EVENT( EV_SafeRemove,			idWorldspawn::Event_Remove )
END_CLASS

/*
================
idWorldspawn::Spawn
================
*/
void idWorldspawn::Spawn( void ) {
	idStr				scriptname;
	idThread			*thread;
	const function_t	*func;
	//const idKeyValue	*kv;		<-- not used in grimm
	// grimm -->
	gameSoundWorld->SetSlowmo( false );
	gameSoundWorld->SetSlowmoSpeed( 0.8f );
	// <-- grimm
	assert( gameLocal.world == NULL );
	gameLocal.world = this;
	g_gravity.SetFloat( spawnArgs.GetFloat( "gravity", va( "%f", DEFAULT_GRAVITY ) ) );
	// disable stamina on hell levels
	if( spawnArgs.GetBool( "no_stamina" ) ) {
		pm_stamina.SetFloat( 0.0f );
	}
	// load script
	scriptname = gameLocal.GetMapName();
	scriptname.SetFileExtension( ".script" );
	if( fileSystem->ReadFile( scriptname, NULL, NULL ) > 0 ) {
		gameLocal.program.CompileFile( scriptname );
		// call the main function by default
		func = gameLocal.program.FindFunction( "main" );
		if( func != NULL ) {
			thread = new idThread( func );
			thread->DelayedStart( 0 );
		}
	}
	// grimm --> set the current ambient light levels for this session
	SetAmbientLight();
	// <-- grimm
	/* grimm --> not needed for us. I call everything from main anyway.

	// call any functions specified in worldspawn
	kv = spawnArgs.MatchPrefix( "call" );
	while( kv != NULL ) {
		func = gameLocal.program.FindFunction( kv->GetValue() );
		if ( func == NULL ) {
			gameLocal.Error( "Function '%s' not found in script for '%s' key on worldspawn", kv->GetValue().c_str(), kv->GetKey().c_str() );
		}

		thread = new idThread( func );
		thread->DelayedStart( 0 );
		kv = spawnArgs.MatchPrefix( "call", kv );
	}
	*/
	// <-- grimm
}

/*
=================
idWorldspawn::Save
=================
*/
void idWorldspawn::Save( idRestoreGame *savefile ) {
}

/*
=================
idWorldspawn::Restore
=================
*/
void idWorldspawn::Restore( idRestoreGame *savefile ) {
	assert( gameLocal.world == this );
	g_gravity.SetFloat( spawnArgs.GetFloat( "gravity", va( "%f", DEFAULT_GRAVITY ) ) );
	// disable stamina on hell levels
	if( spawnArgs.GetBool( "no_stamina" ) ) {
		pm_stamina.SetFloat( 0.0f );
	}
	// grimm --> set the current ambient light levels for this session
	SetAmbientLight();
	// <-- grimm
}

/*
================
idWorldspawn::~idWorldspawn
================
*/
idWorldspawn::~idWorldspawn() {
	if( gameLocal.world == this ) {
		gameLocal.world = NULL;
	}
}

/*
================
idWorldspawn::Event_Remove
================
*/
void idWorldspawn::Event_Remove( void ) {
	gameLocal.Error( "Cannot remove the world." );
}

// grimm --> sets the ambient type for the current session, specified in the worldspawn entity (any brush in the map)
/*
================
idWorldspawn::SetAmbientLight
================
*/
void idWorldspawn::SetAmbientLight( void ) {
	int AmbientType = spawnArgs.GetInt( "AmbientType" );
	gameLocal.Printf( "Ambienttype set to %i.\n", AmbientType );
	if( AmbientType == 0 ) {
		cvarSystem->SetCVarString( "g_ambientLightColor", "0.12 0.06 0.04" );
	} else if( AmbientType == 1 ) {
		cvarSystem->SetCVarString( "g_ambientLightColor", "0.04 0.07 0.11" );
	} else if( AmbientType == 2 ) {
		cvarSystem->SetCVarString( "g_ambientLightColor", "0.08 0.08 0.08" );
	} else if( AmbientType == 3 ) {
		cvarSystem->SetCVarString( "g_ambientLightColor", "0.04 0.12 0.06" );
	} else {
		cvarSystem->SetCVarString( "g_ambientLightColor", "0.12 0.06 0.04" );
	}
}
// <-- grimm
