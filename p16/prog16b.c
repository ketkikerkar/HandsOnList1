/*
============================================================================
Name : prog16b.c
Author : Ketki Kerkar
Description :16. Write a program to perform mandatory locking.
b. Implement read lock

Date: 25th August, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
int main(void){
        struct flock lock;
        int fd;
        fd = open("db", O_RDWR);
        lock.l_type = F_RDLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;
        lock.l_len = 0;
        lock.l_pid = getpid();
        printf("Before entering into critical section\n");
        fcntl(fd, F_SETLKW, &lock);
        printf("Inside the critical section...\n");
        printf("Enter to Unlock...\n");
        getchar();
        printf("unlocked\n");
        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);
        printf("Exited Critical Section\n");
}
