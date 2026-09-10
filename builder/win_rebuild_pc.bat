@echo off
setlocal EnableDelayedExpansion
rem ============================================================
rem  win_rebuild_pc.bat - rebuild the PC port (pmd-red-game.exe)
rem
rem  Uses the MSYS2 MINGW32 environment so the 32-bit host build
rem  (SDL2.dll and the ARM toolchain under build/deps) matches.
rem
rem  If the ARM GNU toolchain is missing it asks before downloading
rem  it into build\deps (needed to assemble the data\*.s blobs).
rem
rem  Usage:
rem    win_rebuild_pc.bat              incremental rebuild + restage
rem    win_rebuild_pc.bat clean        clean-pc + rebuild + restage
rem    win_rebuild_pc.bat full         same as clean
rem    win_rebuild_pc.bat "D:\msys64"  set MSYS2 install dir
rem ============================================================

set "SCRIPT_DIR=%~dp0"
rem repo root = parent of the script dir, trailing backslash stripped
set "ROOT=%SCRIPT_DIR%.."
if "%ROOT:~-1%"=="\" set "ROOT=%ROOT:~0,-1%"

rem ---- parse args: mode (clean/full) vs. MSYS2 root override ----
set "MODE="
set "MSYS_ROOT="
set "FIRST=%~1"
set "SECOND=%~2"
if /I "%FIRST%"=="clean" set "MODE=clean"
if /I "%FIRST%"=="full" set "MODE=full"
if /I "%SECOND%"=="clean" set "MODE=clean"
if /I "%SECOND%"=="full" set "MODE=full"
rem the first arg is a root override only when it is not a mode
if not defined MODE if not "%FIRST%"=="" set "MSYS_ROOT=%FIRST%"
if defined MODE if not "%SECOND%"=="" set "MSYS_ROOT=%SECOND%"

rem ---- locate MSYS2 root ----
if not defined MSYS_ROOT if exist "C:\msys64" set "MSYS_ROOT=C:\msys64"
if not defined MSYS_ROOT if exist "C:\msys2" set "MSYS_ROOT=C:\msys2"
if not defined MSYS_ROOT (
    echo [win_rebuild_pc] Build failed: MSYS2 not found at C:\msys64 or C:\msys2.
    echo Install MSYS2 with the mingw-w64-i686 toolchain, then pass its dir:
    echo   win_rebuild_pc.bat "D:\msys64"
    set "RC=1"
    goto :end
)
if not exist "%MSYS_ROOT%\usr\bin\bash.exe" (
    echo [win_rebuild_pc] Build failed: bash.exe not found in %MSYS_ROOT%\usr\bin
    set "RC=1"
    goto :end
)

rem ---- ensure the ARM GNU toolchain (data\*.s blob assembly) ----
set "ARM_TC_DIR="
for /d %%d in ("%ROOT%\build\deps\arm-gnu-toolchain-*") do if exist "%%d\bin\arm-none-eabi-cpp.exe" set "ARM_TC_DIR=%%d"
if not defined ARM_TC_DIR (
    echo [win_rebuild_pc] ARM GNU toolchain is missing.
    echo It is required to preprocess and assemble the data\*.s blob sources.
    echo   ARM GNU Toolchain 13.2.rel1 ^(mingw-w64-i686^), ^~364 MB from ARM.
    set /p DOWNLOAD=Download it now? [y/n]: 
    if /I not "!DOWNLOAD!"=="y" (
        echo [win_rebuild_pc] Build aborted.
        set "RC=1"
        goto :end
    )
    echo [win_rebuild_pc] Downloading ARM GNU toolchain ^(^~364 MB^)...
    if not exist "%ROOT%\build\deps\src" mkdir "%ROOT%\build\deps\src"
    "%MSYS_ROOT%\usr\bin\curl.exe" -L --fail -o "%ROOT%\build\deps\src\arm-gnu-toolchain.zip" "https://developer.arm.com/-/media/Files/downloads/gnu/13.2.rel1/binrel/arm-gnu-toolchain-13.2.rel1-mingw-w64-i686-arm-none-eabi.zip"
    set "RC=!ERRORLEVEL!"
    if not "!RC!"=="0" (
        echo [win_rebuild_pc] Build failed: ARM toolchain download failed.
        goto :end
    )
    echo [win_rebuild_pc] Extracting ARM GNU toolchain...
    "%MSYS_ROOT%\usr\bin\unzip.exe" -q -o "%ROOT%\build\deps\src\arm-gnu-toolchain.zip" -d "%ROOT%\build\deps"
    set "RC=!ERRORLEVEL!"
    if not "!RC!"=="0" (
        echo [win_rebuild_pc] Build failed: ARM toolchain extraction failed.
        goto :end
    )
    set "ARM_TC_DIR="
    for /d %%d in ("%ROOT%\build\deps\arm-gnu-toolchain-*") do if exist "%%d\bin\arm-none-eabi-cpp.exe" set "ARM_TC_DIR=%%d"
    if not defined ARM_TC_DIR (
        echo [win_rebuild_pc] Build failed: ARM toolchain not found after extraction.
        set "RC=1"
        goto :end
    )
    echo [win_rebuild_pc] ARM GNU toolchain installed.
)

rem ---- convert windows path to an MSYS path (/c/Users/...) ----
set "MROOT=%ROOT:\=/%"
for %%d in (a b c d e f g h i j k l m n o p q r s t u v w x y z) do set "MROOT=!MROOT:%%d:=/%%d!"
for %%d in (A B C D E F G H I J K L M N O P Q R S T U V W X Y Z) do set "MROOT=!MROOT:%%d:=/%%d!"

set "TARGETS=game-link stage-game"
if /I "%MODE%"=="clean" set "TARGETS=clean-pc game-link stage-game"
if /I "%MODE%"=="full" set "TARGETS=clean-pc game-link stage-game"

echo [win_rebuild_pc] root=%ROOT%
echo [win_rebuild_pc] msys2=%MSYS_ROOT%
echo [win_rebuild_pc] targets=%TARGETS%

rem ---- run the build in the MSYS2 MINGW32 login shell ----
set "MSYSTEM=MINGW32"
"%MSYS_ROOT%\usr\bin\bash.exe" -lc "cd '%MROOT%' && export PATH=/usr/bin:/mingw32/bin:$PATH && make -f platform/pc/Makefile.pc %TARGETS%"
set "RC=%ERRORLEVEL%"
if not "%RC%"=="0" (
    echo [win_rebuild_pc] Build failed: make exited with code %RC%.
    goto :end
)

rem ---- ensure a clickable exe exists in build\ ----
set "EXE=%ROOT%\build\pmd-red-game.exe"
if not exist "%EXE%" if exist "%ROOT%\build\pmd-red-game" copy /Y "%ROOT%\build\pmd-red-game" "%EXE%" >nul
if not exist "%EXE%" (
    echo [win_rebuild_pc] Build failed: build\pmd-red-game.exe not found after make.
    set "RC=1"
    goto :end
)
echo [win_rebuild_pc] Build successful - %EXE% is ready.

:end
echo.
echo [win_rebuild_pc] Press any button to close...
pause >nul
exit /b %RC%