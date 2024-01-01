#include<stdio.h>
#include<stdlib.h>
int queue[25];
int rear=-1,front=-1;
int add_item,i,j,v,E,type;
int temp,k;
int visit[5]={0,0,0,0,0};
int graph[5][5];
struct AdjList
{
 	int key;
	struct AdjList *next;


};
struct AdjList*vtx[5];
void enqueue(int add_item)
{
 	if(rear==25-1)
	{
		printf("\n queue is overflow.\n");
	}
	if(rear<25)
	{
		if(rear==-1 && front==-1)
		{
			front=rear=0;
			queue[rear]=add_item;
		}

		else
 		{
		rear=rear+1;
		queue[rear]=add_item;
		}
	}
}
int dequeue()
{
   if(front==-1 )
   {
     printf("\n queue is underflow.\n");
   }
  else if(front==rear)
  {

    temp=queue[front];
    front=-1;
    rear=-1;
  }
  else
   {

     temp=queue[front];
     front=front+1;
   }
    return(temp);

}
int isVisited(int vtx)
{
	return(visit[vtx]);
}
void bfs(int s)
{
        int vtx;
	enqueue(s);
	while(front!=-1 && rear!=-1)
	{
		vtx=dequeue();
		if(!(isVisited(vtx)))
		{
			visit[vtx]=1;
			printf("%d\n",vtx);
			for(int i=0;i<5;i++)
			{
				if(graph[vtx][i]==1)
					enqueue(i);
			}
		}
	}
}
void bfslist(int s)
{
        int x;
	struct AdjList *ptr;
	enqueue(s);
	while(front!=-1 && rear!=-1)
	{
		x=dequeue();
		if(!(isVisited(x)))
		{
			visit[x]=1;
			printf("%d\n",x);
			ptr=vtx[x];
			while(ptr!=NULL)
			  {
				enqueue(ptr->key);
				ptr=ptr->next;
			  }
		}
	}
}
/*void getMatrix()
{
printf("Enter adjacency matrix\n");
	for (i=1;i<=v;++i)
	{
		for(j=i;j<=v;++j)
		{
			printf("Enter value( %d,%d )\n",i,j);
			scanf("%d",&graph[i][j]);
			graph[j][i]=graph[i][j];
		}
	}
	printf("adjacency matrix\n");
	for (i=1;i<=v;++i)
	{
		for(j=1;j<=v;++j)
		{
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
}
*/
void createList(int v,int e)
{
	struct AdjList *newnode,*ptr;
	newnode=(struct AdjList *)malloc(sizeof(struct AdjList));
	newnode->key=e;
	newnode->next=NULL;
        if(vtx[v]==NULL)
		{
	   vtx[v]=newnode;
		}
	else
		{
           ptr=vtx[v];
	   while(ptr->next!=NULL)
		{
		ptr=ptr->next;
		}
           ptr->next=newnode;
		}

}
/*void createMatrix()
{
	int i,j,E1,E2;
	for (i=0;i<v;i++)
	{
		for(j=0;j<=v;j++)
		{
			graph[j][i]=0;
		}
	}
	for (i=0;i<E;i++)
	{
               scanf("%d",&E1);
	       scanf("%d",&E2);
	       graph[E1][E2]=1;
	       if(type==2)
		{
                   graph[E1][E2]=1;
		}
	}
}*/
void main()
{
	int E1,E2;
	printf("Enter the number of vertex\n");
	scanf("%d",&v);
	printf("enter the type of graph (enter 1 for directed and 2 for undirected ");
	scanf("%d",&type);
	printf("Enter the number of edges  :");
	scanf("%d",&E);
	for(i=0;i<v;i++)
	{
		vtx[i]=NULL;
        }
	//createMatrix(v,E,type);
	//printf("enter the sourse vertex ");
        //scanf("%d",&k);
	//bfs(k);
	printf("Enter the edges :");
	for (i=0;i<E;i++)
	{
               scanf("%d",&E1);
	       scanf("%d",&E2);
               createList(E1,E2);
               if(type==2)
                   createList(E2,E1);
	}
	printf("enter the sourse vertex ");
        scanf("%d",&k);

	printf("bfs list is %d \n:",k);
	bfslist(k);



}
