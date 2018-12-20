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