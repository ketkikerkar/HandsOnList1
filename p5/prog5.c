/*
============================================================================
Name : prog5.c
Author : Ketki Kerkar
Description :Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 14th August, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
    int fd1,fd2,fd3,fd4,fd5;
    fd1=open("file1.txt", O_RDWR| O_CREAT|S_IRWXU);
    fd2=open("file2.txt", O_RDWR| O_CREAT|S_IRWXU);
    fd3=open("file3.txt", O_RDWR| O_CREAT|S_IRWXU);
    fd4=open("file4.txt", O_RDWR| O_CREAT|S_IRWXU);
    fd5=open("file5.txt", O_RDWR| O_CREAT|S_IRWXU);
    if(fd1==-1||fd2==-1||fd3==-1||fd4==-1||fd5==-1){
    printf("Error in opening file");
    return -1;
    }
    for(;;);

return 0;
}
