#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SHM_def "Z"
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
                int proc_c_id = 0;
                proc_c_id = fork();
                if(proc_c_id < 0)
		{ 
                        printf("proc_c_id<0\n");
			exit(EXIT_FAILURE);
		}
                if(proc_c_id == 0)
                {
                    printf("Entered");
		int segment_id;
		int mode=0;
		unsigned int key=0x55000;
		segment_id = shmget(key, sizeof(int), O_CREAT);
                printf("\nshm_variable = %i", segment_id);
                if(segment_id == 0){

                }

                else{
                    printf("\nMemory created");
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
