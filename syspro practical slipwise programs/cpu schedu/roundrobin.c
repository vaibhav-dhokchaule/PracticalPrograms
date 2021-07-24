/*ROUNDROBIN date:08/01/2013*/
#include<stdio.h>
struct Input
{
	char pname[10];
	int  bt,at,ct,tbt;
}tab[5];

struct Sequence
{
	int start,end;
	char pname[10];
}seq[100],seq1[20];

int finish,time,n,k,prev,q;

void getinput()
{
	int i;

	printf("\nEnter No.of Processes:");
	scanf("%d",&n);
	printf("Enter Time Quantum: ");
	scanf("%d",&q);
	for(i=0;i<n;i++)
	{
		printf("\nProcess name:\t");
		scanf("%s",tab[i].pname);
		printf("Burst time:\t");
		scanf("%d",&tab[i].bt);
		printf("Arrival time:\t");
		scanf("%d",&tab[i].at);
		tab[i].tbt = tab[i].bt;
	}
}

void printinput()
{
	int i;
	printf("\nProcess\tBT\tAT");
	for(i=0;i<n;i++)
		printf("\n%s\t%d\t%d",tab[i].pname,tab[i].tbt,tab[i].at);
	
}

void bubble()
{
	struct Input t;
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j< (n-1)-i;j++)
			if(tab[j].at>tab[j+1].at)
			{
				t = tab[j];
				tab[j] = tab[j+1];
				tab[j+1] = t;
			}
}

void printoutput()
{
	int i;
	float AvgTAT=0,AvgWT=0;
	printf("\nProcess\tAT\tBT\tCT\tTAT\tWT");
	for(i=0;i<n;i++)
	{
		printf("\n%s\t%d\t%d\t%d\t%d\t%d",tab[i].pname,tab[i].at,tab[i].bt,
		tab[i].ct, tab[i].ct-tab[i].at,tab[i].ct-tab[i].at-tab[i].bt);
		AvgTAT += tab[i].ct-tab[i].at;
		AvgWT += tab[i].ct-tab[i].at-tab[i].bt;
	}
	AvgTAT/=n;
	AvgWT/=n;
	printf("\nAverage TAT = %f",AvgTAT);
	printf("\nAverage WT = %f",AvgWT);

}

int arrived(int t)
{
	int i;
	for(i=0;i<n;i++)
		if(tab[i].at<=t && tab[i].tbt!=0)
			return 1;
	return 0;
}

void processinput()
{
	int i=0,j;
	finish = k = 0;
	time=tab[0].at;
	while(finish!=n)
	{
		if(arrived(time))
		{
			if(tab[i].tbt!=0)
			{
				for(j=0;j<q;j++)
				{
					time++;
					tab[i].tbt--;
					printinput();
					seq[k].start=prev;
					seq[k].end = time;
					strcpy(seq[k++].pname,tab[i].pname);
					prev = time;
					tab[i].ct=time;
					if(tab[i].tbt==0)
					{
						finish++;
						break;
					}
				}
			}
		}
		else
		{
			time++;
			seq[k].start=prev;
			seq[k].end = time;
			strcpy(seq[k++].pname,"*");
			prev = time;
		}
		if(time < tab[(i+1)%n].at)
		{
			i=0;
		}
		else
			i = (i+1)%n;
	}
}

void ganttchart()
{
	int i,j=1;
	printf("\nGANNT CHART:\n");
	seq1[0] = seq[0];
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
	printf("\nEntered data-: ");
	printinput();
	bubble();
	printf("\nData after sorting according to arrival time-: ");
	printinput();
	processinput();
	printoutput();
	ganttchart();
	for(i=0;i<n;i++)
	{
		tab[i].tbt = tab[i].bt=rand()%10+1;
		tab[i].at=tab[i].ct+2;
	}
	printf("\nData after random generation: ");
	printinput();
	processinput();
	printoutput();
	ganttchart();
}
/*OUTPUT

ot@LABIII OS]# ./a.out

Enter No.of Processes:3
Enter Time Quantum: 1

Process name:   p1
Burst time:     3
Arrival time:   1

Process name:   p2
Burst time:     2
Arrival time:   2

Process name:   p3
Burst time:     5
Arrival time:   0

Entered data-: 
Process BT      AT
p1      3       1
p2      2       2
p3      5       0
Data after sorting according to arrival time-: 
Process BT      AT
p3      5       0
p1      3       1
p2      2       2
Process BT      AT
p3      4       0
p1      3       1
p2      2       2
Process BT      AT
p3      4       0
p1      2       1
p2      2       2
Process BT      AT
p3      4       0
p1      2       1
p2      1       2
Process BT      AT
p3      3       0
p1      2       1
p2      1       2
Process BT      AT
p3      3       0
p1      1       1
p2      1       2
Process BT      AT
p3      3       0
p1      1       1
p2      0       2
Process BT      AT
p3      2       0
p1      1       1
p2      0       2
Process BT      AT
p3      2       0
p1      0       1
p2      0       2
Process BT      AT
p3      1       0
p1      0       1
p2      0       2
Process BT      AT
p3      0       0
p1      0       1
p2      0       2
Process AT      BT      CT      TAT     WT
p3      0       5       10      10      5
p1      1       3       8       7       4
p2      2       2       6       4       2
Average TAT = 7.000000
Average WT = 3.666667

GANNT CHART:
0       p3      1
1       p1      2
2       p2      3
3       p3      4
4       p1      5
5       p2      6
6       p3      7
7       p1      8
8       p3      10
Data after random generation: 
Process BT      AT
p3      4       12
p1      7       10
p2      8       8
Process BT      AT
p3      3       12
p1      7       10
p2      8       8
Process BT      AT
p3      3       12
p1      6       10
p2      8       8
Process BT      AT
p3      3       12
p1      6       10
p2      7       8
Process BT      AT
p3      2       12
p1      6       10
p2      7       8
Process BT      AT
p3      2       12
p1      5       10
p2      7       8
Process BT      AT
p3      2       12
p1      5       10
p2      6       8
Process BT      AT
p3      1       12
p1      5       10
p2      6       8
Process BT      AT
p3      1       12
p1      4       10
p2      6       8
Process BT      AT
p3      1       12
p1      4       10
p2      5       8
Process BT      AT
p3      0       12
p1      4       10
p2      5       8
Process BT      AT
p3      0       12
p1      3       10
p2      5       8
Process BT      AT
p3      0       12
p1      3       10
p2      4       8
Process BT      AT
p3      0       12
p1      2       10
p2      4       8
Process BT      AT
p3      0       12
p1      2       10
p2      3       8
Process BT      AT
p3      0       12
p1      1       10
p2      3       8
Process BT      AT
p3      0       12
p1      1       10
p2      2       8
Process BT      AT
p3      0       12
p1      0       10
p2      2       8
Process BT      AT
p3      0       12
p1      0       10
p2      1       8
Process BT      AT
p3      0       12
p1      0       10
p2      0       8
Process AT      BT      CT      TAT     WT
p3      12      4       22      10      6
p1      10      7       29      19      12
p2      8       8       31      23      15
Average TAT = 17.333334
Average WT = 11.000000

GANNT CHART:
10      p3      13
13      p1      14
14      p2      15
15      p3      16
16      p1      17
17      p2      18
18      p3      19
19      p1      20
20      p2      21
21      p3      22
22      p1      23
23      p2      24
24      p1      25
25      p2      26
26      p1      27
27      p2      28
28      p1      29
29      p2      31	*/
