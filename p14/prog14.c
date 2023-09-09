/*
============================================================================
Name : prog14.c
Author : Ketki Kerkar
Description :Write a program to find the type of a file.
            a. Input should be taken from command line.
            b. program should be able to identify any type of a file.
Date: 25th August, 2023.
============================================================================
*/
#include<stdio.h>

#include<stdlib.h>
#include<sys/stat.h>
int main(int argc, char* argv[]){
    struct stat *s;
    s=(struct stat*)malloc(sizeof(struct stat));
    stat(argv[1],s);
    printf("File Type: ");

    if(S_ISDIR(s->st_mode)){
        printf("Directory File\n");
    }
    else if(S_ISCHR(s->st_mode)){
        printf("Character File\n");
    }
    else if(S_ISBLK(s->st_mode)){
        printf("Block File\n");
    }
    else if(S_ISSOCK(s->st_mode)){
        printf("Socket File\n");
    }
    else if(S_ISLNK(s->st_mode)){
        printf("Symbolic File\n");
    }
    else if(S_ISFIFO(s->st_mode)){
        printf("FIFO or Pipe File\n");
    }
    else if(S_ISREG(s->st_mode)){
        printf("Regular File\n");
    }
   else  printf("Others\n");



    return 0;
}
