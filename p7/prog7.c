/*
============================================================================
Name : prog7.c
Author : Ketki Kerkar
Description :Write a program to copy file1 into file2 ($cp file1 file2).
Date: 25th August, 2023.
============================================================================
*/
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(int argc,char* argv[]){

    if(argc!=3){
        printf("Incorrect number of arguments");
        return 0;
    }
    int fd1,fd2;


    fd1=open(argv[1],O_RDONLY);
    fd2=open(argv[2],O_WRONLY |O_CREAT);
    
    if(fd1==-1 || fd2==-1){
        printf("Error");
        return -1;
    }
    
    while(1){
        char buf1;
        int char_read=read(fd1,&buf1,1);
        if(char_read==0) break;
          int char_write=write(fd2,&buf1,1);
        }

        int fd_read_close=close(fd1);
        int fd_write_close=close(fd2);
        
        if(fd_read_close==-1 || fd_write_close==-1){
          printf("Error");
    }
    return 0;
}
