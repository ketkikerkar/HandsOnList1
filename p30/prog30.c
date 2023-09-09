/*
============================================================================
Name : prog30.c
Author : Ketki Kerkar
Description :Write a program to run a script at a specific time using a Daemon process.
Date: 6th September, 2023.
============================================================================
*/
#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
  struct tm desired_time;
  desired_time.tm_hour=19;
  desired_time.tm_min=37;
  desired_time.tm_sec=0;
  desired_time.tm_mday=8;
  desired_time.tm_mon=8;
  desired_time.tm_year=2023-1900;
  
  time_t now;
  struct tm *cur_time;
  time(&now);
  cur_time=localtime(&now);
  time_t time_delay=mktime(&desired_time)-mktime(cur_time);
  
  if(time_delay<=0){
        printf("Invalid time. Please set a future time\n");
  }
  if(!fork()){
        setsid();
        sleep(mktime(&desired_time)-mktime(cur_time));
        printf("Daemon Process\n");
        //execl("/bin/sh", "sh","/home/ketaki/sslab2/p30/file.sh",NULL);
        if(system("sh $HOME/sslab2/p30/file.sh")!=0){
        perror("Error ");
        return 1;
        }
        

  }
  else{
        printf("Parent process exist");
  }
return 0;}

