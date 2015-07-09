#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signo)
{
	printf("HI signal no %d\n",signo);
}

int main(void)
{
	sigset_t set, oldset;

	struct sigaction act;

	act.sa_handler = signal_handler;
	sigaction(SIGINT, &act, NULL);

	sigemptyset(&set);
	sigaddset(&set, SIGINT);

	sigprocmask(SIG_BLOCK, &set, &oldset);
	sleep(10);

	sigprocmask(SIG_SETMASK, &oldset, NULL);

	pause();
	exit(0);
	
	return 0;
}
