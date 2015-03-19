:: Author: Sebastien Maire
:: Contribs:

@echo off
set argc=0
for %%x in (%*) do Set /A argc+=1

set build_folder=".\build\"

if %argc% == 0 goto :all
goto :%1

if %argc% > 1 set build_config="Release"

:all

:release

:debug

:sol

:re

:resol

:help
type "build_help.txt"

:wait_key
pause