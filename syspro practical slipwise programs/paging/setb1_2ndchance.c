/*Date: 05/02/2013	PROGRAM NAME: SECOND CHANCE SET B2*/
#include<stdio.h>
int refstring[20],pt[10],u[10],nof,nor;
void accept()
{
	int i;
	printf("\nEnter the reference string:");
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
void second_chance()
{

	int i,j,k,faults=0,sp=0;
	for(i=0;i<nor;i++)
	{
		printf("%d",refstring[i]);
		k=search(refstring[i]);
			if(k==-1)
			{
				while(1)
				{
					if(u[sp]==0)
                                       {
				        pt[sp]=refstring[i];
					u[sp]=1;
					sp=(sp+1)%nof;
					faults++;
					break;
				}
				else
				{
					u[sp]=0;
					sp=(sp+1)%nof;
				}
			}
	}
	for(j=0;j<nof;j++)
	{
		printf("\n%3d%3d",pt[j],u[j]);
		if(j==sp)
			printf("*");
	}
}
printf("\n\t");
printf("Total page faults=%d\n",faults);
}
int main()
{
	printf("Enter length of reference string:");
	scanf("%d",&nor);
	printf("Enter the no. of frames:");
	scanf("%d",&nof);
	accept();
	second_chance();
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
9
  9  1
  0  0*
  0  0
14
  9  1
 14  1
  0  0*
10
  9  1*
 14  1
 10  1
11
 11  1
 14  0*
 10  0
15
 11  1
 15  1
 10  0*
9
 11  1*
 15  1
  9  1
11
 11  1*
 15  1
  9  1
9
 11  1*
 15  1
  9  1
15
 11  1*
 15  1
  9  1
10
 10  1
 15  0*
  9  0
9
 10  1
 15  0*
  9  0
15
 10  1
 15  0*
  9  0
10
 10  1
 15  0*
  9  0
12
 10  1
 12  1
  9  0*
15
 10  1*
 12  1
 15  1
Total page faults=9	*/
