#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int pipe_descriptor[2];//0 - read 1 - write
	int fork_result;
	unsigned int symbol=0;

	pipe(pipe_descriptor);

	fork_result = fork();
    	if(fork_result == -1) exit(EXIT_FAILURE);
   	while(1)
	{
		if(fork_result == 0)
	{ //child process
        	close(pipe_descriptor[1]);
		read(pipe_descriptor[0], &symbol, sizeof(symbol));
		symbol *= symbol;
		printf("Child proc %d\n", symbol);
    	}
   	else
	{//parent process
        	close(pipe_descriptor[0]);
		printf("Parent proc\n");
		scanf("%d",&symbol);
        	write(pipe_descriptor[1], &symbol, sizeof(symbol));
    	}
}
return 0;
}
