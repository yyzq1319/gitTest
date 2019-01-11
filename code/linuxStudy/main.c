#include <stdio.h>  
#include "open.h"
#include "fcntl_write.h"

int main(int argc, char *argv[])  
 {  
	printf("Hello world, this is my first app!\r\n");
	char buf[255] = argv[0];
	
    printf("%s\n",buf);

	return 0;  
}  
