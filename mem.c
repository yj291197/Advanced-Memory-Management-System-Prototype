#include <stdio.h>
#include <stdlib.h>
#include "mem.h"
void initialize(int OSmemory)
{
	node* temp2;
	if(OSmemory <= total)
	{
		temp2 = (node*)malloc(sizeof(node));
		head -> status = 1;
		head -> info = 0;
		head -> memory = OSmemory;
		head -> next = temp2;	
		head -> prev = NULL;
		count = count + 1;
	
		temp2 -> status = 0;
		temp2 -> memory = total - OSmemory;
		temp2 -> prev = head;
		temp2 -> info = count;   
		temp2 -> next = head;
		freeptr = temp2;
		freememnow = total - OSmemory;
		++count;
	}
	else printf("Cannot assign that much memory to RAM\n");
	
}

void allocate(int mem)
{
	if(mem <= freememnow)
	{
		node* temp = (node*)malloc(sizeof(node));
		freeptr -> memory = mem;
		freeptr -> status = 1;
		freeptr -> next = temp;
	
		temp -> prev = freeptr;
		temp -> memory = freememnow - mem;
		temp -> status = 0;
		temp -> info = count;
		temp -> next = head;
		freememnow = freememnow - mem;
		freeptr = temp;
		count++;
	}
	else printf("Your memory is full free some of it.\n");	
}

void map(void)
{
	node* x;
	printf("\nhead = %p\n", head);
	printf("info = %d mem = %d status = %d next = %p prev = %p\n", head->info,head->memory,head->status,head->next,head->prev);
	for(x=head->next;x!=head;x=x->next)
		printf("info = %d mem = %d status = %d next = %p prev = %p\n\n\n", x->info,x->memory,x->status,x->next,x->prev);

}
void freemem(int info)
{
	node* x,*temp,*temp1;
	if(info == 0)
	{
		printf("You can NOT free memory assigned to OS\n");
		return;
	}
	if(count<=2 && count>0)
	{
		printf("First allocate some memory then try to free\n");
		return;
	}
	else
	{
		for(x=head->next;x!=head;x=x->next)
		{	
			if(x->next == head)
			{	
				x -> prev -> next = head;
				freememnow = freememnow + x -> memory;
				free(x);		
				break;
			}
			else if(x->info == info)
				{
					temp = x;
					for(temp1 = x->next; temp1!=head;temp1=temp1->next)
						temp1 -> info = temp1 -> info - 1;
					x -> prev -> next = x -> next;
					x -> next -> prev = x -> prev;
					freememnow = freememnow + x -> memory;
					free(x);
					break;
				}	
		}	

		freeptr -> memory = freememnow;
	}

}
