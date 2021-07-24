/*Date:5/12/2013 	PROGRAM NAME:MFU set b2*/
#include<stdio.h>
int refstring[20],pt[10],nof,nor;
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
int getmfu(int e,int s)
{
	int i,j,cnt1=0,cnt2,pos;
	i=s;
	do
	{
		cnt2=0;
		for(j=e;j>=0;j--)
		{
			if(pt[i]==refstring[i])
			{
				cnt2++;
			}
            }   
		if(cnt2>cnt1)
		{
			cnt2=cnt1;
			pos=i;
		}
		i=(i+1)%nof;
	}while(i!=s);
	return(pos);
}
void mfu()
	{

		int i,j,k,faults=0;
		for(k=0,i=0;k<nof && j<nor;i++)
		{
			printf("\nframe%d:",i);
			if(search(refstring[i])==-1)
			{
				pt[k]=refstring[i];
				for(j=0;j<nof;j++)
				{
					printf("%2d\t",pt[j]);
				}
				faults++;
				k++;
			}
		}
		k=0;
		while(i<nor)
		{
			printf("\nframe %d:",i);  
			if(search(refstring[i])==-1)
			{
				k=getmfu(i,k);
				pt[k]=refstring[i];
				k=(k+1)%nof;
				for(j=0;j<nof;j++)
				{
					printf("%2d\t",pt[j]);
				}
				faults++;
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
		mfu();
	}

/*    output
1)
[root@localhost 234]# ./a.out
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

frame0: 9        0       0
frame1: 9       14       0
frame2: 9       14      10
frame 3: 9      14      11

frame 4: 9      15      11

frame 5:

frame 6:

frame 7:

frame 8:

frame 9:10      15      11

frame 10:10     15      11

frame 11:

frame 12:

frame 13:10     15      11

frame 14:
Total page faults=8
*/
