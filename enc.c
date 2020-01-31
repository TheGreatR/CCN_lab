#include<stdio.h>
int main()
{
char in[128]={0},key[128]={0},enc[128]={0},dec[128]={0};
int kval[128]={0},inlen=0,klen=0,rows=0;
printf("\nInput : ");
scanf("%s",in);
printf("\nKey : ");
scanf("%s",key);
while(in[++inlen]);
while(key[++klen]);
rows=inlen/klen;
(inlen%klen)?++rows:0;
for(int i=0;i<klen;++i)
	for(int j=0;j<klen;++j)	key[i]>key[j]?kval[i]++:0;
//Encryption
for(int i=0,l=0;i<klen;++i)
	for(int j=0,k=kval[i];j<rows;++j,k+=klen,++l)enc[l]=in[k]?in[k]:'x';
printf("\nCipher : %s",enc);
//Decryption
for(int i=0,l=0;i<klen;++i)
	for(int j=0,k=kval[i];j<rows;++j,k+=klen,++l)dec[k]=(inlen>k)?enc[l]:'\0';
printf("\nDecrypted Cipher : %s\n",dec);
return 0;
}
