attrib *.* -r -a -s -h /s /d

del neo\*.suo /q
del neo\*.user /q
del neo\*.sdf /q

rmdir neo\ipch /s /q
rmdir build /s /q

echo Done

pause
