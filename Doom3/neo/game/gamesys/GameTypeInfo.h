
#ifndef __GAMETYPEINFO_H__
#define __GAMETYPEINFO_H__

/*
===================================================================================

	This file has been generated with the Type Info Generator v1.0 (c) 2004 id Software

	327 constants
	40 enums
	161 classes/structs/unions
	34 templates
	2 max inheritance level for 'idMapPatch'

===================================================================================
*/

typedef struct {
	const char * name;
	const char * type;
	const char * value;
} constantInfo_t;

typedef struct {
	const char * name;
	int value;
} enumValueInfo_t;

typedef struct {
	const char * typeName;
	const enumValueInfo_t * values;
} enumTypeInfo_t;

typedef struct {
	const char * type;
	const char * name;
	int offset;
	int size;
} classVariableInfo_t;

typedef struct {
	const char * typeName;
	const char * superType;
	int size;
	const classVariableInfo_t * variables;
} classTypeInfo_t;

static constantInfo_t constantInfo[] = {
	{ "int", "CPUID_NONE", "0" },
	{ "int", "CPUID_UNSUPPORTED", "1" },
	{ "int", "CPUID_GENERIC", "2" },
	{ "int", "CPUID_INTEL", "4" },
	{ "int", "CPUID_AMD", "8" },
	{ "int", "CPUID_MMX", "16" },
	{ "int", "CPUID_3DNOW", "32" },
	{ "int", "CPUID_SSE", "64" },
	{ "int", "CPUID_SSE2", "128" },
	{ "int", "CPUID_SSE3", "256" },
	{ "int", "CPUID_ALTIVEC", "512" },
	{ "int", "CPUID_HTT", "4096" },
	{ "int", "CPUID_CMOV", "8192" },
	{ "int", "CPUID_FTZ", "16384" },
	{ "int", "CPUID_DAZ", "32768" },
	{ "int", "AXIS_SIDE", "0" },
	{ "int", "AXIS_FORWARD", "1" },
	{ "int", "AXIS_UP", "2" },
	{ "int", "AXIS_ROLL", "3" },
	{ "int", "AXIS_YAW", "4" },
	{ "int", "AXIS_PITCH", "5" },
	{ "int", "MAX_JOYSTICK_AXIS", "6" },
	{ "int", "SE_NONE", "0" },
	{ "int", "SE_KEY", "1" },
	{ "int", "SE_CHAR", "2" },
	{ "int", "SE_MOUSE", "3" },
	{ "int", "SE_JOYSTICK_AXIS", "4" },
	{ "int", "SE_CONSOLE", "5" },
	{ "int", "M_ACTION1", "0" },
	{ "int", "M_ACTION2", "1" },
	{ "int", "M_ACTION3", "2" },
	{ "int", "M_ACTION4", "3" },
	{ "int", "M_ACTION5", "4" },
	{ "int", "M_ACTION6", "5" },
	{ "int", "M_ACTION7", "6" },
	{ "int", "M_ACTION8", "7" },
	{ "int", "M_DELTAX", "8" },
	{ "int", "M_DELTAY", "9" },
	{ "int", "M_DELTAZ", "10" },
	{ "int", "NA_BAD", "0" },
	{ "int", "NA_LOOPBACK", "1" },
	{ "int", "NA_BROADCAST", "2" },
	{ "int", "NA_IP", "3" },
	{ "int", "THREAD_LOWEST", "0" },
	{ "int", "THREAD_BELOW_NORMAL", "1" },
	{ "int", "THREAD_NORMAL", "2" },
	{ "int", "THREAD_ABOVE_NORMAL", "3" },
	{ "int", "THREAD_HIGHEST", "4" },
	{ "const int", "MAX_THREADS", "10" },
	{ "const int", "MAX_CRITICAL_SECTIONS", "4" },
	{ "int", "CRITICAL_SECTION_ZERO", "0" },
	{ "int", "CRITICAL_SECTION_ONE", "1" },
	{ "int", "CRITICAL_SECTION_TWO", "2" },
	{ "int", "CRITICAL_SECTION_THREE", "3" },
	{ "const int", "MAX_TRIGGER_EVENTS", "4" },
	{ "int", "TRIGGER_EVENT_ZERO", "0" },
	{ "int", "TRIGGER_EVENT_ONE", "1" },
	{ "int", "TRIGGER_EVENT_TWO", "2" },
	{ "int", "TRIGGER_EVENT_THREE", "3" },
	{ "const int", "MIXBUFFER_SAMPLES", "4096" },
	{ "int", "SPEAKER_LEFT", "0" },
	{ "int", "SPEAKER_RIGHT", "1" },
	{ "int", "SPEAKER_CENTER", "2" },
	{ "int", "SPEAKER_LFE", "3" },
	{ "int", "SPEAKER_BACKLEFT", "4" },
	{ "int", "SPEAKER_BACKRIGHT", "5" },
	{ "int", "idMath::LOOKUP_BITS", "8" },
	{ "int", "idMath::EXP_POS", "23" },
	{ "int", "idMath::EXP_BIAS", "127" },
	{ "int", "idMath::LOOKUP_POS", "15" },
	{ "int", "idMath::SEED_POS", "15" },
	{ "int", "idMath::SQRT_TABLE_SIZE", "512" },
	{ "int", "idMath::LOOKUP_MASK", "511" },
	{ "static const int", "idRandom::MAX_RAND", "0x7fff" },
	{ "static const int", "idRandom2::MAX_RAND", "0x7fff" },
	{ "static const unsigned long", "idRandom2::IEEE_ONE", "0x3f800000" },
	{ "static const unsigned long", "idRandom2::IEEE_MASK", "0x007fffff" },
	{ "int", "EXTRAPOLATION_NONE", "1" },
	{ "int", "EXTRAPOLATION_LINEAR", "2" },
	{ "int", "EXTRAPOLATION_ACCELLINEAR", "4" },
	{ "int", "EXTRAPOLATION_DECELLINEAR", "8" },
	{ "int", "EXTRAPOLATION_ACCELSINE", "16" },
	{ "int", "EXTRAPOLATION_DECELSINE", "32" },
	{ "int", "EXTRAPOLATION_NOSTOP", "64" },
	{ "int", "idCurve_Spline< class type >::BT_FREE", "0" },
	{ "int", "idCurve_Spline< class type >::BT_CLAMPED", "1" },
	{ "int", "idCurve_Spline< class type >::BT_CLOSED", "2" },
	{ "int", "TRM_INVALID", "0" },
	{ "int", "TRM_BOX", "1" },
	{ "int", "TRM_OCTAHEDRON", "2" },
	{ "int", "TRM_DODECAHEDRON", "3" },
	{ "int", "TRM_CYLINDER", "4" },
	{ "int", "TRM_CONE", "5" },
	{ "int", "TRM_BONE", "6" },
	{ "int", "TRM_POLYGON", "7" },
	{ "int", "TRM_POLYGONVOLUME", "8" },
	{ "int", "TRM_CUSTOM", "9" },
	{ "const int", "C_COLOR_ESCAPE", "^" },
	{ "const int", "C_COLOR_DEFAULT", "0" },
	{ "const int", "C_COLOR_RED", "1" },
	{ "const int", "C_COLOR_GREEN", "2" },
	{ "const int", "C_COLOR_YELLOW", "3" },
	{ "const int", "C_COLOR_BLUE", "4" },
	{ "const int", "C_COLOR_CYAN", "5" },
	{ "const int", "C_COLOR_MAGENTA", "6" },
	{ "const int", "C_COLOR_WHITE", "7" },
	{ "const int", "C_COLOR_GRAY", "8" },
	{ "const int", "C_COLOR_BLACK", "9" },
	{ "const int", "STR_ALLOC_BASE", "20" },
	{ "const int", "STR_ALLOC_GRAN", "32" },
	{ "int", "MEASURE_SIZE", "0" },
	{ "int", "MEASURE_BANDWIDTH", "1" },
	{ "int", "LEXFL_NOERRORS", "1" },
	{ "int", "LEXFL_NOWARNINGS", "2" },
	{ "int", "LEXFL_NOFATALERRORS", "4" },
	{ "int", "LEXFL_NOSTRINGCONCAT", "8" },
	{ "int", "LEXFL_NOSTRINGESCAPECHARS", "16" },
	{ "int", "LEXFL_NODOLLARPRECOMPILE", "32" },
	{ "int", "LEXFL_NOBASEINCLUDES", "64" },
	{ "int", "LEXFL_ALLOWPATHNAMES", "128" },
	{ "int", "LEXFL_ALLOWNUMBERNAMES", "256" },
	{ "int", "LEXFL_ALLOWIPADDRESSES", "512" },
	{ "int", "LEXFL_ALLOWFLOATEXCEPTIONS", "1024" },
	{ "int", "LEXFL_ALLOWMULTICHARLITERALS", "2048" },
	{ "int", "LEXFL_ALLOWBACKSLASHSTRINGCONCAT", "4096" },
	{ "int", "LEXFL_ONLYSTRINGS", "8192" },
	{ "static const int", "idCmdArgs::MAX_COMMAND_ARGS", "64" },
	{ "static const int", "idCmdArgs::MAX_COMMAND_STRING", "2*1024" },
	{ "const int", "OLD_MAP_VERSION", "1" },
	{ "const int", "CURRENT_MAP_VERSION", "2" },
	{ "const int", "DEFAULT_CURVE_SUBDIVISION", "4" },
	{ "const float", "DEFAULT_CURVE_MAX_ERROR", "4.0" },
	{ "const float", "DEFAULT_CURVE_MAX_ERROR_CD", "24.0" },
	{ "const float", "DEFAULT_CURVE_MAX_LENGTH", "-1.0" },
	{ "const float", "DEFAULT_CURVE_MAX_LENGTH_CD", "-1.0" },
	{ "int", "idMapPrimitive::TYPE_INVALID", "-1" },
	{ "int", "idMapPrimitive::TYPE_BRUSH", "0" },
	{ "int", "idMapPrimitive::TYPE_PATCH", "1" },
	{ "int", "idTimer::TS_STARTED", "0" },
	{ "int", "idTimer::TS_STOPPED", "1" },
	{ "const int", "BUILD_NUMBER", "1304" },
	{ "int", "CMD_FL_ALL", "-1" },
	{ "int", "CMD_FL_CHEAT", "1" },
	{ "int", "CMD_FL_SYSTEM", "2" },
	{ "int", "CMD_FL_RENDERER", "4" },
	{ "int", "CMD_FL_SOUND", "8" },
	{ "int", "CMD_FL_GAME", "16" },
	{ "int", "CMD_FL_TOOL", "32" },
	{ "int", "CMD_EXEC_NOW", "0" },
	{ "int", "CMD_EXEC_INSERT", "1" },
	{ "int", "CMD_EXEC_APPEND", "2" },
	{ "int", "CVAR_ALL", "-1" },
	{ "int", "CVAR_BOOL", "1" },
	{ "int", "CVAR_INTEGER", "2" },
	{ "int", "CVAR_FLOAT", "4" },
	{ "int", "CVAR_SYSTEM", "8" },
	{ "int", "CVAR_RENDERER", "16" },
	{ "int", "CVAR_SOUND", "32" },
	{ "int", "CVAR_GUI", "64" },
	{ "int", "CVAR_GAME", "128" },
	{ "int", "CVAR_TOOL", "256" },
	{ "int", "CVAR_USERINFO", "512" },
	{ "int", "CVAR_SERVERINFO", "1024" },
	{ "int", "CVAR_NETWORKSYNC", "2048" },
	{ "int", "CVAR_STATIC", "4096" },
	{ "int", "CVAR_CHEAT", "8192" },
	{ "int", "CVAR_NOCHEAT", "16384" },
	{ "int", "CVAR_INIT", "32768" },
	{ "int", "CVAR_ROM", "65536" },
	{ "int", "CVAR_ARCHIVE", "131072" },
	{ "int", "CVAR_MODIFIED", "262144" },
	{ "int", "EDITOR_NONE", "0" },
	{ "int", "EDITOR_RADIANT", "2" },
	{ "int", "EDITOR_GUI", "4" },
	{ "int", "EDITOR_SCRIPT", "8" },
	{ "int", "EDITOR_LIGHT", "16" },
	{ "int", "EDITOR_SOUND", "32" },
	{ "int", "EDITOR_DECL", "64" },
	{ "int", "EDITOR_AF", "128" },
	{ "int", "EDITOR_PARTICLE", "256" },
	{ "int", "EDITOR_PDA", "512" },
	{ "int", "EDITOR_AAS", "1024" },
	{ "int", "EDITOR_MATERIAL", "2048" },
	{ "int", "FS_SEEK_CUR", "0" },
	{ "int", "FS_SEEK_END", "1" },
	{ "int", "FS_SEEK_SET", "2" },
	{ "static const time_t", "FILE_NOT_FOUND_TIMESTAMP", "0xFFFFFFFF" },
	{ "static const int", "MAX_PURE_PAKS", "128" },
	{ "static const int", "MAX_OSPATH", "256" },
	{ "int", "FS_READ", "1" },
	{ "int", "FS_WRITE", "2" },
	{ "int", "FS_APPEND", "3" },
	{ "int", "PURE_OK", "0" },
	{ "int", "PURE_RESTART", "1" },
	{ "int", "PURE_MISSING", "2" },
	{ "int", "PURE_NODLL", "3" },
	{ "int", "DLTYPE_URL", "0" },
	{ "int", "DLTYPE_FILE", "1" },
	{ "int", "DL_WAIT", "0" },
	{ "int", "DL_INPROGRESS", "1" },
	{ "int", "DL_DONE", "2" },
	{ "int", "DL_ABORTING", "3" },
	{ "int", "DL_FAILED", "4" },
	{ "int", "FILE_EXEC", "0" },
	{ "int", "FILE_OPEN", "1" },
	{ "int", "FIND_NO", "0" },
	{ "int", "FIND_YES", "1" },
	{ "int", "FIND_ADDON", "2" },
	{ "const int", "USERCMD_HZ", "60" },
	{ "const int", "USERCMD_MSEC", "1000/60" },
	{ "const int", "BUTTON_ATTACK", "(1<<(0))" },
	{ "const int", "BUTTON_RUN", "(1<<(1))" },
	{ "const int", "BUTTON_ZOOM", "(1<<(2))" },
	{ "const int", "BUTTON_SCORES", "(1<<(3))" },
	{ "const int", "BUTTON_MLOOK", "(1<<(4))" },
	{ "const int", "BUTTON_5", "(1<<(5))" },
	{ "const int", "BUTTON_6", "(1<<(6))" },
	{ "const int", "BUTTON_7", "(1<<(7))" },
	{ "const int", "IMPULSE_0", "0" },
	{ "const int", "IMPULSE_1", "1" },
	{ "const int", "IMPULSE_2", "2" },
	{ "const int", "IMPULSE_3", "3" },
	{ "const int", "IMPULSE_4", "4" },
	{ "const int", "IMPULSE_5", "5" },
	{ "const int", "IMPULSE_6", "6" },
	{ "const int", "IMPULSE_7", "7" },
	{ "const int", "IMPULSE_8", "8" },
	{ "const int", "IMPULSE_9", "9" },
	{ "const int", "IMPULSE_10", "10" },
	{ "const int", "IMPULSE_11", "11" },
	{ "const int", "IMPULSE_12", "12" },
	{ "const int", "IMPULSE_13", "13" },
	{ "const int", "IMPULSE_14", "14" },
	{ "const int", "IMPULSE_15", "15" },
	{ "const int", "IMPULSE_16", "16" },
	{ "const int", "IMPULSE_17", "17" },
	{ "const int", "IMPULSE_18", "18" },
	{ "const int", "IMPULSE_19", "19" },
	{ "const int", "IMPULSE_20", "20" },
	{ "const int", "IMPULSE_21", "21" },
	{ "const int", "IMPULSE_22", "22" },
	{ "const int", "IMPULSE_23", "23" },
	{ "const int", "IMPULSE_24", "24" },
	{ "const int", "IMPULSE_25", "25" },
	{ "const int", "IMPULSE_26", "26" },
	{ "const int", "IMPULSE_27", "27" },
	{ "const int", "IMPULSE_28", "28" },
	{ "const int", "IMPULSE_29", "29" },
	{ "const int", "IMPULSE_30", "30" },
	{ "const int", "IMPULSE_31", "31" },
	{ "const int", "IMPULSE_32", "32" },
	{ "const int", "IMPULSE_33", "33" },
	{ "const int", "IMPULSE_34", "34" },
	{ "const int", "IMPULSE_35", "35" },
	{ "const int", "IMPULSE_36", "36" },
	{ "const int", "IMPULSE_37", "37" },
	{ "const int", "IMPULSE_38", "38" },
	{ "const int", "IMPULSE_39", "39" },
	{ "const int", "IMPULSE_40", "40" },
	{ "const int", "UCF_IMPULSE_SEQUENCE", "0x0001" },
	{ "int", "INHIBIT_SESSION", "0" },
	{ "int", "INHIBIT_ASYNC", "1" },
	{ "const int", "MAX_BUFFERED_USERCMD", "64" },
	{ "int", "DECL_TABLE", "0" },
	{ "int", "DECL_MATERIAL", "1" },
	{ "int", "DECL_SKIN", "2" },
	{ "int", "DECL_SOUND", "3" },
	{ "int", "DECL_ENTITYDEF", "4" },
	{ "int", "DECL_MODELDEF", "5" },
	{ "int", "DECL_FX", "6" },
	{ "int", "DECL_PARTICLE", "7" },
	{ "int", "DECL_AF", "8" },
	{ "int", "DECL_PDA", "9" },
	{ "int", "DECL_VIDEO", "10" },
	{ "int", "DECL_AUDIO", "11" },
	{ "int", "DECL_EMAIL", "12" },
	{ "int", "DECL_MODELEXPORT", "13" },
	{ "int", "DECL_MAPDEF", "14" },
	{ "int", "DECL_MAX_TYPES", "32" },
	{ "int", "DS_UNPARSED", "0" },
	{ "int", "DS_DEFAULTED", "1" },
	{ "int", "DS_PARSED", "2" },
	{ "const int", "DECL_LEXER_FLAGS", "8|16|128|2048|4096|4" },
	{ "int", "FX_LIGHT", "0" },
	{ "int", "FX_PARTICLE", "1" },
	{ "int", "FX_DECAL", "2" },
	{ "int", "FX_MODEL", "3" },
	{ "int", "FX_SOUND", "4" },
	{ "int", "FX_SHAKE", "5" },
	{ "int", "FX_ATTACHLIGHT", "6" },
	{ "int", "FX_ATTACHENTITY", "7" },
	{ "int", "FX_LAUNCH", "8" },
	{ "int", "FX_SHOCKWAVE", "9" },
	{ "int", "PDIST_RECT", "0" },
	{ "int", "PDIST_CYLINDER", "1" },
	{ "int", "PDIST_SPHERE", "2" },
	{ "int", "PDIR_CONE", "0" },
	{ "int", "PDIR_OUTWARD", "1" },
	{ "int", "PPATH_STANDARD", "0" },
	{ "int", "PPATH_HELIX", "1" },
	{ "int", "PPATH_FLIES", "2" },
	{ "int", "PPATH_ORBIT", "3" },
	{ "int", "PPATH_DRIP", "4" },
	{ "int", "POR_VIEW", "0" },
	{ "int", "POR_AIMED", "1" },
	{ "int", "POR_X", "2" },
	{ "int", "POR_Y", "3" },
	{ "int", "POR_Z", "4" },
	{ "int", "DECLAF_CONSTRAINT_INVALID", "0" },
	{ "int", "DECLAF_CONSTRAINT_FIXED", "1" },
	{ "int", "DECLAF_CONSTRAINT_BALLANDSOCKETJOINT", "2" },
	{ "int", "DECLAF_CONSTRAINT_UNIVERSALJOINT", "3" },
	{ "int", "DECLAF_CONSTRAINT_HINGE", "4" },
	{ "int", "DECLAF_CONSTRAINT_SLIDER", "5" },
	{ "int", "DECLAF_CONSTRAINT_SPRING", "6" },
	{ "int", "DECLAF_JOINTMOD_AXIS", "0" },
	{ "int", "DECLAF_JOINTMOD_ORIGIN", "1" },
	{ "int", "DECLAF_JOINTMOD_BOTH", "2" },
	{ "int", "idAFVector::VEC_COORDS", "0" },
	{ "int", "idAFVector::VEC_JOINT", "1" },
	{ "int", "idAFVector::VEC_BONECENTER", "2" },
	{ "int", "idAFVector::VEC_BONEDIR", "3" },
	{ "int", "idDeclAF_Constraint::LIMIT_NONE", "-1" },
	{ "int", "idDeclAF_Constraint::LIMIT_CONE", "0" },
	{ "int", "idDeclAF_Constraint::LIMIT_PYRAMID", "1" },
	{ "const int", "MAX_EXPRESSION_OPS", "4096" },
	{ "const int", "MAX_EXPRESSION_REGISTERS", "4096" },
	{ NULL, NULL, NULL }
};

static enumValueInfo_t cpuid_t_typeInfo[] = {
	{ "CPUID_NONE", 0 },
	{ "CPUID_UNSUPPORTED", 1 },
	{ "CPUID_GENERIC", 2 },
	{ "CPUID_INTEL", 4 },
	{ "CPUID_AMD", 8 },
	{ "CPUID_MMX", 16 },
	{ "CPUID_3DNOW", 32 },
	{ "CPUID_SSE", 64 },
	{ "CPUID_SSE2", 128 },
	{ "CPUID_SSE3", 256 },
	{ "CPUID_ALTIVEC", 512 },
	{ "CPUID_HTT", 4096 },
	{ "CPUID_CMOV", 8192 },
	{ "CPUID_FTZ", 16384 },
	{ "CPUID_DAZ", 32768 },
	{ NULL, 0 }
};

static enumValueInfo_t joystickAxis_t_typeInfo[] = {
	{ "AXIS_SIDE", 0 },
	{ "AXIS_FORWARD", 1 },
	{ "AXIS_UP", 2 },
	{ "AXIS_ROLL", 3 },
	{ "AXIS_YAW", 4 },
	{ "AXIS_PITCH", 5 },
	{ "MAX_JOYSTICK_AXIS", 6 },
	{ NULL, 0 }
};

static enumValueInfo_t sysEventType_t_typeInfo[] = {
	{ "SE_NONE", 0 },
	{ "SE_KEY", 1 },
	{ "SE_CHAR", 2 },
	{ "SE_MOUSE", 3 },
	{ "SE_JOYSTICK_AXIS", 4 },
	{ "SE_CONSOLE", 5 },
	{ NULL, 0 }
};

static enumValueInfo_t sys_mEvents_typeInfo[] = {
	{ "M_ACTION1", 0 },
	{ "M_ACTION2", 1 },
	{ "M_ACTION3", 2 },
	{ "M_ACTION4", 3 },
	{ "M_ACTION5", 4 },
	{ "M_ACTION6", 5 },
	{ "M_ACTION7", 6 },
	{ "M_ACTION8", 7 },
	{ "M_DELTAX", 8 },
	{ "M_DELTAY", 9 },
	{ "M_DELTAZ", 10 },
	{ NULL, 0 }
};

static enumValueInfo_t netadrtype_t_typeInfo[] = {
	{ "NA_BAD", 0 },
	{ "NA_LOOPBACK", 1 },
	{ "NA_BROADCAST", 2 },
	{ "NA_IP", 3 },
	{ NULL, 0 }
};

static enumValueInfo_t xthreadPriority_typeInfo[] = {
	{ "THREAD_LOWEST", 0 },
	{ "THREAD_BELOW_NORMAL", 1 },
	{ "THREAD_NORMAL", 2 },
	{ "THREAD_ABOVE_NORMAL", 3 },
	{ "THREAD_HIGHEST", 4 },
	{ NULL, 0 }
};

static enumValueInfo_t enum_6_typeInfo[] = {
	{ "CRITICAL_SECTION_ZERO", 0 },
	{ "CRITICAL_SECTION_ONE", 1 },
	{ "CRITICAL_SECTION_TWO", 2 },
	{ "CRITICAL_SECTION_THREE", 3 },
	{ NULL, 0 }
};

static enumValueInfo_t enum_7_typeInfo[] = {
	{ "TRIGGER_EVENT_ZERO", 0 },
	{ "TRIGGER_EVENT_ONE", 1 },
	{ "TRIGGER_EVENT_TWO", 2 },
	{ "TRIGGER_EVENT_THREE", 3 },
	{ NULL, 0 }
};

static enumValueInfo_t speakerLabel_typeInfo[] = {
	{ "SPEAKER_LEFT", 0 },
	{ "SPEAKER_RIGHT", 1 },
	{ "SPEAKER_CENTER", 2 },
	{ "SPEAKER_LFE", 3 },
	{ "SPEAKER_BACKLEFT", 4 },
	{ "SPEAKER_BACKRIGHT", 5 },
	{ NULL, 0 }
};

static enumValueInfo_t idMath_enum_9_typeInfo[] = {
	{ "LOOKUP_BITS", 8 },
	{ "EXP_POS", 23 },
	{ "EXP_BIAS", 127 },
	{ "LOOKUP_POS", 15 },
	{ "SEED_POS", 15 },
	{ "SQRT_TABLE_SIZE", 512 },
	{ "LOOKUP_MASK", 511 },
	{ NULL, 0 }
};

static enumValueInfo_t extrapolation_t_typeInfo[] = {
	{ "EXTRAPOLATION_NONE", 1 },
	{ "EXTRAPOLATION_LINEAR", 2 },
	{ "EXTRAPOLATION_ACCELLINEAR", 4 },
	{ "EXTRAPOLATION_DECELLINEAR", 8 },
	{ "EXTRAPOLATION_ACCELSINE", 16 },
	{ "EXTRAPOLATION_DECELSINE", 32 },
	{ "EXTRAPOLATION_NOSTOP", 64 },
	{ NULL, 0 }
};

static enumValueInfo_t idCurve_Spline_class_type__boundary_t_typeInfo[] = {
//	{ "BT_FREE", 0 },
//	{ "BT_CLAMPED", 1 },
//	{ "BT_CLOSED", 2 },
	{ NULL, 0 }
};

static enumValueInfo_t traceModel_t_typeInfo[] = {
	{ "TRM_INVALID", 0 },
	{ "TRM_BOX", 1 },
	{ "TRM_OCTAHEDRON", 2 },
	{ "TRM_DODECAHEDRON", 3 },
	{ "TRM_CYLINDER", 4 },
	{ "TRM_CONE", 5 },
	{ "TRM_BONE", 6 },
	{ "TRM_POLYGON", 7 },
	{ "TRM_POLYGONVOLUME", 8 },
	{ "TRM_CUSTOM", 9 },
	{ NULL, 0 }
};

static enumValueInfo_t Measure_t_typeInfo[] = {
	{ "MEASURE_SIZE", 0 },
	{ "MEASURE_BANDWIDTH", 1 },
	{ NULL, 0 }
};

static enumValueInfo_t lexerFlags_t_typeInfo[] = {
	{ "LEXFL_NOERRORS", 1 },
	{ "LEXFL_NOWARNINGS", 2 },
	{ "LEXFL_NOFATALERRORS", 4 },
	{ "LEXFL_NOSTRINGCONCAT", 8 },
	{ "LEXFL_NOSTRINGESCAPECHARS", 16 },
	{ "LEXFL_NODOLLARPRECOMPILE", 32 },
	{ "LEXFL_NOBASEINCLUDES", 64 },
	{ "LEXFL_ALLOWPATHNAMES", 128 },
	{ "LEXFL_ALLOWNUMBERNAMES", 256 },
	{ "LEXFL_ALLOWIPADDRESSES", 512 },
	{ "LEXFL_ALLOWFLOATEXCEPTIONS", 1024 },
	{ "LEXFL_ALLOWMULTICHARLITERALS", 2048 },
	{ "LEXFL_ALLOWBACKSLASHSTRINGCONCAT", 4096 },
	{ "LEXFL_ONLYSTRINGS", 8192 },
	{ NULL, 0 }
};

static enumValueInfo_t idMapPrimitive_enum_15_typeInfo[] = {
	{ "TYPE_INVALID", -1 },
	{ "TYPE_BRUSH", 0 },
	{ "TYPE_PATCH", 1 },
	{ NULL, 0 }
};

static enumValueInfo_t idTimer_enum_16_typeInfo[] = {
	{ "TS_STARTED", 0 },
	{ "TS_STOPPED", 1 },
	{ NULL, 0 }
};

static enumValueInfo_t cmdFlags_t_typeInfo[] = {
	{ "CMD_FL_ALL", -1 },
	{ "CMD_FL_CHEAT", 1 },
	{ "CMD_FL_SYSTEM", 2 },
	{ "CMD_FL_RENDERER", 4 },
	{ "CMD_FL_SOUND", 8 },
	{ "CMD_FL_GAME", 16 },
	{ "CMD_FL_TOOL", 32 },
	{ NULL, 0 }
};

static enumValueInfo_t cmdExecution_t_typeInfo[] = {
	{ "CMD_EXEC_NOW", 0 },
	{ "CMD_EXEC_INSERT", 1 },
	{ "CMD_EXEC_APPEND", 2 },
	{ NULL, 0 }
};

static enumValueInfo_t cvarFlags_t_typeInfo[] = {
	{ "CVAR_ALL", -1 },
	{ "CVAR_BOOL", 1 },
	{ "CVAR_INTEGER", 2 },
	{ "CVAR_FLOAT", 4 },
	{ "CVAR_SYSTEM", 8 },
	{ "CVAR_RENDERER", 16 },
	{ "CVAR_SOUND", 32 },
	{ "CVAR_GUI", 64 },
	{ "CVAR_GAME", 128 },
	{ "CVAR_TOOL", 256 },
	{ "CVAR_USERINFO", 512 },
	{ "CVAR_SERVERINFO", 1024 },
	{ "CVAR_NETWORKSYNC", 2048 },
	{ "CVAR_STATIC", 4096 },
	{ "CVAR_CHEAT", 8192 },
	{ "CVAR_NOCHEAT", 16384 },
	{ "CVAR_INIT", 32768 },
	{ "CVAR_ROM", 65536 },
	{ "CVAR_ARCHIVE", 131072 },
	{ "CVAR_MODIFIED", 262144 },
	{ NULL, 0 }
};

static enumValueInfo_t toolFlag_t_typeInfo[] = {
	{ "EDITOR_NONE", 0 },
	{ "EDITOR_RADIANT", 2 },
	{ "EDITOR_GUI", 4 },
	{ "EDITOR_SCRIPT", 8 },
	{ "EDITOR_LIGHT", 16 },
	{ "EDITOR_SOUND", 32 },
	{ "EDITOR_DECL", 64 },
	{ "EDITOR_AF", 128 },
	{ "EDITOR_PARTICLE", 256 },
	{ "EDITOR_PDA", 512 },
	{ "EDITOR_AAS", 1024 },
	{ "EDITOR_MATERIAL", 2048 },
	{ NULL, 0 }
};

static enumValueInfo_t fsOrigin_t_typeInfo[] = {
	{ "FS_SEEK_CUR", 0 },
	{ "FS_SEEK_END", 1 },
	{ "FS_SEEK_SET", 2 },
	{ NULL, 0 }
};

static enumValueInfo_t fsMode_t_typeInfo[] = {
	{ "FS_READ", 1 },
	{ "FS_WRITE", 2 },
	{ "FS_APPEND", 3 },
	{ NULL, 0 }
};

static enumValueInfo_t fsPureReply_t_typeInfo[] = {
	{ "PURE_OK", 0 },
	{ "PURE_RESTART", 1 },
	{ "PURE_MISSING", 2 },
	{ "PURE_NODLL", 3 },
	{ NULL, 0 }
};

static enumValueInfo_t dlType_t_typeInfo[] = {
	{ "DLTYPE_URL", 0 },
	{ "DLTYPE_FILE", 1 },
	{ NULL, 0 }
};

static enumValueInfo_t dlStatus_t_typeInfo[] = {
	{ "DL_WAIT", 0 },
	{ "DL_INPROGRESS", 1 },
	{ "DL_DONE", 2 },
	{ "DL_ABORTING", 3 },
	{ "DL_FAILED", 4 },
	{ NULL, 0 }
};

static enumValueInfo_t dlMime_t_typeInfo[] = {
	{ "FILE_EXEC", 0 },
	{ "FILE_OPEN", 1 },
	{ NULL, 0 }
};

static enumValueInfo_t findFile_t_typeInfo[] = {
	{ "FIND_NO", 0 },
	{ "FIND_YES", 1 },
	{ "FIND_ADDON", 2 },
	{ NULL, 0 }
};

static enumValueInfo_t inhibit_t_typeInfo[] = {
	{ "INHIBIT_SESSION", 0 },
	{ "INHIBIT_ASYNC", 1 },
	{ NULL, 0 }
};

static enumValueInfo_t declType_t_typeInfo[] = {
	{ "DECL_TABLE", 0 },
	{ "DECL_MATERIAL", 1 },
	{ "DECL_SKIN", 2 },
	{ "DECL_SOUND", 3 },
	{ "DECL_ENTITYDEF", 4 },
	{ "DECL_MODELDEF", 5 },
	{ "DECL_FX", 6 },
	{ "DECL_PARTICLE", 7 },
	{ "DECL_AF", 8 },
	{ "DECL_PDA", 9 },
	{ "DECL_VIDEO", 10 },
	{ "DECL_AUDIO", 11 },
	{ "DECL_EMAIL", 12 },
	{ "DECL_MODELEXPORT", 13 },
	{ "DECL_MAPDEF", 14 },
	{ "DECL_MAX_TYPES", 32 },
	{ NULL, 0 }
};

static enumValueInfo_t declState_t_typeInfo[] = {
	{ "DS_UNPARSED", 0 },
	{ "DS_DEFAULTED", 1 },
	{ "DS_PARSED", 2 },
	{ NULL, 0 }
};

static enumValueInfo_t enum_31_typeInfo[] = {
	{ "FX_LIGHT", 0 },
	{ "FX_PARTICLE", 1 },
	{ "FX_DECAL", 2 },
	{ "FX_MODEL", 3 },
	{ "FX_SOUND", 4 },
	{ "FX_SHAKE", 5 },
	{ "FX_ATTACHLIGHT", 6 },
	{ "FX_ATTACHENTITY", 7 },
	{ "FX_LAUNCH", 8 },
	{ "FX_SHOCKWAVE", 9 },
	{ NULL, 0 }
};

static enumValueInfo_t prtDistribution_t_typeInfo[] = {
	{ "PDIST_RECT", 0 },
	{ "PDIST_CYLINDER", 1 },
	{ "PDIST_SPHERE", 2 },
	{ NULL, 0 }
};

static enumValueInfo_t prtDirection_t_typeInfo[] = {
	{ "PDIR_CONE", 0 },
	{ "PDIR_OUTWARD", 1 },
	{ NULL, 0 }
};

static enumValueInfo_t prtCustomPth_t_typeInfo[] = {
	{ "PPATH_STANDARD", 0 },
	{ "PPATH_HELIX", 1 },
	{ "PPATH_FLIES", 2 },
	{ "PPATH_ORBIT", 3 },
	{ "PPATH_DRIP", 4 },
	{ NULL, 0 }
};

static enumValueInfo_t prtOrientation_t_typeInfo[] = {
	{ "POR_VIEW", 0 },
	{ "POR_AIMED", 1 },
	{ "POR_X", 2 },
	{ "POR_Y", 3 },
	{ "POR_Z", 4 },
	{ NULL, 0 }
};

static enumValueInfo_t declAFConstraintType_t_typeInfo[] = {
	{ "DECLAF_CONSTRAINT_INVALID", 0 },
	{ "DECLAF_CONSTRAINT_FIXED", 1 },
	{ "DECLAF_CONSTRAINT_BALLANDSOCKETJOINT", 2 },
	{ "DECLAF_CONSTRAINT_UNIVERSALJOINT", 3 },
	{ "DECLAF_CONSTRAINT_HINGE", 4 },
	{ "DECLAF_CONSTRAINT_SLIDER", 5 },
	{ "DECLAF_CONSTRAINT_SPRING", 6 },
	{ NULL, 0 }
};

static enumValueInfo_t declAFJointMod_t_typeInfo[] = {
	{ "DECLAF_JOINTMOD_AXIS", 0 },
	{ "DECLAF_JOINTMOD_ORIGIN", 1 },
	{ "DECLAF_JOINTMOD_BOTH", 2 },
	{ NULL, 0 }
};

static enumValueInfo_t idAFVector_enum_38_typeInfo[] = {
	{ "VEC_COORDS", 0 },
	{ "VEC_JOINT", 1 },
	{ "VEC_BONECENTER", 2 },
	{ "VEC_BONEDIR", 3 },
	{ NULL, 0 }
};

static enumValueInfo_t idDeclAF_Constraint_enum_39_typeInfo[] = {
	{ "LIMIT_NONE", -1 },
	{ "LIMIT_CONE", 0 },
	{ "LIMIT_PYRAMID", 1 },
	{ NULL, 0 }
};

static enumTypeInfo_t enumTypeInfo[] = {
	{ "cpuid_t", cpuid_t_typeInfo },
	{ "joystickAxis_t", joystickAxis_t_typeInfo },
	{ "sysEventType_t", sysEventType_t_typeInfo },
	{ "sys_mEvents", sys_mEvents_typeInfo },
	{ "netadrtype_t", netadrtype_t_typeInfo },
	{ "xthreadPriority", xthreadPriority_typeInfo },
	{ "enum_6", enum_6_typeInfo },
	{ "enum_7", enum_7_typeInfo },
	{ "speakerLabel", speakerLabel_typeInfo },
	{ "idMath::enum_9", idMath_enum_9_typeInfo },
	{ "extrapolation_t", extrapolation_t_typeInfo },
//	{ "idCurve_Spline< class type >::boundary_t", idCurve_Spline_class_type__boundary_t_typeInfo },
	{ "traceModel_t", traceModel_t_typeInfo },
	{ "Measure_t", Measure_t_typeInfo },
	{ "lexerFlags_t", lexerFlags_t_typeInfo },
	{ "idMapPrimitive::enum_15", idMapPrimitive_enum_15_typeInfo },
	{ "idTimer::enum_16", idTimer_enum_16_typeInfo },
	{ "cmdFlags_t", cmdFlags_t_typeInfo },
	{ "cmdExecution_t", cmdExecution_t_typeInfo },
	{ "cvarFlags_t", cvarFlags_t_typeInfo },
	{ "toolFlag_t", toolFlag_t_typeInfo },
	{ "fsOrigin_t", fsOrigin_t_typeInfo },
	{ "fsMode_t", fsMode_t_typeInfo },
	{ "fsPureReply_t", fsPureReply_t_typeInfo },
	{ "dlType_t", dlType_t_typeInfo },
	{ "dlStatus_t", dlStatus_t_typeInfo },
	{ "dlMime_t", dlMime_t_typeInfo },
	{ "findFile_t", findFile_t_typeInfo },
	{ "inhibit_t", inhibit_t_typeInfo },
	{ "declType_t", declType_t_typeInfo },
	{ "declState_t", declState_t_typeInfo },
	{ "enum_31", enum_31_typeInfo },
	{ "prtDistribution_t", prtDistribution_t_typeInfo },
	{ "prtDirection_t", prtDirection_t_typeInfo },
	{ "prtCustomPth_t", prtCustomPth_t_typeInfo },
	{ "prtOrientation_t", prtOrientation_t_typeInfo },
	{ "declAFConstraintType_t", declAFConstraintType_t_typeInfo },
	{ "declAFJointMod_t", declAFJointMod_t_typeInfo },
	{ "idAFVector::enum_38", idAFVector_enum_38_typeInfo },
	{ "idDeclAF_Constraint::enum_39", idDeclAF_Constraint_enum_39_typeInfo },
	{ NULL, NULL }
};

static classVariableInfo_t sysEvent_t_typeInfo[] = {
	{ "sysEventType_t", "evType", (int)(&((sysEvent_t *)0)->evType), sizeof( ((sysEvent_t *)0)->evType ) },
	{ "int", "evValue", (int)(&((sysEvent_t *)0)->evValue), sizeof( ((sysEvent_t *)0)->evValue ) },
	{ "int", "evValue2", (int)(&((sysEvent_t *)0)->evValue2), sizeof( ((sysEvent_t *)0)->evValue2 ) },
	{ "int", "evPtrLength", (int)(&((sysEvent_t *)0)->evPtrLength), sizeof( ((sysEvent_t *)0)->evPtrLength ) },
	{ "void *", "evPtr", (int)(&((sysEvent_t *)0)->evPtr), sizeof( ((sysEvent_t *)0)->evPtr ) },
	{ NULL, 0 }
};

static classVariableInfo_t sysMemoryStats_t_typeInfo[] = {
	{ "int", "memoryLoad", (int)(&((sysMemoryStats_t *)0)->memoryLoad), sizeof( ((sysMemoryStats_t *)0)->memoryLoad ) },
	{ "int", "totalPhysical", (int)(&((sysMemoryStats_t *)0)->totalPhysical), sizeof( ((sysMemoryStats_t *)0)->totalPhysical ) },
	{ "int", "availPhysical", (int)(&((sysMemoryStats_t *)0)->availPhysical), sizeof( ((sysMemoryStats_t *)0)->availPhysical ) },
	{ "int", "totalPageFile", (int)(&((sysMemoryStats_t *)0)->totalPageFile), sizeof( ((sysMemoryStats_t *)0)->totalPageFile ) },
	{ "int", "availPageFile", (int)(&((sysMemoryStats_t *)0)->availPageFile), sizeof( ((sysMemoryStats_t *)0)->availPageFile ) },
	{ "int", "totalVirtual", (int)(&((sysMemoryStats_t *)0)->totalVirtual), sizeof( ((sysMemoryStats_t *)0)->totalVirtual ) },
	{ "int", "availVirtual", (int)(&((sysMemoryStats_t *)0)->availVirtual), sizeof( ((sysMemoryStats_t *)0)->availVirtual ) },
	{ "int", "availExtendedVirtual", (int)(&((sysMemoryStats_t *)0)->availExtendedVirtual), sizeof( ((sysMemoryStats_t *)0)->availExtendedVirtual ) },
	{ NULL, 0 }
};

static classVariableInfo_t netadr_t_typeInfo[] = {
	{ "netadrtype_t", "type", (int)(&((netadr_t *)0)->type), sizeof( ((netadr_t *)0)->type ) },
	{ "unsigned char[4]", "ip", (int)(&((netadr_t *)0)->ip), sizeof( ((netadr_t *)0)->ip ) },
	{ "unsigned short", "port", (int)(&((netadr_t *)0)->port), sizeof( ((netadr_t *)0)->port ) },
	{ NULL, 0 }
};

static classVariableInfo_t idPort_typeInfo[] = {
	{ "int", "packetsRead", (int)(&((idPort *)0)->packetsRead), sizeof( ((idPort *)0)->packetsRead ) },
	{ "int", "bytesRead", (int)(&((idPort *)0)->bytesRead), sizeof( ((idPort *)0)->bytesRead ) },
	{ "int", "packetsWritten", (int)(&((idPort *)0)->packetsWritten), sizeof( ((idPort *)0)->packetsWritten ) },
	{ "int", "bytesWritten", (int)(&((idPort *)0)->bytesWritten), sizeof( ((idPort *)0)->bytesWritten ) },
	{ "netadr_t", "bound_to", (int)(&((idPort *)0)->bound_to), sizeof( ((idPort *)0)->bound_to ) },
	{ "int", "netSocket", (int)(&((idPort *)0)->netSocket), sizeof( ((idPort *)0)->netSocket ) },
	{ NULL, 0 }
};

static classVariableInfo_t idTCP_typeInfo[] = {
	{ "netadr_t", "address", (int)(&((idTCP *)0)->address), sizeof( ((idTCP *)0)->address ) },
	{ "int", "fd", (int)(&((idTCP *)0)->fd), sizeof( ((idTCP *)0)->fd ) },
	{ NULL, 0 }
};

static classVariableInfo_t xthreadInfo_typeInfo[] = {
	{ "const char *", "name", (int)(&((xthreadInfo *)0)->name), sizeof( ((xthreadInfo *)0)->name ) },
	{ "int", "threadHandle", (int)(&((xthreadInfo *)0)->threadHandle), sizeof( ((xthreadInfo *)0)->threadHandle ) },
	{ "unsigned long", "threadId", (int)(&((xthreadInfo *)0)->threadId), sizeof( ((xthreadInfo *)0)->threadId ) },
	{ NULL, 0 }
};

static classVariableInfo_t idSys_typeInfo[] = {
	{ NULL, 0 }
};

static classVariableInfo_t idLib_typeInfo[] = {
	{ NULL, 0 }
};

static classVariableInfo_t idException_typeInfo[] = {
	{ "char[1024]", "error", (int)(&((idException *)0)->error), sizeof( ((idException *)0)->error ) },
	{ NULL, 0 }
};

static classVariableInfo_t memoryStats_t_typeInfo[] = {
	{ "int", "num", (int)(&((memoryStats_t *)0)->num), sizeof( ((memoryStats_t *)0)->num ) },
	{ "int", "minSize", (int)(&((memoryStats_t *)0)->minSize), sizeof( ((memoryStats_t *)0)->minSize ) },
	{ "int", "maxSize", (int)(&((memoryStats_t *)0)->maxSize), sizeof( ((memoryStats_t *)0)->maxSize ) },
	{ "int", "totalSize", (int)(&((memoryStats_t *)0)->totalSize), sizeof( ((memoryStats_t *)0)->totalSize ) },
	{ NULL, 0 }
};

static classVariableInfo_t idBlockAlloc_class_type_int_blockSize__element_t_typeInfo[] = {
//	{ "element_s *", "next", (int)(&((idBlockAlloc< class type , int blockSize >::element_t *)0)->next), sizeof( ((idBlockAlloc< class type , int blockSize >::element_t *)0)->next ) },
//	{ "type", "t", (int)(&((idBlockAlloc< class type , int blockSize >::element_t *)0)->t), sizeof( ((idBlockAlloc< class type , int blockSize >::element_t *)0)->t ) },
	{ NULL, 0 }
};

static classVariableInfo_t idBlockAlloc_class_type_int_blockSize__block_t_typeInfo[] = {
//	{ "element_t[1]", "elements", (int)(&((idBlockAlloc< class type , int blockSize >::block_t *)0)->elements), sizeof( ((idBlockAlloc< class type , int blockSize >::block_t *)0)->elements ) },
//	{ "block_s *", "next", (int)(&((idBlockAlloc< class type , int blockSize >::block_t *)0)->next), sizeof( ((idBlockAlloc< class type , int blockSize >::block_t *)0)->next ) },
	{ NULL, 0 }
};

static classVariableInfo_t idBlockAlloc_class_type_int_blockSize__typeInfo[] = {
//	{ "block_t *", "blocks", (int)(&((idBlockAlloc< class type , int blockSize > *)0)->blocks), sizeof( ((idBlockAlloc< class type , int blockSize > *)0)->blocks ) },
//	{ "element_t *", "free", (int)(&((idBlockAlloc< class type , int blockSize > *)0)->free), sizeof( ((idBlockAlloc< class type , int blockSize > *)0)->free ) },
//	{ "int", "total", (int)(&((idBlockAlloc< class type , int blockSize > *)0)->total), sizeof( ((idBlockAlloc< class type , int blockSize > *)0)->total ) },
//	{ "int", "active", (int)(&((idBlockAlloc< class type , int blockSize > *)0)->active), sizeof( ((idBlockAlloc< class type , int blockSize > *)0)->active ) },
	{ NULL, 0 }
};

static classVariableInfo_t idDynamicAlloc_class_type_int_baseBlockSize_int_minBlockSize__typeInfo[] = {
//	{ "int", "numUsedBlocks", (int)(&((idDynamicAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->numUsedBlocks), sizeof( ((idDynamicAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->numUsedBlocks ) },
//	{ "int", "usedBlockMemory", (int)(&((idDynamicAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->usedBlockMemory), sizeof( ((idDynamicAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->usedBlockMemory ) },
//	{ "int", "numAllocs", (int)(&((idDynamicAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->numAllocs), sizeof( ((idDynamicAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->numAllocs ) },
//	{ "int", "numResizes", (int)(&((idDynamicAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->numResizes), sizeof( ((idDynamicAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->numResizes ) },
//	{ "int", "numFrees", (int)(&((idDynamicAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->numFrees), sizeof( ((idDynamicAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->numFrees ) },
	{ NULL, 0 }
};

static classVariableInfo_t idBTreeNode_class_objType_class_keyType__typeInfo[] = {
//	{ "keyType", "key", (int)(&((idBTreeNode< class objType , class keyType > *)0)->key), sizeof( ((idBTreeNode< class objType , class keyType > *)0)->key ) },
//	{ "objType *", "object", (int)(&((idBTreeNode< class objType , class keyType > *)0)->object), sizeof( ((idBTreeNode< class objType , class keyType > *)0)->object ) },
//	{ "idBTreeNode *", "parent", (int)(&((idBTreeNode< class objType , class keyType > *)0)->parent), sizeof( ((idBTreeNode< class objType , class keyType > *)0)->parent ) },
//	{ "idBTreeNode *", "next", (int)(&((idBTreeNode< class objType , class keyType > *)0)->next), sizeof( ((idBTreeNode< class objType , class keyType > *)0)->next ) },
//	{ "idBTreeNode *", "prev", (int)(&((idBTreeNode< class objType , class keyType > *)0)->prev), sizeof( ((idBTreeNode< class objType , class keyType > *)0)->prev ) },
//	{ "int", "numChildren", (int)(&((idBTreeNode< class objType , class keyType > *)0)->numChildren), sizeof( ((idBTreeNode< class objType , class keyType > *)0)->numChildren ) },
//	{ "idBTreeNode *", "firstChild", (int)(&((idBTreeNode< class objType , class keyType > *)0)->firstChild), sizeof( ((idBTreeNode< class objType , class keyType > *)0)->firstChild ) },
//	{ "idBTreeNode *", "lastChild", (int)(&((idBTreeNode< class objType , class keyType > *)0)->lastChild), sizeof( ((idBTreeNode< class objType , class keyType > *)0)->lastChild ) },
	{ NULL, 0 }
};

static classVariableInfo_t idBTree_class_objType_class_keyType_int_maxChildrenPerNode__typeInfo[] = {
//	{ "idBTreeNode < objType , keyType > *", "root", (int)(&((idBTree< class objType , class keyType , int maxChildrenPerNode > *)0)->root), sizeof( ((idBTree< class objType , class keyType , int maxChildrenPerNode > *)0)->root ) },
//	{ "idBlockAlloc < idBTreeNode < objType , keyType > , 128 >", "nodeAllocator", (int)(&((idBTree< class objType , class keyType , int maxChildrenPerNode > *)0)->nodeAllocator), sizeof( ((idBTree< class objType , class keyType , int maxChildrenPerNode > *)0)->nodeAllocator ) },
	{ NULL, 0 }
};

static classVariableInfo_t idDynamicBlock_class_type__typeInfo[] = {
//	{ "int", "size", (int)(&((idDynamicBlock< class type > *)0)->size), sizeof( ((idDynamicBlock< class type > *)0)->size ) },
//	{ "idDynamicBlock < type > *", "prev", (int)(&((idDynamicBlock< class type > *)0)->prev), sizeof( ((idDynamicBlock< class type > *)0)->prev ) },
//	{ "idDynamicBlock < type > *", "next", (int)(&((idDynamicBlock< class type > *)0)->next), sizeof( ((idDynamicBlock< class type > *)0)->next ) },
//	{ "idBTreeNode < idDynamicBlock < type > , int > *", "node", (int)(&((idDynamicBlock< class type > *)0)->node), sizeof( ((idDynamicBlock< class type > *)0)->node ) },
	{ NULL, 0 }
};

static classVariableInfo_t idDynamicBlockAlloc_class_type_int_baseBlockSize_int_minBlockSize__typeInfo[] = {
//	{ "idDynamicBlock < type > *", "firstBlock", (int)(&((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->firstBlock), sizeof( ((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->firstBlock ) },
//	{ "idDynamicBlock < type > *", "lastBlock", (int)(&((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->lastBlock), sizeof( ((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->lastBlock ) },
//	{ "idBTree < idDynamicBlock < type > , int , 4 >", "freeTree", (int)(&((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->freeTree), sizeof( ((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->freeTree ) },
//	{ "bool", "allowAllocs", (int)(&((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->allowAllocs), sizeof( ((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->allowAllocs ) },
//	{ "bool", "lockMemory", (int)(&((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->lockMemory), sizeof( ((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->lockMemory ) },
//	{ "int", "numBaseBlocks", (int)(&((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->numBaseBlocks), sizeof( ((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->numBaseBlocks ) },
//	{ "int", "baseBlockMemory", (int)(&((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->baseBlockMemory), sizeof( ((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->baseBlockMemory ) },
//	{ "int", "numUsedBlocks", (int)(&((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->numUsedBlocks), sizeof( ((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->numUsedBlocks ) },
//	{ "int", "usedBlockMemory", (int)(&((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->usedBlockMemory), sizeof( ((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->usedBlockMemory ) },
//	{ "int", "numFreeBlocks", (int)(&((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->numFreeBlocks), sizeof( ((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->numFreeBlocks ) },
//	{ "int", "freeBlockMemory", (int)(&((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->freeBlockMemory), sizeof( ((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->freeBlockMemory ) },
//	{ "int", "numAllocs", (int)(&((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->numAllocs), sizeof( ((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->numAllocs ) },
//	{ "int", "numResizes", (int)(&((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->numResizes), sizeof( ((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->numResizes ) },
//	{ "int", "numFrees", (int)(&((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->numFrees), sizeof( ((idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize > *)0)->numFrees ) },
	{ NULL, 0 }
};

static classVariableInfo_t idList_class_type__typeInfo[] = {
//	{ "int", "num", (int)(&((idList< class type > *)0)->num), sizeof( ((idList< class type > *)0)->num ) },
//	{ "int", "size", (int)(&((idList< class type > *)0)->size), sizeof( ((idList< class type > *)0)->size ) },
//	{ "int", "granularity", (int)(&((idList< class type > *)0)->granularity), sizeof( ((idList< class type > *)0)->granularity ) },
//	{ "type *", "list", (int)(&((idList< class type > *)0)->list), sizeof( ((idList< class type > *)0)->list ) },
	{ NULL, 0 }
};

static classVariableInfo_t idSIMD_typeInfo[] = {
	{ NULL, 0 }
};

static classVariableInfo_t idSIMDProcessor_typeInfo[] = {
	{ "cpuid_t", "cpuid", (int)(&((idSIMDProcessor *)0)->cpuid), sizeof( ((idSIMDProcessor *)0)->cpuid ) },
	{ NULL, 0 }
};

static classVariableInfo_t idMath__flint_typeInfo[] = {
	{ "dword", "i", (int)(&((idMath::_flint *)0)->i), sizeof( ((idMath::_flint *)0)->i ) },
	{ "float", "f", (int)(&((idMath::_flint *)0)->f), sizeof( ((idMath::_flint *)0)->f ) },
	{ NULL, 0 }
};

static classVariableInfo_t idMath_typeInfo[] = {
	{ NULL, 0 }
};

static classVariableInfo_t idRandom_typeInfo[] = {
	{ "int", "seed", (int)(&((idRandom *)0)->seed), sizeof( ((idRandom *)0)->seed ) },
	{ NULL, 0 }
};

static classVariableInfo_t idRandom2_typeInfo[] = {
	{ "unsigned long", "seed", (int)(&((idRandom2 *)0)->seed), sizeof( ((idRandom2 *)0)->seed ) },
	{ NULL, 0 }
};

static classVariableInfo_t idComplex_typeInfo[] = {
	{ "float", "r", (int)(&((idComplex *)0)->r), sizeof( ((idComplex *)0)->r ) },
	{ "float", "i", (int)(&((idComplex *)0)->i), sizeof( ((idComplex *)0)->i ) },
	{ NULL, 0 }
};

static classVariableInfo_t idVec2_typeInfo[] = {
	{ "float", "x", (int)(&((idVec2 *)0)->x), sizeof( ((idVec2 *)0)->x ) },
	{ "float", "y", (int)(&((idVec2 *)0)->y), sizeof( ((idVec2 *)0)->y ) },
	{ NULL, 0 }
};

static classVariableInfo_t idVec3_typeInfo[] = {
	{ "float", "x", (int)(&((idVec3 *)0)->x), sizeof( ((idVec3 *)0)->x ) },
	{ "float", "y", (int)(&((idVec3 *)0)->y), sizeof( ((idVec3 *)0)->y ) },
	{ "float", "z", (int)(&((idVec3 *)0)->z), sizeof( ((idVec3 *)0)->z ) },
	{ NULL, 0 }
};

static classVariableInfo_t idVec4_typeInfo[] = {
	{ "float", "x", (int)(&((idVec4 *)0)->x), sizeof( ((idVec4 *)0)->x ) },
	{ "float", "y", (int)(&((idVec4 *)0)->y), sizeof( ((idVec4 *)0)->y ) },
	{ "float", "z", (int)(&((idVec4 *)0)->z), sizeof( ((idVec4 *)0)->z ) },
	{ "float", "w", (int)(&((idVec4 *)0)->w), sizeof( ((idVec4 *)0)->w ) },
	{ NULL, 0 }
};

static classVariableInfo_t idVec5_typeInfo[] = {
	{ "float", "x", (int)(&((idVec5 *)0)->x), sizeof( ((idVec5 *)0)->x ) },
	{ "float", "y", (int)(&((idVec5 *)0)->y), sizeof( ((idVec5 *)0)->y ) },
	{ "float", "z", (int)(&((idVec5 *)0)->z), sizeof( ((idVec5 *)0)->z ) },
	{ "float", "s", (int)(&((idVec5 *)0)->s), sizeof( ((idVec5 *)0)->s ) },
	{ "float", "t", (int)(&((idVec5 *)0)->t), sizeof( ((idVec5 *)0)->t ) },
	{ NULL, 0 }
};

static classVariableInfo_t idVec6_typeInfo[] = {
	{ "float[6]", "p", (int)(&((idVec6 *)0)->p), sizeof( ((idVec6 *)0)->p ) },
	{ NULL, 0 }
};

static classVariableInfo_t idVecX_typeInfo[] = {
	{ "int", "size", (int)(&((idVecX *)0)->size), sizeof( ((idVecX *)0)->size ) },
	{ "int", "alloced", (int)(&((idVecX *)0)->alloced), sizeof( ((idVecX *)0)->alloced ) },
	{ "float *", "p", (int)(&((idVecX *)0)->p), sizeof( ((idVecX *)0)->p ) },
	{ NULL, 0 }
};

static classVariableInfo_t idPolar3_typeInfo[] = {
	{ "float", "radius", (int)(&((idPolar3 *)0)->radius), sizeof( ((idPolar3 *)0)->radius ) },
	{ "float", "theta", (int)(&((idPolar3 *)0)->theta), sizeof( ((idPolar3 *)0)->theta ) },
	{ "float", "phi", (int)(&((idPolar3 *)0)->phi), sizeof( ((idPolar3 *)0)->phi ) },
	{ NULL, 0 }
};

static classVariableInfo_t idMat2_typeInfo[] = {
	{ "idVec2[2]", "mat", (int)(&((idMat2 *)0)->mat), sizeof( ((idMat2 *)0)->mat ) },
	{ NULL, 0 }
};

static classVariableInfo_t idMat3_typeInfo[] = {
	{ "idVec3[3]", "mat", (int)(&((idMat3 *)0)->mat), sizeof( ((idMat3 *)0)->mat ) },
	{ NULL, 0 }
};

static classVariableInfo_t idMat4_typeInfo[] = {
	{ "idVec4[4]", "mat", (int)(&((idMat4 *)0)->mat), sizeof( ((idMat4 *)0)->mat ) },
	{ NULL, 0 }
};

static classVariableInfo_t idMat5_typeInfo[] = {
	{ "idVec5[5]", "mat", (int)(&((idMat5 *)0)->mat), sizeof( ((idMat5 *)0)->mat ) },
	{ NULL, 0 }
};

static classVariableInfo_t idMat6_typeInfo[] = {
	{ "idVec6[6]", "mat", (int)(&((idMat6 *)0)->mat), sizeof( ((idMat6 *)0)->mat ) },
	{ NULL, 0 }
};

static classVariableInfo_t idMatX_typeInfo[] = {
	{ "int", "numRows", (int)(&((idMatX *)0)->numRows), sizeof( ((idMatX *)0)->numRows ) },
	{ "int", "numColumns", (int)(&((idMatX *)0)->numColumns), sizeof( ((idMatX *)0)->numColumns ) },
	{ "int", "alloced", (int)(&((idMatX *)0)->alloced), sizeof( ((idMatX *)0)->alloced ) },
	{ "float *", "mat", (int)(&((idMatX *)0)->mat), sizeof( ((idMatX *)0)->mat ) },
	{ NULL, 0 }
};

static classVariableInfo_t idAngles_typeInfo[] = {
	{ "float", "pitch", (int)(&((idAngles *)0)->pitch), sizeof( ((idAngles *)0)->pitch ) },
	{ "float", "yaw", (int)(&((idAngles *)0)->yaw), sizeof( ((idAngles *)0)->yaw ) },
	{ "float", "roll", (int)(&((idAngles *)0)->roll), sizeof( ((idAngles *)0)->roll ) },
	{ NULL, 0 }
};

static classVariableInfo_t idQuat_typeInfo[] = {
	{ "float", "x", (int)(&((idQuat *)0)->x), sizeof( ((idQuat *)0)->x ) },
	{ "float", "y", (int)(&((idQuat *)0)->y), sizeof( ((idQuat *)0)->y ) },
	{ "float", "z", (int)(&((idQuat *)0)->z), sizeof( ((idQuat *)0)->z ) },
	{ "float", "w", (int)(&((idQuat *)0)->w), sizeof( ((idQuat *)0)->w ) },
	{ NULL, 0 }
};

static classVariableInfo_t idCQuat_typeInfo[] = {
	{ "float", "x", (int)(&((idCQuat *)0)->x), sizeof( ((idCQuat *)0)->x ) },
	{ "float", "y", (int)(&((idCQuat *)0)->y), sizeof( ((idCQuat *)0)->y ) },
	{ "float", "z", (int)(&((idCQuat *)0)->z), sizeof( ((idCQuat *)0)->z ) },
	{ NULL, 0 }
};

static classVariableInfo_t idRotation_typeInfo[] = {
	{ "idVec3", "origin", (int)(&((idRotation *)0)->origin), sizeof( ((idRotation *)0)->origin ) },
	{ "idVec3", "vec", (int)(&((idRotation *)0)->vec), sizeof( ((idRotation *)0)->vec ) },
	{ "float", "angle", (int)(&((idRotation *)0)->angle), sizeof( ((idRotation *)0)->angle ) },
	{ "mutable idMat3", "axis", (int)(&((idRotation *)0)->axis), sizeof( ((idRotation *)0)->axis ) },
	{ "mutable bool", "axisValid", (int)(&((idRotation *)0)->axisValid), sizeof( ((idRotation *)0)->axisValid ) },
	{ NULL, 0 }
};

static classVariableInfo_t idPlane_typeInfo[] = {
	{ "float", "a", (int)(&((idPlane *)0)->a), sizeof( ((idPlane *)0)->a ) },
	{ "float", "b", (int)(&((idPlane *)0)->b), sizeof( ((idPlane *)0)->b ) },
	{ "float", "c", (int)(&((idPlane *)0)->c), sizeof( ((idPlane *)0)->c ) },
	{ "float", "d", (int)(&((idPlane *)0)->d), sizeof( ((idPlane *)0)->d ) },
	{ NULL, 0 }
};

static classVariableInfo_t idPluecker_typeInfo[] = {
	{ "float[6]", "p", (int)(&((idPluecker *)0)->p), sizeof( ((idPluecker *)0)->p ) },
	{ NULL, 0 }
};

static classVariableInfo_t idPolynomial_typeInfo[] = {
	{ "int", "degree", (int)(&((idPolynomial *)0)->degree), sizeof( ((idPolynomial *)0)->degree ) },
	{ "int", "allocated", (int)(&((idPolynomial *)0)->allocated), sizeof( ((idPolynomial *)0)->allocated ) },
	{ "float *", "coefficient", (int)(&((idPolynomial *)0)->coefficient), sizeof( ((idPolynomial *)0)->coefficient ) },
	{ NULL, 0 }
};

static classVariableInfo_t idExtrapolate_class_type__typeInfo[] = {
//	{ "extrapolation_t", "extrapolationType", (int)(&((idExtrapolate< class type > *)0)->extrapolationType), sizeof( ((idExtrapolate< class type > *)0)->extrapolationType ) },
//	{ "float", "startTime", (int)(&((idExtrapolate< class type > *)0)->startTime), sizeof( ((idExtrapolate< class type > *)0)->startTime ) },
//	{ "float", "duration", (int)(&((idExtrapolate< class type > *)0)->duration), sizeof( ((idExtrapolate< class type > *)0)->duration ) },
//	{ "type", "startValue", (int)(&((idExtrapolate< class type > *)0)->startValue), sizeof( ((idExtrapolate< class type > *)0)->startValue ) },
//	{ "type", "baseSpeed", (int)(&((idExtrapolate< class type > *)0)->baseSpeed), sizeof( ((idExtrapolate< class type > *)0)->baseSpeed ) },
//	{ "type", "speed", (int)(&((idExtrapolate< class type > *)0)->speed), sizeof( ((idExtrapolate< class type > *)0)->speed ) },
//	{ "mutable float", "currentTime", (int)(&((idExtrapolate< class type > *)0)->currentTime), sizeof( ((idExtrapolate< class type > *)0)->currentTime ) },
//	{ "mutable type", "currentValue", (int)(&((idExtrapolate< class type > *)0)->currentValue), sizeof( ((idExtrapolate< class type > *)0)->currentValue ) },
	{ NULL, 0 }
};

static classVariableInfo_t idInterpolate_class_type__typeInfo[] = {
//	{ "float", "startTime", (int)(&((idInterpolate< class type > *)0)->startTime), sizeof( ((idInterpolate< class type > *)0)->startTime ) },
//	{ "float", "duration", (int)(&((idInterpolate< class type > *)0)->duration), sizeof( ((idInterpolate< class type > *)0)->duration ) },
//	{ "type", "startValue", (int)(&((idInterpolate< class type > *)0)->startValue), sizeof( ((idInterpolate< class type > *)0)->startValue ) },
//	{ "type", "endValue", (int)(&((idInterpolate< class type > *)0)->endValue), sizeof( ((idInterpolate< class type > *)0)->endValue ) },
//	{ "mutable float", "currentTime", (int)(&((idInterpolate< class type > *)0)->currentTime), sizeof( ((idInterpolate< class type > *)0)->currentTime ) },
//	{ "mutable type", "currentValue", (int)(&((idInterpolate< class type > *)0)->currentValue), sizeof( ((idInterpolate< class type > *)0)->currentValue ) },
	{ NULL, 0 }
};

static classVariableInfo_t idInterpolateAccelDecelLinear_class_type__typeInfo[] = {
//	{ "float", "startTime", (int)(&((idInterpolateAccelDecelLinear< class type > *)0)->startTime), sizeof( ((idInterpolateAccelDecelLinear< class type > *)0)->startTime ) },
//	{ "float", "accelTime", (int)(&((idInterpolateAccelDecelLinear< class type > *)0)->accelTime), sizeof( ((idInterpolateAccelDecelLinear< class type > *)0)->accelTime ) },
//	{ "float", "linearTime", (int)(&((idInterpolateAccelDecelLinear< class type > *)0)->linearTime), sizeof( ((idInterpolateAccelDecelLinear< class type > *)0)->linearTime ) },
//	{ "float", "decelTime", (int)(&((idInterpolateAccelDecelLinear< class type > *)0)->decelTime), sizeof( ((idInterpolateAccelDecelLinear< class type > *)0)->decelTime ) },
//	{ "type", "startValue", (int)(&((idInterpolateAccelDecelLinear< class type > *)0)->startValue), sizeof( ((idInterpolateAccelDecelLinear< class type > *)0)->startValue ) },
//	{ "type", "endValue", (int)(&((idInterpolateAccelDecelLinear< class type > *)0)->endValue), sizeof( ((idInterpolateAccelDecelLinear< class type > *)0)->endValue ) },
//	{ "mutable idExtrapolate < type >", "extrapolate", (int)(&((idInterpolateAccelDecelLinear< class type > *)0)->extrapolate), sizeof( ((idInterpolateAccelDecelLinear< class type > *)0)->extrapolate ) },
	{ NULL, 0 }
};

static classVariableInfo_t idInterpolateAccelDecelSine_class_type__typeInfo[] = {
//	{ "float", "startTime", (int)(&((idInterpolateAccelDecelSine< class type > *)0)->startTime), sizeof( ((idInterpolateAccelDecelSine< class type > *)0)->startTime ) },
//	{ "float", "accelTime", (int)(&((idInterpolateAccelDecelSine< class type > *)0)->accelTime), sizeof( ((idInterpolateAccelDecelSine< class type > *)0)->accelTime ) },
//	{ "float", "linearTime", (int)(&((idInterpolateAccelDecelSine< class type > *)0)->linearTime), sizeof( ((idInterpolateAccelDecelSine< class type > *)0)->linearTime ) },
//	{ "float", "decelTime", (int)(&((idInterpolateAccelDecelSine< class type > *)0)->decelTime), sizeof( ((idInterpolateAccelDecelSine< class type > *)0)->decelTime ) },
//	{ "type", "startValue", (int)(&((idInterpolateAccelDecelSine< class type > *)0)->startValue), sizeof( ((idInterpolateAccelDecelSine< class type > *)0)->startValue ) },
//	{ "type", "endValue", (int)(&((idInterpolateAccelDecelSine< class type > *)0)->endValue), sizeof( ((idInterpolateAccelDecelSine< class type > *)0)->endValue ) },
//	{ "mutable idExtrapolate < type >", "extrapolate", (int)(&((idInterpolateAccelDecelSine< class type > *)0)->extrapolate), sizeof( ((idInterpolateAccelDecelSine< class type > *)0)->extrapolate ) },
	{ NULL, 0 }
};

static classVariableInfo_t idCurve_class_type__typeInfo[] = {
//	{ "idList < float >", "times", (int)(&((idCurve< class type > *)0)->times), sizeof( ((idCurve< class type > *)0)->times ) },
//	{ "idList < type >", "values", (int)(&((idCurve< class type > *)0)->values), sizeof( ((idCurve< class type > *)0)->values ) },
//	{ "mutable int", "currentIndex", (int)(&((idCurve< class type > *)0)->currentIndex), sizeof( ((idCurve< class type > *)0)->currentIndex ) },
//	{ "mutable bool", "changed", (int)(&((idCurve< class type > *)0)->changed), sizeof( ((idCurve< class type > *)0)->changed ) },
	{ NULL, 0 }
};

static classVariableInfo_t idCurve_Bezier_class_type__typeInfo[] = {
	{ NULL, 0 }
};

static classVariableInfo_t idCurve_QuadraticBezier_class_type__typeInfo[] = {
	{ NULL, 0 }
};

static classVariableInfo_t idCurve_CubicBezier_class_type__typeInfo[] = {
	{ NULL, 0 }
};

static classVariableInfo_t idCurve_Spline_class_type__typeInfo[] = {
//	{ "boundary_t", "boundaryType", (int)(&((idCurve_Spline< class type > *)0)->boundaryType), sizeof( ((idCurve_Spline< class type > *)0)->boundaryType ) },
//	{ "float", "closeTime", (int)(&((idCurve_Spline< class type > *)0)->closeTime), sizeof( ((idCurve_Spline< class type > *)0)->closeTime ) },
	{ NULL, 0 }
};

static classVariableInfo_t idCurve_NaturalCubicSpline_class_type__typeInfo[] = {
//	{ "mutable idList < type >", "b", (int)(&((idCurve_NaturalCubicSpline< class type > *)0)->b), sizeof( ((idCurve_NaturalCubicSpline< class type > *)0)->b ) },
//	{ "mutable idList < type >", "c", (int)(&((idCurve_NaturalCubicSpline< class type > *)0)->c), sizeof( ((idCurve_NaturalCubicSpline< class type > *)0)->c ) },
//	{ "mutable idList < type >", "d", (int)(&((idCurve_NaturalCubicSpline< class type > *)0)->d), sizeof( ((idCurve_NaturalCubicSpline< class type > *)0)->d ) },
	{ NULL, 0 }
};

static classVariableInfo_t idCurve_CatmullRomSpline_class_type__typeInfo[] = {
	{ NULL, 0 }
};

static classVariableInfo_t idCurve_KochanekBartelsSpline_class_type__typeInfo[] = {
//	{ "idList < float >", "tension", (int)(&((idCurve_KochanekBartelsSpline< class type > *)0)->tension), sizeof( ((idCurve_KochanekBartelsSpline< class type > *)0)->tension ) },
//	{ "idList < float >", "continuity", (int)(&((idCurve_KochanekBartelsSpline< class type > *)0)->continuity), sizeof( ((idCurve_KochanekBartelsSpline< class type > *)0)->continuity ) },
//	{ "idList < float >", "bias", (int)(&((idCurve_KochanekBartelsSpline< class type > *)0)->bias), sizeof( ((idCurve_KochanekBartelsSpline< class type > *)0)->bias ) },
	{ NULL, 0 }
};

static classVariableInfo_t idCurve_BSpline_class_type__typeInfo[] = {
//	{ "int", "order", (int)(&((idCurve_BSpline< class type > *)0)->order), sizeof( ((idCurve_BSpline< class type > *)0)->order ) },
	{ NULL, 0 }
};

static classVariableInfo_t idCurve_UniformCubicBSpline_class_type__typeInfo[] = {
	{ NULL, 0 }
};

static classVariableInfo_t idCurve_NonUniformBSpline_class_type__typeInfo[] = {
	{ NULL, 0 }
};

static classVariableInfo_t idCurve_NURBS_class_type__typeInfo[] = {
//	{ "idList < float >", "weights", (int)(&((idCurve_NURBS< class type > *)0)->weights), sizeof( ((idCurve_NURBS< class type > *)0)->weights ) },
	{ NULL, 0 }
};

static classVariableInfo_t idODE_typeInfo[] = {
	{ "int", "dimension", (int)(&((idODE *)0)->dimension), sizeof( ((idODE *)0)->dimension ) },
	{ "deriveFunction_t", "derive", (int)(&((idODE *)0)->derive), sizeof( ((idODE *)0)->derive ) },
	{ "const void *", "userData", (int)(&((idODE *)0)->userData), sizeof( ((idODE *)0)->userData ) },
	{ NULL, 0 }
};

static classVariableInfo_t idODE_Euler_typeInfo[] = {
	{ "float *", "derivatives", (int)(&((idODE_Euler *)0)->derivatives), sizeof( ((idODE_Euler *)0)->derivatives ) },
	{ NULL, 0 }
};

static classVariableInfo_t idODE_Midpoint_typeInfo[] = {
	{ "float *", "tmpState", (int)(&((idODE_Midpoint *)0)->tmpState), sizeof( ((idODE_Midpoint *)0)->tmpState ) },
	{ "float *", "derivatives", (int)(&((idODE_Midpoint *)0)->derivatives), sizeof( ((idODE_Midpoint *)0)->derivatives ) },
	{ NULL, 0 }
};

static classVariableInfo_t idODE_RK4_typeInfo[] = {
	{ "float *", "tmpState", (int)(&((idODE_RK4 *)0)->tmpState), sizeof( ((idODE_RK4 *)0)->tmpState ) },
	{ "float *", "d1", (int)(&((idODE_RK4 *)0)->d1), sizeof( ((idODE_RK4 *)0)->d1 ) },
	{ "float *", "d2", (int)(&((idODE_RK4 *)0)->d2), sizeof( ((idODE_RK4 *)0)->d2 ) },
	{ "float *", "d3", (int)(&((idODE_RK4 *)0)->d3), sizeof( ((idODE_RK4 *)0)->d3 ) },
	{ "float *", "d4", (int)(&((idODE_RK4 *)0)->d4), sizeof( ((idODE_RK4 *)0)->d4 ) },
	{ NULL, 0 }
};

static classVariableInfo_t idODE_RK4Adaptive_typeInfo[] = {
	{ "float", "maxError", (int)(&((idODE_RK4Adaptive *)0)->maxError), sizeof( ((idODE_RK4Adaptive *)0)->maxError ) },
	{ "float *", "tmpState", (int)(&((idODE_RK4Adaptive *)0)->tmpState), sizeof( ((idODE_RK4Adaptive *)0)->tmpState ) },
	{ "float *", "d1", (int)(&((idODE_RK4Adaptive *)0)->d1), sizeof( ((idODE_RK4Adaptive *)0)->d1 ) },
	{ "float *", "d1half", (int)(&((idODE_RK4Adaptive *)0)->d1half), sizeof( ((idODE_RK4Adaptive *)0)->d1half ) },
	{ "float *", "d2", (int)(&((idODE_RK4Adaptive *)0)->d2), sizeof( ((idODE_RK4Adaptive *)0)->d2 ) },
	{ "float *", "d3", (int)(&((idODE_RK4Adaptive *)0)->d3), sizeof( ((idODE_RK4Adaptive *)0)->d3 ) },
	{ "float *", "d4", (int)(&((idODE_RK4Adaptive *)0)->d4), sizeof( ((idODE_RK4Adaptive *)0)->d4 ) },
	{ NULL, 0 }
};

static classVariableInfo_t idLCP_typeInfo[] = {
	{ "int", "maxIterations", (int)(&((idLCP *)0)->maxIterations), sizeof( ((idLCP *)0)->maxIterations ) },
	{ NULL, 0 }
};

static classVariableInfo_t idSphere_typeInfo[] = {
	{ "idVec3", "origin", (int)(&((idSphere *)0)->origin), sizeof( ((idSphere *)0)->origin ) },
	{ "float", "radius", (int)(&((idSphere *)0)->radius), sizeof( ((idSphere *)0)->radius ) },
	{ NULL, 0 }
};

static classVariableInfo_t idBounds_typeInfo[] = {
	{ "idVec3[2]", "b", (int)(&((idBounds *)0)->b), sizeof( ((idBounds *)0)->b ) },
	{ NULL, 0 }
};

static classVariableInfo_t idBox_typeInfo[] = {
	{ "idVec3", "center", (int)(&((idBox *)0)->center), sizeof( ((idBox *)0)->center ) },
	{ "idVec3", "extents", (int)(&((idBox *)0)->extents), sizeof( ((idBox *)0)->extents ) },
	{ "idMat3", "axis", (int)(&((idBox *)0)->axis), sizeof( ((idBox *)0)->axis ) },
	{ NULL, 0 }
};

static classVariableInfo_t idFrustum_typeInfo[] = {
	{ "idVec3", "origin", (int)(&((idFrustum *)0)->origin), sizeof( ((idFrustum *)0)->origin ) },
	{ "idMat3", "axis", (int)(&((idFrustum *)0)->axis), sizeof( ((idFrustum *)0)->axis ) },
	{ "float", "dNear", (int)(&((idFrustum *)0)->dNear), sizeof( ((idFrustum *)0)->dNear ) },
	{ "float", "dFar", (int)(&((idFrustum *)0)->dFar), sizeof( ((idFrustum *)0)->dFar ) },
	{ "float", "dLeft", (int)(&((idFrustum *)0)->dLeft), sizeof( ((idFrustum *)0)->dLeft ) },
	{ "float", "dUp", (int)(&((idFrustum *)0)->dUp), sizeof( ((idFrustum *)0)->dUp ) },
	{ "float", "invFar", (int)(&((idFrustum *)0)->invFar), sizeof( ((idFrustum *)0)->invFar ) },
	{ NULL, 0 }
};

static classVariableInfo_t idDrawVert_typeInfo[] = {
	{ "idVec3", "xyz", (int)(&((idDrawVert *)0)->xyz), sizeof( ((idDrawVert *)0)->xyz ) },
	{ "idVec2", "st", (int)(&((idDrawVert *)0)->st), sizeof( ((idDrawVert *)0)->st ) },
	{ "idVec3", "normal", (int)(&((idDrawVert *)0)->normal), sizeof( ((idDrawVert *)0)->normal ) },
	{ "idVec3[2]", "tangents", (int)(&((idDrawVert *)0)->tangents), sizeof( ((idDrawVert *)0)->tangents ) },
	{ "byte[4]", "color", (int)(&((idDrawVert *)0)->color), sizeof( ((idDrawVert *)0)->color ) },
	{ NULL, 0 }
};

static classVariableInfo_t idJointQuat_typeInfo[] = {
	{ "idQuat", "q", (int)(&((idJointQuat *)0)->q), sizeof( ((idJointQuat *)0)->q ) },
	{ "idVec3", "t", (int)(&((idJointQuat *)0)->t), sizeof( ((idJointQuat *)0)->t ) },
	{ NULL, 0 }
};

static classVariableInfo_t idJointMat_typeInfo[] = {
	{ "float[12]", "mat", (int)(&((idJointMat *)0)->mat), sizeof( ((idJointMat *)0)->mat ) },
	{ NULL, 0 }
};

static classVariableInfo_t idWinding_typeInfo[] = {
	{ "int", "numPoints", (int)(&((idWinding *)0)->numPoints), sizeof( ((idWinding *)0)->numPoints ) },
	{ "idVec5 *", "p", (int)(&((idWinding *)0)->p), sizeof( ((idWinding *)0)->p ) },
	{ "int", "allocedSize", (int)(&((idWinding *)0)->allocedSize), sizeof( ((idWinding *)0)->allocedSize ) },
	{ NULL, 0 }
};

static classVariableInfo_t idFixedWinding_typeInfo[] = {
	{ "idVec5[64]", "data", (int)(&((idFixedWinding *)0)->data), sizeof( ((idFixedWinding *)0)->data ) },
	{ NULL, 0 }
};

static classVariableInfo_t idWinding2D_typeInfo[] = {
	{ "int", "numPoints", (int)(&((idWinding2D *)0)->numPoints), sizeof( ((idWinding2D *)0)->numPoints ) },
	{ "idVec2[16]", "p", (int)(&((idWinding2D *)0)->p), sizeof( ((idWinding2D *)0)->p ) },
	{ NULL, 0 }
};

static classVariableInfo_t surfaceEdge_t_typeInfo[] = {
	{ "int[2]", "verts", (int)(&((surfaceEdge_t *)0)->verts), sizeof( ((surfaceEdge_t *)0)->verts ) },
	{ "int[2]", "tris", (int)(&((surfaceEdge_t *)0)->tris), sizeof( ((surfaceEdge_t *)0)->tris ) },
	{ NULL, 0 }
};

static classVariableInfo_t idSurface_typeInfo[] = {
	{ "idList < idDrawVert >", "verts", (int)(&((idSurface *)0)->verts), sizeof( ((idSurface *)0)->verts ) },
	{ "idList < int >", "indexes", (int)(&((idSurface *)0)->indexes), sizeof( ((idSurface *)0)->indexes ) },
	{ "idList < surfaceEdge_t >", "edges", (int)(&((idSurface *)0)->edges), sizeof( ((idSurface *)0)->edges ) },
	{ "idList < int >", "edgeIndexes", (int)(&((idSurface *)0)->edgeIndexes), sizeof( ((idSurface *)0)->edgeIndexes ) },
	{ NULL, 0 }
};

static classVariableInfo_t idSurface_Patch_typeInfo[] = {
	{ "int", "width", (int)(&((idSurface_Patch *)0)->width), sizeof( ((idSurface_Patch *)0)->width ) },
	{ "int", "height", (int)(&((idSurface_Patch *)0)->height), sizeof( ((idSurface_Patch *)0)->height ) },
	{ "int", "maxWidth", (int)(&((idSurface_Patch *)0)->maxWidth), sizeof( ((idSurface_Patch *)0)->maxWidth ) },
	{ "int", "maxHeight", (int)(&((idSurface_Patch *)0)->maxHeight), sizeof( ((idSurface_Patch *)0)->maxHeight ) },
	{ "bool", "expanded", (int)(&((idSurface_Patch *)0)->expanded), sizeof( ((idSurface_Patch *)0)->expanded ) },
	{ NULL, 0 }
};

static classVariableInfo_t idSurface_Polytope_typeInfo[] = {
	{ NULL, 0 }
};

static classVariableInfo_t idSurface_SweptSpline_typeInfo[] = {
	{ "idCurve_Spline < idVec4 > *", "spline", (int)(&((idSurface_SweptSpline *)0)->spline), sizeof( ((idSurface_SweptSpline *)0)->spline ) },
	{ "idCurve_Spline < idVec4 > *", "sweptSpline", (int)(&((idSurface_SweptSpline *)0)->sweptSpline), sizeof( ((idSurface_SweptSpline *)0)->sweptSpline ) },
	{ NULL, 0 }
};

static classVariableInfo_t traceModelEdge_t_typeInfo[] = {
	{ "int[2]", "v", (int)(&((traceModelEdge_t *)0)->v), sizeof( ((traceModelEdge_t *)0)->v ) },
	{ "idVec3", "normal", (int)(&((traceModelEdge_t *)0)->normal), sizeof( ((traceModelEdge_t *)0)->normal ) },
	{ NULL, 0 }
};

static classVariableInfo_t traceModelPoly_t_typeInfo[] = {
	{ "idVec3", "normal", (int)(&((traceModelPoly_t *)0)->normal), sizeof( ((traceModelPoly_t *)0)->normal ) },
	{ "float", "dist", (int)(&((traceModelPoly_t *)0)->dist), sizeof( ((traceModelPoly_t *)0)->dist ) },
	{ "idBounds", "bounds", (int)(&((traceModelPoly_t *)0)->bounds), sizeof( ((traceModelPoly_t *)0)->bounds ) },
	{ "int", "numEdges", (int)(&((traceModelPoly_t *)0)->numEdges), sizeof( ((traceModelPoly_t *)0)->numEdges ) },
	{ "int[16]", "edges", (int)(&((traceModelPoly_t *)0)->edges), sizeof( ((traceModelPoly_t *)0)->edges ) },
	{ NULL, 0 }
};

static classVariableInfo_t idTraceModel_typeInfo[] = {
	{ "traceModel_t", "type", (int)(&((idTraceModel *)0)->type), sizeof( ((idTraceModel *)0)->type ) },
	{ "int", "numVerts", (int)(&((idTraceModel *)0)->numVerts), sizeof( ((idTraceModel *)0)->numVerts ) },
	{ "traceModelVert_t[32]", "verts", (int)(&((idTraceModel *)0)->verts), sizeof( ((idTraceModel *)0)->verts ) },
	{ "int", "numEdges", (int)(&((idTraceModel *)0)->numEdges), sizeof( ((idTraceModel *)0)->numEdges ) },
	{ "traceModelEdge_t[33]", "edges", (int)(&((idTraceModel *)0)->edges), sizeof( ((idTraceModel *)0)->edges ) },
	{ "int", "numPolys", (int)(&((idTraceModel *)0)->numPolys), sizeof( ((idTraceModel *)0)->numPolys ) },
	{ "traceModelPoly_t[16]", "polys", (int)(&((idTraceModel *)0)->polys), sizeof( ((idTraceModel *)0)->polys ) },
	{ "idVec3", "offset", (int)(&((idTraceModel *)0)->offset), sizeof( ((idTraceModel *)0)->offset ) },
	{ "idBounds", "bounds", (int)(&((idTraceModel *)0)->bounds), sizeof( ((idTraceModel *)0)->bounds ) },
	{ "bool", "isConvex", (int)(&((idTraceModel *)0)->isConvex), sizeof( ((idTraceModel *)0)->isConvex ) },
	{ NULL, 0 }
};

static classVariableInfo_t idStr_typeInfo[] = {
	{ "int", "len", (int)(&((idStr *)0)->len), sizeof( ((idStr *)0)->len ) },
	{ "char *", "data", (int)(&((idStr *)0)->data), sizeof( ((idStr *)0)->data ) },
	{ "int", "alloced", (int)(&((idStr *)0)->alloced), sizeof( ((idStr *)0)->alloced ) },
	{ "char[20]", "baseBuffer", (int)(&((idStr *)0)->baseBuffer), sizeof( ((idStr *)0)->baseBuffer ) },
	{ NULL, 0 }
};

static classVariableInfo_t idToken_typeInfo[] = {
	{ "int", "type", (int)(&((idToken *)0)->type), sizeof( ((idToken *)0)->type ) },
	{ "int", "subtype", (int)(&((idToken *)0)->subtype), sizeof( ((idToken *)0)->subtype ) },
	{ "int", "line", (int)(&((idToken *)0)->line), sizeof( ((idToken *)0)->line ) },
	{ "int", "linesCrossed", (int)(&((idToken *)0)->linesCrossed), sizeof( ((idToken *)0)->linesCrossed ) },
	{ "int", "flags", (int)(&((idToken *)0)->flags), sizeof( ((idToken *)0)->flags ) },
	{ "unsigned long", "intvalue", (int)(&((idToken *)0)->intvalue), sizeof( ((idToken *)0)->intvalue ) },
	{ "double", "floatvalue", (int)(&((idToken *)0)->floatvalue), sizeof( ((idToken *)0)->floatvalue ) },
	{ "const char *", "whiteSpaceStart_p", (int)(&((idToken *)0)->whiteSpaceStart_p), sizeof( ((idToken *)0)->whiteSpaceStart_p ) },
	{ "const char *", "whiteSpaceEnd_p", (int)(&((idToken *)0)->whiteSpaceEnd_p), sizeof( ((idToken *)0)->whiteSpaceEnd_p ) },
	{ "idToken *", "next", (int)(&((idToken *)0)->next), sizeof( ((idToken *)0)->next ) },
	{ NULL, 0 }
};

static classVariableInfo_t punctuation_t_typeInfo[] = {
	{ "const char *", "p", (int)(&((punctuation_t *)0)->p), sizeof( ((punctuation_t *)0)->p ) },
	{ "int", "n", (int)(&((punctuation_t *)0)->n), sizeof( ((punctuation_t *)0)->n ) },
	{ NULL, 0 }
};

static classVariableInfo_t idLexer_typeInfo[] = {
	{ "int", "loaded", (int)(&((idLexer *)0)->loaded), sizeof( ((idLexer *)0)->loaded ) },
	{ "idStr", "filename", (int)(&((idLexer *)0)->filename), sizeof( ((idLexer *)0)->filename ) },
	{ "int", "allocated", (int)(&((idLexer *)0)->allocated), sizeof( ((idLexer *)0)->allocated ) },
	{ "const char *", "buffer", (int)(&((idLexer *)0)->buffer), sizeof( ((idLexer *)0)->buffer ) },
	{ "const char *", "script_p", (int)(&((idLexer *)0)->script_p), sizeof( ((idLexer *)0)->script_p ) },
	{ "const char *", "end_p", (int)(&((idLexer *)0)->end_p), sizeof( ((idLexer *)0)->end_p ) },
	{ "const char *", "lastScript_p", (int)(&((idLexer *)0)->lastScript_p), sizeof( ((idLexer *)0)->lastScript_p ) },
	{ "const char *", "whiteSpaceStart_p", (int)(&((idLexer *)0)->whiteSpaceStart_p), sizeof( ((idLexer *)0)->whiteSpaceStart_p ) },
	{ "const char *", "whiteSpaceEnd_p", (int)(&((idLexer *)0)->whiteSpaceEnd_p), sizeof( ((idLexer *)0)->whiteSpaceEnd_p ) },
	{ "time_t", "fileTime", (int)(&((idLexer *)0)->fileTime), sizeof( ((idLexer *)0)->fileTime ) },
	{ "int", "length", (int)(&((idLexer *)0)->length), sizeof( ((idLexer *)0)->length ) },
	{ "int", "line", (int)(&((idLexer *)0)->line), sizeof( ((idLexer *)0)->line ) },
	{ "int", "lastline", (int)(&((idLexer *)0)->lastline), sizeof( ((idLexer *)0)->lastline ) },
	{ "int", "tokenavailable", (int)(&((idLexer *)0)->tokenavailable), sizeof( ((idLexer *)0)->tokenavailable ) },
	{ "int", "flags", (int)(&((idLexer *)0)->flags), sizeof( ((idLexer *)0)->flags ) },
	{ "const punctuation_t *", "punctuations", (int)(&((idLexer *)0)->punctuations), sizeof( ((idLexer *)0)->punctuations ) },
	{ "int *", "punctuationtable", (int)(&((idLexer *)0)->punctuationtable), sizeof( ((idLexer *)0)->punctuationtable ) },
	{ "int *", "nextpunctuation", (int)(&((idLexer *)0)->nextpunctuation), sizeof( ((idLexer *)0)->nextpunctuation ) },
	{ "idToken", "token", (int)(&((idLexer *)0)->token), sizeof( ((idLexer *)0)->token ) },
	{ "idLexer *", "next", (int)(&((idLexer *)0)->next), sizeof( ((idLexer *)0)->next ) },
	{ "bool", "hadError", (int)(&((idLexer *)0)->hadError), sizeof( ((idLexer *)0)->hadError ) },
	{ NULL, 0 }
};

static classVariableInfo_t define_t_typeInfo[] = {
	{ "char *", "name", (int)(&((define_t *)0)->name), sizeof( ((define_t *)0)->name ) },
	{ "int", "flags", (int)(&((define_t *)0)->flags), sizeof( ((define_t *)0)->flags ) },
	{ "int", "builtin", (int)(&((define_t *)0)->builtin), sizeof( ((define_t *)0)->builtin ) },
	{ "int", "numparms", (int)(&((define_t *)0)->numparms), sizeof( ((define_t *)0)->numparms ) },
	{ "idToken *", "parms", (int)(&((define_t *)0)->parms), sizeof( ((define_t *)0)->parms ) },
	{ "idToken *", "tokens", (int)(&((define_t *)0)->tokens), sizeof( ((define_t *)0)->tokens ) },
	{ "define_s *", "next", (int)(&((define_t *)0)->next), sizeof( ((define_t *)0)->next ) },
	{ "define_s *", "hashnext", (int)(&((define_t *)0)->hashnext), sizeof( ((define_t *)0)->hashnext ) },
	{ NULL, 0 }
};

static classVariableInfo_t indent_t_typeInfo[] = {
	{ "int", "type", (int)(&((indent_t *)0)->type), sizeof( ((indent_t *)0)->type ) },
	{ "int", "skip", (int)(&((indent_t *)0)->skip), sizeof( ((indent_t *)0)->skip ) },
	{ "idLexer *", "script", (int)(&((indent_t *)0)->script), sizeof( ((indent_t *)0)->script ) },
	{ "indent_s *", "next", (int)(&((indent_t *)0)->next), sizeof( ((indent_t *)0)->next ) },
	{ NULL, 0 }
};

static classVariableInfo_t idParser_typeInfo[] = {
	{ "int", "loaded", (int)(&((idParser *)0)->loaded), sizeof( ((idParser *)0)->loaded ) },
	{ "idStr", "filename", (int)(&((idParser *)0)->filename), sizeof( ((idParser *)0)->filename ) },
	{ "idStr", "includepath", (int)(&((idParser *)0)->includepath), sizeof( ((idParser *)0)->includepath ) },
	{ "bool", "OSPath", (int)(&((idParser *)0)->OSPath), sizeof( ((idParser *)0)->OSPath ) },
	{ "const punctuation_t *", "punctuations", (int)(&((idParser *)0)->punctuations), sizeof( ((idParser *)0)->punctuations ) },
	{ "int", "flags", (int)(&((idParser *)0)->flags), sizeof( ((idParser *)0)->flags ) },
	{ "idLexer *", "scriptstack", (int)(&((idParser *)0)->scriptstack), sizeof( ((idParser *)0)->scriptstack ) },
	{ "idToken *", "tokens", (int)(&((idParser *)0)->tokens), sizeof( ((idParser *)0)->tokens ) },
	{ "define_t *", "defines", (int)(&((idParser *)0)->defines), sizeof( ((idParser *)0)->defines ) },
	{ "define_t * *", "definehash", (int)(&((idParser *)0)->definehash), sizeof( ((idParser *)0)->definehash ) },
	{ "indent_t *", "indentstack", (int)(&((idParser *)0)->indentstack), sizeof( ((idParser *)0)->indentstack ) },
	{ "int", "skip", (int)(&((idParser *)0)->skip), sizeof( ((idParser *)0)->skip ) },
	{ "const char *", "marker_p", (int)(&((idParser *)0)->marker_p), sizeof( ((idParser *)0)->marker_p ) },
	{ NULL, 0 }
};

static classVariableInfo_t idBase64_typeInfo[] = {
	{ "byte *", "data", (int)(&((idBase64 *)0)->data), sizeof( ((idBase64 *)0)->data ) },
	{ "int", "len", (int)(&((idBase64 *)0)->len), sizeof( ((idBase64 *)0)->len ) },
	{ "int", "alloced", (int)(&((idBase64 *)0)->alloced), sizeof( ((idBase64 *)0)->alloced ) },
	{ NULL, 0 }
};

static classVariableInfo_t idCmdArgs_typeInfo[] = {
	{ "int", "argc", (int)(&((idCmdArgs *)0)->argc), sizeof( ((idCmdArgs *)0)->argc ) },
	{ "char *[64]", "argv", (int)(&((idCmdArgs *)0)->argv), sizeof( ((idCmdArgs *)0)->argv ) },
	{ "char[2048]", "tokenized", (int)(&((idCmdArgs *)0)->tokenized), sizeof( ((idCmdArgs *)0)->tokenized ) },
	{ NULL, 0 }
};

static classVariableInfo_t idHashIndex_typeInfo[] = {
	{ "int", "hashSize", (int)(&((idHashIndex *)0)->hashSize), sizeof( ((idHashIndex *)0)->hashSize ) },
	{ "int *", "hash", (int)(&((idHashIndex *)0)->hash), sizeof( ((idHashIndex *)0)->hash ) },
	{ "int", "indexSize", (int)(&((idHashIndex *)0)->indexSize), sizeof( ((idHashIndex *)0)->indexSize ) },
	{ "int *", "indexChain", (int)(&((idHashIndex *)0)->indexChain), sizeof( ((idHashIndex *)0)->indexChain ) },
	{ "int", "granularity", (int)(&((idHashIndex *)0)->granularity), sizeof( ((idHashIndex *)0)->granularity ) },
	{ "int", "hashMask", (int)(&((idHashIndex *)0)->hashMask), sizeof( ((idHashIndex *)0)->hashMask ) },
	{ "int", "lookupMask", (int)(&((idHashIndex *)0)->lookupMask), sizeof( ((idHashIndex *)0)->lookupMask ) },
	{ NULL, 0 }
};

static classVariableInfo_t idHashTable_class_Type__hashnode_s_typeInfo[] = {
//	{ "idStr", "key", (int)(&((idHashTable< class Type >::hashnode_s *)0)->key), sizeof( ((idHashTable< class Type >::hashnode_s *)0)->key ) },
//	{ "Type", "value", (int)(&((idHashTable< class Type >::hashnode_s *)0)->value), sizeof( ((idHashTable< class Type >::hashnode_s *)0)->value ) },
//	{ "hashnode_s *", "next", (int)(&((idHashTable< class Type >::hashnode_s *)0)->next), sizeof( ((idHashTable< class Type >::hashnode_s *)0)->next ) },
	{ NULL, 0 }
};

static classVariableInfo_t idHashTable_class_Type__typeInfo[] = {
//	{ "hashnode_s * *", "heads", (int)(&((idHashTable< class Type > *)0)->heads), sizeof( ((idHashTable< class Type > *)0)->heads ) },
//	{ "int", "tablesize", (int)(&((idHashTable< class Type > *)0)->tablesize), sizeof( ((idHashTable< class Type > *)0)->tablesize ) },
//	{ "int", "numentries", (int)(&((idHashTable< class Type > *)0)->numentries), sizeof( ((idHashTable< class Type > *)0)->numentries ) },
//	{ "int", "tablesizemask", (int)(&((idHashTable< class Type > *)0)->tablesizemask), sizeof( ((idHashTable< class Type > *)0)->tablesizemask ) },
	{ NULL, 0 }
};

static classVariableInfo_t idStaticList_class_type_int_size__typeInfo[] = {
//	{ "int", "num", (int)(&((idStaticList< class type , int size > *)0)->num), sizeof( ((idStaticList< class type , int size > *)0)->num ) },
//	{ "type[1]", "list", (int)(&((idStaticList< class type , int size > *)0)->list), sizeof( ((idStaticList< class type , int size > *)0)->list ) },
	{ NULL, 0 }
};

static classVariableInfo_t idLinkList_class_type__typeInfo[] = {
//	{ "idLinkList *", "head", (int)(&((idLinkList< class type > *)0)->head), sizeof( ((idLinkList< class type > *)0)->head ) },
//	{ "idLinkList *", "next", (int)(&((idLinkList< class type > *)0)->next), sizeof( ((idLinkList< class type > *)0)->next ) },
//	{ "idLinkList *", "prev", (int)(&((idLinkList< class type > *)0)->prev), sizeof( ((idLinkList< class type > *)0)->prev ) },
//	{ "type *", "owner", (int)(&((idLinkList< class type > *)0)->owner), sizeof( ((idLinkList< class type > *)0)->owner ) },
	{ NULL, 0 }
};

static classVariableInfo_t idHierarchy_class_type__typeInfo[] = {
//	{ "idHierarchy *", "parent", (int)(&((idHierarchy< class type > *)0)->parent), sizeof( ((idHierarchy< class type > *)0)->parent ) },
//	{ "idHierarchy *", "sibling", (int)(&((idHierarchy< class type > *)0)->sibling), sizeof( ((idHierarchy< class type > *)0)->sibling ) },
//	{ "idHierarchy *", "child", (int)(&((idHierarchy< class type > *)0)->child), sizeof( ((idHierarchy< class type > *)0)->child ) },
//	{ "type *", "owner", (int)(&((idHierarchy< class type > *)0)->owner), sizeof( ((idHierarchy< class type > *)0)->owner ) },
	{ NULL, 0 }
};

static classVariableInfo_t idQueueTemplate_class_type_int_nextOffset__typeInfo[] = {
//	{ "type *", "first", (int)(&((idQueueTemplate< class type , int nextOffset > *)0)->first), sizeof( ((idQueueTemplate< class type , int nextOffset > *)0)->first ) },
//	{ "type *", "last", (int)(&((idQueueTemplate< class type , int nextOffset > *)0)->last), sizeof( ((idQueueTemplate< class type , int nextOffset > *)0)->last ) },
	{ NULL, 0 }
};

static classVariableInfo_t idStackTemplate_class_type_int_nextOffset__typeInfo[] = {
//	{ "type *", "top", (int)(&((idStackTemplate< class type , int nextOffset > *)0)->top), sizeof( ((idStackTemplate< class type , int nextOffset > *)0)->top ) },
//	{ "type *", "bottom", (int)(&((idStackTemplate< class type , int nextOffset > *)0)->bottom), sizeof( ((idStackTemplate< class type , int nextOffset > *)0)->bottom ) },
	{ NULL, 0 }
};

static classVariableInfo_t idPoolStr_typeInfo[] = {
	{ "idStrPool *", "pool", (int)(&((idPoolStr *)0)->pool), sizeof( ((idPoolStr *)0)->pool ) },
	{ "mutable int", "numUsers", (int)(&((idPoolStr *)0)->numUsers), sizeof( ((idPoolStr *)0)->numUsers ) },
	{ NULL, 0 }
};

static classVariableInfo_t idStrPool_typeInfo[] = {
	{ "bool", "caseSensitive", (int)(&((idStrPool *)0)->caseSensitive), sizeof( ((idStrPool *)0)->caseSensitive ) },
	{ "idList < idPoolStr * >", "pool", (int)(&((idStrPool *)0)->pool), sizeof( ((idStrPool *)0)->pool ) },
	{ "idHashIndex", "poolHash", (int)(&((idStrPool *)0)->poolHash), sizeof( ((idStrPool *)0)->poolHash ) },
	{ NULL, 0 }
};

static classVariableInfo_t idVectorSet_class_type_int_dimension__typeInfo[] = {
//	{ "idHashIndex", "hash", (int)(&((idVectorSet< class type , int dimension > *)0)->hash), sizeof( ((idVectorSet< class type , int dimension > *)0)->hash ) },
//	{ "type", "mins", (int)(&((idVectorSet< class type , int dimension > *)0)->mins), sizeof( ((idVectorSet< class type , int dimension > *)0)->mins ) },
//	{ "type", "maxs", (int)(&((idVectorSet< class type , int dimension > *)0)->maxs), sizeof( ((idVectorSet< class type , int dimension > *)0)->maxs ) },
//	{ "int", "boxHashSize", (int)(&((idVectorSet< class type , int dimension > *)0)->boxHashSize), sizeof( ((idVectorSet< class type , int dimension > *)0)->boxHashSize ) },
//	{ "float[1]", "boxInvSize", (int)(&((idVectorSet< class type , int dimension > *)0)->boxInvSize), sizeof( ((idVectorSet< class type , int dimension > *)0)->boxInvSize ) },
//	{ "float[1]", "boxHalfSize", (int)(&((idVectorSet< class type , int dimension > *)0)->boxHalfSize), sizeof( ((idVectorSet< class type , int dimension > *)0)->boxHalfSize ) },
	{ NULL, 0 }
};

static classVariableInfo_t idVectorSubset_class_type_int_dimension__typeInfo[] = {
//	{ "idHashIndex", "hash", (int)(&((idVectorSubset< class type , int dimension > *)0)->hash), sizeof( ((idVectorSubset< class type , int dimension > *)0)->hash ) },
//	{ "type", "mins", (int)(&((idVectorSubset< class type , int dimension > *)0)->mins), sizeof( ((idVectorSubset< class type , int dimension > *)0)->mins ) },
//	{ "type", "maxs", (int)(&((idVectorSubset< class type , int dimension > *)0)->maxs), sizeof( ((idVectorSubset< class type , int dimension > *)0)->maxs ) },
//	{ "int", "boxHashSize", (int)(&((idVectorSubset< class type , int dimension > *)0)->boxHashSize), sizeof( ((idVectorSubset< class type , int dimension > *)0)->boxHashSize ) },
//	{ "float[1]", "boxInvSize", (int)(&((idVectorSubset< class type , int dimension > *)0)->boxInvSize), sizeof( ((idVectorSubset< class type , int dimension > *)0)->boxInvSize ) },
//	{ "float[1]", "boxHalfSize", (int)(&((idVectorSubset< class type , int dimension > *)0)->boxHalfSize), sizeof( ((idVectorSubset< class type , int dimension > *)0)->boxHalfSize ) },
	{ NULL, 0 }
};

static classVariableInfo_t idPlaneSet_typeInfo[] = {
	{ "idHashIndex", "hash", (int)(&((idPlaneSet *)0)->hash), sizeof( ((idPlaneSet *)0)->hash ) },
	{ NULL, 0 }
};

static classVariableInfo_t idKeyValue_typeInfo[] = {
	{ "const idPoolStr *", "key", (int)(&((idKeyValue *)0)->key), sizeof( ((idKeyValue *)0)->key ) },
	{ "const idPoolStr *", "value", (int)(&((idKeyValue *)0)->value), sizeof( ((idKeyValue *)0)->value ) },
	{ NULL, 0 }
};

static classVariableInfo_t idDict_typeInfo[] = {
	{ "idList < idKeyValue >", "args", (int)(&((idDict *)0)->args), sizeof( ((idDict *)0)->args ) },
	{ "idHashIndex", "argHash", (int)(&((idDict *)0)->argHash), sizeof( ((idDict *)0)->argHash ) },
	{ NULL, 0 }
};

static classVariableInfo_t idLangKeyValue_typeInfo[] = {
	{ "idStr", "key", (int)(&((idLangKeyValue *)0)->key), sizeof( ((idLangKeyValue *)0)->key ) },
	{ "idStr", "value", (int)(&((idLangKeyValue *)0)->value), sizeof( ((idLangKeyValue *)0)->value ) },
	{ NULL, 0 }
};

static classVariableInfo_t idLangDict_typeInfo[] = {
	{ "idList < idLangKeyValue >", "args", (int)(&((idLangDict *)0)->args), sizeof( ((idLangDict *)0)->args ) },
	{ "idHashIndex", "hash", (int)(&((idLangDict *)0)->hash), sizeof( ((idLangDict *)0)->hash ) },
	{ "int", "baseID", (int)(&((idLangDict *)0)->baseID), sizeof( ((idLangDict *)0)->baseID ) },
	{ NULL, 0 }
};

static classVariableInfo_t idBitMsg_typeInfo[] = {
	{ "byte *", "writeData", (int)(&((idBitMsg *)0)->writeData), sizeof( ((idBitMsg *)0)->writeData ) },
	{ "const byte *", "readData", (int)(&((idBitMsg *)0)->readData), sizeof( ((idBitMsg *)0)->readData ) },
	{ "int", "maxSize", (int)(&((idBitMsg *)0)->maxSize), sizeof( ((idBitMsg *)0)->maxSize ) },
	{ "int", "curSize", (int)(&((idBitMsg *)0)->curSize), sizeof( ((idBitMsg *)0)->curSize ) },
	{ "int", "writeBit", (int)(&((idBitMsg *)0)->writeBit), sizeof( ((idBitMsg *)0)->writeBit ) },
	{ "mutable int", "readCount", (int)(&((idBitMsg *)0)->readCount), sizeof( ((idBitMsg *)0)->readCount ) },
	{ "mutable int", "readBit", (int)(&((idBitMsg *)0)->readBit), sizeof( ((idBitMsg *)0)->readBit ) },
	{ "bool", "allowOverflow", (int)(&((idBitMsg *)0)->allowOverflow), sizeof( ((idBitMsg *)0)->allowOverflow ) },
	{ "bool", "overflowed", (int)(&((idBitMsg *)0)->overflowed), sizeof( ((idBitMsg *)0)->overflowed ) },
	{ NULL, 0 }
};

static classVariableInfo_t idBitMsgDelta_typeInfo[] = {
	{ "const idBitMsg *", "base", (int)(&((idBitMsgDelta *)0)->base), sizeof( ((idBitMsgDelta *)0)->base ) },
	{ "idBitMsg *", "newBase", (int)(&((idBitMsgDelta *)0)->newBase), sizeof( ((idBitMsgDelta *)0)->newBase ) },
	{ "idBitMsg *", "writeDelta", (int)(&((idBitMsgDelta *)0)->writeDelta), sizeof( ((idBitMsgDelta *)0)->writeDelta ) },
	{ "const idBitMsg *", "readDelta", (int)(&((idBitMsgDelta *)0)->readDelta), sizeof( ((idBitMsgDelta *)0)->readDelta ) },
	{ "mutable bool", "changed", (int)(&((idBitMsgDelta *)0)->changed), sizeof( ((idBitMsgDelta *)0)->changed ) },
	{ NULL, 0 }
};

static classVariableInfo_t idMapPrimitive_typeInfo[] = {
	{ "idDict", "epairs", (int)(&((idMapPrimitive *)0)->epairs), sizeof( ((idMapPrimitive *)0)->epairs ) },
	{ "int", "type", (int)(&((idMapPrimitive *)0)->type), sizeof( ((idMapPrimitive *)0)->type ) },
	{ NULL, 0 }
};

static classVariableInfo_t idMapBrushSide_typeInfo[] = {
	{ "idStr", "material", (int)(&((idMapBrushSide *)0)->material), sizeof( ((idMapBrushSide *)0)->material ) },
	{ "idPlane", "plane", (int)(&((idMapBrushSide *)0)->plane), sizeof( ((idMapBrushSide *)0)->plane ) },
	{ "idVec3[2]", "texMat", (int)(&((idMapBrushSide *)0)->texMat), sizeof( ((idMapBrushSide *)0)->texMat ) },
	{ "idVec3", "origin", (int)(&((idMapBrushSide *)0)->origin), sizeof( ((idMapBrushSide *)0)->origin ) },
	{ NULL, 0 }
};

static classVariableInfo_t idMapBrush_typeInfo[] = {
	{ "int", "numSides", (int)(&((idMapBrush *)0)->numSides), sizeof( ((idMapBrush *)0)->numSides ) },
	{ "idList < idMapBrushSide * >", "sides", (int)(&((idMapBrush *)0)->sides), sizeof( ((idMapBrush *)0)->sides ) },
	{ NULL, 0 }
};

static classVariableInfo_t idMapPatch_typeInfo[] = {
	{ "idStr", "material", (int)(&((idMapPatch *)0)->material), sizeof( ((idMapPatch *)0)->material ) },
	{ "int", "horzSubdivisions", (int)(&((idMapPatch *)0)->horzSubdivisions), sizeof( ((idMapPatch *)0)->horzSubdivisions ) },
	{ "int", "vertSubdivisions", (int)(&((idMapPatch *)0)->vertSubdivisions), sizeof( ((idMapPatch *)0)->vertSubdivisions ) },
	{ "bool", "explicitSubdivisions", (int)(&((idMapPatch *)0)->explicitSubdivisions), sizeof( ((idMapPatch *)0)->explicitSubdivisions ) },
	{ NULL, 0 }
};

static classVariableInfo_t idMapEntity_typeInfo[] = {
	{ "idDict", "epairs", (int)(&((idMapEntity *)0)->epairs), sizeof( ((idMapEntity *)0)->epairs ) },
	{ "idList < idMapPrimitive * >", "primitives", (int)(&((idMapEntity *)0)->primitives), sizeof( ((idMapEntity *)0)->primitives ) },
	{ NULL, 0 }
};

static classVariableInfo_t idMapFile_typeInfo[] = {
	{ "float", "version", (int)(&((idMapFile *)0)->version), sizeof( ((idMapFile *)0)->version ) },
	{ "time_t", "fileTime", (int)(&((idMapFile *)0)->fileTime), sizeof( ((idMapFile *)0)->fileTime ) },
	{ "unsigned int", "geometryCRC", (int)(&((idMapFile *)0)->geometryCRC), sizeof( ((idMapFile *)0)->geometryCRC ) },
	{ "idList < idMapEntity * >", "entities", (int)(&((idMapFile *)0)->entities), sizeof( ((idMapFile *)0)->entities ) },
	{ "idStr", "name", (int)(&((idMapFile *)0)->name), sizeof( ((idMapFile *)0)->name ) },
	{ "bool", "hasPrimitiveData", (int)(&((idMapFile *)0)->hasPrimitiveData), sizeof( ((idMapFile *)0)->hasPrimitiveData ) },
	{ NULL, 0 }
};

static classVariableInfo_t idTimer_typeInfo[] = {
	{ "idTimer::enum_16", "state", (int)(&((idTimer *)0)->state), sizeof( ((idTimer *)0)->state ) },
	{ "double", "start", (int)(&((idTimer *)0)->start), sizeof( ((idTimer *)0)->start ) },
	{ "double", "clockTicks", (int)(&((idTimer *)0)->clockTicks), sizeof( ((idTimer *)0)->clockTicks ) },
	{ NULL, 0 }
};

static classVariableInfo_t idTimerReport_typeInfo[] = {
	{ "idList < idTimer * >", "timers", (int)(&((idTimerReport *)0)->timers), sizeof( ((idTimerReport *)0)->timers ) },
	{ "idStrList", "names", (int)(&((idTimerReport *)0)->names), sizeof( ((idTimerReport *)0)->names ) },
	{ "idStr", "reportName", (int)(&((idTimerReport *)0)->reportName), sizeof( ((idTimerReport *)0)->reportName ) },
	{ NULL, 0 }
};

static classVariableInfo_t idCmdSystem_typeInfo[] = {
	{ NULL, 0 }
};

static classVariableInfo_t idCVar_typeInfo[] = {
	{ "const char *", "name", (int)(&((idCVar *)0)->name), sizeof( ((idCVar *)0)->name ) },
	{ "const char *", "value", (int)(&((idCVar *)0)->value), sizeof( ((idCVar *)0)->value ) },
	{ "const char *", "description", (int)(&((idCVar *)0)->description), sizeof( ((idCVar *)0)->description ) },
	{ "int", "flags", (int)(&((idCVar *)0)->flags), sizeof( ((idCVar *)0)->flags ) },
	{ "float", "valueMin", (int)(&((idCVar *)0)->valueMin), sizeof( ((idCVar *)0)->valueMin ) },
	{ "float", "valueMax", (int)(&((idCVar *)0)->valueMax), sizeof( ((idCVar *)0)->valueMax ) },
	{ "const char * *", "valueStrings", (int)(&((idCVar *)0)->valueStrings), sizeof( ((idCVar *)0)->valueStrings ) },
	{ "argCompletion_t", "valueCompletion", (int)(&((idCVar *)0)->valueCompletion), sizeof( ((idCVar *)0)->valueCompletion ) },
	{ "int", "integerValue", (int)(&((idCVar *)0)->integerValue), sizeof( ((idCVar *)0)->integerValue ) },
	{ "float", "floatValue", (int)(&((idCVar *)0)->floatValue), sizeof( ((idCVar *)0)->floatValue ) },
	{ "idCVar *", "internalVar", (int)(&((idCVar *)0)->internalVar), sizeof( ((idCVar *)0)->internalVar ) },
	{ "idCVar *", "next", (int)(&((idCVar *)0)->next), sizeof( ((idCVar *)0)->next ) },
	{ NULL, 0 }
};

static classVariableInfo_t idCVarSystem_typeInfo[] = {
	{ NULL, 0 }
};

static classVariableInfo_t MemInfo_t_typeInfo[] = {
	{ "idStr", "filebase", (int)(&((MemInfo_t *)0)->filebase), sizeof( ((MemInfo_t *)0)->filebase ) },
	{ "int", "total", (int)(&((MemInfo_t *)0)->total), sizeof( ((MemInfo_t *)0)->total ) },
	{ "int", "assetTotals", (int)(&((MemInfo_t *)0)->assetTotals), sizeof( ((MemInfo_t *)0)->assetTotals ) },
	{ "int", "memoryManagerTotal", (int)(&((MemInfo_t *)0)->memoryManagerTotal), sizeof( ((MemInfo_t *)0)->memoryManagerTotal ) },
	{ "int", "gameSubsystemTotal", (int)(&((MemInfo_t *)0)->gameSubsystemTotal), sizeof( ((MemInfo_t *)0)->gameSubsystemTotal ) },
	{ "int", "renderSubsystemTotal", (int)(&((MemInfo_t *)0)->renderSubsystemTotal), sizeof( ((MemInfo_t *)0)->renderSubsystemTotal ) },
	{ "int", "imageAssetsTotal", (int)(&((MemInfo_t *)0)->imageAssetsTotal), sizeof( ((MemInfo_t *)0)->imageAssetsTotal ) },
	{ "int", "modelAssetsTotal", (int)(&((MemInfo_t *)0)->modelAssetsTotal), sizeof( ((MemInfo_t *)0)->modelAssetsTotal ) },
	{ "int", "soundAssetsTotal", (int)(&((MemInfo_t *)0)->soundAssetsTotal), sizeof( ((MemInfo_t *)0)->soundAssetsTotal ) },
	{ NULL, 0 }
};

static classVariableInfo_t idCommon_typeInfo[] = {
	{ NULL, 0 }
};

static classVariableInfo_t idFile_typeInfo[] = {
	{ NULL, 0 }
};

static classVariableInfo_t idFile_Memory_typeInfo[] = {
	{ "idStr", "name", (int)(&((idFile_Memory *)0)->name), sizeof( ((idFile_Memory *)0)->name ) },
	{ "int", "mode", (int)(&((idFile_Memory *)0)->mode), sizeof( ((idFile_Memory *)0)->mode ) },
	{ "int", "maxSize", (int)(&((idFile_Memory *)0)->maxSize), sizeof( ((idFile_Memory *)0)->maxSize ) },
	{ "int", "fileSize", (int)(&((idFile_Memory *)0)->fileSize), sizeof( ((idFile_Memory *)0)->fileSize ) },
	{ "int", "allocated", (int)(&((idFile_Memory *)0)->allocated), sizeof( ((idFile_Memory *)0)->allocated ) },
	{ "int", "granularity", (int)(&((idFile_Memory *)0)->granularity), sizeof( ((idFile_Memory *)0)->granularity ) },
	{ "char *", "filePtr", (int)(&((idFile_Memory *)0)->filePtr), sizeof( ((idFile_Memory *)0)->filePtr ) },
	{ "char *", "curPtr", (int)(&((idFile_Memory *)0)->curPtr), sizeof( ((idFile_Memory *)0)->curPtr ) },
	{ NULL, 0 }
};

static classVariableInfo_t idFile_BitMsg_typeInfo[] = {
	{ "idStr", "name", (int)(&((idFile_BitMsg *)0)->name), sizeof( ((idFile_BitMsg *)0)->name ) },
	{ "int", "mode", (int)(&((idFile_BitMsg *)0)->mode), sizeof( ((idFile_BitMsg *)0)->mode ) },
	{ "idBitMsg *", "msg", (int)(&((idFile_BitMsg *)0)->msg), sizeof( ((idFile_BitMsg *)0)->msg ) },
	{ NULL, 0 }
};

static classVariableInfo_t idFile_Permanent_typeInfo[] = {
	{ "idStr", "name", (int)(&((idFile_Permanent *)0)->name), sizeof( ((idFile_Permanent *)0)->name ) },
	{ "idStr", "fullPath", (int)(&((idFile_Permanent *)0)->fullPath), sizeof( ((idFile_Permanent *)0)->fullPath ) },
	{ "int", "mode", (int)(&((idFile_Permanent *)0)->mode), sizeof( ((idFile_Permanent *)0)->mode ) },
	{ "int", "fileSize", (int)(&((idFile_Permanent *)0)->fileSize), sizeof( ((idFile_Permanent *)0)->fileSize ) },
	{ "FILE *", "o", (int)(&((idFile_Permanent *)0)->o), sizeof( ((idFile_Permanent *)0)->o ) },
	{ "bool", "handleSync", (int)(&((idFile_Permanent *)0)->handleSync), sizeof( ((idFile_Permanent *)0)->handleSync ) },
	{ NULL, 0 }
};

static classVariableInfo_t idFile_InZip_typeInfo[] = {
	{ "idStr", "name", (int)(&((idFile_InZip *)0)->name), sizeof( ((idFile_InZip *)0)->name ) },
	{ "idStr", "fullPath", (int)(&((idFile_InZip *)0)->fullPath), sizeof( ((idFile_InZip *)0)->fullPath ) },
	{ "int", "zipFilePos", (int)(&((idFile_InZip *)0)->zipFilePos), sizeof( ((idFile_InZip *)0)->zipFilePos ) },
	{ "int", "fileSize", (int)(&((idFile_InZip *)0)->fileSize), sizeof( ((idFile_InZip *)0)->fileSize ) },
	{ "void *", "z", (int)(&((idFile_InZip *)0)->z), sizeof( ((idFile_InZip *)0)->z ) },
	{ NULL, 0 }
};

static classVariableInfo_t urlDownload_t_typeInfo[] = {
	{ "idStr", "url", (int)(&((urlDownload_t *)0)->url), sizeof( ((urlDownload_t *)0)->url ) },
	{ "char[1024]", "dlerror", (int)(&((urlDownload_t *)0)->dlerror), sizeof( ((urlDownload_t *)0)->dlerror ) },
	{ "int", "dltotal", (int)(&((urlDownload_t *)0)->dltotal), sizeof( ((urlDownload_t *)0)->dltotal ) },
	{ "int", "dlnow", (int)(&((urlDownload_t *)0)->dlnow), sizeof( ((urlDownload_t *)0)->dlnow ) },
	{ "int", "dlstatus", (int)(&((urlDownload_t *)0)->dlstatus), sizeof( ((urlDownload_t *)0)->dlstatus ) },
	{ "dlStatus_t", "status", (int)(&((urlDownload_t *)0)->status), sizeof( ((urlDownload_t *)0)->status ) },
	{ NULL, 0 }
};

static classVariableInfo_t fileDownload_t_typeInfo[] = {
	{ "int", "position", (int)(&((fileDownload_t *)0)->position), sizeof( ((fileDownload_t *)0)->position ) },
	{ "int", "length", (int)(&((fileDownload_t *)0)->length), sizeof( ((fileDownload_t *)0)->length ) },
	{ "void *", "buffer", (int)(&((fileDownload_t *)0)->buffer), sizeof( ((fileDownload_t *)0)->buffer ) },
	{ NULL, 0 }
};

static classVariableInfo_t backgroundDownload_t_typeInfo[] = {
	{ "backgroundDownload_s *", "next", (int)(&((backgroundDownload_t *)0)->next), sizeof( ((backgroundDownload_t *)0)->next ) },
	{ "dlType_t", "opcode", (int)(&((backgroundDownload_t *)0)->opcode), sizeof( ((backgroundDownload_t *)0)->opcode ) },
	{ "idFile *", "f", (int)(&((backgroundDownload_t *)0)->f), sizeof( ((backgroundDownload_t *)0)->f ) },
	{ "fileDownload_t", "file", (int)(&((backgroundDownload_t *)0)->file), sizeof( ((backgroundDownload_t *)0)->file ) },
	{ "urlDownload_t", "url", (int)(&((backgroundDownload_t *)0)->url), sizeof( ((backgroundDownload_t *)0)->url ) },
	{ "volatile bool", "completed", (int)(&((backgroundDownload_t *)0)->completed), sizeof( ((backgroundDownload_t *)0)->completed ) },
	{ NULL, 0 }
};

static classVariableInfo_t idFileList_typeInfo[] = {
	{ "idStr", "basePath", (int)(&((idFileList *)0)->basePath), sizeof( ((idFileList *)0)->basePath ) },
	{ "idStrList", "list", (int)(&((idFileList *)0)->list), sizeof( ((idFileList *)0)->list ) },
	{ NULL, 0 }
};

static classVariableInfo_t idModList_typeInfo[] = {
	{ "idStrList", "mods", (int)(&((idModList *)0)->mods), sizeof( ((idModList *)0)->mods ) },
	{ "idStrList", "descriptions", (int)(&((idModList *)0)->descriptions), sizeof( ((idModList *)0)->descriptions ) },
	{ NULL, 0 }
};

static classVariableInfo_t idFileSystem_typeInfo[] = {
	{ NULL, 0 }
};

static classVariableInfo_t usercmd_t_typeInfo[] = {
	{ "int", "gameFrame", (int)(&((usercmd_t *)0)->gameFrame), sizeof( ((usercmd_t *)0)->gameFrame ) },
	{ "int", "gameTime", (int)(&((usercmd_t *)0)->gameTime), sizeof( ((usercmd_t *)0)->gameTime ) },
	{ "int", "duplicateCount", (int)(&((usercmd_t *)0)->duplicateCount), sizeof( ((usercmd_t *)0)->duplicateCount ) },
	{ "byte", "buttons", (int)(&((usercmd_t *)0)->buttons), sizeof( ((usercmd_t *)0)->buttons ) },
	{ "signed char", "forwardmove", (int)(&((usercmd_t *)0)->forwardmove), sizeof( ((usercmd_t *)0)->forwardmove ) },
	{ "signed char", "rightmove", (int)(&((usercmd_t *)0)->rightmove), sizeof( ((usercmd_t *)0)->rightmove ) },
	{ "signed char", "upmove", (int)(&((usercmd_t *)0)->upmove), sizeof( ((usercmd_t *)0)->upmove ) },
	{ "short[3]", "angles", (int)(&((usercmd_t *)0)->angles), sizeof( ((usercmd_t *)0)->angles ) },
	{ "short", "mx", (int)(&((usercmd_t *)0)->mx), sizeof( ((usercmd_t *)0)->mx ) },
	{ "short", "my", (int)(&((usercmd_t *)0)->my), sizeof( ((usercmd_t *)0)->my ) },
	{ "signed char", "impulse", (int)(&((usercmd_t *)0)->impulse), sizeof( ((usercmd_t *)0)->impulse ) },
	{ "byte", "flags", (int)(&((usercmd_t *)0)->flags), sizeof( ((usercmd_t *)0)->flags ) },
	{ "int", "sequence", (int)(&((usercmd_t *)0)->sequence), sizeof( ((usercmd_t *)0)->sequence ) },
	{ NULL, 0 }
};

static classVariableInfo_t idUsercmdGen_typeInfo[] = {
	{ NULL, 0 }
};

static classVariableInfo_t idDeclBase_typeInfo[] = {
	{ NULL, 0 }
};

static classVariableInfo_t idDecl_typeInfo[] = {
	{ "idDeclBase *", "base", (int)(&((idDecl *)0)->base), sizeof( ((idDecl *)0)->base ) },
	{ NULL, 0 }
};

static classVariableInfo_t idDeclManager_typeInfo[] = {
	{ NULL, 0 }
};

static classVariableInfo_t idDeclTable_typeInfo[] = {
	{ "bool", "clamp", (int)(&((idDeclTable *)0)->clamp), sizeof( ((idDeclTable *)0)->clamp ) },
	{ "bool", "snap", (int)(&((idDeclTable *)0)->snap), sizeof( ((idDeclTable *)0)->snap ) },
	{ "idList < float >", "values", (int)(&((idDeclTable *)0)->values), sizeof( ((idDeclTable *)0)->values ) },
	{ NULL, 0 }
};

static classVariableInfo_t skinMapping_t_typeInfo[] = {
	{ "const idMaterial *", "from", (int)(&((skinMapping_t *)0)->from), sizeof( ((skinMapping_t *)0)->from ) },
	{ "const idMaterial *", "to", (int)(&((skinMapping_t *)0)->to), sizeof( ((skinMapping_t *)0)->to ) },
	{ NULL, 0 }
};

static classVariableInfo_t idDeclSkin_typeInfo[] = {
	{ "idList < skinMapping_t >", "mappings", (int)(&((idDeclSkin *)0)->mappings), sizeof( ((idDeclSkin *)0)->mappings ) },
	{ "idStrList", "associatedModels", (int)(&((idDeclSkin *)0)->associatedModels), sizeof( ((idDeclSkin *)0)->associatedModels ) },
	{ NULL, 0 }
};

static classVariableInfo_t idDeclEntityDef_typeInfo[] = {
	{ "idDict", "dict", (int)(&((idDeclEntityDef *)0)->dict), sizeof( ((idDeclEntityDef *)0)->dict ) },
	{ NULL, 0 }
};

static classVariableInfo_t idFXSingleAction_typeInfo[] = {
	{ "int", "type", (int)(&((idFXSingleAction *)0)->type), sizeof( ((idFXSingleAction *)0)->type ) },
	{ "int", "sibling", (int)(&((idFXSingleAction *)0)->sibling), sizeof( ((idFXSingleAction *)0)->sibling ) },
	{ "idStr", "data", (int)(&((idFXSingleAction *)0)->data), sizeof( ((idFXSingleAction *)0)->data ) },
	{ "idStr", "name", (int)(&((idFXSingleAction *)0)->name), sizeof( ((idFXSingleAction *)0)->name ) },
	{ "idStr", "fire", (int)(&((idFXSingleAction *)0)->fire), sizeof( ((idFXSingleAction *)0)->fire ) },
	{ "float", "delay", (int)(&((idFXSingleAction *)0)->delay), sizeof( ((idFXSingleAction *)0)->delay ) },
	{ "float", "duration", (int)(&((idFXSingleAction *)0)->duration), sizeof( ((idFXSingleAction *)0)->duration ) },
	{ "float", "restart", (int)(&((idFXSingleAction *)0)->restart), sizeof( ((idFXSingleAction *)0)->restart ) },
	{ "float", "size", (int)(&((idFXSingleAction *)0)->size), sizeof( ((idFXSingleAction *)0)->size ) },
	{ "float", "fadeInTime", (int)(&((idFXSingleAction *)0)->fadeInTime), sizeof( ((idFXSingleAction *)0)->fadeInTime ) },
	{ "float", "fadeOutTime", (int)(&((idFXSingleAction *)0)->fadeOutTime), sizeof( ((idFXSingleAction *)0)->fadeOutTime ) },
	{ "float", "shakeTime", (int)(&((idFXSingleAction *)0)->shakeTime), sizeof( ((idFXSingleAction *)0)->shakeTime ) },
	{ "float", "shakeAmplitude", (int)(&((idFXSingleAction *)0)->shakeAmplitude), sizeof( ((idFXSingleAction *)0)->shakeAmplitude ) },
	{ "float", "shakeDistance", (int)(&((idFXSingleAction *)0)->shakeDistance), sizeof( ((idFXSingleAction *)0)->shakeDistance ) },
	{ "float", "shakeImpulse", (int)(&((idFXSingleAction *)0)->shakeImpulse), sizeof( ((idFXSingleAction *)0)->shakeImpulse ) },
	{ "float", "lightRadius", (int)(&((idFXSingleAction *)0)->lightRadius), sizeof( ((idFXSingleAction *)0)->lightRadius ) },
	{ "float", "rotate", (int)(&((idFXSingleAction *)0)->rotate), sizeof( ((idFXSingleAction *)0)->rotate ) },
	{ "float", "random1", (int)(&((idFXSingleAction *)0)->random1), sizeof( ((idFXSingleAction *)0)->random1 ) },
	{ "float", "random2", (int)(&((idFXSingleAction *)0)->random2), sizeof( ((idFXSingleAction *)0)->random2 ) },
	{ "idVec3", "lightColor", (int)(&((idFXSingleAction *)0)->lightColor), sizeof( ((idFXSingleAction *)0)->lightColor ) },
	{ "idVec3", "offset", (int)(&((idFXSingleAction *)0)->offset), sizeof( ((idFXSingleAction *)0)->offset ) },
	{ "idMat3", "axis", (int)(&((idFXSingleAction *)0)->axis), sizeof( ((idFXSingleAction *)0)->axis ) },
	{ "bool", "soundStarted", (int)(&((idFXSingleAction *)0)->soundStarted), sizeof( ((idFXSingleAction *)0)->soundStarted ) },
	{ "bool", "shakeStarted", (int)(&((idFXSingleAction *)0)->shakeStarted), sizeof( ((idFXSingleAction *)0)->shakeStarted ) },
	{ "bool", "shakeFalloff", (int)(&((idFXSingleAction *)0)->shakeFalloff), sizeof( ((idFXSingleAction *)0)->shakeFalloff ) },
	{ "bool", "shakeIgnoreMaster", (int)(&((idFXSingleAction *)0)->shakeIgnoreMaster), sizeof( ((idFXSingleAction *)0)->shakeIgnoreMaster ) },
	{ "bool", "bindParticles", (int)(&((idFXSingleAction *)0)->bindParticles), sizeof( ((idFXSingleAction *)0)->bindParticles ) },
	{ "bool", "explicitAxis", (int)(&((idFXSingleAction *)0)->explicitAxis), sizeof( ((idFXSingleAction *)0)->explicitAxis ) },
	{ "bool", "noshadows", (int)(&((idFXSingleAction *)0)->noshadows), sizeof( ((idFXSingleAction *)0)->noshadows ) },
	{ "bool", "particleTrackVelocity", (int)(&((idFXSingleAction *)0)->particleTrackVelocity), sizeof( ((idFXSingleAction *)0)->particleTrackVelocity ) },
	{ "bool", "trackOrigin", (int)(&((idFXSingleAction *)0)->trackOrigin), sizeof( ((idFXSingleAction *)0)->trackOrigin ) },
	{ NULL, 0 }
};

static classVariableInfo_t idDeclFX_typeInfo[] = {
	{ "idList < idFXSingleAction >", "events", (int)(&((idDeclFX *)0)->events), sizeof( ((idDeclFX *)0)->events ) },
	{ "idStr", "joint", (int)(&((idDeclFX *)0)->joint), sizeof( ((idDeclFX *)0)->joint ) },
	{ NULL, 0 }
};

static classVariableInfo_t idParticleParm_typeInfo[] = {
	{ "const idDeclTable *", "table", (int)(&((idParticleParm *)0)->table), sizeof( ((idParticleParm *)0)->table ) },
	{ "float", "from", (int)(&((idParticleParm *)0)->from), sizeof( ((idParticleParm *)0)->from ) },
	{ "float", "to", (int)(&((idParticleParm *)0)->to), sizeof( ((idParticleParm *)0)->to ) },
	{ NULL, 0 }
};

static classVariableInfo_t particleGen_t_typeInfo[] = {
	{ "const renderEntity_t *", "renderEnt", (int)(&((particleGen_t *)0)->renderEnt), sizeof( ((particleGen_t *)0)->renderEnt ) },
	{ "const renderView_t *", "renderView", (int)(&((particleGen_t *)0)->renderView), sizeof( ((particleGen_t *)0)->renderView ) },
	{ "int", "index", (int)(&((particleGen_t *)0)->index), sizeof( ((particleGen_t *)0)->index ) },
	{ "float", "frac", (int)(&((particleGen_t *)0)->frac), sizeof( ((particleGen_t *)0)->frac ) },
	{ "idRandom", "random", (int)(&((particleGen_t *)0)->random), sizeof( ((particleGen_t *)0)->random ) },
	{ "idVec3", "origin", (int)(&((particleGen_t *)0)->origin), sizeof( ((particleGen_t *)0)->origin ) },
	{ "idMat3", "axis", (int)(&((particleGen_t *)0)->axis), sizeof( ((particleGen_t *)0)->axis ) },
	{ "float", "age", (int)(&((particleGen_t *)0)->age), sizeof( ((particleGen_t *)0)->age ) },
	{ "idRandom", "originalRandom", (int)(&((particleGen_t *)0)->originalRandom), sizeof( ((particleGen_t *)0)->originalRandom ) },
	{ "float", "animationFrameFrac", (int)(&((particleGen_t *)0)->animationFrameFrac), sizeof( ((particleGen_t *)0)->animationFrameFrac ) },
	{ NULL, 0 }
};

static classVariableInfo_t idParticleStage_typeInfo[] = {
	{ "const idMaterial *", "material", (int)(&((idParticleStage *)0)->material), sizeof( ((idParticleStage *)0)->material ) },
	{ "int", "totalParticles", (int)(&((idParticleStage *)0)->totalParticles), sizeof( ((idParticleStage *)0)->totalParticles ) },
	{ "float", "cycles", (int)(&((idParticleStage *)0)->cycles), sizeof( ((idParticleStage *)0)->cycles ) },
	{ "int", "cycleMsec", (int)(&((idParticleStage *)0)->cycleMsec), sizeof( ((idParticleStage *)0)->cycleMsec ) },
	{ "float", "spawnBunching", (int)(&((idParticleStage *)0)->spawnBunching), sizeof( ((idParticleStage *)0)->spawnBunching ) },
	{ "float", "particleLife", (int)(&((idParticleStage *)0)->particleLife), sizeof( ((idParticleStage *)0)->particleLife ) },
	{ "float", "timeOffset", (int)(&((idParticleStage *)0)->timeOffset), sizeof( ((idParticleStage *)0)->timeOffset ) },
	{ "float", "deadTime", (int)(&((idParticleStage *)0)->deadTime), sizeof( ((idParticleStage *)0)->deadTime ) },
	{ "prtDistribution_t", "distributionType", (int)(&((idParticleStage *)0)->distributionType), sizeof( ((idParticleStage *)0)->distributionType ) },
	{ "float[4]", "distributionParms", (int)(&((idParticleStage *)0)->distributionParms), sizeof( ((idParticleStage *)0)->distributionParms ) },
	{ "prtDirection_t", "directionType", (int)(&((idParticleStage *)0)->directionType), sizeof( ((idParticleStage *)0)->directionType ) },
	{ "float[4]", "directionParms", (int)(&((idParticleStage *)0)->directionParms), sizeof( ((idParticleStage *)0)->directionParms ) },
	{ "idParticleParm", "speed", (int)(&((idParticleStage *)0)->speed), sizeof( ((idParticleStage *)0)->speed ) },
	{ "float", "gravity", (int)(&((idParticleStage *)0)->gravity), sizeof( ((idParticleStage *)0)->gravity ) },
	{ "bool", "worldGravity", (int)(&((idParticleStage *)0)->worldGravity), sizeof( ((idParticleStage *)0)->worldGravity ) },
	{ "bool", "randomDistribution", (int)(&((idParticleStage *)0)->randomDistribution), sizeof( ((idParticleStage *)0)->randomDistribution ) },
	{ "bool", "entityColor", (int)(&((idParticleStage *)0)->entityColor), sizeof( ((idParticleStage *)0)->entityColor ) },
	{ "prtCustomPth_t", "customPathType", (int)(&((idParticleStage *)0)->customPathType), sizeof( ((idParticleStage *)0)->customPathType ) },
	{ "float[8]", "customPathParms", (int)(&((idParticleStage *)0)->customPathParms), sizeof( ((idParticleStage *)0)->customPathParms ) },
	{ "idVec3", "offset", (int)(&((idParticleStage *)0)->offset), sizeof( ((idParticleStage *)0)->offset ) },
	{ "int", "animationFrames", (int)(&((idParticleStage *)0)->animationFrames), sizeof( ((idParticleStage *)0)->animationFrames ) },
	{ "float", "animationRate", (int)(&((idParticleStage *)0)->animationRate), sizeof( ((idParticleStage *)0)->animationRate ) },
	{ "float", "initialAngle", (int)(&((idParticleStage *)0)->initialAngle), sizeof( ((idParticleStage *)0)->initialAngle ) },
	{ "idParticleParm", "rotationSpeed", (int)(&((idParticleStage *)0)->rotationSpeed), sizeof( ((idParticleStage *)0)->rotationSpeed ) },
	{ "prtOrientation_t", "orientation", (int)(&((idParticleStage *)0)->orientation), sizeof( ((idParticleStage *)0)->orientation ) },
	{ "float[4]", "orientationParms", (int)(&((idParticleStage *)0)->orientationParms), sizeof( ((idParticleStage *)0)->orientationParms ) },
	{ "idParticleParm", "size", (int)(&((idParticleStage *)0)->size), sizeof( ((idParticleStage *)0)->size ) },
	{ "idParticleParm", "aspect", (int)(&((idParticleStage *)0)->aspect), sizeof( ((idParticleStage *)0)->aspect ) },
	{ "idVec4", "color", (int)(&((idParticleStage *)0)->color), sizeof( ((idParticleStage *)0)->color ) },
	{ "idVec4", "fadeColor", (int)(&((idParticleStage *)0)->fadeColor), sizeof( ((idParticleStage *)0)->fadeColor ) },
	{ "float", "fadeInFraction", (int)(&((idParticleStage *)0)->fadeInFraction), sizeof( ((idParticleStage *)0)->fadeInFraction ) },
	{ "float", "fadeOutFraction", (int)(&((idParticleStage *)0)->fadeOutFraction), sizeof( ((idParticleStage *)0)->fadeOutFraction ) },
	{ "float", "fadeIndexFraction", (int)(&((idParticleStage *)0)->fadeIndexFraction), sizeof( ((idParticleStage *)0)->fadeIndexFraction ) },
	{ "bool", "hidden", (int)(&((idParticleStage *)0)->hidden), sizeof( ((idParticleStage *)0)->hidden ) },
	{ "float", "boundsExpansion", (int)(&((idParticleStage *)0)->boundsExpansion), sizeof( ((idParticleStage *)0)->boundsExpansion ) },
	{ "idBounds", "bounds", (int)(&((idParticleStage *)0)->bounds), sizeof( ((idParticleStage *)0)->bounds ) },
	{ NULL, 0 }
};

static classVariableInfo_t idDeclParticle_typeInfo[] = {
	{ "idList < idParticleStage * >", "stages", (int)(&((idDeclParticle *)0)->stages), sizeof( ((idDeclParticle *)0)->stages ) },
	{ "idBounds", "bounds", (int)(&((idDeclParticle *)0)->bounds), sizeof( ((idDeclParticle *)0)->bounds ) },
	{ "float", "depthHack", (int)(&((idDeclParticle *)0)->depthHack), sizeof( ((idDeclParticle *)0)->depthHack ) },
	{ NULL, 0 }
};

static classVariableInfo_t idAFVector_typeInfo[] = {
	{ "idAFVector::enum_38", "type", (int)(&((idAFVector *)0)->type), sizeof( ((idAFVector *)0)->type ) },
	{ "idStr", "joint1", (int)(&((idAFVector *)0)->joint1), sizeof( ((idAFVector *)0)->joint1 ) },
	{ "idStr", "joint2", (int)(&((idAFVector *)0)->joint2), sizeof( ((idAFVector *)0)->joint2 ) },
	{ "mutable idVec3", "vec", (int)(&((idAFVector *)0)->vec), sizeof( ((idAFVector *)0)->vec ) },
	{ "bool", "negate", (int)(&((idAFVector *)0)->negate), sizeof( ((idAFVector *)0)->negate ) },
	{ NULL, 0 }
};

static classVariableInfo_t idDeclAF_Body_typeInfo[] = {
	{ "idStr", "name", (int)(&((idDeclAF_Body *)0)->name), sizeof( ((idDeclAF_Body *)0)->name ) },
	{ "idStr", "jointName", (int)(&((idDeclAF_Body *)0)->jointName), sizeof( ((idDeclAF_Body *)0)->jointName ) },
	{ "declAFJointMod_t", "jointMod", (int)(&((idDeclAF_Body *)0)->jointMod), sizeof( ((idDeclAF_Body *)0)->jointMod ) },
	{ "int", "modelType", (int)(&((idDeclAF_Body *)0)->modelType), sizeof( ((idDeclAF_Body *)0)->modelType ) },
	{ "idAFVector", "v1", (int)(&((idDeclAF_Body *)0)->v1), sizeof( ((idDeclAF_Body *)0)->v1 ) },
	{ "idAFVector", "v2", (int)(&((idDeclAF_Body *)0)->v2), sizeof( ((idDeclAF_Body *)0)->v2 ) },
	{ "int", "numSides", (int)(&((idDeclAF_Body *)0)->numSides), sizeof( ((idDeclAF_Body *)0)->numSides ) },
	{ "float", "width", (int)(&((idDeclAF_Body *)0)->width), sizeof( ((idDeclAF_Body *)0)->width ) },
	{ "float", "density", (int)(&((idDeclAF_Body *)0)->density), sizeof( ((idDeclAF_Body *)0)->density ) },
	{ "idAFVector", "origin", (int)(&((idDeclAF_Body *)0)->origin), sizeof( ((idDeclAF_Body *)0)->origin ) },
	{ "idAngles", "angles", (int)(&((idDeclAF_Body *)0)->angles), sizeof( ((idDeclAF_Body *)0)->angles ) },
	{ "int", "contents", (int)(&((idDeclAF_Body *)0)->contents), sizeof( ((idDeclAF_Body *)0)->contents ) },
	{ "int", "clipMask", (int)(&((idDeclAF_Body *)0)->clipMask), sizeof( ((idDeclAF_Body *)0)->clipMask ) },
	{ "bool", "selfCollision", (int)(&((idDeclAF_Body *)0)->selfCollision), sizeof( ((idDeclAF_Body *)0)->selfCollision ) },
	{ "idMat3", "inertiaScale", (int)(&((idDeclAF_Body *)0)->inertiaScale), sizeof( ((idDeclAF_Body *)0)->inertiaScale ) },
	{ "float", "linearFriction", (int)(&((idDeclAF_Body *)0)->linearFriction), sizeof( ((idDeclAF_Body *)0)->linearFriction ) },
	{ "float", "angularFriction", (int)(&((idDeclAF_Body *)0)->angularFriction), sizeof( ((idDeclAF_Body *)0)->angularFriction ) },
	{ "float", "contactFriction", (int)(&((idDeclAF_Body *)0)->contactFriction), sizeof( ((idDeclAF_Body *)0)->contactFriction ) },
	{ "idStr", "containedJoints", (int)(&((idDeclAF_Body *)0)->containedJoints), sizeof( ((idDeclAF_Body *)0)->containedJoints ) },
	{ "idAFVector", "frictionDirection", (int)(&((idDeclAF_Body *)0)->frictionDirection), sizeof( ((idDeclAF_Body *)0)->frictionDirection ) },
	{ "idAFVector", "contactMotorDirection", (int)(&((idDeclAF_Body *)0)->contactMotorDirection), sizeof( ((idDeclAF_Body *)0)->contactMotorDirection ) },
	{ NULL, 0 }
};

static classVariableInfo_t idDeclAF_Constraint_typeInfo[] = {
	{ "idStr", "name", (int)(&((idDeclAF_Constraint *)0)->name), sizeof( ((idDeclAF_Constraint *)0)->name ) },
	{ "idStr", "body1", (int)(&((idDeclAF_Constraint *)0)->body1), sizeof( ((idDeclAF_Constraint *)0)->body1 ) },
	{ "idStr", "body2", (int)(&((idDeclAF_Constraint *)0)->body2), sizeof( ((idDeclAF_Constraint *)0)->body2 ) },
	{ "declAFConstraintType_t", "type", (int)(&((idDeclAF_Constraint *)0)->type), sizeof( ((idDeclAF_Constraint *)0)->type ) },
	{ "float", "friction", (int)(&((idDeclAF_Constraint *)0)->friction), sizeof( ((idDeclAF_Constraint *)0)->friction ) },
	{ "float", "stretch", (int)(&((idDeclAF_Constraint *)0)->stretch), sizeof( ((idDeclAF_Constraint *)0)->stretch ) },
	{ "float", "compress", (int)(&((idDeclAF_Constraint *)0)->compress), sizeof( ((idDeclAF_Constraint *)0)->compress ) },
	{ "float", "damping", (int)(&((idDeclAF_Constraint *)0)->damping), sizeof( ((idDeclAF_Constraint *)0)->damping ) },
	{ "float", "restLength", (int)(&((idDeclAF_Constraint *)0)->restLength), sizeof( ((idDeclAF_Constraint *)0)->restLength ) },
	{ "float", "minLength", (int)(&((idDeclAF_Constraint *)0)->minLength), sizeof( ((idDeclAF_Constraint *)0)->minLength ) },
	{ "float", "maxLength", (int)(&((idDeclAF_Constraint *)0)->maxLength), sizeof( ((idDeclAF_Constraint *)0)->maxLength ) },
	{ "idAFVector", "anchor", (int)(&((idDeclAF_Constraint *)0)->anchor), sizeof( ((idDeclAF_Constraint *)0)->anchor ) },
	{ "idAFVector", "anchor2", (int)(&((idDeclAF_Constraint *)0)->anchor2), sizeof( ((idDeclAF_Constraint *)0)->anchor2 ) },
	{ "idAFVector[2]", "shaft", (int)(&((idDeclAF_Constraint *)0)->shaft), sizeof( ((idDeclAF_Constraint *)0)->shaft ) },
	{ "idAFVector", "axis", (int)(&((idDeclAF_Constraint *)0)->axis), sizeof( ((idDeclAF_Constraint *)0)->axis ) },
	{ "idDeclAF_Constraint::enum_39", "limit", (int)(&((idDeclAF_Constraint *)0)->limit), sizeof( ((idDeclAF_Constraint *)0)->limit ) },
	{ "idAFVector", "limitAxis", (int)(&((idDeclAF_Constraint *)0)->limitAxis), sizeof( ((idDeclAF_Constraint *)0)->limitAxis ) },
	{ "float[3]", "limitAngles", (int)(&((idDeclAF_Constraint *)0)->limitAngles), sizeof( ((idDeclAF_Constraint *)0)->limitAngles ) },
	{ NULL, 0 }
};

static classVariableInfo_t idDeclAF_typeInfo[] = {
	{ "bool", "modified", (int)(&((idDeclAF *)0)->modified), sizeof( ((idDeclAF *)0)->modified ) },
	{ "idStr", "model", (int)(&((idDeclAF *)0)->model), sizeof( ((idDeclAF *)0)->model ) },
	{ "idStr", "skin", (int)(&((idDeclAF *)0)->skin), sizeof( ((idDeclAF *)0)->skin ) },
	{ "float", "defaultLinearFriction", (int)(&((idDeclAF *)0)->defaultLinearFriction), sizeof( ((idDeclAF *)0)->defaultLinearFriction ) },
	{ "float", "defaultAngularFriction", (int)(&((idDeclAF *)0)->defaultAngularFriction), sizeof( ((idDeclAF *)0)->defaultAngularFriction ) },
	{ "float", "defaultContactFriction", (int)(&((idDeclAF *)0)->defaultContactFriction), sizeof( ((idDeclAF *)0)->defaultContactFriction ) },
	{ "float", "defaultConstraintFriction", (int)(&((idDeclAF *)0)->defaultConstraintFriction), sizeof( ((idDeclAF *)0)->defaultConstraintFriction ) },
	{ "float", "totalMass", (int)(&((idDeclAF *)0)->totalMass), sizeof( ((idDeclAF *)0)->totalMass ) },
	{ "idVec2", "suspendVelocity", (int)(&((idDeclAF *)0)->suspendVelocity), sizeof( ((idDeclAF *)0)->suspendVelocity ) },
	{ "idVec2", "suspendAcceleration", (int)(&((idDeclAF *)0)->suspendAcceleration), sizeof( ((idDeclAF *)0)->suspendAcceleration ) },
	{ "float", "noMoveTime", (int)(&((idDeclAF *)0)->noMoveTime), sizeof( ((idDeclAF *)0)->noMoveTime ) },
	{ "float", "noMoveTranslation", (int)(&((idDeclAF *)0)->noMoveTranslation), sizeof( ((idDeclAF *)0)->noMoveTranslation ) },
	{ "float", "noMoveRotation", (int)(&((idDeclAF *)0)->noMoveRotation), sizeof( ((idDeclAF *)0)->noMoveRotation ) },
	{ "float", "minMoveTime", (int)(&((idDeclAF *)0)->minMoveTime), sizeof( ((idDeclAF *)0)->minMoveTime ) },
	{ "float", "maxMoveTime", (int)(&((idDeclAF *)0)->maxMoveTime), sizeof( ((idDeclAF *)0)->maxMoveTime ) },
	{ "int", "contents", (int)(&((idDeclAF *)0)->contents), sizeof( ((idDeclAF *)0)->contents ) },
	{ "int", "clipMask", (int)(&((idDeclAF *)0)->clipMask), sizeof( ((idDeclAF *)0)->clipMask ) },
	{ "bool", "selfCollision", (int)(&((idDeclAF *)0)->selfCollision), sizeof( ((idDeclAF *)0)->selfCollision ) },
	{ "idList < idDeclAF_Body * >", "bodies", (int)(&((idDeclAF *)0)->bodies), sizeof( ((idDeclAF *)0)->bodies ) },
	{ "idList < idDeclAF_Constraint * >", "constraints", (int)(&((idDeclAF *)0)->constraints), sizeof( ((idDeclAF *)0)->constraints ) },
	{ NULL, 0 }
};

static classVariableInfo_t idDeclEmail_typeInfo[] = {
	{ "idStr", "text", (int)(&((idDeclEmail *)0)->text), sizeof( ((idDeclEmail *)0)->text ) },
	{ "idStr", "subject", (int)(&((idDeclEmail *)0)->subject), sizeof( ((idDeclEmail *)0)->subject ) },
	{ "idStr", "date", (int)(&((idDeclEmail *)0)->date), sizeof( ((idDeclEmail *)0)->date ) },
	{ "idStr", "to", (int)(&((idDeclEmail *)0)->to), sizeof( ((idDeclEmail *)0)->to ) },
	{ "idStr", "from", (int)(&((idDeclEmail *)0)->from), sizeof( ((idDeclEmail *)0)->from ) },
	{ "idStr", "image", (int)(&((idDeclEmail *)0)->image), sizeof( ((idDeclEmail *)0)->image ) },
	{ NULL, 0 }
};

static classVariableInfo_t idDeclVideo_typeInfo[] = {
	{ "idStr", "preview", (int)(&((idDeclVideo *)0)->preview), sizeof( ((idDeclVideo *)0)->preview ) },
	{ "idStr", "video", (int)(&((idDeclVideo *)0)->video), sizeof( ((idDeclVideo *)0)->video ) },
	{ "idStr", "videoName", (int)(&((idDeclVideo *)0)->videoName), sizeof( ((idDeclVideo *)0)->videoName ) },
	{ "idStr", "info", (int)(&((idDeclVideo *)0)->info), sizeof( ((idDeclVideo *)0)->info ) },
	{ "idStr", "audio", (int)(&((idDeclVideo *)0)->audio), sizeof( ((idDeclVideo *)0)->audio ) },
	{ NULL, 0 }
};

static classVariableInfo_t idDeclAudio_typeInfo[] = {
	{ "idStr", "audio", (int)(&((idDeclAudio *)0)->audio), sizeof( ((idDeclAudio *)0)->audio ) },
	{ "idStr", "audioName", (int)(&((idDeclAudio *)0)->audioName), sizeof( ((idDeclAudio *)0)->audioName ) },
	{ "idStr", "info", (int)(&((idDeclAudio *)0)->info), sizeof( ((idDeclAudio *)0)->info ) },
	{ "idStr", "preview", (int)(&((idDeclAudio *)0)->preview), sizeof( ((idDeclAudio *)0)->preview ) },
	{ NULL, 0 }
};

static classVariableInfo_t idDeclPDA_typeInfo[] = {
	{ "mutable idStrList", "videos", (int)(&((idDeclPDA *)0)->videos), sizeof( ((idDeclPDA *)0)->videos ) },
	{ "mutable idStrList", "audios", (int)(&((idDeclPDA *)0)->audios), sizeof( ((idDeclPDA *)0)->audios ) },
	{ "mutable idStrList", "emails", (int)(&((idDeclPDA *)0)->emails), sizeof( ((idDeclPDA *)0)->emails ) },
	{ "idStr", "pdaName", (int)(&((idDeclPDA *)0)->pdaName), sizeof( ((idDeclPDA *)0)->pdaName ) },
	{ "idStr", "fullName", (int)(&((idDeclPDA *)0)->fullName), sizeof( ((idDeclPDA *)0)->fullName ) },
	{ "idStr", "icon", (int)(&((idDeclPDA *)0)->icon), sizeof( ((idDeclPDA *)0)->icon ) },
	{ "idStr", "id", (int)(&((idDeclPDA *)0)->id), sizeof( ((idDeclPDA *)0)->id ) },
	{ "idStr", "post", (int)(&((idDeclPDA *)0)->post), sizeof( ((idDeclPDA *)0)->post ) },
	{ "idStr", "title", (int)(&((idDeclPDA *)0)->title), sizeof( ((idDeclPDA *)0)->title ) },
	{ "mutable idStr", "security", (int)(&((idDeclPDA *)0)->security), sizeof( ((idDeclPDA *)0)->security ) },
	{ "mutable int", "originalEmails", (int)(&((idDeclPDA *)0)->originalEmails), sizeof( ((idDeclPDA *)0)->originalEmails ) },
	{ "mutable int", "originalVideos", (int)(&((idDeclPDA *)0)->originalVideos), sizeof( ((idDeclPDA *)0)->originalVideos ) },
	{ NULL, 0 }
};

static classTypeInfo_t classTypeInfo[] = {
	{ "sysEvent_t", "", sizeof(sysEvent_t), sysEvent_t_typeInfo },
	{ "sysMemoryStats_t", "", sizeof(sysMemoryStats_t), sysMemoryStats_t_typeInfo },
	{ "netadr_t", "", sizeof(netadr_t), netadr_t_typeInfo },
	{ "idPort", "", sizeof(idPort), idPort_typeInfo },
	{ "idTCP", "", sizeof(idTCP), idTCP_typeInfo },
	{ "xthreadInfo", "", sizeof(xthreadInfo), xthreadInfo_typeInfo },
	{ "idSys", "", sizeof(idSys), idSys_typeInfo },
	{ "idLib", "", sizeof(idLib), idLib_typeInfo },
	{ "idException", "", sizeof(idException), idException_typeInfo },
	{ "memoryStats_t", "", sizeof(memoryStats_t), memoryStats_t_typeInfo },
//	{ "idBlockAlloc< class type , int blockSize >::element_t", "", sizeof(idBlockAlloc< class type , int blockSize >::element_t), idBlockAlloc_class_type_int_blockSize__element_t_typeInfo },
//	{ "idBlockAlloc< class type , int blockSize >::block_t", "", sizeof(idBlockAlloc< class type , int blockSize >::block_t), idBlockAlloc_class_type_int_blockSize__block_t_typeInfo },
//	{ "idBlockAlloc< class type , int blockSize >", "", sizeof(idBlockAlloc< class type , int blockSize >), idBlockAlloc_class_type_int_blockSize__typeInfo },
//	{ "idDynamicAlloc< class type , int baseBlockSize , int minBlockSize >", "", sizeof(idDynamicAlloc< class type , int baseBlockSize , int minBlockSize >), idDynamicAlloc_class_type_int_baseBlockSize_int_minBlockSize__typeInfo },
//	{ "idBTreeNode< class objType , class keyType >", "", sizeof(idBTreeNode< class objType , class keyType >), idBTreeNode_class_objType_class_keyType__typeInfo },
//	{ "idBTree< class objType , class keyType , int maxChildrenPerNode >", "", sizeof(idBTree< class objType , class keyType , int maxChildrenPerNode >), idBTree_class_objType_class_keyType_int_maxChildrenPerNode__typeInfo },
//	{ "idDynamicBlock< class type >", "", sizeof(idDynamicBlock< class type >), idDynamicBlock_class_type__typeInfo },
//	{ "idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize >", "", sizeof(idDynamicBlockAlloc< class type , int baseBlockSize , int minBlockSize >), idDynamicBlockAlloc_class_type_int_baseBlockSize_int_minBlockSize__typeInfo },
//	{ "idList< class type >", "", sizeof(idList< class type >), idList_class_type__typeInfo },
	{ "idSIMD", "", sizeof(idSIMD), idSIMD_typeInfo },
	{ "idSIMDProcessor", "", sizeof(idSIMDProcessor), idSIMDProcessor_typeInfo },
	{ "idMath::_flint", "", sizeof(idMath::_flint), idMath__flint_typeInfo },
	{ "idMath", "", sizeof(idMath), idMath_typeInfo },
	{ "idRandom", "", sizeof(idRandom), idRandom_typeInfo },
	{ "idRandom2", "", sizeof(idRandom2), idRandom2_typeInfo },
	{ "idComplex", "", sizeof(idComplex), idComplex_typeInfo },
	{ "idVec2", "", sizeof(idVec2), idVec2_typeInfo },
	{ "idVec3", "", sizeof(idVec3), idVec3_typeInfo },
	{ "idVec4", "", sizeof(idVec4), idVec4_typeInfo },
	{ "idVec5", "", sizeof(idVec5), idVec5_typeInfo },
	{ "idVec6", "", sizeof(idVec6), idVec6_typeInfo },
	{ "idVecX", "", sizeof(idVecX), idVecX_typeInfo },
	{ "idPolar3", "", sizeof(idPolar3), idPolar3_typeInfo },
	{ "idMat2", "", sizeof(idMat2), idMat2_typeInfo },
	{ "idMat3", "", sizeof(idMat3), idMat3_typeInfo },
	{ "idMat4", "", sizeof(idMat4), idMat4_typeInfo },
	{ "idMat5", "", sizeof(idMat5), idMat5_typeInfo },
	{ "idMat6", "", sizeof(idMat6), idMat6_typeInfo },
	{ "idMatX", "", sizeof(idMatX), idMatX_typeInfo },
	{ "idAngles", "", sizeof(idAngles), idAngles_typeInfo },
	{ "idQuat", "", sizeof(idQuat), idQuat_typeInfo },
	{ "idCQuat", "", sizeof(idCQuat), idCQuat_typeInfo },
	{ "idRotation", "", sizeof(idRotation), idRotation_typeInfo },
	{ "idPlane", "", sizeof(idPlane), idPlane_typeInfo },
	{ "idPluecker", "", sizeof(idPluecker), idPluecker_typeInfo },
	{ "idPolynomial", "", sizeof(idPolynomial), idPolynomial_typeInfo },
//	{ "idExtrapolate< class type >", "", sizeof(idExtrapolate< class type >), idExtrapolate_class_type__typeInfo },
//	{ "idInterpolate< class type >", "", sizeof(idInterpolate< class type >), idInterpolate_class_type__typeInfo },
//	{ "idInterpolateAccelDecelLinear< class type >", "", sizeof(idInterpolateAccelDecelLinear< class type >), idInterpolateAccelDecelLinear_class_type__typeInfo },
//	{ "idInterpolateAccelDecelSine< class type >", "", sizeof(idInterpolateAccelDecelSine< class type >), idInterpolateAccelDecelSine_class_type__typeInfo },
//	{ "idCurve< class type >", "", sizeof(idCurve< class type >), idCurve_class_type__typeInfo },
//	{ "idCurve_Bezier< class type >", "idCurve< type >", sizeof(idCurve_Bezier< class type >), idCurve_Bezier_class_type__typeInfo },
//	{ "idCurve_QuadraticBezier< class type >", "idCurve< type >", sizeof(idCurve_QuadraticBezier< class type >), idCurve_QuadraticBezier_class_type__typeInfo },
//	{ "idCurve_CubicBezier< class type >", "idCurve< type >", sizeof(idCurve_CubicBezier< class type >), idCurve_CubicBezier_class_type__typeInfo },
//	{ "idCurve_Spline< class type >", "idCurve< type >", sizeof(idCurve_Spline< class type >), idCurve_Spline_class_type__typeInfo },
//	{ "idCurve_NaturalCubicSpline< class type >", "idCurve_Spline< type >", sizeof(idCurve_NaturalCubicSpline< class type >), idCurve_NaturalCubicSpline_class_type__typeInfo },
//	{ "idCurve_CatmullRomSpline< class type >", "idCurve_Spline< type >", sizeof(idCurve_CatmullRomSpline< class type >), idCurve_CatmullRomSpline_class_type__typeInfo },
//	{ "idCurve_KochanekBartelsSpline< class type >", "idCurve_Spline< type >", sizeof(idCurve_KochanekBartelsSpline< class type >), idCurve_KochanekBartelsSpline_class_type__typeInfo },
//	{ "idCurve_BSpline< class type >", "idCurve_Spline< type >", sizeof(idCurve_BSpline< class type >), idCurve_BSpline_class_type__typeInfo },
//	{ "idCurve_UniformCubicBSpline< class type >", "idCurve_BSpline< type >", sizeof(idCurve_UniformCubicBSpline< class type >), idCurve_UniformCubicBSpline_class_type__typeInfo },
//	{ "idCurve_NonUniformBSpline< class type >", "idCurve_BSpline< type >", sizeof(idCurve_NonUniformBSpline< class type >), idCurve_NonUniformBSpline_class_type__typeInfo },
//	{ "idCurve_NURBS< class type >", "idCurve_NonUniformBSpline< type >", sizeof(idCurve_NURBS< class type >), idCurve_NURBS_class_type__typeInfo },
	{ "idODE", "", sizeof(idODE), idODE_typeInfo },
	{ "idODE_Euler", "idODE", sizeof(idODE_Euler), idODE_Euler_typeInfo },
	{ "idODE_Midpoint", "idODE", sizeof(idODE_Midpoint), idODE_Midpoint_typeInfo },
	{ "idODE_RK4", "idODE", sizeof(idODE_RK4), idODE_RK4_typeInfo },
	{ "idODE_RK4Adaptive", "idODE", sizeof(idODE_RK4Adaptive), idODE_RK4Adaptive_typeInfo },
	{ "idLCP", "", sizeof(idLCP), idLCP_typeInfo },
	{ "idSphere", "", sizeof(idSphere), idSphere_typeInfo },
	{ "idBounds", "", sizeof(idBounds), idBounds_typeInfo },
	{ "idBox", "", sizeof(idBox), idBox_typeInfo },
	{ "idFrustum", "", sizeof(idFrustum), idFrustum_typeInfo },
	{ "idDrawVert", "", sizeof(idDrawVert), idDrawVert_typeInfo },
	{ "idJointQuat", "", sizeof(idJointQuat), idJointQuat_typeInfo },
	{ "idJointMat", "", sizeof(idJointMat), idJointMat_typeInfo },
	{ "idWinding", "", sizeof(idWinding), idWinding_typeInfo },
	{ "idFixedWinding", "idWinding", sizeof(idFixedWinding), idFixedWinding_typeInfo },
	{ "idWinding2D", "", sizeof(idWinding2D), idWinding2D_typeInfo },
	{ "surfaceEdge_t", "", sizeof(surfaceEdge_t), surfaceEdge_t_typeInfo },
	{ "idSurface", "", sizeof(idSurface), idSurface_typeInfo },
	{ "idSurface_Patch", "idSurface", sizeof(idSurface_Patch), idSurface_Patch_typeInfo },
	{ "idSurface_Polytope", "idSurface", sizeof(idSurface_Polytope), idSurface_Polytope_typeInfo },
	{ "idSurface_SweptSpline", "idSurface", sizeof(idSurface_SweptSpline), idSurface_SweptSpline_typeInfo },
	{ "traceModelEdge_t", "", sizeof(traceModelEdge_t), traceModelEdge_t_typeInfo },
	{ "traceModelPoly_t", "", sizeof(traceModelPoly_t), traceModelPoly_t_typeInfo },
	{ "idTraceModel", "", sizeof(idTraceModel), idTraceModel_typeInfo },
	{ "idStr", "", sizeof(idStr), idStr_typeInfo },
	{ "idToken", "idStr", sizeof(idToken), idToken_typeInfo },
	{ "punctuation_t", "", sizeof(punctuation_t), punctuation_t_typeInfo },
	{ "idLexer", "", sizeof(idLexer), idLexer_typeInfo },
	{ "define_t", "", sizeof(define_t), define_t_typeInfo },
	{ "indent_t", "", sizeof(indent_t), indent_t_typeInfo },
	{ "idParser", "", sizeof(idParser), idParser_typeInfo },
	{ "idBase64", "", sizeof(idBase64), idBase64_typeInfo },
	{ "idCmdArgs", "", sizeof(idCmdArgs), idCmdArgs_typeInfo },
	{ "idHashIndex", "", sizeof(idHashIndex), idHashIndex_typeInfo },
//	{ "idHashTable< class Type >::hashnode_s", "", sizeof(idHashTable< class Type >::hashnode_s), idHashTable_class_Type__hashnode_s_typeInfo },
//	{ "idHashTable< class Type >", "", sizeof(idHashTable< class Type >), idHashTable_class_Type__typeInfo },
//	{ "idStaticList< class type , int size >", "", sizeof(idStaticList< class type , int size >), idStaticList_class_type_int_size__typeInfo },
//	{ "idLinkList< class type >", "", sizeof(idLinkList< class type >), idLinkList_class_type__typeInfo },
//	{ "idHierarchy< class type >", "", sizeof(idHierarchy< class type >), idHierarchy_class_type__typeInfo },
//	{ "idQueueTemplate< class type , int nextOffset >", "", sizeof(idQueueTemplate< class type , int nextOffset >), idQueueTemplate_class_type_int_nextOffset__typeInfo },
//	{ "idStackTemplate< class type , int nextOffset >", "", sizeof(idStackTemplate< class type , int nextOffset >), idStackTemplate_class_type_int_nextOffset__typeInfo },
	{ "idPoolStr", "idStr", sizeof(idPoolStr), idPoolStr_typeInfo },
	{ "idStrPool", "", sizeof(idStrPool), idStrPool_typeInfo },
//	{ "idVectorSet< class type , int dimension >", "idList< type >", sizeof(idVectorSet< class type , int dimension >), idVectorSet_class_type_int_dimension__typeInfo },
//	{ "idVectorSubset< class type , int dimension >", "", sizeof(idVectorSubset< class type , int dimension >), idVectorSubset_class_type_int_dimension__typeInfo },
	{ "idPlaneSet", "idList< idPlane >", sizeof(idPlaneSet), idPlaneSet_typeInfo },
	{ "idKeyValue", "", sizeof(idKeyValue), idKeyValue_typeInfo },
	{ "idDict", "", sizeof(idDict), idDict_typeInfo },
	{ "idLangKeyValue", "", sizeof(idLangKeyValue), idLangKeyValue_typeInfo },
	{ "idLangDict", "", sizeof(idLangDict), idLangDict_typeInfo },
	{ "idBitMsg", "", sizeof(idBitMsg), idBitMsg_typeInfo },
	{ "idBitMsgDelta", "", sizeof(idBitMsgDelta), idBitMsgDelta_typeInfo },
	{ "idMapPrimitive", "", sizeof(idMapPrimitive), idMapPrimitive_typeInfo },
	{ "idMapBrushSide", "", sizeof(idMapBrushSide), idMapBrushSide_typeInfo },
	{ "idMapBrush", "idMapPrimitive", sizeof(idMapBrush), idMapBrush_typeInfo },
	{ "idMapPatch", "idSurface_Patch", sizeof(idMapPatch), idMapPatch_typeInfo },
	{ "idMapEntity", "", sizeof(idMapEntity), idMapEntity_typeInfo },
	{ "idMapFile", "", sizeof(idMapFile), idMapFile_typeInfo },
	{ "idTimer", "", sizeof(idTimer), idTimer_typeInfo },
	{ "idTimerReport", "", sizeof(idTimerReport), idTimerReport_typeInfo },
	{ "idCmdSystem", "", sizeof(idCmdSystem), idCmdSystem_typeInfo },
	{ "idCVar", "", sizeof(idCVar), idCVar_typeInfo },
	{ "idCVarSystem", "", sizeof(idCVarSystem), idCVarSystem_typeInfo },
	{ "MemInfo_t", "", sizeof(MemInfo_t), MemInfo_t_typeInfo },
	{ "idCommon", "", sizeof(idCommon), idCommon_typeInfo },
	{ "idFile", "", sizeof(idFile), idFile_typeInfo },
	{ "idFile_Memory", "idFile", sizeof(idFile_Memory), idFile_Memory_typeInfo },
	{ "idFile_BitMsg", "idFile", sizeof(idFile_BitMsg), idFile_BitMsg_typeInfo },
	{ "idFile_Permanent", "idFile", sizeof(idFile_Permanent), idFile_Permanent_typeInfo },
	{ "idFile_InZip", "idFile", sizeof(idFile_InZip), idFile_InZip_typeInfo },
	{ "urlDownload_t", "", sizeof(urlDownload_t), urlDownload_t_typeInfo },
	{ "fileDownload_t", "", sizeof(fileDownload_t), fileDownload_t_typeInfo },
	{ "backgroundDownload_t", "", sizeof(backgroundDownload_t), backgroundDownload_t_typeInfo },
	{ "idFileList", "", sizeof(idFileList), idFileList_typeInfo },
	{ "idModList", "", sizeof(idModList), idModList_typeInfo },
	{ "idFileSystem", "", sizeof(idFileSystem), idFileSystem_typeInfo },
	{ "usercmd_t", "", sizeof(usercmd_t), usercmd_t_typeInfo },
	{ "idUsercmdGen", "", sizeof(idUsercmdGen), idUsercmdGen_typeInfo },
	{ "idDeclBase", "", sizeof(idDeclBase), idDeclBase_typeInfo },
	{ "idDecl", "", sizeof(idDecl), idDecl_typeInfo },
	{ "idDeclManager", "", sizeof(idDeclManager), idDeclManager_typeInfo },
	{ "idDeclTable", "idDecl", sizeof(idDeclTable), idDeclTable_typeInfo },
	{ "skinMapping_t", "", sizeof(skinMapping_t), skinMapping_t_typeInfo },
	{ "idDeclSkin", "idDecl", sizeof(idDeclSkin), idDeclSkin_typeInfo },
	{ "idDeclEntityDef", "idDecl", sizeof(idDeclEntityDef), idDeclEntityDef_typeInfo },
	{ "idFXSingleAction", "", sizeof(idFXSingleAction), idFXSingleAction_typeInfo },
	{ "idDeclFX", "idDecl", sizeof(idDeclFX), idDeclFX_typeInfo },
	{ "idParticleParm", "", sizeof(idParticleParm), idParticleParm_typeInfo },
	{ "particleGen_t", "", sizeof(particleGen_t), particleGen_t_typeInfo },
	{ "idParticleStage", "", sizeof(idParticleStage), idParticleStage_typeInfo },
	{ "idDeclParticle", "idDecl", sizeof(idDeclParticle), idDeclParticle_typeInfo },
	{ "idAFVector", "", sizeof(idAFVector), idAFVector_typeInfo },
	{ "idDeclAF_Body", "", sizeof(idDeclAF_Body), idDeclAF_Body_typeInfo },
	{ "idDeclAF_Constraint", "", sizeof(idDeclAF_Constraint), idDeclAF_Constraint_typeInfo },
	{ "idDeclAF", "idDecl", sizeof(idDeclAF), idDeclAF_typeInfo },
	{ "idDeclEmail", "idDecl", sizeof(idDeclEmail), idDeclEmail_typeInfo },
	{ "idDeclVideo", "idDecl", sizeof(idDeclVideo), idDeclVideo_typeInfo },
	{ "idDeclAudio", "idDecl", sizeof(idDeclAudio), idDeclAudio_typeInfo },
	{ "idDeclPDA", "idDecl", sizeof(idDeclPDA), idDeclPDA_typeInfo },
	{ NULL, NULL, 0, NULL }
};

#endif /* !__GAMETYPEINFO_H__ */
