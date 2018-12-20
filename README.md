# DuckSlayersSMS
Test repository for original Duck Slayers

ORG source code
E:\Steven\INSTALLATIONSEGA\SMSPower\2018\DuckslayerAdventures-SMS-0.3.0-src

My first attempt
E:\Steven\INSTALLATIONSEGA\SMSPower\SteveSlayerAdventures


warning C4090: 'initializing': different 'const' qualifiers
Turns out that the folder2c generates all gfx.h and gfx.c as const
Therefore, the code that consumes thia should also be const

This also includes the *map and *frames but original const actor_class now non-const

Other z80 warnings
main.c:462: warning 59: function 'green_dragon_ai' must return value
main.c:462: warning 59: function 'yellow_dragon_ai' must return value
there was no return type of void on these 2x methods

main.c:448: warning 110: conditional flow changed by optimizer: so said EVELYN the modified DOG
main.c:459: warning 110: conditional flow changed by optimizer: so said EVELYN the modified DOG

this can be "removed" either 2x ways
https://sourceforge.net/p/sdcc/bugs/2441

01.
main.c
#pragma disable_warning 110

02.
build.bat
sdcc -c -mz80 main.c --disable-warning 110