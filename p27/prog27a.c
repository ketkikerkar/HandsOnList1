/*
============================================================================
Name : prog27a.c
Author : Ketki Kerkar
Description :Write a program to execute ls -Rl by the following system call a)execl()
Date: 5th September, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
char* path="/bin/ls";
char *arg1="ls";
char *arg2="-Rl";
if(execl(path,arg1,arg2,NULL)==-1){
perror("Error in execl()");
exit(EXIT_FAILURE);
}
return 0;
}

