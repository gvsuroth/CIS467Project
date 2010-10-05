#include <stdio.h>
#include <stdlib.h>
#include <sys/io.h>

#define port 0x0378  /* printer port address */

int main() {
	if (ioperm(port, 1, 1))
		printf("Could not connect to the port.\n"), exit(1);

	outb(255, port);
	sleep(2);
	return 0;
}
