/*	Rollno: 175
	Date: 20/12/12
	OS Ass1.4
*/
#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<stdlib.h>

char *t1, *t2, *t3, *buff;
DIR *dir;
struct dirent *entry;

void List(char *t2, char *t3)
{
	int filecount=0;
	dir = opendir(t3);
	if(dir==NULL)
	{
		printf("Directory \"%s\" not found!!",t3);
		return;	
	}
	switch(*t2)
	{
		case 'F':
		while((entry = readdir(dir))!=NULL)
		{
			printf("%s\n",entry->d_name);
		}
		break;

		case 'N':
		while((entry = readdir(dir))!=NULL)
		{
			filecount++;
		}
		printf("Total no of files = %d\n",filecount);
		break;

		case 'I':
		printf("FileName\t\tInode number\n");
		while((entry = readdir(dir))!=NULL)
		{
			if(strcmp(entry->d_name,".")!=0 
			&& strcmp(entry->d_name,"..")!=0)
			printf("%s\t\t%d\n",entry->d_name, entry->d_ino);
		}
		break;
	}
}

main()
{
	int pid;
	while(1)
	{	
		printf("[MyShell]$ ");
		fflush(stdin);
		t1 = (char *)malloc(80); 
		t2 = (char *)malloc(80); 
		t3 = (char *)malloc(80); 
		buff = (char *)malloc(80); 	
		
		fgets(buff,80,stdin);
		sscanf(buff,"%s %s %s",t1,t2,t3);
		if(strcmp(t1,"pause")==0)	
			exit(0);
		if(strcmp(t1,"list")==0)
			List(t2,t3);
		else
		{
			pid = fork();
			if(pid<0)
			printf("Child process not created!!");
			else if(pid==0)
			{
				execlp("/bin",NULL);
				if(strcmp(t1,"exit")==0)
					exit(0);
				system(buff);
			}
			else
			{
				wait(NULL);
				exit(0);
			}
		}
	}
}
/*	OUTPUT:
	[root@localhost ty175]# ./a.out
	[MyShell]$ ls
	a.out  ass1_4.c  madhuri
	[MyShell]$ date
	Fri Nov 23 04:04:57 PKT 2012
	[MyShell]$ list F madhuri
	.
	..
	encode.txt
	a.out
	decode.txt
	encoder.c
	decoder.c
	[MyShell]$ list N madhuri
	Total no of files = 7
	[MyShell]$ list I madhuri
	FileName                Inode number
	encode.txt              261202
	a.out           		261208
	decode.txt              261214
	encoder.c               261217
	decoder.c               261218
	[MyShell]$ exit			*/
		
