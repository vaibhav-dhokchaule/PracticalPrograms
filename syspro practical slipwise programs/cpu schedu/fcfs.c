#include<conio.h>
#include<stdio.h>
#include<string.h>
struct input
{
	char pname[20];
	int bt,at,ct,tbt;
}tab[5];

struct sequence
{
	int start,end;
	char pname[20];
}seq[100],seq1[100];

int finish,time,n,k,prev;

void getinput()
{
	int i;
	printf("enter no of process");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nProcess name:");
		scanf("%s",tab[i].pname);
		printf("Burst time");
		scanf("%d",&tab[i].bt);
		printf("Arrival time");
		scanf("%d",&tab[i].at);
		tab[i].tbt=tab[i].bt;
	}
}

void printinput()
{
	int i;
	printf("\nProcess\tBT\tAT");
	for(i=0;i<n;i++)
	{
		printf("\n%s\t%d\t%d",tab[i].pname,tab[i].tbt,tab[i].at);
	}
}
void bubble()
{
	struct input a;
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<(n-1)-i;j++)
			if(tab[j].at>tab[j+1].at)
			{
				a=tab[j];
				tab[j]=tab[j+1];
				tab[j+1]=a;
			}
	}
}

int arrived( int a)
{
	int i;
	for(i=0;i<n;i++)
		if(tab[i].at<=a && tab[i].tbt!=0)
			return 1;
	return 0;
}


void process()
{
	int i=0,j;
	finish=k=0;
	time=tab[0].at;
	while(finish!=n)
	{
		if(arrived(time))
		{
			if(tab[i].tbt!=0)
			{
				for(j=0;j<tab[i].bt;j++) // for loop for non-preemptive
			{
					time++;
					tab[i].tbt--;
					printinput();
					seq[k].start=prev;// for gannt chart
					seq[k].end=time;// for gannt chart
					strcpy(seq[k++].pname,tab[i].pname);// for gannt chart
					prev=time;
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
			seq[k].end=time;
			strcpy(seq[k++].pname,"#");
			prev=time;
		}
if(time<tab[(i+1)%n].at)
{
i=0;
}
else
i=(i+1)%n;
}
}
void printoutput()
{
	int i;
	float avgtat=0,avgwt;
	printf("\n process\tAT\tBT\tCT\tTAT\tST\tWT");
	for(i=0;i<n;i++)
	{
		printf("\n%s\t%d\t%d\t%d\t%d\t%d\t%d",tab[i].pname,tab[i].at,tab[i].bt,tab[i].ct,tab[i].ct,tab[i].at,tab[i].ct-tab[i].at-tab[i].bt);
		avgtat+=tab[i].ct-tab[i].at;
		avgwt+=tab[i].ct-tab[i].at-tab[i].bt;
	}
	avgtat/=n;
	avgwt/=n;
	printf("\n average time TAT=%f",avgtat);
	printf("\n average time WT=%f",avgwt);
}

void ganttchart()
{
	int i,j=1;
	seq1[0]=seq[0];
	for(i=1;i<k;i++)
	{
		if(strcmp(seq1[j-1].pname,seq[i].pname)==0)
			seq1[j-1].end=seq[i].end;
		else
			seq1[j++]=seq[i];
	}
	for(i=0;i<j;i++)
		printf("\n%d\t%s\t%d",seq[i].start,seq1[i].pname,seq1[i].end);
	
}
void main()
{
	getinput();
	printf("\nEntered data:");
	printinput();
	bubble();
	printf("\nData after sorting according to arrival time:");
	printinput();		
	process();
	printf("Process input\n");
	printoutput();
	printf("gannt chart");
	ganttchart();
	getch();
}
/*	OUTPUT:
Enter no of processes: 3
Process name:  p1
Burst time:    2
Arrival time:  1

Process name:  p2
Burst time:    3
Arrival time:  0

Process name:  p3
Burst time:    4
Arrival time:  2

Entered data:
Process	BT	AT
p1		2	1
p2		3	0	
p3		4	2

Data after sorting according to arrival time:
Process BT      AT
p2      3       0
p1      2       1
p3      4       2

Process Input:
Process BT      AT
p2      2       0
p1      2       1
p3      4       2
Process BT      AT
p2      1       0
p1      2       1
p3      4       2
Process BT      AT
p2      0       0
p1      2       1
p3      4       2
Process BT      AT
p2      0       0
p1      1       1
p3      4       2
Process BT      AT
p2      0       0
p1      0       1
p3      4       2
Process BT      AT
p2      0       0
p1      0       1
p3      3       2
Process BT      AT
p2      0       0
p1      0       1
p3      2       2
Process BT      AT
p2      0       0
p1      0       1
p3      1       2
Process BT      AT
p2      0       0
p1      0       1
p3      0       2
Process AT      BT      CT      TAT     ST      WT
p2      0       3       3       3       0       0
p1      1       2       5       5       1       2
p3      2       4       9       9       2       3
 average time TAT=4.666667
 average time WT=1.666667
Gannt chart:
0       p2      3
1       p1      5
2       p3      9
*/


