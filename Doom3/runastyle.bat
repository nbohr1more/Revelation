rem A script to run Astyle for the sources
rem Astyle is a source indenter / formatter.
@echo off
CLS
rem options are in astyle-options.ini
SET STYLE=--options=astyle-options.ini
rem also add brackets to unbracketed functions.
SET OPTIONS=--add-brackets

rem carefull here do not enable everything 
rem astyle can fuck up asm code majorly.
rem idlib has one place that comes to mind in the SIMD code.
rem astyle %STYLE% %OPTIONS% -r neo/game/*.cpp
rem astyle %STYLE% %OPTIONS% -r neo/game/*.h
rem astyle %STYLE% %OPTIONS% -r neo/d3xp/*.cpp
rem astyle %STYLE% %OPTIONS% -r neo/d3xp/*.h
rem astyle %STYLE% %OPTIONS% -r neo/cm/*.cpp
rem astyle %STYLE% %OPTIONS% -r neo/cm/*.h
rem astyle %STYLE% %OPTIONS% -r neo/framework/*.cpp
rem astyle %STYLE% %OPTIONS% -r neo/framework/*.h
rem astyle %STYLE% %OPTIONS% -r neo/idlib/*.cpp
rem astyle %STYLE% %OPTIONS% -r neo/idlib/*.h
rem astyle %STYLE% %OPTIONS% -r neo/libs/*.cpp
rem astyle %STYLE% %OPTIONS% -r neo/libs/*.h
astyle %STYLE% %OPTIONS% -r neo/renderer/*.cpp
astyle %STYLE% %OPTIONS% -r neo/renderer/*.h
rem astyle %STYLE% %OPTIONS% -r neo/sound/*.cpp
rem astyle %STYLE% %OPTIONS% -r neo/sound/*.h
rem astyle %STYLE% %OPTIONS% -r neo/sys/*.cpp
rem astyle %STYLE% %OPTIONS% -r neo/sys/*.h
rem astyle %STYLE% %OPTIONS% -r neo/typeinfo/*.cpp
rem astyle %STYLE% %OPTIONS% -r neo/typeinfo/*.h
rem astyle %STYLE% %OPTIONS% -r neo/tools/*.cpp
rem astyle %STYLE% %OPTIONS% -r neo/tools/*.h
rem astyle %STYLE% %OPTIONS% -r neo/ui/*.cpp
rem astyle %STYLE% %OPTIONS% -r neo/ui/*.h

rem astyle %STYLE% %OPTIONS% -r extras/*.cpp
rem astyle %STYLE% %OPTIONS% -r extras/*.h

pause



