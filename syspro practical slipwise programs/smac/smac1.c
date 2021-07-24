
Assignment Name: A 1
1. Write a SMAC0 CPU simulator program in C for the following instruction
set
Mnemonic    Opcode    Meaning
MOVER             01          Move memory operand contents to register
MOVEM           02          Move register operand contents to memory
READ                03           Read into memory operand
PRINT               04           Print contents of memory operand
COMP               05           Compare register & mem operand to set
                                           condition code appropriately
BC                     06           Branch to 2nd operator depending on cond
                                         code specified as 1st operand
MULT               07           Multiply memory operand to register operand
DIV                   08           Divide memory operand to register operand
ADD                 09            Add memory operand to register operand
SUB                 10            Subtract memory operand to register operand
STOP               11            Stop of halt execution

Assemble following program manually and execute it using above simulator.

READ N
MOVER AREG, N
COMP AREG, ZERO
BC LT, SHOW1
COMP AREG, ZERO
BC GE, SHOW
SHOW PRINT ONE
STOP
SHOW1 PRINT ZERO
STOP
N DS 1
ONE DC 1
ZERO DC 0
END
Code format of above program is given as follow save it in notepad by code.txt
100   3  0  110
101   1  1  110
102   5  1  112
103   6  1  108
104   5  1  112
105   6  5  106
106   4  0  111
107  11  0   0
108   4  0  112
109   11  0  0
110  -1  0  1
111  -1  0  1
112  -1  0  0

#include<stdio.h>
#include<conio.h>
main()
{
FILE *fp;
char  sloc[10],sreg[10],snmemo[10] ,soper[10],name[20];
long int  lp[1000],reg,nmemo,oper,loc,pc=-1,Registers[5];
int  lt,gt,eq,any;
clrscr();
printf("\n Enter Smac0 file name=");
scanf("%s",name);
fp=fopen(name,"r");
if(fp==NULL)
{
printf("Sorry File Dose Not Exist!!!!!");
return 0;
}
printf("\n Loc\tNmemo\tReg\tOper\t\tCODE");
while(!feof(fp))
{
fscanf(fp,"%s%s%s%s",sloc,snmemo,sreg,soper);
loc=atoi(sloc);
nmemo=atoi(snmemo);
reg=atoi(sreg);
oper=atoi(soper);
if(nmemo==-1)                // it is use to store constant values
lp[loc]=oper;
else
lp[loc]=nmemo*10000+reg*1000+oper;
if(pc==-1&& nmemo!=11)      // it is use to store staring position code to execute
pc=loc;
printf("\n %ld  \t%ld  \t%ld  \t%ld \t\t%ld",loc,nmemo,reg,oper,lp[loc]);
}
while(1)
{
nmemo=lp[pc]/10000;
reg=(lp[pc]%10000)/1000;
oper=(lp[pc]%10000)%1000;
printf("\n pc=%ld  nmemo=%ld r=%ld oper=%ld\n",pc,nmemo,reg,oper);
pc=pc+1;
switch(nmemo)
{
case 11:{getch();
      printf("\n\n Process Finished"); //stop
      return 0;
      }
case 9:Registers[reg]+=lp[oper];       // add
       break;
case 10:Registers[reg]-=lp[oper];       //sub
       break;
case 7:Registers[reg]*=lp[oper];      //mult
       break;
case 1:Registers[reg]=lp[oper];       //mover
       break;
case 2:lp[oper]=Registers[reg];      //movem
       break;
case 5:{
       if(Registers[reg]<lp[oper])      //comp
	lt=1;
	else
	lt=0;
	if(Registers[reg]==lp[oper])
	eq=1;
	else
	eq=0;
	if(Registers[reg]>lp[oper])
	gt=1;
	else
	gt=0;
	}
	break;
case 6:	switch(reg)                    //BC
       { case 1: if(lt==1)pc=oper;
		 break;
	 case 2: if(lt==1||eq==1)
		 pc=oper;
		 break;
	case 3: if(eq==1)
		 pc=oper;
		 break;
	case 4: if(gt==1)
		 pc=oper;
		 break;
	case 5: if(gt==1||eq==1)
		 pc=oper;
		 break;
	case 6: pc=oper;
	}
	break;
case 8:Registers[reg]/=lp[oper];       //DIV
       break;
case 3:{printf("\n\n Enter the single value =>"); //READ
	scanf("%ld",&lp[oper]);
	break;
	}
case 4:printf("\n\n Final Ans=%ld\n",lp[oper]);    //PRINT
	break;
	}
      }
  }

Out put:-


 Enter Smac0 file name=code.txt

 Loc    Nmemo   Reg     Oper            CODE
 100               3       0       110             30110
 101               1       1       110             11110
 102               5       1       112             51112
 103               6       1       108             61108
 104               5       1       112             51112
 105               6       5       106             65106
 106               4       0       111             40111
 107              11      0         0               110000
 108               4       0       112             40112
 109              11      0         0               110000
 110              -1       0           1               1
 111              -1       0           1               1
 112              -1       0           0               0
 pc=100 nmemo=3 r=0 oper=110

 Enter the single value =>3

 pc=101 nmemo=1 r=1 oper=110
 pc=102 nmemo=5 r=1 oper=112
 pc=103 nmemo=6 r=1 oper=108

 pc=104 nmemo=5 r=1 oper=112
 pc=105 nmemo=6 r=5 oper=106
 pc=106 nmemo=4 r=0 oper=111

 Final Ans=1

 pc=107 nmemo=11 r=0 oper=0
 Process Finished


