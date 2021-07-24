#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct File_tab
{
	char name[10];
	int start,end;
	struct File_tab *next;
}File;

typedef struct BLOCK
{
	int data;
      int next;
}block;
File *first=NULL;
block *disk;
int ch,i,fcnt,acnt,size;
//initialization of disk blocks
void init()
{
	for(i=0;i<size;i++)
  	{
		disk[i].next=-1;
  		disk[i].data=0; //to free block 
  	}
}

int search() //s is size of file
{
	int cnt=0,j;
	for(i=0;i<size;i++) //blcok size
 	{
   	   if(disk[i].data==0) //allocated
     		return i;
      }
	return -1;
}

void allocate()
{
	File *f1,*f2;  //file table implementation
	int res,fsize,j,cnt;
	f1=(File *)malloc (sizeof(File));
	printf("\nEnter the file name ");
	scanf("%s",&(f1->name));
	printf("\nEnter the file size ");
	scanf("%d",&(fsize));
	if(fcnt<fsize)  //freecnt
		printf("\nMemeory not availbale");
	else
	{
		res=search(); //index of free block
		f1->start=res;
		f1->next=NULL;
		cnt=0;
 		disk[res].data=1;  //allocated
		fcnt--;
		acnt++;

		for(i=res;i<size;i++)
 		{
			j=i+1;
			for(;cnt<fsize-1;j++)
  			{
				if(disk[j].data==0)
    				{
				 	disk[i].next=j;
					disk[j].data=1;
					fcnt--;
					acnt++;
					cnt++; 
				      i=j;
     				}//if
			}//for j
			if(cnt==fsize-1)
			{
				f1->end=j-1;
				disk[j-1].next=-1;  //last block
				break;
   			}
		}//for i;

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

	printf("\nFilename start size  \n");
	while(ptr!=NULL)
 	{
		printf("\n%s   %d    %d",ptr->name,ptr->start,ptr->end);
		ptr=ptr->next;
 	}
	printf("\nBlock  Flag ");
	for(i=0;i<size;i++)
	{
		printf("\n%d     %s",i,disk[i].data==1?"allocated":"free");
	}
	printf("\nTotal freeblocks are %d",fcnt);
	printf("\nTotal allocated blocks are %d",acnt);
}

void deallocate()
{
	char name[10];
	File *ptr,*p1;
	printf("\nEnter the file to be deallocate ");
	scanf("%s",name);
	ptr=first;

	//delete from file table
	while(ptr!=NULL)
	{
		if(strcmp(ptr->name,name)==0)
		{
			for(i=ptr->start; i!=-1;)
			{
			      disk[i].data=0;
         			i=disk[i].next;
         			fcnt++;
         			acnt--; 
    			}
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
	printf("Enter the size of disk ");
	scanf("%d",&size);
	fcnt=size;
	acnt=0;

	disk=(block *)malloc(sizeof(block)*size);
	init();
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
	
/*OUTPUT:-[root@localhost fileallocation]# ./a.out
Enter the size of disk 10
        Menu 
        1.Allocate  the memory for file
        2.Deallocate
        3.show used and free space from disk 
        4.Exit 
        Enter the choice 1
Enter the file name a.c
Enter the file size 5
        Menu 
        1.Allocate  the memory for file
        2.Deallocate
        3.show used and free space from disk 
        4.Exit 
        Enter the choice 3
Filename size  start 
a.c   	0  	  4
Block  Flag 
0     allocated
1     allocated
2     allocated
3     allocated
4     allocated
5     free
6     free
7     free
8     free
9     free
Total freeblocks are 5
Total allocated blocks are 5
        Menu 
        1.Allocate  the memory for file
        2.Deallocate
        3.show used and free space from disk 
        4.Exit 
        Enter the choice 1
Enter the file name b.c
Enter the file size 4
        Menu 
        1.Allocate  the memory for file
        2.Deallocate
        3.show used and free space from disk 
        4.Exit 
        Enter the choice 3
Filename size  start 
a.c	   0     4
b.c   5    8
Block  Flag 
0     allocated
1     allocated
2     allocated
3     allocated
4     allocated
5     allocated
6     allocated
7     allocated
8     allocated
9     free
Total freeblocks are 1
Total allocated blocks are 9
        Menu 
        1.Allocate  the memory for file
        2.Deallocate
        3.show used and free space from disk 
        4.Exit 
        Enter the choice 2
Enter the file to be deallocate a.c
File is deallocated 
        Menu 
        1.Allocate  the memory for file
        2.Deallocate
        3.show used and free space from disk 
        4.Exit 
        Enter the choice 3
Filename size  start 
b.c	   5     8
Block  Flag 
0     free
1     free
2     free
3     free
4     free
5     allocated
6     allocated
7     allocated
8     allocated
9     free
Total freeblocks are 6
Total allocated blocks are 4
        Menu 
        1.Allocate  the memory for file
        2.Deallocate
        3.show used and free space from disk 
        4.Exit 
        Enter the choice 1
Enter the file name d.c
Enter the file size 3
        Menu 
        1.Allocate  the memory for file
        2.Deallocate
        3.show used and free space from disk 
        4.Exit 
        Enter the choice 3
Filename size  start 
b.c  	 5       8
d.c   0    2
Block  Flag 
0     allocated
1     allocated
2     allocate
3     free
4     free
5     allocated
6     allocated
7     allocated
8     allocated
9     free
Total freeblocks are 3
Total allocated blocks are 7
        Menu 
        1.Allocate  the memory for file
        2.Deallocate
        3.show used and free space from disk 
        4.Exit 
        Enter the choice 4*/
