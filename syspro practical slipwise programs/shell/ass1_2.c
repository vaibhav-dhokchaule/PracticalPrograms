/*	Date: 07/12/12
	OS Assmt 1.2
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

char *buff, *t1, *t2, *t3, ch;
FILE *fp;
int pid;

void typeline(char *t2, char *t3)
{
	int i, n, count=0;
	if((fp=fopen(t3,"r"))==NULL)
	{
		printf("File Not Found!! ");
		exit(0);
	}
	if(strcmp(t2,"a")==0)
	{
		while((ch=fgetc(fp))!=EOF)
			printf("%c",ch);
		fclose(fp);
		return;
	}
	n = atoi(t2);
	if(n>0)
	{
		i=0;
		while((ch=fgetc(fp))!=EOF)
		{
			if(ch=='\n')	i++;
			if(i==n) break;
			printf("%c",ch);
		}
		printf("\n");
	}
	else
	{
		count = 0;
		while((ch=fgetc(fp))!=EOF)
		{
			if(ch=='\n')
				count++;
		}
		fseek(fp,0,SEEK_SET);
		 i=-1;
		while((ch=fgetc(fp))!=EOF)
		{
			if(ch=='\n')
				i++;
			if(i==count+n-1) break;
		}
		while((ch=fgetc(fp))!=EOF)
			printf("%c",ch);
	}
	fclose(fp);
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
		else if(strcmp(t1,"typeline")==0)
			typeline(t2,t3);
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
[MyShell]$ ls /usr
bin  etc  games  include  java  kerberos  lib  libexec  local  sbin  share  src  tmp  X11R6

[MyShell]$ pwd
/root/ty175

[MyShell]$ ls
abc.txt  a.out  count.c  proc.c

[MyShell]$ date
Fri Dec  7 11:40:56 IST 2012

[MyShell]$ ls  
abc.txt  a.out  count.c  lineprint.c

[MyShell]$ typeline a abc.txt
one: Hello World.
two: Java is Purely Object Orientd Language.
three: Java does not support pointers.
four: Multiple Inheritance in java is possible using the concept of interface.
five: C++ is developed by BJarne Stroustrup.
six: There are 366 days in a leap year.
seven: Hi!, Wats Up!

[MyShell]$ typeline 3 abc.txt
one: Hello World.
two: Java is Purely Object Orientd Language.
three: Java does not support pointers.

[MyShell]$ typeline -3 abc.txt
five: C++ is developed by BJarne Stroustrup.
six: There are 366 days in a leap year.
seven: Hi!, Wats Up!

[MyShell]$ exit   
*/
		












