/*	CORRECT BANKER: 22/01/13	*/
#include<stdio.h>

int i, j, nop, nor, A[10][10], M[10][10], N[10][10], Av[10], P[10], safe[10];

void accept()
{
	printf("Enter Allocation Matrix:\n");
	for(i=0;i<nop;i++)
	{
		for(j=0;j<nor;j++)
		scanf("%d",&A[i][j]);
	}
	printf("\nEnter Max:\n");
	for(i=0;i<nop;i++)
	{
		for(j=0;j<nor;j++)
		scanf("%d",&M[i][j]);
	}
	printf("\nEnter Available Matrix:\n");
	for(i=0;i<nor;i++)
	scanf("%d",&Av[i]);
}
void printinput()
{
	printf("Process\t    Allocation\t\tMax\t\tNeed\n");
	printf("******************************************************\n");
	printf("\t");
	int j=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<nor;j++)
			printf("%4c",65+j);
		printf("\t");
	}
	printf("\n");
	
	for(i=0;i<nop;i++)
	{
		printf("P[%d]",i);
		printf("\t");
		
 		for(j=0;j<nor;j++)
		printf("%4d",A[i][j]);
		printf("\t");
		
		for(j=0;j<nor;j++)
		printf("%4d",M[i][j]);
		printf("\t");
			
		for(j=0;j<nor;j++)
		{
			N[i][j]=M[i][j]-A[i][j];
			printf("%4d",N[i][j]);
		}
		printf("\n");
	}

	printf("\nAvailable:\n");
	printf("------------\n");
	for(i=0;i<nor;i++)
	printf("%4d",Av[i]);
			
}
int checkneed(int x)
{
	for(j=0;j<nor;j++)
	if(N[x][j]>Av[j])
		return -1;
	return 1;
}
void Banker()
{	
	printf("\n");
	int finish[10]={0},ss[10],k=0,i=0,f=0;
	while(1)
	{
		f=0;i=0;
		while(i<nop)
		{
			if(finish[i]==0)
			{
				if(checkneed(i)==-1)
				printf("Since need of P[%d] > Av, requirement of P[%d] cannot be satisfied\n",i,i);
				else
				{
					f=1,finish[i]=1;
					ss[k++]=i;
					for(j=0;j<nor;j++)
					Av[j]=Av[j]+A[i][j];
					printf("\nSince need of P[%d] <= Av, requirement of P[%d] can be satisfied\n",i,i);
					printf("Work = [");
					for(j=0;j<nor;j++)
					printf("%d,",Av[j]);
					printf("\b]\n");
					
				}
			}	
			i++;
		}
		if(f==0 || k==nop)	
		break;
	}
	if(k==nop)
	{
		printf("\nSince All Requirements have been satisfied, system is in safe state and safe sequence is:\n [");
		for(i=0;i<k;i++)
		printf("P[%d],",ss[i]);
		printf("\b]");
	}
	else
	printf("System is not in safe state");
}
					
		
main()
{
	int flag=1;
	printf("Enter no of processes: ");
	scanf("%d",&nop);
	printf("Enter no of resources: ");
	scanf("%d",&nor);
	accept();
	printinput();
	Banker();
	printf("\nNew Process has Arrived..Enter the requirements:\n");
	for(i=0;i<nor;i++)
	{
		printf("%c: ",65+i);
		scanf("%d",&P[i]);
	}
	for(i=0;i<nor;i++)	
	{
		if(P[i]>Av[i])	
		{
			flag=0;
			break;
		}
	}
	if(flag==0)
		printf("New Process cannot be granted Required Resources\n");
	else
		printf("New Process can be granted Required Resources\n");
	
	printf("\n");
}
/*	OUTPUT:
SET A que 1
Enter no of processes: 5
Enter no of resources: 3
Enter Allocation Matrix:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
 
Enter Max:
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
 
Enter Available Matrix:
3 3 2
Process     Allocation          Max             Need
******************************************************
           A   B   C       A   B   C       A   B   C
P[0]       0   1   0       7   5   3       7   4   3
P[1]       2   0   0       3   2   2       1   2   2
P[2]       3   0   2       9   0   2       6   0   0
P[3]       2   1   1       2   2   2       0   1   1
P[4]       0   0   2       4   3   3       4   3   1
 
Available:
------------
3   3   2
Since need of P[0] > Av, requirement of P[0] cannot be satisfied
Since need of P[1] <= Av, requirement of P[1] can be satisfied
Work = [5,3,2]
Since need of P[2] > Av, requirement of P[2] cannot be satisfied
Since need of P[3] <= Av, requirement of P[3] can be satisfied
Work = [7,4,3]
Since need of P[4] <= Av, requirement of P[4] can be satisfied
Work = [7,4,5]
Since need of P[0] <= Av, requirement of P[0] can be satisfied
Work = [7,5,5]
Since need of P[2] <= Av, requirement of P[2] can be satisfied
Work = [10,5,7]
 
Since All Requirements have been satisfied, system is in safe state and safe sequence is:
 [P[1],P[3],P[4],P[0],P[2]]
New Process has Arrived..Enter the requirements:
A: 9
B: 6
C: 4
New Process cannot be granted Required Resources

set A que 2
Enter no of processes: 5
Enter no of resources: 4
Enter Allocation Matrix:
0 0 1 2
1 0 0 0
1 3 5 4
0 6 3 2
0 0 1 4
                                                                                                
Enter Max:
0 0 1 2
1 7 5 0
2 3 5 6
0 6 5 2
0 6 5 6
                                                                                                
Enter Available Matrix:
1 5 2 0
Process     Allocation          Max             Need
******************************************************
           A   B   C   D           A   B   C   D           A   B   C   D
P[0]       0   0   1   2           0   0   1   2           0   0   0   0
P[1]       1   0   0   0           1   7   5   0           0   7   5   0
P[2]       1   3   5   4           2   3   5   6           1   0   0   2
P[3]       0   6   3   2           0   6   5   2           0   0   2   0
P[4]       0   0   1   4           0   6   5   6           0   6   4   2
 
Available:
------------
   1   5   2   0
 
Since need of P[0] <= Av, requirement of P[0] can be satisfied
Work = [1,5,3,2]
Since need of P[1] > Av, requirement of P[1] cannot be satisfied
Since need of P[2] <= Av, requirement of P[2] can be satisfied
Work = [2,8,8,6]
Since need of P[3] <= Av, requirement of P[3] can be satisfied
Work = [2,14,11,8]
Since need of P[4] <= Av, requirement of P[4] can be satisfied
Work = [2,14,12,12]
Since need of P[1] <= Av, requirement of P[1] can be satisfied
Work = [3,14,12,12]
 
Since All Requirements have been satisfied, system is in safe state and safe sequence is:
 [P[0],P[2],P[3],P[4],P[1]]
New Process has Arrived..Enter the requirements:
A: 2
B: 2
C: 11
D: 10
New Process can be granted Required Resources

set B que 1
Enter no of processes: 5
Enter no of resources: 3
Enter Allocation Matrix:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
 
Enter Max:
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
 
Enter Available Matrix:
3 3 2
Process     Allocation          Max             Need
******************************************************
           A   B   C       A   B   C       A   B   C
P[0]       0   1   0       7   5   3       7   4   3
P[1]       2   0   0       3   2   2       1   2   2
P[2]       3   0   2       9   0   2       6   0   0
P[3]       2   1   1       2   2   2       0   1   1
P[4]       0   0   2       4   3   3       4   3   1
 
Available:
------------
   3   3   2
Since need of P[0] > Av, requirement of P[0] cannot be satisfied
Since need of P[1] <= Av, requirement of P[1] can be satisfied
Work = [5,3,2]
Since need of P[2] > Av, requirement of P[2] cannot be satisfied
Since need of P[3] <= Av, requirement of P[3] can be satisfied
Work = [7,4,3]
Since need of P[4] <= Av, requirement of P[4] can be satisfied
Work = [7,4,5]
Since need of P[0] <= Av, requirement of P[0] can be satisfied
Work = [7,5,5]
Since need of P[2] <= Av, requirement of P[2] can be satisfied
Work = [10,5,7]
 
Since All Requirements have been satisfied, system is in safe state and safe sequence is:
 [P[1],P[3],P[4],P[0],P[2]]
New Process has Arrived..Enter the requirements:
A: 1
B: 0
C: 2
New Process can be granted Required Resources

set B que 2

Enter no of processes: 5
Enter no of resources: 4
Enter Allocation Matrix:
0 0 1 2
1 0 0 0
1 3 5 4
0 6 3 2
0 0 1 4
                                                                                                
Enter Max:
0 0 1 2
1 7 5 0
2 3 5 6
0 6 5 2
0 6 5 6
                                                                                                
Enter Available Matrix:
1 5 2 0
Process     Allocation          Max             Need
******************************************************
           A   B   C   D           A   B   C   D           A   B   C   D
P[0]       0   0   1   2           0   0   1   2           0   0   0   0
P[1]       1   0   0   0           1   7   5   0           0   7   5   0
P[2]       1   3   5   4           2   3   5   6           1   0   0   2
P[3]       0   6   3   2           0   6   5   2           0   0   2   0
P[4]       0   0   1   4           0   6   5   6           0   6   4   2
 
Available:
------------
   1   5   2   0
 
Since need of P[0] <= Av, requirement of P[0] can be satisfied
Work = [1,5,3,2]
Since need of P[1] > Av, requirement of P[1] cannot be satisfied
Since need of P[2] <= Av, requirement of P[2] can be satisfied
Work = [2,8,8,6]
Since need of P[3] <= Av, requirement of P[3] can be satisfied
Work = [2,14,11,8]
Since need of P[4] <= Av, requirement of P[4] can be satisfied
Work = [2,14,12,12]
Since need of P[1] <= Av, requirement of P[1] can be satisfied
Work = [3,14,12,12]
 
Since All Requirements have been satisfied, system is in safe state and safe sequence is:
[P[0],P[2],P[3],P[4],P[1]]
New Process has Arrived..Enter the requirements:
A: 0
B: 4
C: 2
D: 0
New Process can be granted Required Resources	*/
