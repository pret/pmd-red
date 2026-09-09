@echo off
setlocal EnableDelayedExpansion
rem ============================================================
rem  win_rebuild_pc.bat - rebuild the PC port (pmd-red-game.exe)
rem
rem  Uses the MSYS2 MINGW32 environment so the 32-bit host build
rem  (SDL2.dll and the ARM toolchain under build/deps) matches.
rem
rem  Usage:
rem    win_rebuild_pc.bat              incremental rebuild + restage
rem    win_rebuild_pc.bat clean        clean-pc + rebuild + restage
rem    win_rebuild_pc.bat full         same as clean
rem ============================================================

set "SCRIPT_DIR=%~dp0"
rem repo root = parent of the script dir, trailing backslash stripped
set "ROOT=%SCRIPT_DIR%.."
if "%ROOT:~-1%"=="\" set "ROOT=%ROOT:~0,-1%"

rem ---- locate MSYS2 root (override with first arg) ----
set "MSYS_ROOT=%~1"
if not defined MSYS_ROOT if exist "C:\msys64" set "MSYS_ROOT=C:\msys64"
if not defined MSYS_ROOT if exist "C:\msys2" set "MSYS_ROOT=C:\msys2"
if not defined MSYS_ROOT (
    echo [win_rebuild_pc] MSYS2 not found at C:\msys64 or C:\msys2.
    echo Pass the install dir as the first argument, e.g.:
    echo   win_rebuild_pc.bat "D:\msys64"
    exit /b 1
)
if not exist "%MSYS_ROOT%\msys2_shell.cmd" (
    echo [win_rebuild_pc] msys2_shell.cmd not found in %MSYS_ROOT%
    exit /b 1
)

rem ---- convert windows path to an MSYS path (/c/Users/...) ----
set "MROOT=%ROOT:\=/%"
for %%d in (a b c d e f g h i j k l m n o p q r s t u v w x y z) do set "MROOT=!MROOT:%%d:=/%%d!"
for %%d in (A B C D E F G H I J K L M N O P Q R S T U V W X Y Z) do set "MROOT=!MROOT:%%d:=/%%d!"

set "TARGETS=game-link stage-game"
if /I "%~1"=="clean" set "TARGETS=clean-pc game-link stage-game"
if /I "%~1"=="full" set "TARGETS=clean-pc game-link stage-game"

echo [win_rebuild_pc] root=%ROOT%
echo [win_rebuild_pc] msys2=%MSYS_ROOT%
echo [win_rebuild_pc] targets=%TARGETS%

"%MSYS_ROOT%\msys2_shell.cmd" -mingw32 -defterm -no-start -c "cd '%MROOT%' && make -f platform/pc/Makefile.pc %TARGETS%"
set "RC=%ERRORLEVEL%"
if not "%RC%"=="0" (
    echo [win_rebuild_pc] build FAILED ^(exit %RC%^).
    exit /b %RC%
)
echo [win_rebuild_pc] build OK - build\pmd-red-game.exe is ready.
exit /b 0