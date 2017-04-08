#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
int main()
{
int pipe_descriptor[2];//0 - read 1 - write
pipe(pipe_descriptor);
int fork_result;
char symbol;
fork_result = fork();
    if(fork_result == -1)
        exit(EXIT_FAILURE);
    if(fork_result == 0){ //child process
        close(pipe_descriptor[1]);
        read(pipe_descriptor[0], &symbol, pipe_descriptor);
    }
    else{//parent process
        close(pipe_descriptor[0]);
        write(pipe_descriptor[1], &symbol, pipe_descriptor);
    }
return 0;
}