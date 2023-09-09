/*
============================================================================
Name : prog8.c
Author : Ketki Kerkar
Description :Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 25th August, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc,char* argv[]){
    int fd_read;
    int flag=0;
    char buf[200];
    fd_read=open(argv[1],O_RDONLY);
    if(fd_read==-1){
      perror("Error in opening file");
      return -1;
    }
    int ind=0,read_char=0;
    while(1){

      read_char=read(fd_read,&buf[ind],1);

      if(buf[ind]=='\n')
      {
              write(STDOUT_FILENO,&buf,ind+1);
	      
	      for(int i=0;i<ind;i++){
	      buf[i]='\0';
	      
	      ind=-1;
	      }
      }
      ind++;
      if(read_char==0)
              break;
    }


    close(fd_read);
    return 0;
}
