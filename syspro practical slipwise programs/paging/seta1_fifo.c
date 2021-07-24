/*Date: 05/02/2013	PROGRAM NAME: FIFO SET A 1*/
#include<stdio.h>
int refstring[20],pt[10],nof,nor;
void accept()
{
	int i;
	printf("Enter the reference string:");
	for(i=0;i<nor;i++)
	{
		printf("[%d]=",i);
		scanf("%d",&refstring[i]);
	}
}
int search(int s)
{
	int i;
	for(i=0;i<nof;i++)
		if(pt[i]==s)
			return(i);
	return(-1);
}
void FIFO()
{
	int i,j,k=0,faults=0;
	for(i=0;i<nor;i++)
	{
		printf("%2d||\t",refstring[i]);
		if(search(refstring[i])==-1)
		{
			pt[k]=refstring[i];
			for(j=0;j<nof;j++)
			{
				printf("%d\t",pt[j]);
			}
			faults++;
			k=(k+1)%nof;
			printf("page faults");
		}
		printf("\n");
	}
	printf("total page faults %d\n",faults);
}
int main()
{
	printf("Enter the length of the reference string:");
	scanf("%d",&nor);
	printf("Enter the no. of frames:");
	scanf("%d",&nof);
	accept();
	FIFO();
}
/*OUTPUT:
Enter the length of the reference string:15
Enter the no. of frames:3
Enter the reference string:[0]=9
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
 9||    9       0       0       page faults
14||    9       14      0       page faults
10||    9       14      10      page faults
11||    11      14      10      page faults
15||    11      15      10      page faults
 9||    11      15      9       page faults
11||
 9||
15||
10||    10      15      9       page faults
 9||
15||
10||
12||    10      12      9       page faults
15||    10      12      15      page faults
total page faults 9		*/
