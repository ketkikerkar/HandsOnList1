/*
============================================================================
Name : prog25.c
Author : Ketki Kerkar
Description :Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 6th September, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	pid_t p;
	printf("Before fork\n");
	p=fork();

	if(p==0)
	{
		printf("Child1 pid : %d\n", getpid());
		printf("Child1 Parent pid : %d\n", getppid());

	}

	else
	{
		pid_t q;
		printf("Inside first in parent\n");
		q=fork();
		if(q==0)
		{
			printf("Child2 pid : %d\n", getpid());
			printf("Child2 Parent pid : %d\n", getppid());
		}
		else
		{
			pid_t r;
			printf("Inside second in parent\n");
			r=fork();
			if(r==0)
			{
				        sleep(10);
					printf("Child3 pid : %d\n", getpid());
					printf("Child3 Parent pid : %d\n", getppid());
					printf("Child3 is completed\n");
			}
			else
			{
				        waitpid(r,WIFEXITED(2), WCONTINUED);
					printf("Parent pid : %d\n", getpid());
			}

		}


	}
	return 0;
}
