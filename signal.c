#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(void)
{

	sigset_t set;

	if(sigemptyset(&set) == -1){
		perror("sigemptyset failed");
		exit(1);
	}

	if(sigaddset(&set, SIGINT) == -1){
		perror("sigaddset fail");
		exit(1);
	}

	if(sigismember(&set, SIGINT)){
		printf("SIGINT is a member\n");
	} else {
		printf("SIGINT is not a member\n");
	}
}

