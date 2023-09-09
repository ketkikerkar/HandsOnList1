/*
============================================================================
Name : prog9.c
Author : Ketki Kerkar
Description :Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 25th August, 2023.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<time.h>


int main(){
    struct stat s;
    stat("file.c",&s);
    
    printf("Inode number: %ld\n",(long)s.st_ino);
    printf("Number of Hard links: %ld\n",(long)s.st_nlink);
    printf("UID: %ld\n",(long)s.st_uid);
    printf("GID: %ld\n",(long)s.st_gid);
    printf("Size: %lld\n",(long long)s.st_size);
    printf("Block size: %ld\n",(long)s.st_blksize);
    printf("Last Access:%s\n",ctime(&s.st_atime));
    printf("Last Modification time: %s\n",ctime(&s.st_mtime));
    printf("Time of last change: %s\n",ctime(&s.st_ctime));

    return 0;
}
