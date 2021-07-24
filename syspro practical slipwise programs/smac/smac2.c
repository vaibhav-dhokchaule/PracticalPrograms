mAssignment Name: A 2
2. Write a SMAC0 CPU simulator program in C for the following instruction set

Mnemonic Opcode      Meaning
READ         01             Read into memory operand
PRINT        02             Print contents of memory operand14
STOP          03             Stop of halt execution
ADD           04             Add memory operand to register operand
SUB            05             Subtract memory operand to register operand
MOVER      06             Move memory operand contents to register
MOVEM     07             Move register operand contents to memory
MULT         08             Multiply memory operand to register operand
DIV             09             Divide memory operand to register operand
BC               10             Branch to 2nd operator depending on cond
                                      code specified as 1st operand
COMP         11            Compare register & mem operand to set condition
                                     code appropriately
Assemble following program manually and execute it using above simulator.
READ N
LOOP MOVER AREG, SUM
ADD AREG, N
MOVEM AREG, SUM
MOVER AREG, N
SUB AREG, ONE
COMP AREG, ZERO
BC LE, OUT
MOVEM AREG, N
BC ANY, LOOP
OUT PRINT SUM
STOP
N DS 1
ZERO DC 0
ONE DC 1
SUM DC 0
END
Code format of above program is given as follow save it in notepad by code.txt
100 1 1 112
101 6 1 115
102 4 1 112
103 7 1 115
104 6 1 112
105 5 1 114
106 11 1 113
107 10 1 110
108 7 1 112
109 10 6 101
110 2 0 115
111 3 0 0
112 -1 0 1
113 -1 0 0
114 -1 0 1
115 -1 0 0

#include<stdio.h>
#include<conio.h>
main()
{
FILE *fp;
char sloc[10],sreg[10],snmemo[10] ,soper[10],name[20];
long int lp[1000],reg,nmemo,oper,loc,pc=-1,Registers[5];
int lt,gt,eq,any;
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
//printf("\n pc=%ld nmemo=%ld r=%ld oper=%ld\n",pc,nmemo,reg,oper);
pc=pc+1;
switch(nmemo)
{
case 3:{getch();
      printf("\n\n Process Finished"); //stop
      return 0;
      }
case 4:Registers[reg]+=lp[oper];       // add
       break;
case 5:Registers[reg]-=lp[oper];       //sub
       break;
case 8:Registers[reg]*=lp[oper];      //mult
       break;
case 6:Registers[reg]=lp[oper];       //mover
       break;
case 7:lp[oper]=Registers[reg];      //movem
       break;
case 11:{
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
case 10:switch(reg)                    //BC
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
case 9:Registers[reg]/=lp[oper];       //DIV
       break;
case 1:{printf("\n\n Enter the single value =>"); //READ
	scanf("%ld",&lp[oper]);
	break;
	}
case 2:printf("\n\n Final Ans=%ld\n",lp[oper]);    //PRINT
	break;
	}
      }
  }

out put:-

 Enter Smac0 file name=code.txt

 Loc    Nmemo   Reg     Oper            CODE
 100              1       1       112             11112
 101              6       1       115             61115
 102              4       1       112             41112
 103              7       1       115             71115
 104              6       1       112             61112
 105              5       1       114             51114
 106             11      1       113             111113
 107             10      1       110             101110
 108              7       1       112             71112
 109             10      6       101             106101
 110              2       0       115             20115
 111              3       0       0                  30000
 112             -1       0       1                   1
 113             -1       0       0                   0
 114             -1       0       1                   1
 115             -1       0       0                   0
 115             -1       0       0                   0

 Enter the single value =>10

 Final Ans=55 Process Finished

