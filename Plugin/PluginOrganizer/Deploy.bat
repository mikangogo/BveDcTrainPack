@echo off
setlocal

set SOURCE_NAME=PluginOrganizer.dll
set SOURCE_PATH=

for /f "usebackq delims=" %%a in (`chdir`) do @set SOURCE_PATH=%%a
set SOURCE_PATH=%SOURCE_PATH%\%SOURCE_NAME%

echo %SOURCE_PATH%

forfiles /P .\..\..\Vehicle /M %SOURCE_NAME% /S /c "cmd /c xcopy %SOURCE_PATH% @path /Y%"

endlocal
