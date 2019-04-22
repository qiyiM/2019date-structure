#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 9999
typedef struct
{
    char ch;
    int weight;
    int lchild,rchild,mother;
}hufftree;
typedef struct
{
    char code[40];
    int rnt;
}code;
void Initialization(hufftree *ht,int n)
{
    int i,j,min1,min2;
    int m,c;
    ht[0].ch=' ';//对空格做处理
    ht[0].rchild=ht[0].lchild=ht[0].mother=-1;
    printf("请输入空格的权值");
    scanf("%d",&ht[0].weight);
     printf("请输入每个字母的权值");
    for(i=1;i<n;i++)//初始化A-Z的huffman
    {
        ht[i].ch='A'+i-1;
        ht[i].lchild=ht[i].rchild=ht[i].mother=-1;
        scanf("%d",&ht[i].weight);
    }
    for(i=n;i<2*n-1;i++)
    {
        min1=min2=MAX;
        c=m=0;
        for(j=0;j<i;j++)
        {
            if(ht[j].mother==-1)
            {
                if(ht[j].weight<min1)
                {
                    c=m;
                    min2=min1;
                    min1=ht[j].weight;
                    m=j;
                }
                else if(ht[j].weight<min2)
                {
                    min2=ht[j].weight;
                    c=j;
                }
            }

        }
        ht[i].weight=min1+min2;
        ht[i].lchild=m;
        ht[i].rchild=c;
        ht[i].mother=-1;
        ht[c].mother=ht[m].mother=i;
        ht[i].ch=' ';
    }


}
void Encoding(hufftree*ht,code*codein,int N)
 {
     int i,p,c;
     code s;
     for(i=0;i<N;i++)
     {
         c=i;
         p=ht[c].mother;
         s.rnt=N;
         s.code[N]='\0';
         while(p!=-1)
         {
             if(ht[p].lchild==c)
                s.code[--s.rnt]='0';
             else
                s.code[--s.rnt]='1';
             c=p;
             p=ht[c].mother;
         }
         codein[i]=s;
     }

 }
 void Decode(hufftree*ht,char*tobetre,int N)
 {
     char ch;
     int i,ct=0;
     scanf("%c",&ch);
     i=2*N-2;
     while(ch!='~')
     {
         if(ch=='0')
            i=ht[i].lchild;
            else if(ch=='1')
                i=ht[i].rchild;
            if(ht[i].lchild==-1||ht[i].rchild==-1)
            {
                tobetre[ct++]=ht[i].ch;
                i=2*N-2;
            }
            scanf("%c",&ch);

     }
     if((ht[i].lchild!=-1||ht[i].rchild!=-1)&&i!=2*N-2)
     printf("error");
     tobetre[ct]='\0';

 }

int main()
{
    int i,j,n=27;
    char str[]="THIS PROGRAM IS MY FAVORITE";
     char *tobetre,c;
      hufftree * ht;
      code * codein;
      tobetre=(char *)malloc(sizeof(char)*40);
      ht=(hufftree *)malloc(sizeof(hufftree)*(2*n-1));
      codein=(code *)malloc(sizeof(code)*n);
      Initialization(ht,n);
      Encoding(ht,codein,n);
      scanf("%c",&c);
      printf("\n");
      printf("改字符的编码是：\n");
      for(i=0;i<strlen(str);i++)
      {
          if(str[i]==' ')
            printf("%s",codein[0].code+codein[0].rnt);
          else
            printf("%s",codein[str[i]-'A'+1].code+codein[str[i]-'A'+1].rnt);
      }
      printf("\n\n");
      printf("请输入要编译");
      Decode(ht,tobetre,n);
      printf("\n");
      printf("编译的译文为：\n");
      printf("%s",tobetre);
    return 0;
}






