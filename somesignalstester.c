#include <signal.h>
#include <unistd.h>
#include  <stdio.h>
#define MAX 3

int signals[MAX];
int next_sig = 0;

void handler(int s) 
{
	printf("Handler recieves signal: %d\n",s);
	signals[next_sig++] = s;		
}

int main(void) 
{
	struct sigaction sact;
	sigset_t sigset;
	sact.sa_handler = handler;
	sact.sa_flags = 0;

	sigemptyset(&sact.sa_mask);

	sigaddset(&sigset, SIGALRM);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);

	sigaction(SIGALRM, &sact, NULL);
	sigaction(SIGUSR1, &sact, NULL);
	sigaction(SIGUSR2, &sact, NULL);

	sigprocmask(SIG_BLOCK, &sigset, NULL);
	kill(getpid(), SIGALRM);
	kill(getpid(), SIGUSR1);
	kill(getpid(), SIGUSR2);
	
	sigprocmask(SIG_UNBLOCK, &sigset, NULL);

	int i;
	for(i = 0; i < next_sig; i++)
	{
		printf("Recieved and stored signal: ");
		switch(signals[i])
		{
			case SIGALRM:
				printf("SIGALRM\n");
				break;
			case SIGUSR1:
				printf("SIGUSR1\n");
				break;
			case SIGUSR2:
				printf("SIGUSR2\n");
				break;
			default:
				printf("unknown signal\n");
		}
	}
	
	return 0;

}
