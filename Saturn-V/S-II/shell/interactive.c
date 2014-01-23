/*	A part of kestrel
	Kestrel Kernel Project
	Copyright 2007-2014 BMY-Soft
	Copyright 2007-2014 PC GO Ld.

	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*/

#include <kestrel/kernel.h>
#include <kestrel/shell.h>

void enter_shell() {
	char *prompt;

	kernel_printf("Kestrel Kernel build-in shell\n\n");

	while(1) {
		prompt = "kestrel> ";
		kernel_printf(prompt);

		//int c = console_getkey();
		int c = kernel_getchar();
		putchar('\n');
		kernel_printf("You pressed %d(%c)\n", c, c);
		//kernel_panic("Not implemented", 38);
	}
}
