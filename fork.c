#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;

	if((pid=fork()) == -1){
		perror("fork failed");
	} else if(pid != 0){
		printf("parent process %d\n",getpid());
	} else {
		printf("child process %d\n",getpid());
	}

}

