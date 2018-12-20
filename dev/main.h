#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _CONSOLE
#include "..\tmp\SMSlib.h"
#include "..\tmp\PSGlib.h"
#else
#include "..\lib\SMSlib.h"
#include "..\lib\PSGlib.h"
#endif

#include "gfx.h"