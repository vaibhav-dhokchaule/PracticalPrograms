/* PROGRAM NAME: LRU USING COUNTER SET A3	*/
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
int GETLRU(int e)
{
	int i,j,pos=99,posi,k;
	for(i=0;i<nof;i++)
	{
		for(j=e-1;j>=0;j--)
		{
			if(pt[i]==refstring[j])
			{
				if(j<pos)
				{
					pos=j;
					posi=i;
				}
				break;
			}
		}
	}
	return(posi);
}
void LRU()
{
	int i,j,k,faults=0;
	for(k=0,i=0;k<nof && i<nor;i++)
	{
		printf("%2d\t",refstring[i]);
		if(search(refstring[i])==-1)
		{
			pt[k]=refstring[i];
			for(j=0;j<3;j++)
			{
				printf("%2d\t",pt[j]);
			}
			faults++;
			k++;
			printf("page faults");
		}
		printf("\n");
	}
	while(i<nor)
	{
		printf("%2d\t",refstring[i]);
		if(search(refstring[i])==-1)
		{
			k=GETLRU(i);
			pt[k]=refstring[i];
			for(j=0;j<nof;j++)
			{
				printf("%2d\t",pt[j]);
			}
			faults++;
			printf("page faults");
		}
		i++;
		printf("\n");
	}
	printf("Total page faults=%d\n",faults);
}
int main()
{
	printf("Enter length of reference string:");
	scanf("%d",&nor);
	printf("Enter the no. of frames:");
	scanf("%d",&nof);
	accept();
	LRU();
}
/*OUTPUT:
Enter length of reference string:15
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
 9       9       0       0      page faults
14       9      14       0      page faults
10       9      14      10      page faults
11      11      14      10      page faults
15      11      15      10      page faults
 9      11      15       9      page faults
11
 9
15
10      10      15       9      page faults
 9
15
10
12      10      15      12      page faults
15
Total page faults=8
*/

