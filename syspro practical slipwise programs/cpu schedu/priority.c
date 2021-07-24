/*correct prog preemptive priority prev tue of 8/1/13*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Input
{
	char pname[10];
	int bt,at,ct,tbt,p;
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
		printf("Enter Priority:   ");
		scanf("%d",&tab[i].p);
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
				tab[i]=tab[j];
				tab[j]=temp;
			}
		}
	}
}
int gethighpriority(int t1)
{
	int i,highpriop=0,highpri=0;	//highpri: highest priority value 
	for(i=0;i<n;i++)
	{
		if(tab[i].at<=t1 && tab[i].tbt!=0 && tab[i].p>highpri)
		{	
			highpri=tab[i].p;
			highpriop=i;	//highpriop: highest priority process no
		}
	
	}
	return highpriop;
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
			i=gethighpriority(time);
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
[root@LABIII OS]# ./a.out
Enter no of processes: 3

Enter Process name: p1
Enter Burst time:   3
Enter Arrival time:   1
Enter Priority:   3

Enter Process name: p2
Enter Burst time:   2
Enter Arrival time:   2
Enter Priority:   2

Enter Process name: p3
Enter Burst time:   5
Enter Arrival time:   0
Enter Priority:   1
ENTERED DATA: 

Pname   BT      AT
p1      3       1
p2      2       2
p3      5       0
DATA AFTER SORTING: 

Pname   BT      AT
p3      5       0
p1      3       1
p2      2       2
PROCESS INPUT:

Pname   BT      AT
p3      4       0
p1      3       1
p2      2       2

Pname   BT      AT
p3      4       0
p1      2       1
p2      2       2

Pname   BT      AT
p3      4       0
p1      1       1
p2      2       2

Pname   BT      AT
p3      4       0
p1      0       1
p2      2       2

Pname   BT      AT
p3      4       0
p1      0       1
p2      1       2

Pname   BT      AT
p3      4       0
p1      0       1
p2      0       2

Pname   BT      AT
p3      3       0
p1      0       1
p2      0       2

Pname   BT      AT
p3      2       0
p1      0       1
p2      0       2

Pname   BT      AT
p3      1       0
p1      0       1
p2      0       2

Pname   BT      AT
p3      0       0
p1      0       1
p2      0       2

Process AT      BT      CT      TAT     WT
p3      0       5       10      10      5
p1      1       3       4       3       0
p2      2       2       6       4       2
Average TAT = 5.666667
Average WT = 2.333333

GANNT CHART:

0       p3      1
1       p1      4
4       p2      6
6       p3      10
Data after random generation: 
Pname   BT      AT
p3      4       12
p1      7       6
p2      8       8

Pname   BT      AT
p3      4       12
p1      6       6
p2      8       8

Pname   BT      AT
p3      4       12
p1      5       6
p2      8       8

Pname   BT      AT
p3      4       12
p1      4       6
p2      8       8

Pname   BT      AT
p3      4       12
p1      3       6
p2      8       8

Pname   BT      AT
p3      4       12
p1      2       6
p2      8       8

Pname   BT      AT
p3      4       12
p1      1       6
p2      8       8

Pname   BT      AT
p3      4       12
p1      0       6
p2      8       8

Pname   BT      AT
p3      4       12
p1      0       6
p2      7       8

Pname   BT      AT
p3      4       12
p1      0       6
p2      6       8

Pname   BT      AT
p3      4       12
p1      0       6
p2      5       8

Pname   BT      AT
p3      4       12
p1      0       6
p2      4       8

Pname   BT      AT
p3      4       12
p1      0       6
p2      3       8

Pname   BT      AT
p3      4       12
p1      0       6
p2      2       8

Pname   BT      AT
p3      4       12
p1      0       6
p2      1       8

Pname   BT      AT
p3      4       12
p1      0       6
p2      0       8

Pname   BT      AT
p3      3       12
p1      0       6
p2      0       8

Pname   BT      AT
p3      2       12
p1      0       6
p2      0       8

Pname   BT      AT
p3      1       12
p1      0       6
p2      0       8

Pname   BT      AT
p3      0       12
p1      0       6
p2      0       8

Process AT      BT      CT      TAT     WT
p3      12      4       31      19      15
p1      6       7       19      13      6
p2      8       8       27      19      11
Average TAT = 17.000000
Average WT = 10.666667

GANNT CHART:

10      p1      19
19      p2      27
27      p3      31	*/		
