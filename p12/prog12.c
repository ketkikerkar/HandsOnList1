/*
============================================================================
Name : prog12.c
Author : Ketki Kerkar
Description :Write a program to find out the opening mode of a file. Use fcntl.
Date: 25th August, 2023.
============================================================================
*/
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(int argc, char* argv[]){

      int fd,flag,accessMode;
      fd=open(argv[1],O_CREAT|O_RDONLY);
      //fd=open(argv[1],O_CREAT|O_WRONLY);
      //fd=open(argv[1],O_CREAT|O_RDWR);

      flag=fcntl(fd,F_GETFL);
      accessMode=flag & O_ACCMODE;
      if(accessMode==O_RDWR){
        printf("The file is opened in read write mode\n");
      }
      else if(accessMode==O_RDONLY){
        printf("The file is opened in read only mode\n");

      }
      else if(accessMode==O_WRONLY){
        printf("The file is opened in write only mode\n");
      }

      close(fd);


      return 0;
}
