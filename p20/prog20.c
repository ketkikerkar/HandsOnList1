/*
============================================================================
Name : prog20.c
Author : Ketki Kerkar
Description :Find out the priority of your running program. Modify the priority with nice command.
Date: 4th September, 2023.
============================================================================
*/
#include<stdlib.h>
#include<sys/resource.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	
	id_t pid;
	
	pid=getpid();
	
	printf("The priority of current process=%d\n",getpriority(PRIO_PROCESS,pid));
        nice(-4);
	printf("Modified Priority:%d\n",getpriority(PRIO_PROCESS,pid));
	return 0;
}
