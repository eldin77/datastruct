#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX 100

int main(void)
{
	int fd, i;

	char buf[MAX];
	unsigned long length = 0;

	if((fd = open("test.txt", ORDONLY)) == -1) {
		perror("open error");
		exit(1);
	}

	while((i = read(fd, buf, MAX)) > 0){
		length += i;
	}
	printf("total length = %lu",length);
	close(fd);
	exit(0);
	return 0;
}
