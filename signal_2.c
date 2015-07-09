#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void signal_handler(int signo)
{
	printf("hi ! signal %d \n",signo);
	signal(SIGINT, SIG_DFL);
}
int main(void)
{
	int count = 0;

	//signal(SIGINT, SIG_IGN);
	signal(SIGINT,signal_handler);

	while(1){
		printf("Hello world\n");
		sleep(1);
#if 0
		if(++count == 5){
			signal(SIGINT, SIG_DFL);
		}
#endif
	}
}
