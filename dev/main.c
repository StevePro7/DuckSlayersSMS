#include "main.h"

void main(void)
{
	
}

#ifdef _CONSOLE
#else
	SMS_EMBED_SEGA_ROM_HEADER(9999, 0);
	SMS_EMBED_SDSC_HEADER(1, 0, 2017, 3, 17, "StevePro Studios", "Candy Kid Demo", "DESC");
#endif

