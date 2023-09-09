/*
============================================================================
Name : prog11a.c
Author : Ketki Kerkar
Description :Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup

Date: 25th August, 2023.
============================================================================
*/
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[]){
    int fd=open("file11a.txt",O_RDWR|O_APPEND|O_CREAT,S_IRUSR|S_IWUSR);
    if(fd==-1){
     printf("Error opening file");
    }
    int fd_dup1=dup(fd);

    write(fd,"Original file descriptor:",25);

    char buff[10],buff2[10];
    int n=sprintf(buff,"%d",fd);
    write(fd,buff,n);
    write(fd,"\nDuplicate file descriptor:",26);
    int m=sprintf(buff2,"%d",fd_dup1);
    write(fd,buff2,m);

    close(fd);
    close(fd_dup1);


    return 0;
    }
