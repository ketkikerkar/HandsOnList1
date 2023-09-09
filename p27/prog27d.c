/*
============================================================================
Name : prog27d.c
Author : Ketki Kerkar
Description :Write a program to execute ls -Rl by the following system call d)execv()
Date: 5th September, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){

char *arg[]={"/bin/ls","-Rl",NULL};

if(execv(arg[0],arg)==-1){
perror("Error in execv()");
exit(EXIT_FAILURE);
}
return 0;
}
