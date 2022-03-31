@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by QASYSTEM.HPJ. >"hlp\QAsystem.hm"
echo. >>"hlp\QAsystem.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\QAsystem.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\QAsystem.hm"
echo. >>"hlp\QAsystem.hm"
echo // Prompts (IDP_*) >>"hlp\QAsystem.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\QAsystem.hm"
echo. >>"hlp\QAsystem.hm"
echo // Resources (IDR_*) >>"hlp\QAsystem.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\QAsystem.hm"
echo. >>"hlp\QAsystem.hm"
echo // Dialogs (IDD_*) >>"hlp\QAsystem.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\QAsystem.hm"
echo. >>"hlp\QAsystem.hm"
echo // Frame Controls (IDW_*) >>"hlp\QAsystem.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\QAsystem.hm"
REM -- Make help for Project QASYSTEM


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\QAsystem.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\QAsystem.hlp" goto :Error
if not exist "hlp\QAsystem.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\QAsystem.hlp" Debug
if exist Debug\nul copy "hlp\QAsystem.cnt" Debug
if exist Release\nul copy "hlp\QAsystem.hlp" Release
if exist Release\nul copy "hlp\QAsystem.cnt" Release
echo.
goto :done

:Error
echo hlp\QAsystem.hpj(1) : error: Problem encountered creating help file

:done
echo.
