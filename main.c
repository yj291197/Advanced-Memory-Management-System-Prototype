#include<stdio.h>
#include<stdlib.h>
#include"mem.h"


int main()
{	
	int a,b,c,m,i,j,k=0,l;
	printf("MAXIMUM Memory your RAM can hold while running: ");
	scanf("%d", &total);
	freeptr = NULL;
	head = NULL;
	count = 0;
//	node* head = NULL;
	node* x;
	head = (node*)malloc(sizeof(node));
	head -> status = 0;
	head -> memory = total;
	printf("How much memory do you want to put into Kernel: ");
	scanf("%d", &a);
 	initialize(a);
	/*
	
	printf("How much memory do you want to allocate to your program: ");
	scanf("%d", &b);
	allocate(b);
	map();
	
	*/
	map();
	
	while(k!=4)
	{
		printf("1. ALLOCATE\n2. FREE\n3. MAP\n4. EXIT\n\nEnter your choice here : ");	
		scanf("%d", &k);
		if(k==1)
		{
			printf("How much memory do you want to allocate to your program: ");
			scanf("%d", &b);	
			allocate(b);
		}
		else if(k==2)
		{
			printf("Which numbered(info) used memory do you want to free: ");	
			scanf("%d", &m);
			freemem(m);
		}
		else if(k==3)
			map();
		else return 0;
	
	}
	
	
	
return 0;
}
