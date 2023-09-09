/*
============================================================================
Name : prog29.c
Author : Ketki Kerkar
Description :Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 6th September, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sched.h>
#include<stdlib.h>

int main(){
	struct sched_param sp;
	int policy,policy1;
	pid_t pid;
	pid=getpid();
	policy=sched_getscheduler(pid);
	
	if(policy==-1)
	{
		perror("Error in Sched_getscheduler()");
		exit(EXIT_FAILURE);
	}
	
       if (sched_getparam(pid, &sp) == -1) {
          perror("Error in sched_getparam");
          exit(EXIT_FAILURE);
       }
	
	printf("Scheduling Policy:");
	if(policy==SCHED_RR) printf("RR");
	else if(policy==SCHED_FIFO)printf("FIFO");
        else if(policy==SCHED_OTHER)printf("OTHER");
        else printf("Unknown");
        printf("\nCurrent priority: %d\n", sp.sched_priority);
	
	int p=SCHED_RR;
	sp.sched_priority=55;
	
	printf("\nScheduling Policy after modification:");
	if(sched_setscheduler(pid,SCHED_FIFO,&sp)==-1){
	         perror("Error in sched_setscheduler()");
                 exit(EXIT_FAILURE);
	}
        
	policy1=sched_getscheduler(pid);
	if(policy1==-1)
	{
		perror("Error in Sched_getscheduler() after modification");
		exit(EXIT_FAILURE);
	}

	if(policy1==SCHED_RR) printf("RR");
	else if(policy1==SCHED_FIFO)printf("FIFO");
	else if(policy1==SCHED_OTHER)printf("OTHER");
	else printf("Unknown");
	printf("\nModified priority: %d\n", sp.sched_priority);
	
	
	return 0;
}
