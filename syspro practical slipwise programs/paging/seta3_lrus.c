/*Date: 05/02/2013	LRU using stack set a1*/
#include<stdio.h>
struct stack
{
   int item[10];
   int top,bottom;
};
typedef struct stack STACK;
STACK s;
int RefString[20],PT[10],nof,nor;
void push(int a)
{
	s.item[s.top++]=a;
}
int pop()
{
	 return(s.item[s.bottom++]);
}
void Accept()
{
	 int i;
	 printf("Enter Reference String: \n");
	 for(i=0;i<nor;i++)
	{
		printf("[%d]=",i);
		scanf("%d",&RefString[i]);
	}
}

int Search(int s)
{
	int i;
	for(i=0;i<nof; i++)
	if(PT[i]==s)
		return(i);
	return(-1);
}

void LRU()
{
	int i,j,k,Faults=0,val;
	printf("\nString\tframes\n");
	for(k=0,i=0; k<nof && i<nor; i++)
	{
		printf("%4d",RefString[i]);
		if(Search(RefString[i])==-1)
		{
			PT[k]=RefString[i];
			push(RefString[i]);
			for(j=0;j<nof;j++)
			{
				if(PT[j])
					printf("%4d",PT[j]);
			}
			Faults++;
			k++;
		}
		printf("\n");
	}
	while(i<nor)
	{
		printf("%4d",RefString[i]);
		if(Search(RefString[i])==-1)
		{
			val = pop();
			printf("%2d",val);
			k=Search(val);
			printf("%2d",k);
			PT[k]=RefString[i];
			for(j=0;j<nof;j++)
			{
				printf("%4d",PT[j]);
			}
			Faults++;
		}
		i++;
		printf("\n");
	}
	printf("Total Page Faults: %d",Faults);
}
main()
{
	printf("Enter Length of reference string: ");
	scanf("%d",&nor);
	printf("Enter No.of Frames: ");
	scanf("%d",&nof);
	Accept();
	LRU();
}
/*  output
Enter Length of reference string: 15
Enter No.of Frames: 3
Enter Reference String: 
[0]=9
[1]=14
[2]=10
[3]=11
[4]=15
[5]=9
[6]=11
[7]=9
[8]=15
[9]=10
[10]=9
[11]=15
[12]=10
[13]=12
[14]=15

String  frames
   9   	9
  14   	9  14
  10   	9  14  10
  11 	9 	0  11  14  10
  15	14 	1  11  15  10
   9	10 	2  11  15   9
  11
   9
  15
  10 	0	-1  11  15   9
   9
  15
  10 	0	-1  11  15   9
  12 	0	-1  11  15   9
  15
Total Page Faults: 9		*/


