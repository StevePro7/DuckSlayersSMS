@echo off

REM folder2c ..\gfx gfx

REM echo Build gfx
REM sdcc -c -mz80 gfx.c

sdcc -c -mz80 main.c
sdcc -o output.ihx -mz80 --data-loc 0xC000 --no-std-crt0 ..\crt0\crt0_sms.rel main.rel ..\lib\SMSlib.lib ..\lib\PSGlib.rel gfx.rel
ihx2sms output.ihx output.sms


REM copy output.sms ..\asm
REM cd ..\asm
REM smsexamine.exe output.sms
REM cd ..\dev


del *.asm > nul
del *.ihx > nul
del *.lk > nul
del *.lst > nul
del *.map > nul
del *.noi > nul
del *.rel > nul
del *.sym > nul

E:\Fusion\fusion.exe output.sms
REM E:\Meka\mekaw.exe output.sms
REM java -jar E:\Emulicious\emulicious.jar output.sms