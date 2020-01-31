#include<stdio.h>
int min(int n,int unvisited[n],int cost[n]){
int m=cost[0],mnode=0;
while(n--)if(unvisited[n]>=0)if(m>cost[n]){m=cost[n];mnode=n;}
return mnode;}
int main()
{
int n,src,dest,e;
printf("\nEnter the no. of nodes : ");
scanf("%d",&n);
int costmtrx[n][n],path[n],cost[n],unvisited[n],uvn=0;
printf("\nEnter the cost matrix :\n");
for(int i=0;i<n;printf("\n"),++i)
	for(int j=0;j<n;scanf("%d",&costmtrx[i][j]),(costmtrx[i][j])?0:(costmtrx[i][j]=9999),++j);
//printf("Cost matrix :\n");
//for(int i=0;i<n;printf("\n"),++i)for(int j=0;j<n;printf("%d ",costmtrx[i][j]),++j);
do{
printf("\nEnter the source node : ");
scanf("%d",&src);
printf("\nEnter the destination node : ");
scanf("%d",&dest);
for(int i=0;i<n;cost[i]=9999,unvisited[i]=i,path[i]=0,++uvn,++i);
unvisited[src]=-1;
--uvn;
for(int cnode=src;uvn;cnode=min(n,unvisited,cost),unvisited[cnode]=-1,--uvn)
	for(int j=0,k;k=unvisited[j],j<n;++j)
		if(k>=0)
			if((costmtrx[cnode][k]+((cnode!=src)?cost[cnode]:0))<cost[k]){
				cost[k]=(costmtrx[cnode][k]+((cnode!=src)?cost[cnode]:0));
				path[k]=cnode;	}
int p=dest;
printf("\nShortest path to destination is : ");
while(p!=src)	{
printf("%d <- ",p);
p=path[p];	}
printf("%d",src);
printf("\nCost of shortest path is : %d\n",cost[dest]);
}while(printf("\nEnter any no. to check different source and destinations anything else to exit\n")&&scanf("%d",&e));
return 0;
}
