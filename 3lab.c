#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
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
		int c_id=0;
		const char name;
		c_id = fork();
		if(c_id < 0) exit(EXIT_FAILURE);
                if(c_id == 0)
                {
                    printf("Entered");
		int shm_variable=0; 
		shm_variable = shm_open(&name, O_CREAT, RWX);
                printf("\nshm_variable = %i", shm_variable);
                if(shm_variable == 0){

                }
                        }
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
