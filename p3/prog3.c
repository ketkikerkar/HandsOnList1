/*
============================================================================
Name : prog3.c
Author : Ketki Kerkar
Description :Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 14th August, 2023.
============================================================================
*/
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(void){
  int fd;
  fd=creat("myfile",S_IRUSR | S_IWUSR);
  printf("fd=%d\n",fd);


}
