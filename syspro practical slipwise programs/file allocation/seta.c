#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct File_tab
{
	char name[10];
  	int size,start;
	struct File_tab *next;
}File;
File *first=NULL;
int *block,size,ch,i;
int search(int s) //s is size of file
{
	int cnt=0,j;
	for(i=0;i<size;i++) //blcok size
	{
		j=i;
	      cnt=0;
		for(;cnt<s;j++,cnt++) //file size
		{
   			if(block[j]==1) //allocated
		     		break;
   		}
		if((cnt)==s)
		      return i; //index of free block
 	}
	return -1;
}

void allocate()
{
	File *f1,*f2;
	int res;
	f1=(File *)malloc (sizeof(File));
	printf("\nEnter the file name ");
	scanf("%s",&(f1->name));
	printf("\nEnter the file size ");
	scanf("%d",&(f1->size));
	res=search(f1->size);
	if(res==-1)
		 printf("\nSpace is not available ");
	else
	{
		f1->start=res;
		f1->next=NULL;
		for(i=0;i<f1->size;i++)
			 block[res+i]=1;
		//table
		 if(first==NULL) //first entry
			 first=f1;
 		else
 		{
			 f2=first; //add  entry at last
			  while(f2->next!=NULL)
				    f2=f2->next;
			  f2->next=f1;
  		}
	}
}

void show()
{
	File *ptr;
	ptr=first;
	printf("\nFilename size  start \n");
	while(ptr!=NULL)
	{
			printf("\n%s   %d    %d",ptr->name,ptr->size,ptr->start);
			ptr=ptr->next;
	}
	printf("\nBlock  Flag ");
	for(i=0;i<size;i++)
	{
		printf("\n%d     %s",i,block[i]==1?"allocated":"free");
	}
}

void deallocate()
{
	char name[10];
	File *ptr,*p1;
	printf("\nEnter the file to be deallocate ");
	scanf("%s",name);
	ptr=first;
	while(ptr!=NULL)
	{
		if(strcmp(ptr->name,name)==0)
		{
			for(i=ptr->start; i<ptr->size;i++)
			      block[i]=0;
			p1=ptr;
			if(ptr==first)
		      	first=first->next;
			else
   			{
		      	ptr=ptr->next;
    			}
		     free(p1);
		     printf("\nFile is deallocated ");
	           break;
    		}
		ptr=ptr->next;
	}
	if(ptr==NULL)
	 printf("\nFile not found ");
}
 

main()
{
	printf("Enter the size of block ");
	scanf("%d",&size);
	block=(int *)malloc(sizeof(int)*size);
	while(1)
	{
		 printf("\n\n\tMenu \n\n\t1.Allocate  the memory for file\n\n\t2.Deallocate");
		 printf("\n\n\t3.show used and free space from disk \n\n\t4.Exit ");
		 printf("\n\n\tEnter the choice ");
		 scanf("%d",&ch);
		  switch(ch)
		  {
			    case 1: allocate();
		            break;
			    case 2 :deallocate();
		            break;
			    case 3 :show();
		            break;
			    case 4: exit(0);
  		}
	}
}  
/*Output
Enter the size of block 4
        Menu 
        1.Allocate  the memory for file
        2.Deallocate
        3.show used and free space from disk 
        4.Exit 
        Enter the choice 1
Enter the file name abc.txt
Enter the file size 5
        Menu 
        1.Allocate  the memory for file
        2.Deallocate
        3.show used and free space from disk 
        4.Exit 
        Enter the choice 3
Filename size  start 
abc.txt   5    0
Block  Flag 
0     allocated
1     allocated
2     allocated
3     allocated
        Menu 
        1.Allocate  the memory for file
        2.Deallocate
        3.show used and free space from disk 
        4.Exit 
        Enter the choice 2
Enter the file to be deallocate abc.txt
File is deallocated 
        Menu 
        1.Allocate  the memory for file
        2.Deallocate
        3.show used and free space from disk 
        4.Exit 
	Enter the choice 4	*/