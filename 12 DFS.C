#include<stdio.h>
int top=-1,s[25];

int graph[5][5]={{0,1,1,0,0},{1,0,0,1,1},{1,0,0,1,0},{0,1,1,0,1},{0,1,0,1,0}};


int visit[5]={0,0,0,0,0};

void push(int item)
{

    if(top>=24){
        printf("Stack is full\n");
    }
    else{


        top++;
        s[top]=item;
    }
}
int pop()
{
    int item=0;
    if(top==-1){
        printf("Stack is empty\n");
    }
    else{
       item=s[top];
        top--;
    }
    return item;
}
void dfs(int s)
{
	int V,i;
	push(s);
	while((top!=-1))
	{
		V=pop();
		if(visit[V]!=1)
		{
			visit[V]=1;
			printf("%d ",V);
			for(i=0;i<5;i++)
			{
				if(graph[V][i]==1)
					push(i);

			}

		}
	}

}
int main()
{
	int i,j,k;
	printf("DFS\n \n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		 printf("%d ",graph[i][j]);

		printf("\n");
	}
	printf("source vertex :");
        scanf("%d",&k);
        dfs(k);
    return 0;

}
