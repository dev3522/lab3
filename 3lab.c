#include <errno.h>
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
		printf("Child proc (B) %d\n", symbol);
                int proc_c_id = 0, segment_id;
                proc_c_id = fork();
                if(proc_c_id < 0)
		{ 
                        printf("proc_c_id<0\n");
			exit(EXIT_FAILURE);
		}
                if(proc_c_id == 0)//child process C
                {
			printf("child process\n");
                   
                if(segment_id == -1){
			printf("segment_id = -1\n");
			exit(EXIT_FAILURE);
		}

		if(segment_id == 0){
			printf("\nsegment_id = 0");
                }
                else{
                    printf("\nMemory created\n");
		key_t shmKEY=1;
		printf("shmKEY = %d\n",shmKEY);		
		segment_id = shmget(shmKEY, sizeof(int), IPC_CREAT|0666);
		printf("Errno=%d\n",errno);
                printf("segment_id = %i\n", segment_id);
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
