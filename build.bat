:: Author: Sebastien Maire
:: Contribs:

::@echo off
set argc=0
for %%x in (%*) do Set /A argc+=1

set build_folder=".\build\"
set build_config="debug"


if %argc% == 0 goto %build_config%
goto :%1

:all
mkdir %build_folder%
cd %build_folder%
cmake ..
cmake --build . --target ALL_BUILD --config %build_config%
cd ..
goto :wait_key

:proj
cd %build_folder%
cmake ..\
cd ..

:re
rmdir %build_folder%
goto :all

:reproj


:help
type "build_help.txt"

:wait_key
pause