#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define MAX 100

int main(void)
{
	int fd ,i;
	char buf[MAX] = "Linux C Programming\0";
	unsigned int len;

	if((fd = open("testt.txt",O_WRONLY | O_CREAT, 0644)) == -1){
		perror("open error");
		exit(1);
	}
	len = strlen(buf);
	if(write(fd, buf, len) == -1) {
		perror("write error");
		exit(1);
	}
	close(fd);
	exit(0);
	return 0;
}

