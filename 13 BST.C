#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node*rightchild;
        int data;
        struct node*leftchild;
};
struct node *Root=NULL;
struct node *temp2=NULL;


struct node* create(int item)
{
    struct node *node;
    node=(struct node*)malloc(sizeof(struct node));
    node->rightchild=NULL;
    node->leftchild=NULL;
    node->data=item;
    return node;
}

struct node*insert(struct node*temp,int item)
{
    if(temp==NULL)
    {
        temp=create(item);
    }
    else if(item < temp->data)
    {
        temp->leftchild=insert(temp->leftchild,item);
    }
    else
    {
        temp->rightchild=insert(temp->rightchild,item);
    }
    return temp;
}




void inorder(struct node*temp)
{

    if(temp!=NULL)
    {
        inorder(temp->leftchild);
        printf("%d ",temp->data);
        inorder(temp->rightchild);

    }

}

void postorder(struct node*temp)
{

    if(temp!=NULL)
    {
        postorder(temp->leftchild);
        postorder(temp->rightchild);
        printf("%d ",temp->data);

    }

}

void preorder(struct node*temp)
{

    if(temp!=NULL)
    {
        printf("%d ",temp->data);
        preorder(temp->leftchild);
        preorder(temp->rightchild);

    }

}

int main()
{

    int sr,c;
	printf("Binary search Tree\n");
	while(1)
    {
        printf("\n1.Insertion\n2.Traversal\n3.Exit");
        printf("\nSelect the options\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                    printf("\nenter the data to insert\n");
                    scanf("%d",&sr);
                    Root=insert(Root,sr);
                    break;

            case 2: if(Root==NULL)
                    {
                        printf("\nEmpty\n");
                    }
                    else
                    {
                    printf("\nInorder\n");
                    inorder(Root);
		    printf("\n");
		    printf("\nPostorder \n");
                    postorder(Root);
		    printf("\n");
                    printf("\nPre order\n");
                    preorder(Root);
		    printf("\n");
                    }
                    break;

        case 3: printf("\nExited\n");
		        exit(0);
                break;

        default:
		printf("\nwrong input.\n");
        }
    }
	return 0;
}
