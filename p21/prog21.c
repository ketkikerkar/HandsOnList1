/*
============================================================================
Name : prog21.c
Author : Ketki Kerkar
Description :Write a program, call fork and print the parent and child process id.
Date: 4th September, 2023.
============================================================================
*/
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
int main(){
	pid_t pid;
	pid=fork();
	if(pid==-1){
	perror("Fork failed");
	exit(EXIT_FAILURE);
	}

	if(pid==0){
	printf("This is Child process:\n");
	printf("The child process id is:%d\n The parent process id is:%d\n",getpid(),getppid());
	}
	else{
	printf("This is Parent process\n");
	printf("In parent pid:%d\nThe child process id:%d\n",getpid(),pid);
	}
	wait(NULL);

return 0;
}
