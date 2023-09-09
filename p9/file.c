/*
============================================================================
Name : prog1.c
Author : Ketki Kerkar
Description :1. Create the following types of a files using (i) shell command (ii) system call
              a. soft link (symlink system call)
              b. hard link (link system call)
              c. FIFO (mkfifo Library Function or mknod system call)
Date: 14th August, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
int v=symlink("newfile","destSL");//softlink is created
if(v<0){
perror("Failed");return -1;
}
int f=link("newfile","destHL");//hardlink is created
if(f<0){
perror("Failed");
return -1;
}
int e=mknod("file2",S_IFIFO,0);
if(e<0)
{
	perror("Failed");
}

return 0;
}
