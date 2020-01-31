#include<stdio.h>
void mod2div(int n,int k,int in[n+k-1],int g[k])
{
	for(int i=0;(i+=in[i]^1),i<n;) for(int j=i;j<(k+i);in[j]=(g[j-i]^in[j]),++j);
}
int main()
{
	int n,k,m,i=0,syn=0;
	printf("Enter the no. of bits of generator polynomial and message polynomial anything else to exit:-\n");
	scanf("%d%d",&k,&n);
	if(( (k<0)||(n<0) )&&(printf("Wrong input\n")))return 0;
	m=n+k-1;
	int g[k],in[m],c[m],t[m];
	printf("Enter the generator polynomial:-\n");
	for(i=0;i<k;scanf("%1d",&g[i]),++i);
	printf("Enter the input data:\n");
	for(i=0;i<n;scanf("%1d",&in[i]),c[i]=in[i],++i);
	for(i=n;i<m;in[i]=c[i]=0,++i);
	mod2div(n,k,in,g);
	printf("\nCodeword :-");
	for(i=0;i<m;c[i]+=in[i],printf("%d ",c[i]),++i);
	printf("\nEnter the transmitted codeword:-\n");
	for(i=0;i<m;scanf("%1d",&t[i]),++i);
	mod2div(n,k,t,g);
	printf("\nSyndrome :-");
	for(i=n;i<m;printf("%d ",t[i]),syn+=t[i],++i);
	printf("\n");
	if(syn)printf("\n\nERROR in transmission");
	else printf("\nNo error");
	printf("\n");
	return 0;
}
