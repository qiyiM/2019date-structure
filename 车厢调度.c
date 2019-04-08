#include<stdio.h>
#define MaxLen 100
int n;
struct snode
{
    int data[MaxLen];
    int bottom;
}s;//����ջ

void Initstact()//����ջ��������ֵ�Ĺ�ϵ
{
    s.bottom=-1;
}

void push(int q)//��ջ
{
    s.bottom++;
    s.data[s.bottom]=q;
}
int pop()//��ջ
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
void process(int pos,int path[],int curp)//curpΪ��ջ�����λ�ñ��
{
    int m,i;
    if(pos<n){//��Ԫ��δȫ���룬�������ջ
        push(pos+1);
        process(pos+1,path,curp);//�ݹ���ջ
        pop();//��һ��Ԫ�ش����������׼����ջ
    }
    if(!Emptys()){//�ݹ��ջ
        m=pop();
        path[curp]=m;
        curp++;
        process(pos,path,curp);//��ջ������һ��Ԫ�ؽ�ջ
        push(m);
    }
    if(pos==n&&Emptys()){//���һ�����ܷ���
        for(i=0;i<curp;i++){
            printf("%d,",path[i]);
        }
        printf("\n");
    }

}


void main()
{
    int path[MaxLen];
    printf("���복��������\n");
    scanf("%d",&n);
    Initstact();
    push(1);
    printf("�������У�\n");
    process(1,path,0);//��1��ʼ����Ԫ�طŽ�ÿ��ջ�ף��ݹ�
}

