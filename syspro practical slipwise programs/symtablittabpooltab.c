/*********************************************************	
	 Varqa college Of Higher and Technical Education, Ahmednagar
			Department of Computer Science
Name: Shirke Pramod Suryabhan                      Class: T.Y.B.Sc(CS)
Batch: 					      
Assignment no:                 			        Date: 

Remark: ____________				    Sign: __________
*********************************************************/
Assignment Name: A 1
Write a program to accept a program written in assembly language. After accepting
entire program list out errors wherever applicable.
a) Symbols used but not defined
b) Symbols declared but not used
23
c) Redeclaration of symbolsAA
Consider following program as input
START 100
READ X
Y MOVER BREG, X
ADD BREG, X
X MOVEM AREG, Z
STOP
X DS 1
Y DS 1
END
#include<stdio.h>
#include<conio.h>
#include<string.h>
/* Symbol table structure*/
struct symbol
{
char name[6],def;
int addr,use,length,redef;
}st[20];

/*  literal */
int ltr=0;
/* instruction ,register & condition */
char opcode[][6]={"STOP","ADD","SUB","MULT","MOVER","MOVEM",
		  "COMP","BC","DIV","READ","PRINT"};
char asmcode[][7]={"START","END","ORIGIN","EQU","LTORG"};
char reg[][5]={"AREG","BREG","CREG","DREG"};
char cmp[][4]={"LT","LE","EQ","GT","GE","ANY"};

/* read parameter */
FILE *f;
int i,j,k,start=0,cnt=0,fg=0;
char name[10];
char para[4][10];
char c,c1='b';

void initial()
{int h=0;
 for(;h<20;h++)
 st[h].def='N';
}
chkasm()
{
int h,chk=1;
for(h=0;h<6&&chk;h++)
if(strcmp(asmcode[h],para[k])==0)
chk--;
  if(chk==0)
 { switch(h)
     {
      case 1:  start=atoi(para[++k])-1;break;
      case 2:case 3:case 4:k=i;break;
      case 5:start=ltr-1;
	  ltr=0; k=i;break;
     }
     return h;
 }
   return -1;
}
 chkopc()
{
int h;
for(h=0;h<11;h++)
if(strcmp(opcode[h],para[k])==0)
return h;
return -1;
}
 chkreg()
{
int h;
for(h=0;h<4;h++)
if(strcmp(reg[h],para[k])==0)
return(h+1);
return -1;
}
chkcond()
{
int h;
for(h=0;h<6;h++)
if(strcmp(cmp[h],para[k])==0)
return(h+1);
return -1;
}

 void display()
 {
 k=0;
 printf("\n\n                 Symbol Table \n");
 printf("\n\n -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
 printf("\n\n symbol   Addr   Use   Def   Len   Redef\n");
 for(k=0;k<cnt;k++)
 printf("\n %s\t  %d     %d     %c     %d     %d",st[k].name,st[k].addr,st[k].use,st[k].def,st[k].length,st[k].redef);
 printf("\n\n -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
 printf("\n\nDeclaration Error as follow\n");
 for(k=0;k<cnt;k++)
 {if(st[k].redef!=0)
  printf("\n%s Symbol is Redeclaration",st[k].name);
  else
  if(st[k].def=='Y'&&st[k].use==0)
  printf("\n%s Symbol is declare but not used.",st[k].name) ;
  else
  if(st[k].def=='N'&&st[k].use)
  printf("\n%s Symbol is used but not defined",st[k].name);
  }
 }
 declare()
{
if(strcmp(para[k],"DS")==0||strcmp(para[k],"DC")==0)
{ if(st[fg].def=='Y')
  st[fg].redef++;
  else
  {
  st[fg].def='Y';
  st[fg].addr=start;
  st[fg].length=atoi(para[++k]);
  }
  st[fg].use--;
  k=i;
  return 1;
}
return -1;
}
void read()
{i=j=0;

 while((c=getc(f))!=EOF&&c!='\n')
 {
    if(c==' '||c=='\t'||c==',')   // if occure
	 {
	 para[i++][j]='\0';           //then puttin \0 at end of string
	 j=0;
	 }
	 else
	 if(c=='-'||c=='+'||c=='=') //it is use to perform operation of ORIGIN oprtion
	 {c1=c;
	 para[i][j]=getc(f);
	 j=0;
	 }
	 else
	 para[i][j++]=c;
   }
   para[i++][j]='\0';
   if(c1=='=')
   {c1='a';
   i--;
   ltr++;
   }
      }

void symbol() // to check symbol
{
   int h,chk=1;
   for(h=0;h<cnt&& chk;h++)
   if(strcmp(st[h].name,para[k])==0)
   chk--;
   h--;
    if(chk==1)
    {
    strcpy(st[cnt].name,para[k]);
    st[cnt].use++;
    fg=cnt++;
    }
    else
    { st[h].use++;
      fg=h;
      }
   if(k==0)
     {k++;
     if(chkcond()==-1)
     {
	if(st[fg].def=='Y')
	st[fg].redef++;
	else
	{
	st[fg].addr=start;
	st[fg].def='Y';
	}
     }
     k--;
    }
}
void main()
{
int l=0;
clrscr();
printf("\n Enter the code file name =>");
scanf("%s",name);
f=fopen(name,"r");
initial();
while(!feof(f)&&c!=EOF)
{
l++;
start++;
read();
k=0;
 while(k<i)
 {
 if(i-k==4)
 {
 symbol();
 k++;
 }
 else
 if(chkasm()!=-1) k++;else
 if(chkopc()!=-1) k++;else
 if(chkreg()!=-1) k++;else
 if(chkcond()!=-1)k++;else
 if(declare()!=-1) k++;else
 {symbol();
 k++;
 }
}//inner
 } //out while
display();
getch();
}

Out put :-


 Enter the code file name =>code.txt

                 Symbol Table
 -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

 symbol   Addr   Use   Def   Len   Redef

 X            103     4      Y       0     2
 Y            101     1      Y       0     2
 Z                0     1      N       0     0

 -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

Declaration Error as follow

X Symbol is Redeclaration
Y Symbol is Redeclaration
Z Symbol is used but not defined












/*********************************************************
	 Varqa college Of Higher and Technical Education, Ahmednagar
			Department of Computer Science
Name: Shirke Pramod Suryabhan	               Class: T.Y.B.Sc(CS)
Batch: 					      	
Assignment no:                 			    Date: 

Remark: ____________				    Sign: __________
*********************************************************/
Assignment Name: A 2
Write a program to accept a program written in assembly language. After accepting
entire program list out errors wherever applicable.
a) Invalid statement
b) Invalid mnemonic
Consider following program as input
START 100 ,2
READ A
MOVER A,AREG
BDD AREG, A
A MOVEM AREG, ‘=2’
STOP
X DS 1
Y DS 1
END
#include<stdio.h>
#include<conio.h>
#include<string.h>

struct symbol
{
char name[6],def;
int addr,use,length,redef;
}st[20];

int ltr=0;
char opcode[][6]={"STOP","ADD","SUB","MULT","MOVER","MOVEM",
		  "COMP","BC","DIV","READ","PRINT"};
char asmcode[][7]={"START","END","ORIGIN","EQU","LTORG"};
char reg[][5]={"AREG","BREG","CREG","DREG"};
char cmp[][4]={"LT","LE","EQ","GT","GE","ANY"};

FILE *f;
int i,j,k;
int l=0;
int start=0,cnt=0,fg=0;
char name[10];
char para[4][10];
char c,c1='b';

void initial()
{int h=0;
 for(;h<20;h++)
 st[h].def='N';
}
void display()
 {
 k=0;
 printf("\n\n                 Symbol Table \n");
 printf("\n\n -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
 printf("\n\n symbol   Addr   Use   Def   Len   Redef\n");
 for(k=0;k<cnt;k++)
 printf("\n %s\t  %d     %d     %c     %d     %d",st[k].name,st[k].addr,st[k].use,st[k].def,st[k].length,st[k].redef);
 printf("\n\n -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
 }

void read()
{i=j=0;
 while((c=getc(f))!=EOF&&c!='\n')
 {
    if(c==' '||c=='\t'||c==','||c=='+'||c=='-')   // if occure
	 {
	 c1=c;
	 para[i++][j]='\0';           //then puttin \0 at end of string
	 j=0;
	 }
	 else
	 if(c=='=')
	 {
	 c1=c;
	 para[i][j++]=getc(f);
	 }
	 else
	 para[i][j++]=c;
   }
   para[i++][j]='\0';
   if(c1=='=')
   {ltr++;
   c1='a';
   }
   }

void symbol() // to check symbol
{
int h,chk=1;
for(h=0;h<cnt&&chk;h++)
 if(strcmp(st[h].name,para[k])==0)
 chk--;
 h--;
    if(chk==1)
    {
    strcpy(st[cnt].name,para[k]);
    st[cnt].use++;
    fg=cnt++;
    }
    else
    { st[h].use++;
     fg=h;
    }
     if(k==0)
     {k++;
     if(declare()!=-1)
     k=i+1;
     k--;
    }
}
void error(int k)
{
printf("\n");
for(j=0;j<=i;j++)
printf("%s ",para[j]);
if(k==1)
printf("\nInvalide statement on the line %d.\n\n",l);
else
printf("\n\n Invalide mnemonic  on the line %d.\n",l);
}
 chkasm()
{
int h,chk=1;
for(h=0;h<6&&chk;h++)
if(strcmp(asmcode[h],para[k])==0)
chk--;
  if(chk==0)
 {    switch(h)
     {
      case 1:  if(i-k!=2){k=i;error(1);}
	       else
	       start=atoi(para[++k])-1;break;

     case 2:  if(i-k!=1){k=i;error(1);}
	       break;
     case 3:  if(k+1==i)error(2);else
	      if(i-k!=2){k=i;error(1);}
	       else
	      if(c1=='+'||c1=='-')
	      {
	       symbol(para[++k]);
	       if(c1=='+')
	       start=st[fg].addr+atoi(para[++k]);
	       else
	       start=st[fg].addr-atoi(para[++k]);
	       c1='a';
	      }
	      else
	      start=st[fg].addr;
	      break;
       case 4:  if(i-k!=2)
		{k=i;
		error(1);
		}
		else
		{
		chk=fg;
		symbol(para[++k]);
		st[chk].addr=st[fg].addr;
		}
	       break;
       case 5: if(i-k!=1)
	       {error(1);
	       k=i;
	       }
	       else
	      {start=start+ltr-1;
	       ltr=0;
	       }
	       break;
	       }
     return h;
   }
   return -1;
}
 chkopc()
{
 int h,chk=1;
 for(h=0;h<11&&chk;h++)
if(strcmp(opcode[h],para[k])==0)
 chk--;
 if(chk==0)
 { h--;
    switch(h)
   {
    case 0:if(i-k!=1){k=i;error(1);}break;
    case 9:
    case 10:if(i-k!=2){k=i;error(1);}break;
    case 1:case 2:case 3:case 4:case 5:case 8:case 6:
    case 7:if(i-k!=3){k=i;error(1);} break;
   }
   return h;
}
else
return -1;
}
 chkreg()
{
int h;
for(h=0;h<4;h++)
if(strcmp(reg[h],para[k])==0)
return(h+1);
return -1;
}
chkcond()
{
int h;
for(h=0;h<6;h++)
if(strcmp(cmp[h],para[k])==0)
return(h+1);
return -1;
}
declare()
{
if(strcmp(para[k],"DS")==0||strcmp(para[k],"DC")==0)
{ if(st[fg].def=='Y')
   st[fg].redef++;
   else
   st[fg].def='Y';
  st[fg].addr=start;
  st[fg].length=atoi(para[++k]);
  st[fg].use--;
  return 1;
}
return -1;
}
void main()
{
int temp,temp1,temp2,temp3;
clrscr();
printf("\n Enter the code file name =>");
scanf("%s",name);
f=fopen(name,"r");
initial();
while(!feof(f)&&c!=EOF)
{
l++;
start++;
read();
k=0;
while(k<i)
 {
 temp=chkasm();
 temp1=chkopc();
 if(temp!=-1)
 k=i;
 else
 if(temp1!=-1)
 {
 k++;
 temp=chkreg();
 temp2=chkcond();
 switch(temp1)
 {
  case 0:k=i;break;
  case 9:case 10:if(temp!=-1||temp2!=-1){error(1); k=i;}break;
  case 7:if(temp2==-1){error(1);k=i;}else k++;break;
  default:if(temp==-1){error(1);k=i;}else k++;
  }
 }
  else
 {
 k++;
 temp=chkreg();
 temp1=chkcond();
 if(temp!=-1||temp2!=-1)
 {error(0);k=i;}
 else
 {k--;
  if(chkasm()==-1)
  symbol();
 }
 k++;
 }
  }//inner while
 } //out while
 display();
 getch();
}

Out put :-


 Enter the code file name =>code.txt

START 100 2
Invalide statement on the line 1.


MOVER A AREG
Invalide statement on the line 3.

BDD AREG A
Invalide mnemonic  on the line 4.

                Symbol Table
 -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
 symbol   Addr   Use   Def   Len   Redef
   A        0     2     N     0     0
   2        0     1     N     0     0
   X        7     0     Y     1     0
   Y        8     0     Y     1     0
 -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-













/********************************************************
	 Varqa college Of Higher and Technical Education, Ahmednagar
			Department of Computer Science
Name: Shirke Pramod Suryabhan		    Class: T.Y.B.Sc(CS)
Batch: 					      	
Assignment no:                 			                    Date: 

Remark: ____________				    Sign: __________
*********************************************************/
Assignment Name: A 3
 Write a program to accept a program written in assembly language. After accepting
entire program list out errors wherever applicable.
a) Symbols used but not defined
b) Symbols declared but not used
c) Redeclaration of symbols
d)Invalid symbol name
Consider following program as input
START 100
READ A
MOVER AREG, ORIGIN
ADD AREG, A
A MOVEM AREG, C
STOP
24
X DS 1
Y DS 1
END
#include<stdio.h>
#include<conio.h>
#include<string.h>

struct symbol
{
char name[6],def;
int addr,use,length,redef;
}st[20];

int ltr=0;
char opcode[][6]={"STOP","ADD","SUB","MULT","MOVER","MOVEM",
		  "COMP","BC","DIV","READ","PRINT"};
char asmcode[][7]={"START","END","ORIGIN","EQU","LTORG"};
char reg[][5]={"AREG","BREG","CREG","DREG"};
char cmp[][4]={"LT","LE","EQ","GT","GE","ANY"};

FILE *f;
int i,j,k;
int l=0;
int start=0,cnt=0,fg=0;
char name[10];
char para[4][10];
char c,c1='b';

void initial()
{int h=0;
 for(;h<20;h++)
 st[h].def='N';
}
void display()
 {
 k=0;
 printf("\n\n                 Symbol Table \n");
 printf("\n\n -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
 printf("\n\n symbol   Addr   Use   Def   Len   Redef\n");
 for(k=0;k<cnt;k++)
 printf("\n %s\t  %d     %d     %c     %d     %d",st[k].name,st[k].addr,st[k].use,st[k].def,st[k].length,st[k].redef);
 printf("\n\n -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
 printf("\n\nDeclaration Error as follow\n");
 for(k=0;k<cnt;k++)
 {if(st[k].redef!=0)
  printf("\n%s Symbol is Redeclaration",st[k].name);
  else
  if(st[k].def=='Y'&&st[k].use==0)
  printf("\n%s Symbol is declare but not used.",st[k].name) ;
  else
  if(st[k].def=='N'&&st[k].use)
  printf("\n%s Symbol is used but not defined",st[k].name);
  }
 }

void read()
{i=j=0;
 while((c=getc(f))!=EOF&&c!='\n')
 {
    if(c==' '||c=='\t'||c==','||c=='+'||c=='-')   // if occure
	 {
	 c1=c;
	 para[i++][j]='\0';           //then puttin \0 at end of string
	 j=0;
	 }
	 else
	 if(c=='=')
	 {
	 c1=c;
	 para[i][j++]=getc(f);
	 }
	 else
	 para[i][j++]=c;
   }
   para[i++][j]='\0';
   if(c1=='=')
   {ltr++;
   c1='a';
   }
   }

void symbol() // to check symbol
{
int h,chk=1;
for(h=0;h<cnt&&chk;h++)
 if(strcmp(st[h].name,para[k])==0)
 chk--;
 h--;
    if(chk==1)
    {
    strcpy(st[cnt].name,para[k]);
    st[cnt].use++;
    fg=cnt++;
    }
    else
    { st[h].use++;
     fg=h;
    }
     if(k==0)
     {k++;
     if(declare()!=-1)
     k=i+1;
     k--;
    }
}
void error(int k)
{
printf("\n");
for(j=0;j<=i;j++)
printf("%s ",para[j]);
if(k==2)
printf("\n Invalide Symbol Name\n\n");
else
if(k==1)
printf("\nInvalide statement on the line %d.\n\n",l);
else
printf("\n\n Invalide mnemonic  on the line %d.\n",l);
}
 chkasm()
{
int h,chk=1;
for(h=0;h<6&&chk;h++)
if(strcmp(asmcode[h],para[k])==0)
chk--;
  if(chk==0)
 {    switch(h)
     {
      case 1:  if(i-k!=2){k=i;error(1);}
	       else
	       start=atoi(para[++k])-1;break;

     case 2:  if(i-k!=1){k=i;error(1);}
	       break;
     case 3:  if(k+1==i)error(2);else
	      if(i-k!=2){k=i;error(1);}
	       else
	      if(c1=='+'||c1=='-')
	      {
	       symbol(para[++k]);
	       if(c1=='+')
	       start=st[fg].addr+atoi(para[++k]);
	       else
	       start=st[fg].addr-atoi(para[++k]);
	       c1='a';
	      }
	      else
	      start=st[fg].addr;
	      break;
       case 4:  if(i-k!=2)
		{k=i;
		error(1);
		}
		else
		{
		chk=fg;
		symbol(para[++k]);
		st[chk].addr=st[fg].addr;
		}
	       break;
       case 5: if(i-k!=1)
	       {error(1);
	       k=i;
	       }
	       else
	      {start=start+ltr-1;
	       ltr=0;
	       }
	       break;
	       }
     return h;
   }
   return -1;
}
 chkopc()
{
 int h,chk=1;
 for(h=0;h<11&&chk;h++)
if(strcmp(opcode[h],para[k])==0)
 chk--;
 if(chk==0)
 { h--;
    switch(h)
   {
    case 0:if(i-k!=1){k=i;error(1);}break;
    case 9:
    case 10:if(i-k!=2){k=i;error(1);}break;
    case 1:case 2:case 3:case 4:case 5:case 8:case 6:
    case 7:if(i-k!=3){k=i;error(1);} break;
   }
   return h;
}
else
return -1;
}
 chkreg()
{
int h;
for(h=0;h<4;h++)
if(strcmp(reg[h],para[k])==0)
return(h+1);
return -1;
}
chkcond()
{
int h;
for(h=0;h<6;h++)
if(strcmp(cmp[h],para[k])==0)
return(h+1);
return -1;
}
declare()
{
if(strcmp(para[k],"DS")==0||strcmp(para[k],"DC")==0)
{ if(st[fg].def=='Y')
   st[fg].redef++;
   else
   st[fg].def='Y';
  st[fg].addr=start;
  st[fg].length=atoi(para[++k]);
  st[fg].use--;
  return 1;
}
return -1;
}
void main()
{
int temp,temp1,temp2,temp3;
clrscr();
printf("\n Enter the code file name =>");
scanf("%s",name);
f=fopen(name,"r");
initial();
while(!feof(f)&&c!=EOF)
{
l++;
start++;
read();
k=0;
while(k<i)
 {
 temp=chkasm();
 temp1=chkopc();
 if(temp!=-1)
 k=i;
 else
 if(temp1!=-1)
 {
 k++;
 temp=chkreg();
 temp2=chkcond();
 switch(temp1)
 {
  case 0:k=i;break;
  case 9:case 10:if(temp!=-1||temp2!=-1){error(1); k=i;}break;
  case 7:if(temp2==-1){error(1);k=i;}else k++;break;
  default:if(temp==-1){error(1);k=i;}else k++;
  }
 }
  else
 {
 k++;
 temp=chkreg();
 temp1=chkcond();
 if(temp!=-1||temp2!=-1)
 {error(0);k=i;}
 else
 {k--;
  if(chkasm()==-1)
  symbol();
 }
 k++;
 }
  }//inner while
 } //out while
 display();
 getch();
}

out put :-

 Enter the code file name =>code.txt

MOVER AREG ORIGIN
 Invalide Symbol Name



                 Symbol Table


 -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
 symbol   Addr   Use   Def   Len   Redef

 A          0     3     N     0     0
 C          0     1     N     0     0
 X        105     0     Y     1     0
 Y        106     0     Y     1     0
 -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

Declaration Error as follow

A Symbol is used but not defined
C Symbol is used but not defined
X Symbol is declare but not used.
Y Symbol is declare but not used.











































/*********************************************************
	 Varqa college Of Higher and Technical Education, Ahmednagar
			Department of Computer Science
Name: Shirke Pramod Suryabhan		     Class: T.Y.B.Sc(CS)
Batch: 					      	
Assignment no:                 			    Date: 
Remark: ____________				    Sign: __________
*********************************************************/
Assignment Name: A 4
 Write a c program that will read given assembly language program as input.
Display the contents of SYMBOL TABLE, LITERAL TABLE and POOL TABLE.
Consider following program as input.
START 100
MOVER AREG, =5
MOVER BREG, =1
MOVER BREG, A
LTORG
MOVER CREG, =4
MOVER DREG, =1
MOVER BREG, B
PRINT A
STOP
A DS 1
B DC 2
END
#include<stdio.h>
#include<conio.h>
#include<string.h>

struct symbol
{
char name[6],def;
int addr,use,length,redef;
}st[20];

int polno=0;
int litno=0,ltr=0;
int poltab[]={1,0,0,0,0};
int literal[10][2];

char opcode[][6]={"STOP","ADD","SUB","MULT","MOVER","MOVEM",
		  "COMP","BC","DIV","READ","PRINT"};
char asmcode[][7]={"START","END","ORIGIN","EQU","LTORG"};
char reg[][5]={"AREG","BREG","CREG","DREG"};
char cmp[][4]={"LT","LE","EQ","GT","GE","ANY"};

FILE *f;
int i,j,k;
int l=0;
int start=0,beg=0;
int cnt=0,fg=0;
char name[10];
char para[4][10];
char c,c1='b';

void initial()
{int h=0;
 for(;h<20;h++)
 st[h].def='N';
 }

void lit()
 {
int chk=1;
int h=poltab[polno];
int value=atoi(para[k]);
if(ltr==polno)
{
 while(h<litno&&chk)
 if(value==literal[h++][0])
 chk--;
 if(chk==1)
 literal[litno++][0]=value;
 }
else
{
poltab[++polno]=litno+1;
literal[litno++][0]=value;
}
}
void lite()
{
printf("\n\n\t LitSymb Address\n");
for(k=0;k<litno;k++)
printf("\n   \t %d   \t %d ",literal[k][0],literal[k][1]);
printf("\n\n\t PoolIndex\n");
for(k=0;k<=polno;k++)
printf("\n\t  %d",poltab[k]);
}



void symbol() // to check symbol
{
int h,chk=1;
for(h=0;h<cnt&&chk;h++)
 if(strcmp(st[h].name,para[k])==0)
 chk--;
 h--;
    if(chk==1)
    {
    strcpy(st[cnt].name,para[k]);
    st[cnt].use++;
    st[cnt].addr=start;
    fg=cnt++;
    }
    else
    { st[h].use++;
     fg=h;
    }
}
void error(int i)
{
if(i==2)
printf("\n%s Invalide Symbol name on the line %d.",para[k],l);
else
if(i==1)
printf("\n Invalide statement on the line %d.",l);
else
printf("\n Invalide mnemonic on the line %d.",l);
}

 chkasm()
{
int h,chk=1;
for(h=0;h<6&&chk;h++)
if(strcmp(asmcode[h],para[k])==0)
chk--;
  if(chk==0)
 { switch(h)
     {
      case 1:  if(i-k!=2){k=i;error(1);}
	       else
	       beg=start=atoi(para[++k])-1;break;

     case 2:  if(i-k!=1){k=i;error(1);}
		else
	       {
	       h=poltab[polno]-1;
	       while(h<=litno)
	       literal[h++][1]=start++;
	       start--;
	       }
	       break;

      case 3: if(k==2){error(2);k=i;}else
	      if(i-k!=2){k=i;error(1);}else
	      if(c1=='+'||c1=='-')
	      {
	       symbol(para[++k]);
	       if(c1=='+')
	       start=st[fg].addr+atoi(para[++k]);
	       else
	       start=st[fg].addr-atoi(para[++k]);
	       c1='a';
	      }
	      else
	      start=st[fg].addr;
	      break;
       case 4:  if(k!=1||i-k!=2){error(2);k=i;}else
		if(i-k!=3){k=i;error(1);}
		else
		{
		chk=fg;
		symbol(para[++k]);
		st[chk].addr=st[fg].addr;
		}
	       break;
       case 5: if(i-k!=1)
	       {error(1);
	       k=i;
	       }
		else
	       { h=poltab[polno]-1;
		 while(h<litno)
	       literal[h++][1]=start++;
	       start--;
	       ltr++;
	       }
	       break;
		  }
     return h;
   }
   return -1;
}
 chkopc()
{
 int h,chk=1;
 for(h=0;h<11&&chk;h++)
if(strcmp(opcode[h],para[k])==0)
 chk--;
 if(chk==0)
 { h--;
   switch(h)
   {
    case 0:if(i-k!=1){k=i;error(1);}break;
    case 9:case 10:if(i-k!=2){k=i;error(1);}break;
    case 1:case 2:case 3:case 4:case 5:case 8:case 6:
    case 7:if(i-k!=3){k=i;error(1);} break;
   }
   return h;
}
else
return -1;
}
 chkreg()
{
int h;
for(h=0;h<4;h++)
if(strcmp(reg[h],para[k])==0)
return(h+1);
return -1;
}
chkcond()
{
int h;
for(h=0;h<6;h++)
if(strcmp(cmp[h],para[k])==0)
return(h);
return -1;
}

 void display()
 {
 k=0;
 for(k=0;k<cnt;k++)
 {if(st[k].redef!=0)
  printf("\n%s Symbol is Redeclaration",st[k].name);
  if(st[k].def=='Y'&&st[k].use==0)
  printf("\n%s Symbol is declare but not used.",st[k].name) ;
  else
  if(st[k].def=='N'&&st[k].use)
  printf("\n%s Symbol is used but not defined",st[k].name);
  }
  printf("\n\n|****************Symbol Table******************|\n\n");
  printf("\nSymbol\t Address  Used\t Defi\t length\t Redef \n");
 for(k=0;k<cnt;k++)
 printf("\n %s       %d        %d      %c      %d       %d",st[k].name,st[k].addr,st[k].use,st[k].def,st[k].length,st[k].redef);
 printf("\n*************************************************\n");
 }
declare()
{
if(strcmp(para[k],"DS")==0||strcmp(para[k],"DC")==0)
{ if(st[fg].def=='Y')
   st[fg].redef++;
   else
   st[fg].def='Y';
  st[fg].addr=start;
  st[fg].length=atoi(para[++k]);
  st[fg].use--;
  return 1;
}
return -1;
}

void read()
{i=j=0;
 while((c=getc(f))!=EOF&&c!='\n')
 {
    if(c==' '||c=='\t'||c==','||c=='+'||c=='-')   // if occure
	 {
	 c1=c;
	 para[i++][j]='\0';           //then puttin \0 at end of string
	 j=0;
	 }
	 else
	 if(c=='=')
	 {
	 c1=c;
	 para[i][j++]=getc(f);
	 }
	 else
	 para[i][j++]=c;
   }
   para[i++][j]='\0';
   }

void main()
{
int temp,temp1,temp2;
clrscr();
printf("\n Enter the code file name =>");
scanf("%s",name);
f=fopen(name,"r");
initial();
while(!feof(f)&&c!=EOF)
{
l++;
start++;
read();
k=0;
while(k<i)
 {
 temp=chkasm();
 temp1=chkopc();
 if(temp!=-1)
 k++;
 else
 if(temp1!=-1)
 {
 k++;
 temp=chkreg();
 temp2=chkcond();
 switch(temp1)
 {
  case 0:k=i;break;
  case 9:case 10:if(temp!=-1||temp2!=-1){error(1); k=i;}break;
  case 7:if(temp2==-1){error(1);k=i;}else k++;break;
  default:if(temp==-1){error(1);k=i;}else k++;
  }
 }
 else
 {
 if(c1=='=')
  {
  lit();
  c1='a';
  }
  else
 if(chkasm()==-1)
  symbol();

  k++;
 temp=chkreg();
 temp1=chkcond();
 if(declare()!=-1)
 k++;
 else
 if(temp!=-1||temp2!=-1)
 {error(0);k=i;}
  k++;
  }
 }//inner while
 } //out while
 display();
 printf("\n\n");
 if(litno>0)
 lite();
 getch();
}


Out put:-



 Enter the code file name =>code.txt


|****************Symbol Table******************|


Symbol   Address  Used   Defi    length  Redef

 A       110        2      Y      1       0
 B       111        1      Y      2       0
*************************************************




         LitSymb Address

         5       103
         1       104
         4       112
         1       113

         PoolIndex

          1
          3




/*********************************************************
	 Varqa college Of Higher and Technical Education, Ahmednagar
			Department of Computer Science
Name: Shirke Pramod Suryabhan 		    Class: T.Y.B.Sc(CS)
Batch: 						      	
Assignment no:                			    Date: 

Remark: ____________				    Sign: __________
*********************************************************/
Assignment Name: B2
 Write a assembler for error free assembly language program that will generate
target code. Display the contents of symbol table, literal table. pool table. Also
display target code generated.
Consider the following program as input
START 200
MOVER AREG, =’5’
MOVEM AREG, A
LOOP MOVER AREG, A
MOVER CREG, B
ADD CREG, =’1’
BC ANY, NEXT
LTORG
=’5’
=’1’
NEXT SUB AREG, =’1’
BC LT BACK
LAST STOP
ORIGIN LOOP+2
MULT CREG, B
ORIGIN LAST+1
A DS 1
BACK EQU LOOP
B DS 1
END
#include<stdio.h>
#include<conio.h>
#include<string.h>

struct symbol
{
char name[6],def;
int addr,use,length,redef;
}st[20];

int polno=0,litno=0,ltr=0,ltr1=-1;
int poltab[]={0,0,0,0,0};
int literal[10][2];

char opcode[][6]={"STOP","ADD","SUB","MULT","MOVER","MOVEM",
			  "COMP","BC","DIV","READ","PRINT"};
char asmcode[][7]={"START","END","ORIGIN","EQU","LTORG"};
char reg[][5]={"AREG","BREG","CREG","DREG"};
char cmp[][4]={"LT","LE","EQ","GT","GE","ANY"};

FILE *f;
int i,j,k,l=0;
int start=100,beg=0,cnt=0,fg=0;
char name[10];
char para[4][10];
char c,c1='b';

void initial() // Initialized the struct array
{int h=0;
 for(;h<20;h++)
 st[h].def='N';
 }

void lit()
 {
int chk=1;
int h=poltab[polno];
int value=atoi(para[k]);
if(ltr==polno)
{
 while(h<litno&&chk)
 if(value==literal[h++][0])
 chk--;
 if(chk==1)
 literal[litno++][0]=value;
 }
else
{
poltab[++polno]=litno;
literal[litno++][0]=value;
}
}
void lite()
{
printf("\n\n\t LitSymb Address\n");
for(k=0;k<litno;k++)
printf("\n   \t %d   \t %d ",literal[k][0],literal[k][1]);
printf("\n\n\t PoolIndex\n");
for(k=0;k<=polno;k++)
printf("\n\t  %d",poltab[k]+1);
}
void vallit()
{
int h=poltab[ltr1];
int value=atoi(para[k]);
while(literal[h++][0]!=value);
fg=h-1;
}
void display()
 {
 k=0;
 printf("\n\n|****************Symbol Table******************|\n\n");
 printf("\nSymbol\t Address  Used\t Defi\t length\t Redef \n");
 for(k=0;k<cnt;k++)
 printf("\n %s       %d        %d      %c      %d       %d",st[k].name,st[k].addr,st[k].use,st[k].def,st[k].length,st[k].redef);
 printf("\n*************************************************\n");
 }

void symbol() // to check symbol
{
int h,chk=1;
for(h=0;h<cnt&&chk;h++)
 if(strcmp(st[h].name,para[k])==0)
 chk--;
 h--;
    if(chk==1)
    {
    strcpy(st[cnt].name,para[k]);
    st[cnt].use++;
    st[cnt].addr=start;
    fg=cnt++;
    }
    else
    { st[h].use++;
     fg=h;
    }
}
 chkasm()
{
int p;
int h,chk=1;
for(p=0;p<6&&chk;p++)
if(strcmp(asmcode[p],para[k])==0)
chk--;
  if(chk==0)
 { switch(p)
     {
      case 1:start=atoi(para[++k])-1;break;   //start
      case 2:{                                //end
	       h=poltab[polno];
	       while(h<litno)
	       literal[h++][1]=start++;
	       start--;
	       }
	       break;
      case 3: if(c1=='+'||c1=='-')          //origin
	      {
	       symbol(para[++k]);
	       if(c1=='+')
	       start=st[fg].addr+atoi(para[++k]);
	       else
	       start=st[fg].addr-atoi(para[++k]);
		c1='a';
		}
	      else
	      start=st[fg].addr;
		       break;
       case 4:  chk=fg;                  // EQU
		symbol(para[++k]);
		st[chk].addr=st[fg].addr;
		 break;
       case 5: h=poltab[polno];          //LTORG
	       if(ltr1==-1)
	       {
	       while(h<litno)
	       literal[h++][1]=start++;
	       start--;
	       ltr++;
	       }
	       break;
	    }
	       return p;
   } //end of if
   return -1;
}
 chkopc()
{
 int h;
 for(h=0;h<11;h++)
if(strcmp(opcode[h],para[k])==0)
 return h;
 return -1;
}
 chkreg()
{
int h;
for(h=0;h<4;h++)
if(strcmp(reg[h],para[k])==0)
return(h+1);
return -1;
}
chkcond()
{
int h;
for(h=0;h<6;h++)
if(strcmp(cmp[h],para[k])==0)
return(h+1);
return -1;
}
 declare()
{
if(strcmp(para[k],"DS")==0||strcmp(para[k],"DC")==0)
{ if(st[fg].def=='Y')
  {
  st[fg].redef++;
  k=i;
  }
  else
  {
  st[fg].def='Y';
  st[fg].addr=start;
  st[fg].length=atoi(para[++k]);
  st[fg].use--;
  }
  return 1;
}
return -1;
}

void read()
{i=j=0;
 while((c=getc(f))!=EOF&&c!='\n')
 {
    if(c==' '||c=='\t'||c==','||c=='+'||c=='-')   // if occure
	 {
	 c1=c;
	 para[i++][j]='\0';           //then puttin \0 at end of string
	 j=0;
	 }
	 else
	 if(c=='=')
	 {
	 c1=c;
	 c=getc(f);
	 para[i][j++]=c;
	 k=i;
	 }
	 else
	 para[i][j++]=c;
   }
   para[i++][j]='\0';
   }
 void  pass1()
 {
 while(k<i)
 {
   if(i-k==4)
   {symbol();
    st[fg].addr=start;
    k++;
   }
   else
 if(chkasm()!=-1)
 k++;
 else
    if((j=chkopc())!=-1)
   {
      k++;
    if(chkreg()!=-1)
    k++;
    else
    if(chkcond()!=-1)
    k++;
   }
 else
 if(declare()!=-1)
 k++;
 else
 if(c1=='=')
 {
 lit();
 k++;
 c1='b';
 }
 else
  {
   symbol();
   if(k==0)
   st[fg].addr=start;
    k++;
    }
 }//inner while
  }

 void  pass2()
 {
 printf("\n");
 while(k<i)
 {
   if(i-k==4)
   k++;
   else
   if((j=chkasm())!=-1)
   {if(j==5)
    ltr1++;
    k=i;
    }
   else
    if((j=chkopc())!=-1)
    {
      if(j==0)
      {printf("\n00000");k++;}
      else
       {
       printf("%d",j);
       k++;
       if((j=chkreg())!=-1)
       {printf("%d",j);k++;}
	else
       if((j=chkcond())!=-1)
       { printf("%d",j); k++;}
       else
       printf("0");
       }
    }
 else
     if(declare()!=-1)
     {  printf("0000%d",st[fg].length);
	k++;
      }
 else
	if(c1=='=')
      {
	vallit();
	printf("%d",literal[fg][1]);
	k++;
	c1='b';
       }
 else
      { symbol();
	if(k!=0)
	printf("%d",st[fg].addr);
	k++;
      }
 }//inner while
 }

void main()
{
clrscr();
printf("\n Enter the code file name =>");
scanf("%s",name);
f=fopen(name,"r");
initial();
while(!feof(f)&&c!=EOF)
{l++;
start++;
read();
k=0;
pass1();
} //out while
 display();
 printf("\n\n");
 if(litno>1)
 lite();
 getch();
 c='a';
 rewind(f);
 ltr1=0;
 printf("\n Source Code in SMAC 0 form as follow :-\n\n");
 while(!feof(f)&&c!=EOF)
{
l++;
start++;
read();
k=0;
pass2();
 } //out while
getch();
}


out put:-



|****************Symbol Table******************|
           Symbol   Address  Used   Defi    length  Redef

           A               212           2        Y            1       0
           LOOP       202           3        N            0       0
           B              214            2        Y             1       0
           NEXT       208           2        N             0       0
           BACK       202           2        N             0       0
           LAST       210            2        N             0       0
*************************************************




         LitSymb   Address

         5                 206
         1                 207
         1                 215

         PoolIndex

          1
          3
 
Source Code in SMAC 0 form as follow :-

41206
51212
41212
43214
13207
76208

21215
71202

00000

33214

00001

00001

