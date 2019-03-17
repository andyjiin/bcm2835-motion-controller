#include <stdio.h>

#include "common/inc/status.h"
#include "hal/bcm2835.h"

static Status init() {
	if (!bcm2835_init()) {
    	return STATUS_FAILURE;
	}
}

int main(void) {
	if (init() != STATUS_OK) {
		return 1;
	}

	/*while(true) {
		printf("running \n");
	}*/

	return 0;
}