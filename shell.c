#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#define MAXARG 7

int main(void)
{
	char buf[256];
	char *arg[MAXARG];
	char *s;
	char *save;
	int argv;

	static const char delim[] = "\t\n";
	int pid, status;

	while(1){
		printf("myshell :");
		gets(buf);
		argv = 0;
		for(s = strtok_r(buf, delim, &save);
				s;
				s = strtok_r(NULL, delim, &save)){
			arg[argv++] = s;
		}

		if(!strcmp(arg[0], "quit")){
			break;
		}

		if((pid = fork()) == -1){
			perror("fork error");
		} else if(pid != 0){
			pid = wait(&status);
		}else {
			execvp(arg[0], arg);
		}

	}
}
