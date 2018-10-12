#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int search(int target,int arr[], int arr_index)
{
	int i;
	for(i=0;i<arr_index;i++)
	{
		if (target==arr[i])
			return 1;
	}
	return -1;
}

int compar(char arr1[], char arr2[], int arr_index)
{
	int i;
	for(i=0;i<arr_index;i++)
	{
		if (arr1[i]!=arr2[i])
			return -1;
	}
	return 1;
}

int main(int argc, char *argv[]) 
{
	int i, n, p;
	int search(int target,int arr[], int arr_index);
	int compar(char arr1[], char arr2[], int arr_index);
	int result, compare;
	int num[100]={0};
	int guess[100]={0};
	char stat[100];
	char fakestat[100];
	n = atoi(argv[1]);
	p = atoi(argv[2]);
	memset (stat, 'H', 100);//set all the values in the array as H =>the max of p is 100
	memset (fakestat, 'H', 100);
	printf("You set N=%d, P=%d\n",n,p);
	srand((unsigned) time(0));
	
	for (i=0;i<p;i++)
	{	num[i]=rand()%n+1;
		printf("%i\t",num[i]);
	}
	printf("\n\n");

	printf("*******************************\n");
do
	{	
	printf("Input %d guesses:\n",p);
	for (i=0;i<p;i++)
	{	scanf("%d",&guess[i]);
	}
	for (i=0;i<p;i++)	
	{	//printf("%d\t",guess[i]);
	}
	//printf("\n");
	
	for(i=0;i<p;i++)
	{	result = search(guess[i], num, p);
		if(result==-1)
		{	//printf("0");
			stat[i] = 0;
		}
		else if(result==1)
		{	if(guess[i]==num[i])
			{	//printf("H");
				stat[i]= 'H';
			}
			else
			{	//printf("X");
				stat[i]= 'X';
			}
		}
	}
	printf("\n");
	/*for (i=0;i<p;i++)	
	{	printf("%c\t",stat[i]);
	}*/
	//printf("\n");
	
	int h=0,x=0;
	for (i=0;i<p;i++)
	{	
		if(stat[i]=='H')
			h+=1;
		if(stat[i]=='X')
			x=x+1;
	}
	printf("%dH, %dX",h,x);
	printf("\n\n");
	compare = compar(stat, fakestat, p);
	}while(compare!=1);

	printf("Congradulations!\n");
}


