/*	Date: 07/12/12
	OS Assmt 1.3
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

char *buff, *t1, *t2, *t3, ch;
FILE *fp;
int pid;

void count(char *t2, char *t3)
{
	int charcount=0, wordcount=0, linecount=0;
	if((fp=fopen(t3,"r"))==NULL)
	{
		printf("File Not Found!!");
		exit(0);
	}
	while((ch=fgetc(fp))!=EOF)
	{
		if(ch==' ')
			wordcount++;
		else if(ch=='\n')
		{
			linecount++;
			wordcount++;
		}
		else
			charcount++;
	}
	fclose(fp);
	if(strcmp(t2,"cw")==0)
	{	
		printf("Total no of characters = %d \n",charcount);
		printf("Total no of words = %d \n",wordcount);
	}
	else if(strcmp(t2,"wl")==0)
	{
		printf("Total no of words = %d \n",wordcount);
		printf("Total no of lines = %d \n",linecount);
	}
	else if(strcmp(t2,"cl")==0)
	{
		printf("Total no of characters = %d \n",charcount);
		printf("Total no of lines = %d \n",linecount);
	}
	else if(strcmp(t2,"cwl")==0)
	{
		printf("Total no of characters = %d \n",charcount);
		printf("Total no of words = %d \n",wordcount);
		printf("Total no of lines = %d \n",linecount);
	}
	else
		printf("%s: Command not found!! \n",t2);
	
}

main()
{
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
		else if(strcmp(t1,"count")==0)
			count(t2,t3);
		else
		{
			pid = fork();
			if(pid<0)
				printf("Child Process is not created\n");
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

[MyShell]$ count cw abc.txt
Total no of characters = 239 
Total no of words = 48 

[MyShell]$ count wl abc.txt
Total no of words = 48 
Total no of lines = 7 

[MyShell]$ count cl abc.txt
Total no of characters = 239 
Total no of lines = 7 

[MyShell]$ count cwl abc.txt
Total no of characters = 239 
Total no of words = 48 
Total no of lines = 7 

[MyShell]$ count zz abc.txt
zz: Command not found!! 

[MyShell]$ ls
abc.txt  a.out  count2.c  count.c  lineprint.c

[MyShell]$ date
Fri Dec  7 12:31:35 IST 2012

[MyShell]$ exit		*/
		












