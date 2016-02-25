/*
  字符串的所有排列，前提是字符串中没有相同的字符，举个例子，输入字符串“ab”，所有的排列为“aa”，“ab”，“ba”，“bb”
*/
#include "stdio.h"
#include "string.h"
#include "malloc.h"
int getPermutation(char *s, char *tmp, int len, int size);

int main()
{
	char *s="abc";
	int size=strlen(s);
	int count;
	char *tmp=(char *)malloc(sizeof(char)*size);//分配空间
	memset(tmp,0,sizeof(char)*size);//初始化
	count=getPermutation(s,tmp,0,size);
	printf("total num is %d\n",count);//输出排列的个数
	return 0;
}

int getPermutation(char *s, char *tmp,int len,int size)
{
	if(s==NULL) return 0;
	int i,j;
	//static的特性，保存值
	static count=0;
	//设置一个长度，达到字符串总长度时就打印
	if(len<size)
	{
		for(i=0;i<size;i++)
		{
			tmp[len]=s[i];
			getPermutation(s,tmp,len+1,size);
		}
	}
	else
	{
		count++;
		for(j=0;j<size;j++)
			printf("%c",tmp[j]);
		printf("\n");
	}
	return count;
}
