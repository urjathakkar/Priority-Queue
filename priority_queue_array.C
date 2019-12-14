#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#define MAX 10
int queue[5][2] = {0};
int top=-1;
int bottom=-1;

void insert(int value, int pr)
{
	int i,j,k;
	if(top > MAX -1)
	{
		printf("\nQueue is full");
	}
	else
	{
		if(queue[top][1] > pr)
		{
		for(i=0;i<top;i++)
			{
			if(queue[i][1] > pr)
			{
				break;
			}
			}
		for(j=top;j>=i;j--)
		{
			queue[j+1][0] = queue[j][0];
			queue[j+1][1] = queue[j][1];
		}
		top++;
		queue[i][0] = value;
		queue[i][1] = pr;
		}
	else
	{
	top++;
	queue[top][0] = value;
	queue[top][1] = pr;
	}
}
}


void del()
{
int i;
if(queue[0][0] == 0)
{
	printf("\n The queue is empty  \n");
}
else
{
	printf("the deleted value is %d \n", queue[0][0]);
	for(i=0;i<top;i++)
	{
	queue[i][0] = queue[i+1][0];
	queue[i][1] = queue[i+1][1];
	}
	queue[top][0] = 0;
	queue[top][1] = 0;
	top--;
	}
}


void print()
{
int i,j;
printf("Element\tPriority \n");
for(i=top ;i>=0;i--)
{
for(j=0;j<2;j++)
{
printf(" %d\t",queue[i][j]);
}
printf("\n");
}
}

main()
{
int i,j, ch=0 ,value = 0,pr=0;
while(ch!=4)
{
	printf("\n1.Enqueue.\n2.Dequeue.\n3.Print\n4.Exit");
	printf("\nEnter the choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\nEnter the number to be inserted:");
			scanf("%d", &value);
			printf("\nEnter the priority:");
			scanf("%d", &pr);
			insert(value,pr);
			break;
		case 2:
		del();
		break;
		case 3:
		print();
		break;
		case 4:
			exit(0);
	}
}
}
