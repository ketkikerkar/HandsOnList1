
/*
============================================================================
Name : prog27e.c
Author : Ketki Kerkar
Description :Write a program to execute ls -Rl by the following system call e)execvp()
Date: 5th September, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
char *arg[]={"ls","-Rl",NULL};

if(execvp(arg[0],arg)==-1){
perror("Error in execvp()");
exit(EXIT_FAILURE);
}
return 0;
}

