#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int open_test(void)
{
	int fd,size;
	char *buf_w = "I like the word,I like linux.";
	char buf_r[100];
    unsigned int len = 0;
   
    len = strlen(buf_w);

    /*创建文件hello.c*/ 
	if((fd=open("/home/hian/code/test/hello.c",O_CREAT|O_TRUNC|O_RDWR,0777))<0)
	{
		perror("open");
		exit(1);
	}
    else
	{
		printf("Open file: hello.c %d\n",fd);
	}
	
    /*写文件*/ 
    if((size = write(fd,buf_w,len))<0)
	{
		perror("write");		
		exit(1);
	}
	else
	{	
		printf("Write file: hello.c %d\n",fd);
	}
	
	//exit(0); 	
    /*读文件 */
	printf("fd: %d\n",len);
	lseek( fd, 0, SEEK_SET );
	
    if((size = read(fd,buf_r,len))<0)
    {
		perror("read");        
		exit(1);
    }
    else
    {   
         printf("read file: %s\n",buf_r);
    }
	

	/*文件关闭 */
	if( close(fd) < 0 )
	{
		perror("close");
		exit(1);
	}
	else
		printf("Close hello.c\n");

	exit(0);

	return 0;

}
