/*
============================================================================
Name : prog17.c
Author : Ketki Kerkar
Description :Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 25th August, 2023.
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
	
		int ticket_num;
	}db;
	fd=open("ticketfile",O_RDWR);
	struct flock lock;
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=sizeof(db);
	lock.l_pid=getpid();
	lseek(fd,0,SEEK_SET);
	read(fd,&db,sizeof(db));
	printf("Before enterning critical section\n");
	fcntl(fd,F_SETLKW,&lock);
	printf("Current ticket count:%d",db.ticket_num);
	db.ticket_num++;
	lseek(fd,0,SEEK_SET);
	write(fd,&db,sizeof(db));
	printf("\nTo book ticket, press Enter\n");
	getchar();
	lock.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	printf("Ticket booked with number%d\n",db.ticket_num);
 
	return 0;}
