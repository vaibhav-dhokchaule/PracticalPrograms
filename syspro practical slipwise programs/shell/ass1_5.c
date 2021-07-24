/*	Rollno: 175
	Date: 20/12/12
	OS Ass1.5
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

char *t1,*t2,*t3,*t4,*buff;
FILE *fp;
void search(char *t2, char *t3, char *t4)
{
	int i=1, count=0;
	fp = fopen(t4,"r");
	if(fp==NULL)
	{
		printf("File not found!!\n");
		exit(0);
	}
	switch(*t2)
	{
		case 'F':
		while(fgets(buff,80,fp))
		{
			if(strstr(buff,t3)!=NULL)
			{
				printf("Line %d: %s\n",i,buff);
				break;
			}
			i++;
		}
		break;
		
		case 'C':
		while(fgets(buff,80,fp))
		{
			if(strstr(buff,t3)!=NULL)
				count++;
		}
		printf("Total occurences of '%s' in '%s' = %d \n",t3,t4,count);
		break;
	
		case 'A':
		while(fgets(buff,80,fp))
		{
			if(strstr(buff,t3)!=NULL)
			{
				printf("Line %d: %s\n",i,buff);
			}
			i++;
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
		t4 = (char *)malloc(80); 
		buff = (char *)malloc(80); 	
		
		fgets(buff,80,stdin);
		sscanf(buff,"%s %s %s %s",t1,t2,t3, t4);
		if(strcmp(t1,"pause")==0)	
			exit(0);
		if(strcmp(t1,"search")==0)
			search(t2,t3,t4);
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
[MyShell]$ search F Hello abc.txt
Line 2: Hello world.
                                                                                
[MyShell]$ search C Hello abc.txt
Total occurences of 'Hello' in 'abc.txt' = 3

[MyShell]$ search A Hello abc.txt
Line 2: Hello world.
Line 4: Hello Prajakta How are you?
Line 6: Hello Can i talk to Miss.Pallavi?
*/
