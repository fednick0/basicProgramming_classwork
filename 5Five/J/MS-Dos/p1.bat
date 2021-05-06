@echo off
title MATRIX
REM esto es un comentario

set /p Nombre=Escriba su nombre 
echo Hola %Nombre%
pause

color 02

echo %random%

echo.

pause>nul

::de ahuevo el = junto a la variable
set n= 7
set m= 3
set /a r= %n% + %m%
echo %r%

pause

exit