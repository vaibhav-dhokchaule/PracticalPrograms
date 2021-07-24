/*********************************************************
	Varqa College Of Higher and Technical Education,Ahmednagar
			Department of Computer Science
Name: Shirke Pramod Suryabhan		Class: T.Y.B.Sc(CS)
Batch:  				      	
Assignment no: 			     Date:   /  /201 .	
Assignment Name: Write a program that behaves like a shell (command interpreter). It hasits own prompt say "myshell$". Any normal shell command is executed from your shell by starting a child process to execute the system program corresponding to the command. It should additionally interpret
the following command.
	i)	search f <pattern> <filename>
		- search first occurrence of pattern in filename
	ii)	search c <pattern> <filename>
		- count no. of occurrences of pattern in filename
	iii)           search a <pattern> <filename>
		- search all occurrences of pattern in filename
Remark: ____________			Sign: __________
*********************************************************/
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>

void search(char c, char *s, char *fn)
{
	int handle,i=1,cnt=0,j=0;
	char ch,buff[80],*p;
	if((handle=open(fn,O_RDONLY))==-1)
	{
		printf("File %s not found\n",fn);
		return;
	}
	switch(c)
	{
	case 'f':
		while(read(handle,&ch,1)!=0)
		{
			if(ch=='\n')
			{
				buff[j]='\0';
				j=0;
				if(strstr(buff,s)!=NULL)
				{
					printf("%d : %s\n",i,buff);
					break;
				}
				i++;
			}
			else
				buff[j++]=ch;
		}
		break;
	case 'c':
		while(read(handle,&ch,1)!=0)
		{
			if(ch=='\n')
			{
				buff[j]='\0';
				j=0;
				if(strstr(buff,s)!=NULL)
				{
					p=buff;
					while((p=strstr(p,s))!=NULL)
					{
						cnt++;
						p++;
					}
				}
			}
			else
				buff[j++]=ch;
		}
		printf("Total No.of Occurrences = %d\n",cnt);
		break;
	case 'a':
		while(read(handle,&ch,1)!=0)
		{
			if(ch=='\n')
			{
				buff[j]='\0';
				j=0;
				if(strstr(buff,s)!=NULL)
					printf("%d : %s\n",i,buff);
				i++;
			}
			else
				buff[j++]=ch;
		}
	}
	close(handle);
}

main()
{
	char command[80],t1[20],t2[20],t3[20],t4[20];
	int n;
	system("clear");
	while(1)
	{
		printf("myShell$");
		fflush(stdin);
		fgets(command,80,stdin);
		n = sscanf(command,"%s %s %s %s",t1,t2,t3,t4);
		switch(n)
		{
		case 1:
			if(!fork())
			{
				execlp(t1,t1,NULL);
				perror(t1);
			}
			break;
		case 2:
			if(!fork())
			{
				execlp(t1,t1,t2,NULL);
				perror(t1);
			}
			break;
		case 3:
			if(!fork())
			{
				execlp(t1,t1,t2,t3,NULL);
				perror(t1);
			}
			break;
		case 4:
			if(strcmp(t1,"search")==0)
				search(t2[0],t3,t4);
			else
			{
				if(!fork())
				{
					execlp(t1,t1,t2,t3,t4,NULL);
					perror(t1);
				}
			}
		}
	}
}



