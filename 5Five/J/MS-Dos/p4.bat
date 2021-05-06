@echo off
title Practica_4

:menu
cls
echo ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
echo +
echo + Fecha actual: %Date%
echo +
echo + Hora precisa en que se ejecuto el programa: %Time%
echo +
echo ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

echo.
echo              1.- Crear carpeta 
echo              2.- Crear archivo
echo              3.- Editar archivo
echo              4.- Renombrar carpeta
echo              5.- Renombrar archivo
echo              6.- Mover carpeta
echo              7.- Copiar carpeta
echo              8.- Salir
echo.
set /p opc=   Ingrese opcion deseada: 

if %opc%==1 (goto cc) else goto p1
:p1
if %opc%==2 (goto ca) else goto p2
:p2
if %opc%==3 (goto ea) else goto p3
:p3
if %opc%==4 (goto rc) else goto p4
:p4
if %opc%==5 (goto ra) else goto p5
:p5
if %opc%==6 (goto mc) else goto p6
:p6
if %opc%==7 (goto cp) else goto p7
:p7
if %opc%==8 (goto salir) else goto menu

:cc
cls
echo ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
echo +
echo +            1.- Crear carpeta
echo +
echo ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
set /p nc= Nombre de la carpeta: 
md %nc%
pause
goto menu

:ca
cls
echo ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
echo +
echo +            2.- Crear archivo
echo +
echo ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
set /p na= Nombre del archivo: 
COPY CON %na%
pause
goto menu

:ea
cls
echo ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
echo +
echo +            3.- Editar archivo
echo +
echo ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
set /p na= Nombre del archivo: 
notepad %na%
pause
goto menu

:rc
cls
echo ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
echo +
echo +            4.- Renombrar carpeta
echo +
echo ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
set /p ori= Nombre original de la carpeta: 
set /p nueva= Nuevo nombre de la carpeta: 
ren %ori% %nueva%
pause
goto menu

:ra
cls
echo ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
echo +
echo +            5.- Renombrar archivo
echo +
echo ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
set /p ori= Nombre original del archivo: 
set /p nueva= Nuevo nombre del archivo: 
ren %ori% %nueva%
pause
goto menu

:mc
cls
echo ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
echo +
echo +            6.- Mover carpeta
echo +
echo ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
set /p ori= Nombre de la carpeta: 
set /p nueva= Nuevo direccion de la carpeta: 
move %ori% %nueva%
pause
goto menu

:cp
cls
echo ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
echo +
echo +            7.- Copiar carpeta
echo +
echo ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
set /p ori= Nombre de la carpeta: 
set /p nueva= Nombre de la copia: 
xcopy %ori% %nueva% /s/c/y
pause
goto menu

pause
:salir