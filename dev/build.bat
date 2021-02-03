@echo off

folder2c ..\gfx gfx

REM echo Build gfx
sdcc --debug -c -mz80 gfx.c

sdcc --debug -c -mz80 main.c --disable-warning 110
sdcc --debug -o output.ihx -mz80 --data-loc 0xC000 --no-std-crt0 ..\crt0\crt0_sms.rel main.rel ..\lib\SMSlib.lib ..\lib\PSGlib.rel gfx.rel
ihx2sms output.ihx output.sms


::copy output.sms ..\asm
::cd ..\asm
::smsexamine.exe output.sms
::cd ..\dev


del *.asm > nul
del *.ihx > nul
del *.lk > nul
del *.lst > nul
del *.map > nul
del *.noi > nul
del main.rel > nul
del *.sym > nul

 C:\SEGA\Fusion\fusion.exe output.sms
::  C:\SEGA\Meka\mekaw.exe output.sms
::java -jar C:\SEGA\Emulicious\emulicious.jar output.sms