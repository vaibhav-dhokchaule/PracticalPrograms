/*********************************************************
	Varqa College of higher and Techincal Education,Ahmednagar
			Department of Computer Science
Name: Shirke Pramod Suryabhan                     Class: T.Y.B.Sc(CS)
Batch:				  	
Assignment no:                    			       Date: 
  Assignment Name: Write a command line program for line editor. The file to be editied is taken as command line argument; an empty file is opened for editing if no argument is supplied. It should display a ‘$’ prompt to accept the line editing commands.
Implement the following commands:

i. a
ii. p
iii. p m n
iv. p m-n
v. s
vi.d n
vii.d m n
viii f<patt>
ix. i n
x .m n1 n2
xi.m n1 n2 n3
xii.c n1 n2
xiii.c n1 n2 n3
xiv. h

Remark: ____________				    Sign: __________
*********************************************************/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct LinEdit
{
char line[80];
struct LinEdit *next,*prev;
};
struct LinEdit *hd=NULL;
struct LinEdit *l=NULL;
FILE *f;
int nodecnt=0;
char fname[14];



void readf()         /*first read the given file from user */
{
struct LinEdit *temp;
char c='a';
int i,j=0;
f=fopen(fname,"r");
if(f==NULL)
{printf("\n File dose Not Exist");
exit(0);
}
     while(!feof(f+1)&&c!=EOF) /*it is used to shift the file pointer to next line */
	{ nodecnt++;
	j++;
	temp=(struct LinEdit *)malloc(sizeof(struct LinEdit));
	temp->next=NULL;
	i=0;
	while((c=getc(f))!='\n'&& i<78 &&c!=EOF) /*reading a single line of file upto 80 characters.*/
	{temp->line[i++]=c;
	}temp->line[i]='\0';
		if(hd==NULL)
		{temp->prev=NULL;
		l=hd=temp;
		}
		else
		{
		l->next=temp;
		temp->prev=l;
		l=temp;
		}
	}   printf("\n\n\n Total no. of lines are follow=%d",j);
		fclose(f);
}

/* -------------- DISPLAY SECTION--------------------------------- */


void display()     /* it is use display whole file */
{
	   struct LinEdit *temp;
	   printf("\n File contains are as follow:-");
	   for(temp=hd;temp!=NULL;temp=temp->next)
	   printf("\n%s",temp->line);

}


/* it is use display file from m positn to n number of node*/

 displaymn(int m,int n)
{
int i=1;
struct LinEdit *temp;
	if(m<=0&&m>nodecnt)
	{
	printf("\n Starting position of display Node is less or greater than zero or total node ");
	return 0;
	}
	else
	if(n<0)
	{
	printf("\n Number of node to display is less than Zero or Zero");
	return 0;
	}
	else
     if(n-m>nodecnt+1)
	{printf("\n There not to much Node to display from the given position");
	return 0;
	}
	temp=hd;
	while(i++<m)
	temp=temp->next;
	printf("\n Contain from the file %d poistion to %d number of nodes ",m,n);
	for(;n--;temp=temp->next)
	printf("\n%s",temp->line);
	return 0;
}
 /* display the file from reverse order  p m-n */
 displayrev(int m,int n)
{
	int i=1;
	struct LinEdit *temp;
	if(m<=0)
	{
	printf("\n Starting position of display Node is less than zero or zero ");
	return 0;
	}
	else
	if(n<0)
	{
	printf("\n Number of node to display is less than Zero or Zero");
	return 0;
	}
	else
	if(n>m)
	{printf("\n THe number of node is greater then position nodes");
	return 0;
	}
	temp=hd;
	while(i++<m)
	temp=temp->next;
	printf("\n Contain from the file %d poistion to %d number of nodes(revers) ",m,n);
	for(i=0;i++<n;temp=temp->prev)
	printf("\n%s",temp->line);
	 return 0;
}




/*-----------------------Save the File-------------------*/
  save()
 {
  struct LinEdit *temp=hd;
  char c;
  if(!strcmp(fname,"empty.txt"))
  {
  printf("\n You want's to save the File Y/N ?");
fflush(stdin);  
c=getchar();

     if(c=='Y'||c=='y')
     {
     printf("\n Enter the file name :");
     scanf("%s",fname);
      }
       else
     {
     printf("\n\n File is not saved");
     return 0;
     }
   }
    f=fopen(fname,"w");
    for(temp=hd;temp->next!=NULL;temp=temp->next)
    fprintf(f,"%s%c",temp->line,'\n');
    fprintf(f,"%s",temp->line);
    printf("\n File is Saved.");
    fclose(f);
    return 1;
    }


  /*-----------------------InSERT the line--------------------*/
     insert(int n)
    {
    struct LinEdit *l1,*temp,*l2;
    if(n<=0)
    {printf("\n Insert position is less than zero or zero.");
     return 0;
     }
     else
    if(n>nodecnt)
    {
    printf("\n There is not to much Lines has enter line number.");
    return 0;
    }
    nodecnt++;
    temp=(struct LinEdit *)malloc(sizeof(struct LinEdit));
    temp->next=NULL;
    printf("\n Enter the insert line:-\n");
    fflush(stdin);
    gets(temp->line);
    if(n==nodecnt)
    {temp->prev=l;
    l->next=temp;
     l=temp;
    }
    else
    if(n==1)
    {
    l1=hd->next;
    hd->next=temp;
    temp->prev=hd;
    temp->next=l1;
    l1->prev=temp;
    }
    else
    {l1=hd;
     while(--n)
     {
     l1=l1->next;
     l2=l1->next;
     }
     temp->prev=l1;
     temp->next=l2;
     l2->prev=temp;
     l1->next=temp;
     }
  return 0;
 }



   /*------------------------AppEND the file----------------------*/

    void append()
    {
    char c;
    struct LinEdit *temp;
    temp=(struct LinEdit *) malloc(sizeof(struct LinEdit));
    nodecnt++;
    temp->next=NULL;
    printf("\n\n Enter the append line.\n");
    fflush(stdin);
    gets(temp->line);
    if(hd==NULL)
    {temp->prev=NULL;
    l=hd=temp;
    }
    else
    {temp->prev=l;
    l->next=temp;
    l=temp;
    }

    }

/*----------------------------DELETE section------------------------*/
    delet(int n)
 {
 struct LinEdit *temp,*l1;
 if(n<0)
 {printf("\n You has negative number of lines.");
  return 0;
  }
  else
  if(n>nodecnt)
  {
  printf("\n There is not to much node to delete");
  return 0;
  }
 temp=hd;
 printf("\n Deleted Line are as Follow:-");
 while(n--)
 { nodecnt--;
   l1=temp;
   printf("\n%s",l1->line);
   temp=temp->next;
   temp->prev=NULL;
   free(l1);
 }
 hd=temp;

 return 0;
}
/* Delete the the contain from m position to N number of node */
delets(int m,int n)
{
int i=1;
struct LinEdit *temp,*l1,*l2;
	if(m<=0)
	{
	printf("\n Starting position of delete Node is less than zero or zero ");
	return 0;
	}
	else
	if(n<0)
	{
	printf("\n Number of node to delete is less than Zero or Zero");
	return 0;
	}
	else
	if(m+n>nodecnt+1)
	{printf("\n There are not to much Node to delete \n from the given position to N no. of nodes");
	return 0;
	}
	temp=hd;
	printf("\n THe delete line from file at given poistion %d to %d number of node",m,n);
	nodecnt--;
	if(m==1)
	{
	nodecnt=nodecnt+1-n;
	while(n--)
	{l1=temp;
	temp=temp->next;
	temp->prev=NULL;
	printf("\n%s",l1->line);
	free(l1);
	 }
	 hd=temp;
	 }
		else
	if(m==nodecnt)
	{
	temp=l;
	l=l->prev;
	l->next=NULL;
	printf("\n%s",temp->line);
	free(temp);
	}
	else
	{i=1;
	while(i++<m)   // move to particular node for m position
	{l1=temp;
	temp=temp->next;
	}
	if(nodecnt==m+n-2)
	{l=l1;
	l->next=NULL;
	}
	nodecnt=nodecnt+1-n;
	while(n--)
	{ l2=temp;
	 temp=temp->next;
	 l1->next=temp;
	 temp->prev=l1;
	 printf("\n%s",l2->line);
	 free(l2);
	 }

	}


 return 0;
}
/*----------------------------Copy the lines-------------------------------*/

copy(int m,int n)
{
struct LinEdit *temp1,*temp2,*temp3,*temp4;
int i=1;
if(m<=0&&n<=0)
{
printf("\n n1 or n2 node position less than zero or zero ");
return 0;
}
else
if(m>nodecnt && n>nodecnt)
{
printf("\n n1 or n2 node position greater than total number of node ");
return 0;
}
temp1=hd;
temp4=(struct LinEdit *)malloc(sizeof(struct LinEdit));
temp4->next=NULL;
for(i=1;i<m;i++)
temp1=temp1->next;
strcpy(temp4->line,temp1->line);
temp2=hd;
temp3=temp2->next;
for(i=1;i++<n;temp3=temp2->next)
temp2=temp2->next;
if(n==nodecnt)
{
temp2->next=temp4;
temp4->prev=temp2;
l=temp4;
}
else
{
temp2->next=temp4;
temp4->prev=temp2;
temp4->next=temp3;
temp3->prev=temp4;
}
nodecnt++;
return 0;
}

   copys(int m,int n,int n1)
{
	struct LinEdit *temp1,*temp2,*temp3,*temp4;
	int i=1;
	if(m<=0||n<=0||n1<=0)
	 {
	printf("\n n1,n2 or n3 node position less than zero or zero ");
	return 0;
	}
		else
	if(m>nodecnt || n>nodecnt || n1>nodecnt)
	{
	printf("\n n1,n2 or n3 node position greater than total number of node ");
	return 0;
	}
	else
	if(n1>=m&&n1<n)
	{
	printf("\n The n3 node is middle between n1 and n2 ");
	return 0;
	}

  temp1=hd;             //first node
  temp2=temp1->next;
  for(i=1;i<n1;i++,temp2=temp1->next)         //find n3 position  to add N2 nodes form n1 position
  temp1=temp1->next;
  temp3=hd;
  for(i=1;i<m;i++) //find n1 position from to move N2 nodes
  temp3=temp3->next;
  for(i=0;i<n;i++)
  {nodecnt++;
  temp4=(struct LinEdit *) malloc(sizeof(struct LinEdit));
  strcpy(temp4->line,temp3->line);
  temp1->next=temp4;
  temp4->prev=temp1;
  temp4->next=temp2;
  temp2->prev=temp4;
  temp1=temp1->next;
  temp3=temp3->next;
  }
  if(temp1->next==NULL)
  l=temp1;
     return 0;
}

/*------------------------------Move the node-------------------------------*/
   move(int n1,int n2)
  {
  struct LinEdit *temp1,*temp2,*temp3,*temp4;
  int i;
  if(n1<=0 && n2<=0)
  {
  printf("\n some of the Node is Less then Zero or Zero");
  return 0;
  }
  temp1=hd;
  for(i=1;i<n1;i++)
  {
  temp2=temp1;
  temp1=temp1->next;
  temp3=temp1->next;
  }
   if(n1==1)
  {
   temp2=temp1->next;
   temp2->prev=NULL;
   hd=temp2;
   }
   else
   if(n1==nodecnt)
  {
  temp2->next=NULL;
  l=temp2;
  }
  else
  {
  temp2->next=temp3;
  temp3->prev=temp2;
  }
  temp4=hd;
  temp3=temp4->next;
  for(i=1;i<n2-1;i++)
  {
  temp4=temp4->next;
  temp3=temp4->next;
  }
  if(n1==nodecnt)
  {
  temp4=l;
  temp4->next=temp1;
  temp1->next=NULL;
  l=temp1;
  }
  else
  {
  temp4->next=temp1;
  temp1->prev=temp4;
  temp1->next=temp3;
  temp3->prev=temp1;
  }
  return 0;
  }

  moves(int n1,int n2,int n3)
  {
  struct LinEdit *temp1,*temp2,*temp3,*temp4,*temp5;
  int i;
  if(n1<=0 || n2<=0 || n3<=0)
  {
  printf("\n some of the Node is Less then Zero or Zero");
  return 0;
  }
  else
  if(n1>nodecnt || n2>nodecnt || n3>nodecnt)
  {
  printf("\n Position of the number of node is much more then total number of node");
  return 0;
  }
  else
  if(n3>=n1&&n3<=n2)
  {
  printf("\n The n3 node is middle between n1 and n2 ");
  return 0;
  }
  temp1=hd;             //firt node
  temp2=temp1->next;
  for(i=1;i<n3;i++,temp2=temp1->next)         //find n3 position  to add N2 nodes form n1 position
  temp1=temp1->next;

  temp5=NULL;
  temp3=hd;
  temp4=temp3->next;
  for(i=1;i<n1;i++,temp4=temp3->next /* forwdend*/)			 //find n1 position from to move N2 nodes
  {
  temp3=temp3->next;  /* cuur*/
  temp5=temp3->prev;  /* backend*/
  }
   if(temp5==NULL)
   {temp1->prev=NULL;
   hd=temp1;
   }
   else
   {
   temp5->next=temp1;
   temp1->prev=temp5;
   }
  for(i=0;i<n2;i++)
  { temp1->next=temp3;//move node n3 position
    temp3->prev=temp1;
    temp3->next=temp2;
    temp2->prev=temp3;
    temp1=temp1->next;
    temp3=temp4;
    temp4=temp4->next;
  }
   if(temp1->next==NULL)
    l=temp1;
    return 0;
   }

/*----------------------------pattern-------------------------------------*/

void pattern(char pat[])
   {
    struct LinEdit *temp;
    int nodcnt=1;
    for(temp=hd;temp!=NULL;temp=temp->next)
    { if(strstr(temp->line,pat))
       printf("\nGiven  Pattern is present on the =%d node",nodcnt);
       nodcnt++;
       }
     }


/*---------------------------Help ----------------------------------------*/
void help()
{
clrscr();
printf("\n\n a         : To append.");
printf("\n p         : To display.");
printf("\n p m n     : To display range of line.");
printf("\n p m - n   : To display previous n lines from m position.");
printf("\n s         : To Save file.");
printf("\n d n       : To delete nth line.");
printf("\n d m n     : To delete range of lines.");
printf("\n f <pat>   : To search pattern. ");
printf("\n i n       : To insert after n line.");
printf("\n m n1 n2   : To move line n1 at n2 position.");
printf("\n m n1 n2 n3: To move range of line at n3.");
printf("\n c n1 n2   : To copy line n1 at position n2. ");
printf("\n c n1 n2 n3: To copy range of line at n3. ");
printf("\n h         :To give help information about all commands");
printf("\n\n Where\n m,n are numeric values.\n n1,n2,n3 are position of node.");
getch();
clrscr();
}


/*---------------------------Heart of Program------------------------------*/


void main(int argc,char *argv[])
{
char c='n';
int num[3];
char pat[15];
if(argc>2 &&argc<1)
printf("\n To much paramter there should be 1 or 2 only");
else
{
if(argc==1)
strcpy(fname,"empty.txt");
else
strcpy(fname,argv[1]);
printf("%s",fname);
readf();
while(c!='s')
{
fflush(stdin);
printf("\n\n$");
c=getchar();
switch(c)
{
case 'a':append();break;
case 'p':
	{
	 c=getchar();
	 if(c=='\n')
	 display();
	 else
	 {
	 scanf("%d",&num[0]);
	 c=getchar();
	 if(c=='-')
	 {scanf("%d",&num[1]);
	 displayrev(num[0],num[1]);
	 }
	 else
	 {scanf("%d",&num[1]);
	 displaymn(num[0],num[1]);
	 }
	 }
	 }
	 break;
case 's':save();break;
case 'h':help();break;
case 'f':
	{scanf("%s",pat);
	pattern(pat);
	}
	break;
case 'i':
	{
	scanf("%d",&num[0]);
	insert(num[0]);
	}
	break;
case 'd':
	{scanf("%d",&num[0]);
	c=getchar();
	if(c=='\n')
	delet(num[0]);
	else
	{
	scanf("%d",&num[1]);
	delets(num[0],num[1]);
	}
	}
	break;
case 'c':
	{scanf("%d%d",&num[0],&num[1]);
	c=getchar();
	if(c=='\n')
	copy(num[0],num[1]);
	else
	{
	scanf("%d",&num[2]);
	copys(num[0],num[1],num[2]);
	}
	}
	break;
case 'm':
	 {
	 scanf("%d%d",&num[0],&num[1]);
	 c=getchar();
	 if(c=='\n')
	 move(num[0],num[1]);
	 else
	 {
	scanf("%d",&num[2]);
	moves(num[0],num[1],num[2]);
	}
	 }
	 break;
default :printf("\n\n It is Invalid Choice....");
}
}
}
}

Out  put :-

C:\TC\SOURCE>LINEDIT sati.txt
sati.txt
 Total no. of lines are follow=5

$p
 File contains are as follow:-
1
2
3
4
5

$a
 Enter the append line.
6
$p
 File contains are as follow:-
1
2
3
4
5
6
$p 3  2
 Contain from the file 3 poistion to 2 number of nodes
3
4
$p 4-3
 Contain from the file 4 poistion to 3 number of nodes(revers)
4
3
2
$d 3
 Deleted Line are as Follow:-
1
2
3
$p
 File contains are as follow:-
4
5
6
$d 1 2
 THe delete line from file at given poistion 1 to 2 number of node
4
5
$p
 File contains are as follow:-
6
$f  6
Given  Pattern is present on the =1 node
$a
 Enter the append line.
13
$a
 Enter the append line.
12
$i  2
 Enter the insert line:-
10
$p
 File contains are as follow:-
6
13
10
12

$m 2 3

$p
 File contains are as follow:-
6
10
13
12

$m 2 1 3

$p
 File contains are as follow:-
6
13
10
12

$m 2 2 4

$p
 File contains are as follow:-
6
12
13
10

$c 2 4

$p
 File contains are as follow:-
6
12
13
10
12

$c 1  3  5

$p
 File contains are as follow:-
6
12
13
10
12
6
12
13


















$h
 a              : To append.
 p             : To display.
 p m n      : To display range of line.
 p m - n    : To display previous n lines from m position.
 s              : To Save file.
 d n          : To delete nth line.
 d m n      : To delete range of lines.
 f <pat>   : To search pattern.
 i n           : To insert after n line.
 m n1 n2  : To move line n1 at n2 position.
 m n1 n2 n3: To move range of line at n3.
 c n1 n2   : To copy line n1 at position n2.
 c n1 n2 n3 : To copy range of line at n3.
 h            :To give help information about all commands

 Where
 m,n are numeric values.
 n1,n2,n3 are position of node.

$s

 File is Saved.


