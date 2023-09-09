/*
============================================================================
Name : prog23.c
Author : Ketki Kerkar
Description : Write a program to create a Zombie state of the running program.
Date: 5th September, 2023.
============================================================================
*/
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    // Fork returns process id of child+-

    pid_t child_pid = fork();
  
    // Parent process 
    if (child_pid > 0)
        sleep(50);
  
    // Child process
    else        
        exit(0);
  
    return 0;
}

