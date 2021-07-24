/*correct pro SJFnp prev tue of 8/1/13*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Input
{
	char pname[10];
	int bt,at,ct,tbt;
}tab[5];

struct Sequence
{
	int start, end;
	char pname[10];
}seq[100],seq1[100];

int finish,time,t,n,k,prev,q;

void getinput()
{
	int i;
	printf("Enter no of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter Process name: ");
		scanf("%s",tab[i].pname);
		printf("Enter Burst time:   ");
		scanf("%d",&tab[i].bt);
		printf("Enter Arrival time:   ");
		scanf("%d",&tab[i].at);
		tab[i].tbt=tab[i].bt;
	}
}
void printinput()
{
	int i;
	printf("\nPname\tBT\tAT\n");
	for(i=0;i<n;i++)
		printf("%s\t%d\t%d\n",tab[i].pname,tab[i].tbt,tab[i].at);
}
void bubble()
{
	int i,j;
	struct Input temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(tab[i].at>tab[j].at)
			{
				temp=tab[i];
				tab[j]=temp;
			}
		}
	}
}
int getmin(int t1)
{
	int i,mini,min=99;
	for(i=0;i<n;i++)
	{
		if(tab[i].at<=t1 && tab[i].tbt!=0 && tab[i].tbt<min)
		{	
			min=tab[i].tbt;
			mini=i;
		}
	
	}
	return mini;
}
int arrived(int t)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(tab[i].at<=t && tab[i].tbt!=0)
		{
			return 1;
		}
	}
	return 0;
}
void processinput()
{
	int i,j;
	finish=k=0;
	time=tab[0].at;
	while(finish!=n)
	{
		if(arrived(time))
		{
			i=getmin(time);
			for(j=0;j<=tab[i].bt;j++)	
			{
				time++;
				tab[i].tbt--;
				tab[i].ct=time;
				printinput();
				seq[k].start=prev;
				seq[k].end=time;
				strcpy(seq[k++].pname,tab[i].pname);
				prev=time;
				if(tab[i].tbt==0)
				{
					finish++;
					break;
				}
			}
		}
		else
		{
			time++;
			seq[k].start=prev;
			seq[k].end=time;
			strcpy(seq[k++].pname,tab[i].pname);
			prev=time;
		}
		if(time<tab[(i+1)%n].at)
			i=0;
		else
			i=(i+1)%n;
		
	}
}	
void printoutput()
{
	int i;
	float AvgTAT=0, AvgWT=0;
	printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t%d\t%d\t%d\t%d\t%d\n",tab[i].pname,tab[i].at,tab[i].bt,tab[i].ct,
		tab[i].ct-tab[i].at,tab[i].ct-tab[i].at-tab[i].bt);
		AvgTAT += tab[i].ct-tab[i].at;
		AvgWT += tab[i].ct-tab[i].at-tab[i].bt;	//cab
	}
	AvgTAT/=n;
	AvgWT/=n;
	
	printf("Average TAT = %f\n",AvgTAT);
	printf("Average WT = %f\n",AvgWT);
}
void ganttchart()
{
	int i,j=1;
	seq1[0] = seq[0];
	printf("\nGANNT CHART:\n");
	for(i=1;i<k;i++)
	{
		if(strcmp(seq1[j-1].pname,seq[i].pname)==0)
			seq1[j-1].end = seq[i].end;
		else
			seq1[j++] = seq[i];
	}
	for(i=0;i<j;i++)
		printf("\n%d\t%s\t%d",seq1[i].start,seq1[i].pname,seq1[i].end);
}
main()
{
	int i;
	getinput();
	printf("ENTERED DATA: \n");
	printinput();
	printf("DATA AFTER SORTING: \n");
	bubble();
	printinput();
	printf("PROCESS INPUT:\n");
	processinput();
	printoutput();
	ganttchart();
	for(i=0;i<n;i++)
	{
		tab[i].tbt=tab[i].bt=rand()%10+1;
		tab[i].at=tab[i].ct+2;
	}
	printf("\nData after random generation: ");
	printinput();
	processinput();
	printoutput();
	ganttchart();
}
/*	OUTPUT:
[root@LABIII OS]# cc SJFnp.c
[root@LABIII OS]# ./a.out
Enter no of processes: 4

Enter Process name: p1
Enter Burst time:   4
Enter Arrival time:   0

Enter Process name: p2
Enter Burst time:   1
Enter Arrival time:   1

Enter Process name: p3
Enter Burst time:   2
Enter Arrival time:   2

Enter Process name: p4
Enter Burst time:   1
Enter Arrival time:   3
ENTERED DATA: 

Pname   BT      AT
p1      4       0
p2      1       1
p3      2       2
p4      1       3
DATA AFTER SORTING: 

Pname   BT      AT
p1      4       0
p2      1       1
p3      2       2
p4      1       3
PROCESS INPUT:

Pname   BT      AT
p1      3       0
p2      1       1
p3      2       2
p4      1       3

Pname   BT      AT
p1      2       0
p2      1       1
p3      2       2
p4      1       3

Pname   BT      AT
p1      1       0
p2      1       1
p3      2       2
p4      1       3

Pname   BT      AT
p1      0       0
p2      1       1
p3      2       2
p4      1       3

Pname   BT      AT
p1      0       0
p2      0       1
p3      2       2
p4      1       3

Pname   BT      AT
p1      0       0
p2      0       1
p3      2       2
p4      0       3

Pname   BT      AT
p1      0       0
p2      0       1
p3      1       2
p4      0       3

Pname   BT      AT
p1      0       0
p2      0       1
p3      0       2
p4      0       3

Process AT      BT      CT      TAT     WT
p1      0       4       4       4       0
p2      1       1       5       4       3
p3      2       2       8       6       4
p4      3       1       6       3       2
Average TAT = 4.250000
Average WT = 2.250000

GANNT CHART:
0       p1      4
4       p2      5
5       p4      6
6       p3      8

Data after random generation: 
Pname   BT      AT
p1      4       6
p2      7       7
p3      8       10
p4      6       8

Pname   BT      AT
p1      3       6
p2      7       7
p3      8       10
p4      6       8

Pname   BT      AT
p1      2       6
p2      7       7
p3      8       10
p4      6       8

Pname   BT      AT
p1      1       6
p2      7       7
p3      8       10
p4      6       8

Pname   BT      AT
p1      0       6
p2      7       7
p3      8       10
p4      6       8

Pname   BT      AT
p1      0       6
p2      7       7
p3      8       10
p4      5       8

Pname   BT      AT
p1      0       6
p2      7       7
p3      8       10
p4      4       8

Pname   BT      AT
p1      0       6
p2      7       7
p3      8       10
p4      3       8

Pname   BT      AT
p1      0       6
p2      7       7
p3      8       10
p4      2       8

Pname   BT      AT
p1      0       6
p2      7       7
p3      8       10
p4      1       8

Pname   BT      AT
p1      0       6
p2      7       7
p3      8       10
p4      0       8

Pname   BT      AT
p1      0       6
p2      6       7
p3      8       10
p4      0       8

Pname   BT      AT
p1      0       6
p2      5       7
p3      8       10
p4      0       8

Pname   BT      AT
p1      0       6
p2      4       7
p3      8       10
p4      0       8

Pname   BT      AT
p1      0       6
p2      3       7
p3      8       10
p4      0       8

Pname   BT      AT
p1      0       6
p2      2       7
p3      8       10
p4      0       8

Pname   BT      AT
p1      0       6
p2      1       7
p3      8       10
p4      0       8

Pname   BT      AT
p1      0       6
p2      0       7
p3      8       10
p4      0       8

Pname   BT      AT
p1      0       6
p2      0       7
p3      7       10
p4      0       8

Pname   BT      AT
p1      0       6
p2      0       7
p3      6       10
p4      0       8

Pname   BT      AT
p1      0       6
p2      0       7
p3      5       10
p4      0       8

Pname   BT      AT
p1      0       6
p2      0       7
p3      4       10
p4      0       8

Pname   BT      AT
p1      0       6
p2      0       7
p3      3       10
p4      0       8

Pname   BT      AT
p1      0       6
p2      0       7
p3      2       10
p4      0       8

Pname   BT      AT
p1      0       6
p2      0       7
p3      1       10
p4      0       8

Pname   BT      AT
p1      0       6
p2      0       7
p3      0       10
p4      0       8

Process AT      BT      CT      TAT     WT
p1      6       4       10      4       0
p2      7       7       23      16      9
p3      10      8       31      21      13
p4      8       6       16      8       2
Average TAT = 12.250000
Average WT = 6.000000

GANNT CHART:

8       p1      10
10      p4      16
16      p2      23
23      p3      31	*/

			
