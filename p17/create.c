#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(){
	int i,fd;
	struct{
	
		int ticket_num;
	}db;
	printf("Enter initial ticket number:");
	scanf("%d",&db.ticket_num);
	//db.ticket_num=i;
	fd=open("ticketfile",O_RDWR|O_CREAT);
	write(fd,&db,sizeof(db));
	return 0;}
