/*
============================================================================
Name : prog27a.c
Author : Ketki Kerkar
Description :Write a program to execute ls -Rl by the following system call c)execle()
Date: 5th September, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void){
char *envp[]={"PATH=/bin:/usr/bin",NULL};
char* path="/bin/ls";
char *arg1="ls";
char *arg2="-Rl";
if(execle(path,arg1,arg2,NULL,envp)==-1){
perror("Error in execle()");
exit(EXIT_FAILURE);
}

}
