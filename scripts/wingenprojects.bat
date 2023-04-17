@echo off
pushd %~dp0\..\
call D:\Graphics\Ulta\external\premake\windows\premake5.exe vs2022
popd
PAUSE