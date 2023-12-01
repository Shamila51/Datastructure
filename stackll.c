#include<stdio.h>
#include<stdlib.h>
struct node
{	
	int data;
	struct node*link;
};
struct node*Top=NULL;

void push(int item)
{
	struct node*new;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=item;
	new->link=Top;
	Top=new;
	printf("%d inserted",new->data);

	if(Top==NULL)
	{
		Top=new;
		new->link=NULL;
	}
	else
	{
		new->link=Top;
		Top=new;
	}
}
void pop()
{
	if(Top==NULL)
	{	
		printf("stack is empty");
	}
	else
	{
		struct node*temp=Top;
		Top=Top->link;
		free(temp);
	}
}
void disp()
{
	if(Top==NULL)
	{
		printf("\n---list is empty----\n");
	}
	else
	{
		struct node*temp=Top;
		printf("\nEntered items are:\n");
		while(temp!=NULL)
		{
			printf("%d",temp->data);
			temp=temp->link;
		}
		printf("\n");
	}
}
void srch(int key)
{
	int count=0;
	if(Top=NULL)
	{
		printf("\n---list is empty---\n");
	}
	else
	{
		struct node*temp1=Top;
		while((temp1->data!=key)&&(temp1->link!=NULL))
		{
			temp1=temp1->link;
			count++;
		}
		if ((temp1->link==NULL)&&(temp1->data!=key))
		{
			printf("\nkey is not found\n");
		}
		else
		{
			printf("\nkey found at position %d\n",count+1);
		}
	}
}

int main()
{
	int z,k,c;
	printf("-------STACK USING LINKED LIST OPERATIONS----\n");
	while(1)
	{
		printf("\n1.PUSH\n2.POP\n3.DISPLAY ELEMENTS\n4.Search position of element\n5.EXIT");
		printf("\n selected the option\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("\n Enterd the data--\n");
				scanf("%d",&z);
				break;
			case 2:
				pop();
				break;
			case 3:
				disp();
				break;
			case 4:
				printf("\n---Enterd the key-----\n");
				scanf("%d",&k);
				srch(k);
				break;
			case 5:
				printf("\nbye bye---\n");
				exit(0);
				break;
			default:
				printf("\nwrong input---");
		}
	}

return 0;
}
				
		

