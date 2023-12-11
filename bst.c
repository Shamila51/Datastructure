#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *lchild;
	int key;
	struct node *rchild;
};
struct node *root=NULL;
void insert(int item)
{
	struct node *ptr=root,*ptr1,*newnode;
	int flag=0;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->lchild=NULL;
	newnode->key=item;
	newnode->rchild=NULL;
	while((ptr!=NULL) && (flag==0))
	{
		if(item<ptr->key)
		{
			ptr1=ptr;
			ptr=ptr->lchild;	
		}
		else if(item>ptr->key)
		{
				ptr1=ptr;
				ptr=ptr->rchild;		
		}
		else
		{
			if(item==ptr->key)	
			{
				flag=1;
				printf("failed...");
			}
		}
	}
		if(root==NULL)
			root=newnode;
		else
		{
			if(flag!=1)
			{
				if(item<ptr1->key)
				{
					ptr1->lchild=newnode;
				}
				else
				{
					ptr1->rchild=newnode;
				}
			}
		}

}		

void inorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		printf("%d\n",ptr->key);
		inorder(ptr->rchild);
	}
}

void preorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		printf("%d\n",ptr->key);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}

void postorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d\n",ptr->key);
	}
}



void search(int item)
{
	struct node *ptr=root;
	int flag=0;
	while((ptr!=NULL)&&(flag==0))
	{
		
		if(item<ptr->key)
		{
			ptr=ptr->lchild;	
		}
		else if(item>ptr->key)
		{
			ptr=ptr->rchild;		
		}
		else
		{
			if(item==ptr->key)	
			{
				flag=1;
			}
		}
	}
	if(flag==1)
		printf("Key found.\n");
	else
		printf("Key not found.\n");
}

struct node *minimum(struct node *ptr)
{
	while(ptr->lchild!=NULL)
		ptr=ptr->lchild;
	return(ptr);
}

struct node *successor(struct node *ptr)
{
	if(ptr->rchild!=NULL)
		return(minimum(ptr->rchild));
	return(ptr);
}
void delete(int item)
{
	struct node *ptr=root,*ptr1,*newnode;
	int flag=0;
	while((ptr!=NULL) && (flag==0))
	{
		if(item<ptr->key)
		{
			ptr1=ptr;
			ptr=ptr->lchild;	
		}
		else if(item>ptr->key)
		{
				ptr1=ptr;
				ptr=ptr->rchild;		
		}
		else
		{
			if(item==ptr->key)	
			{
				flag=1;
			}
		}
	}
	//CASE 1:No child nodes
	if((ptr->lchild==NULL)&&(ptr->rchild==NULL))
	{
		if(ptr==ptr1->lchild)
			ptr1->lchild=NULL;
		else
			ptr1->rchild=NULL;
		free(ptr);	
	}
	else
	{
		//CASE 3:If both child node exists
		if((ptr->lchild!=NULL)&&(ptr->rchild!=NULL))
		{
			int temp;
			struct node *succr;
			succr=successor(ptr);
			temp=succr->key;
			delete(temp);
			ptr->key=temp;
		}
		//CASE 2:If one child node exists
		else
		{
			int temp;
			if(ptr->rchild!=NULL)
			{
				temp=ptr->rchild->key;
				delete(temp);
				ptr->key=temp;
			}
			else
			{
				temp=ptr->lchild->key;
				delete(temp);
				ptr->key=temp;	
			}
		}
			
	}		

}
int main()
{
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	printf("Inorder of root is :\n");
	inorder(root);
	printf("preorder of root is :\n");
	preorder(root);
	printf("postorder of root is :\n");
	postorder(root);
	struct node *succr=successor(root);
	printf("Successor of root is : %d\n",succr->key);
	delete(5);
	inorder(root);
}
	
			
				
	
	
	
