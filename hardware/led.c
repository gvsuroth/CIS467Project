#include <stdio.h>
#include <stdlib.h>
#include <sys/io.h>

#define port 0x0378  /* printer port address */

int main() {
	if (ioperm(port, 1, 1))
		printf("Could not connect to the port.\n"), exit(1);

	// 255 sets all ports to high
  int disp[5];
  disp[0] = 1;
  disp[1] = 0;
  disp[2] = 0;
  disp[3] = 1;
  disp[4] = 1;

  int step = 0;
  while(1) {
    int out = disp[step] << step;
    outb(out, port);
    step++;
    usleep(5000);
    printf("Out: %d\n", out);
  }

	return 0;
}
