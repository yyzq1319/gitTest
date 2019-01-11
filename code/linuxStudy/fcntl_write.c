/*lock_set 函数*/
#include <unistd.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

void lock_set(int fd, int type)
{
	struct flock lock;
	lock.l_whence = SEEK_SET;//赋值 lock 结构体
	lock.l_start = 0;
	lock.l_len =0;

	while(1)
	{
		lock.l_type = type;
		/*根据不同的 type 值给文件上锁或解锁*/
		if((fcntl(fd, F_SETLK, &lock)) == 0)
		{
			if( lock.l_type == F_RDLCK )
				printf("read lock set by %d\n",getpid());
			else if( lock.l_type == F_WRLCK )
				printf("write lock set by %d\n",getpid());
			else if( lock.l_type == F_UNLCK )
				printf("release lock by %d\n",getpid());
			return;
		}
	
		/*判断文件是否可以上锁*/
		fcntl(fd, F_GETLK,&lock);

		/*判断文件不能上锁的原因*/
		if(lock.l_type != F_UNLCK)
		{
			/*/该文件已有写入锁*/
			if( lock.l_type == F_RDLCK )
				printf("read lock already set by %d\n",lock.l_pid);
		
				/*该文件已有读取锁*/
			else if( lock.l_type == F_WRLCK )
				printf("write lock already set by %d\n",lock.l_pid);
			
			getchar();
	
		}
	}
}


/*fcntl_write.c 测试文件写入锁主函数部分*/
int fcntl_test(void)
{
	int fd;
	
	/*首先打开文件*/
	fd=open("fcntl_test_file",O_RDWR | O_CREAT, 0666);
	if(fd < 0)
	{
		perror("open");
		exit(1);
	}

	/*给文件上写入锁*/
	lock_set(fd, F_WRLCK);
	
	getchar();
	
	/*给文件解锁*/
	lock_set(fd, F_UNLCK);
	
	getchar();
	
	close(fd);
	exit(0);
	
	return 0;
}
