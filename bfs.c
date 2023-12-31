#include<stdio.h>
#include<stdlib.h>
struct AdjList
{
	int key;
	struct AdjList *next;
};
struct Adjlist *vtx[5];

int queuearr[25];
void enqueue();
int dequeue();
int temp,i;
int front=-1,rear=-1;
//Adjacency Matrix
//int graph[5][5]={{0,1,1,0,0},{1,0,0,1,1},{1,0,0,1,0},{1,0,1,0,1},{0,1,0,1,0}};
int graph[5][5];
//visit array 0 rep. not visited and 1 rep. visited
int visit[5]={0,0,0,0,0};
int V,type,E;

void getMatrix(int V)
{
	int i,j;
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
}
void createList(int v,int e,int type)
{
	int i;
	//initialization
	struct AdjList *newnode;
	for(i=0;i<V;i++)
		Vtx[i]=NULL;
	printf("Enter the edges:");
	
	newnode=(struct AdjList *)malloc(sizeof(Adjlist));
	newnode->key
	newnode->next=NULL;
	if(Vtx[V]==NULL)
		Vtx[V]=newnode;
	else
	{
		ptr=Vtx[V];
		while(ptr->next1=NULL)
			ptr=ptr->next;
		ptr->next=newnode;

	}
}
void createMatrix(int V,int E,int type)
{
	int i,j;
	int E1,E2;
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			graph[i][j]=0;
		}
	}
	for(i=0;i<E;i++)
	{
		scanf("%d",&E1);
		scanf("%d",&E2);
		graph[E1][E2]=1;
		if(type==2)
			graph[E2][E1]=1;
	}
	
}
void enqueue(int key)
{
	if(rear<25)
	{
		if(front==-1 && rear==-1)
		{
			front=0;
			rear=0;
		}
		else
		{
			rear++;
		
		}
		queuearr[rear]=key;
	}
	else
		printf("Queue is full");
	
}
int dequeue()
{
	int item;
	if(front==-1 || front>rear)
	{
		printf("No element to delete");
	}
	else
	{
		item=queuearr[front];
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
			front=front+1;
		}
		
		return(item);
	}
	
}
void display_graph()
{
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
}
int isVisited(int Vtx)
{
	return(visit[Vtx]);
}
void bfs(int S)
{
	int Vtx;
	enqueue(S);
	while((front!=-1)&&(rear!=-1))
	{
		Vtx=dequeue();
		if(!isVisited(Vtx))
		{
			visit[Vtx]=1;
			printf("%d ",Vtx);
			for(int i=0;i<5;i++)
			{
				if(graph[Vtx][i]==1)
					enqueue(i);
			}
		}
	}
}	
	
int main()
{
	printf("Enter the number of vertices:");
	scanf("%d",&V);
	//getMatrix(V);
	printf("Enter the type of graph(enter 1 for directed ):");
	scanf("%d",&type);
	
	printf("Enter the number of edges:");
	scanf("%d",&E);
	//creatematrix();
	printf("Enter the edges:");
	for(i=0;i<E;i++)
	{
		scanf("%d",&E1);
		scanf("%d",&E2);
	createList(V,E,type);
	if(type==2)
		creteList(E2,E1,type);

	printf("BFS traversal is: ");
	bfs(0);
	return(0);
}
