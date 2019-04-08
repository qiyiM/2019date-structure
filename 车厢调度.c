#include<stdio.h>
#define MaxLen 100
int n;
struct snode
{
    int data[MaxLen];
    int bottom;
}s;//定义栈

void Initstact()//定义栈中数组与值的关系
{
    s.bottom=-1;
}

void push(int q)//进栈
{
    s.bottom++;
    s.data[s.bottom]=q;
}
int pop()//出栈
{
    int temp;
    temp=s.data[s.bottom];
    s.bottom--;
    return temp;
}
int Emptys()
{
    if(s.bottom==-1)
        return 1;
    else
        return 0;
}
void process(int pos,int path[],int curp)//curp为出栈铁轨的位置编号
{
    int m,i;
    if(pos<n){//若元素未全放入，则继续入栈
        push(pos+1);
        process(pos+1,path,curp);//递归入栈
        pop();//下一个元素处理运算完后，准备出栈
    }
    if(!Emptys()){//递归出栈
        m=pop();
        path[curp]=m;
        curp++;
        process(pos,path,curp);//出栈后处理下一个元素进栈
        push(m);
    }
    if(pos==n&&Emptys()){//输出一个可能方案
        for(i=0;i<curp;i++){
            printf("%d,",path[i]);
        }
        printf("\n");
    }

}


void main()
{
    int path[MaxLen];
    printf("输入车厢总数：\n");
    scanf("%d",&n);
    Initstact();
    push(1);
    printf("所有序列：\n");
    process(1,path,0);//从1开始，将元素放进每个栈底，递归
}

