/*
============================================================================
Name : prog27b.c
Author : Ketki Kerkar
Description :Write a program to execute ls -Rl by the following system call b)execlp()
Date: 5th September, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
char* program="ls";
char *arg1="ls";
char *arg2="-Rl";       
if(execlp(program,arg1,arg2,NULL)==-1){
perror("Error in execlp()");
exit(EXIT_FAILURE);
}
	return 0;}
