/*
============================================================================
Name : prog10.c
Author : Ketki Kerkar
Description :Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
    a. check the return value of lseek
    b. open the file with od and check the empty spaces in between the data.
Date: 25th August, 2023.
============================================================================
*/


#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(int argc, char* argv[]){
      int fd;
      fd=open("seekfile",O_CREAT|O_RDWR,0744);
      if(fd==-1)
      {
	      printf("Error in opening file");
	      return -1;
      }
      
      write(fd,"Hi,Ketki!!",10);
      int pos=lseek(fd,10L,SEEK_CUR);
      printf("File position:%d\n",pos);
      printf("Written sucessfully");
      write(fd,"SS Program",10);
      close(fd);
      return 0;
}
