/*
============================================================================
Name : prog22.c
Author : Ketki Kerkar
Description :Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 5th September, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{

    int fd;
    fd=open("ofile",O_RDWR| O_APPEND);
    if(fd==-1)
    {
      perror("Error opening file");
      exit(EXIT_FAILURE);

    }
    pid_t pid;
    pid=fork();
    if(pid==-1){
       perror("Fork failed");
       exit(EXIT_FAILURE);
    }

    if(pid>0){
      printf("Inside parent process\n");
      write(fd,"Hello Parent Process\n",21);
    }
    else{
      printf("Inside child process\n");
      write(fd,"Hello Child Process\n",20);
    }
    close(fd);
    return 0;
}
