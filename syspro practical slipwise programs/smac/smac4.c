Assignment Name: B 2
2: Write a SMAC0 CPU simulator program in C for the following instruction
set
Mnemonic       Opcode      Meaning
MOVER              01           Move memory operand contents to register
MOVEM             02           Move register operand contents to memory
READ                 03             Read into memory operand
PRINT                04            Print contents of memory operand
COMP                05             Compare register & mem operand to set
                                            condition code appropriately
BC                      06              Branch to 2nd operator depending on cond
                                            code specified as 1st operand
MULT                07             Multiply memory operand to register operand
DIV                    08             Divide memory operand to register operand
ADD                  09             Add memory operand to register operand
SUB                  10              Subtract memory operand to register operand
STOP                11              Stop of halt execution

Assemble following program manually and execute it using above
simulator.

READ N
MOVER AREG, ONE
MOVEM AREG, FACT
MOVEM AREG, COUNT
LOOP MOVER BREG, COUNT
MULT BREG, FACT
MOVEM BREG, FACT
17
MOVER AREG, COUNT
ADD AREG, ONE
MOVEM AREG, COUNT
COMP AREG, N
BC LE, LOOP
PRINT FACT
STOP
COUNT DS 1
ONE DC 1
N DS 1
FACT DS 1
END
Code format of above program is given as follow save it in notepad by code.txt
100 3 0 116
101 1 1 115
102 2 1 117
103 2 1 114
104 1 2 114
105 7 2 117
106 2 2 117
107 1 1 114
108 9 1 115
109 2 1 114
110 5 1 116
111 6 2 104
112 4 0 117
113 11 0 0
114 -1 0 1
115 -1 0 1
116 -1 0 1
117 -1 0 1

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
case 6:switch(reg)                    //BC
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

out put:-


 Enter Smac0 file name=code.txt

 Loc    Nmemo   Reg     Oper            CODE
 100    3       0       116             30116
 101    1       1       115             11115
 102    2       1       117             21117
 103    2       1       114             21114
 104    1       2       114             12114
 105    7       2       117             72117
 106    2       2       117             22117
 107    1       1       114             11114
 108    9       1       115             91115
 109    2       1       114             21114
 110    5       1       116             51116
 111    6       2       104             62104
 112    4       0       117             40117
 113    11      0       0               110000
 114    -1      0       1               1
 115    -1      0       1               1
 116    -1      0       1               1
 117    -1      0       1               1
 117    -1      0       1               1

 Enter the single value =>6

 Final Ans=720

 Process Finished
