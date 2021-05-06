@echo off
title Practica 3
color 03

:menu
cls
echo.
echo.
echo    ++++++++++++++++++
echo    +   Caculadora   +
echo    ++++++++++++++++++
echo.
echo.

echo        1.- Suma
echo        2.- Resta
echo        3.- Multiplicacion
echo        4.- Divicion
echo        5.- Salir
echo.
set /p opc= Ingrese opcion deseada: 
REM para guardar en variables


::Sintaxis el if completamente diferente, proceso de adaptacion
if %opc%==1 (goto suma) else goto p1
:p1
if %opc%==2 (goto resta) else goto p2
:p2
if %opc%==3 (goto multiplicacion) else goto p3
:p3
if %opc%==4 (goto divicion) else goto p4
:p4
if %opc%==5 (goto salir) else goto menu


:suma
cls
echo    ++++++++++++++++++
echo    +      Suma      +
echo    ++++++++++++++++++
echo.
set /p n1= Ingrese un numero: 
set /p n2= Ingrese un otro numero: 
set /a r= %n1% + %n2% REM Realizar operacion
echo.
echo Resultado de la suma es: %r% REM Para mostrar variable
pause
goto menu

:resta
cls
echo    ++++++++++++++++++
echo    +      Resta     +
echo    ++++++++++++++++++
echo.
set /p n1= Ingrese un numero: 
set /p n2= Ingrese un otro numero: 
set /a r= %n1% - %n2%
echo.
echo Resultado de la resta es: %r%
pause
goto menu

:multiplicacion
cls
echo    ++++++++++++++++++
echo    + Multiplicacion +
echo    ++++++++++++++++++
echo.
set /p n1= Ingrese un numero: 
set /p n2= Ingrese un otro numero: 
set /a r= %n1% * %n2%
echo.
echo Resultado de la multiplicacion es: %r%
pause
goto menu

:divicion
cls
echo    ++++++++++++++++++
echo    +    Divicion    +
echo    ++++++++++++++++++
echo.
set /p n1= Ingrese un numero: 
set /p n2= Ingrese un otro numero: 
set /a r= %n1% / %n2%
echo.
echo Resultado de la Divicion es: %r%
pause
goto menu

:salir
pause