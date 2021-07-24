Assignment Name: A 3

Write a SMAC0 CPU simulator program in C for the following instruction set
Mnemonic    Opcode     Meaning
STOP               01           Stop of halt execution
SUB                 02           Subtract memory operand to register operand
ADD                03           Add memory operand to register operand
DIV                 04            Divide memory operand to register operand
MULT             05            Multiply memory operand to register operand
PRINT             06            Print contents of memory operand
READ             07             Read into memory operand
MOVEM         08             Move register operand contents to memory
MOVER          09             Move memory operand contents to register
BC                   10             Branch to 2nd operator depending on cond
                                        code specified as 1st operand
COMP             11            Compare register & mem operand to set condition
                                         code appropriately
Assemble following program manualy and execute it using above simulator.
15
READ N
LOOP MOVER AREG, N
MULT AREG, I
MOVEM AREG, ANS
PRINT RES
MOVEM AREG, I
ADD AREG, ONE
COMP AREG, TEN
BC GE, HALT
MOVEM AREG, I
BC ANY, LOOP
HALT STOP
N DS 1
RES DS 1
I DC 1
ONE DC 1
TEN DC 10
END
Code format of above program is given as follow save it in notepad by code.txt
200 7 0 212
201 9 1 212
202 5 1 214
203 8 1 217
204 6 0 213
205 8 1 214
206 3 1 215
207 11 1 216
208 10 5 211
209 8 1 214
210 10 6 201
211 1 0 0
212 -1 0 1
213 -1 0 1
214 -1 0 1
215 -1 0 1
216 -1 0 10
217 -1 0 1

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
case 1:{getch();
      printf("\n\n Process Finished"); //stop
      return 0;
      }
case 3:Registers[reg]+=lp[oper];       // add
       break;
case 2:Registers[reg]-=lp[oper];       //sub
       break;
case 5:Registers[reg]*=lp[oper];      //mult
       break;
case 9:Registers[reg]=lp[oper];       //mover
       break;
case 8:lp[oper]=Registers[reg];      //movem
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
case 4:Registers[reg]/=lp[oper];       //DIV
       break;
case 7:{printf("\n\n Enter the single value =>"); //READ
	scanf("%ld",&lp[oper]);
	break;
	}
case 6:printf("%ld  ",lp[oper]);    //PRINT
	break;
	}
      }
  }

Out put:-


 Enter Smac0 file name=code.txt

 Loc    Nmemo   Reg     Oper            CODE
 200    7       0       212             70212
 201    9       1       212             91212
 202    5       1       214             51214
 203    8       1       217             81217
 204    6       0       213             60213
 205    8       1       214             81214
 206    3       1       215             31215
 207    11      1       216             111216
 208    10      5       211             105211
 209    8       1       214             81214
 210    10      6       201             106201
 211    1       0       0               10000
 212    -1      0       1               1
 213    -1      0       1               1
 214    -1      0       1               1
 215    -1      0       1               1
 216    -1      0       10              10
 217    -1      0       1               1
 217    -1      0       1               1

 Enter the single value =>1
1  1  1  1  1  1  1  1  1

 Process Finished


