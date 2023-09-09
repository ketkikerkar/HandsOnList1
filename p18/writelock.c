/*
============================================================================
Name : writelock.c
Author : Ketki Kerkar
Description :Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 25 August, 2023.
============================================================================
*/
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(){
	int fd,input;
	struct{
		int train_num;
		int ticket_count;
	}db[3];
	fd=open("record",O_RDWR);
	printf("Select train number:1, 2, 3,\n");
	scanf("%d",&input);
	struct flock lock;
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=(input-1)*sizeof(db);
	lock.l_len=sizeof(db);
	lock.l_pid=getpid();
	lseek(fd,(input-1)*sizeof(db),SEEK_SET);
	read(fd,&db,sizeof(db));
	printf("Before enterning critical section\n");
	fcntl(fd,F_SETLKW,&lock);
	printf("Current ticket count:%d",db->ticket_count);
	db->ticket_count++;
	lock.l_start=(input-1)*sizeof(db);
	write(fd,&db,sizeof(db));
	printf("\nTo book ticket, press Enter\n");
	getchar();
	getchar();
	lock.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	printf("Ticket booked with number%d\n",db->ticket_count);
 
	return 0;}
