#include<stdio.h>
int main()
{	int d ;
 while( printf("Enter the no. of bits  : ") && scanf("%d",&d) ) {
	int n, p=0, m=0, e=0, pos=0 ;
	while( (d+p >= 1<<p) && ++p ) ;
	n=d+p ;
	int h[n];
	for(int i=0 ; i<p ; h[n-(1<<i)]=3, ++i ) ;
	printf("Enter the bit stream  : ");
	for(int i=0 ; i<n ; h[i]==3? h[i]=0 : scanf("%1d",&h[i]) , ++i ) ;
	for(int i=0 ; m=n-(1<<i), i<p ; ++i )
		for(int j=n-m+1 ; j<=n ; h[m]^= ( j & (n-m) ) ? h[n-j]:0 , ++j );
	for(int i=0;i<n;printf("%d ",h[i]),++i);
	printf("\n");
	printf("Enter pos 1 to %d to make error, 0 for No error  : ",n); scanf("%d",&pos);
	printf("Recieved code  : "); h[n-pos] ^= 1 ;
	for(int i=0 ; i<n ; printf("%d ",h[i]) , ++i) ;
	if(pos){
		for(int i=0, s=0 ; m=n-(1<<i) , i < p ; e+=s*(1<<i) ,s=0, ++i )
			for(int j=n-m ; j<=n ; s^= ( j&(n-m) ) ? h[n-j]:0 , ++j );
		printf("\nError in %d th bit\n",e); h[n-e] ^= 1 ;
		printf("Error corrected code is  : ") ;
		for(int i=0 ; i<n ; printf("%d ",h[i]) , ++i) ; }
	printf("\nEnter 1 for continue : ") ;
	char c;
	if( !scanf(" %[1]1",&c) ) return 0; }
}
