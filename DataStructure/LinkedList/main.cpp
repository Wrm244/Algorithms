// 编程完成下列任务
//（1）建立一个单链表 21  3  15  27  11  18，并输出该链表；
//（2）输入序号n，查找序号为n的结点，并输出；
//（3）输入值x，查找值为x的结点，并输出；
//（4）插入结点: 输入序号 n和值x。在序号为n的结点后插入x，并输出该链表；
//（5）删除结点: 输入序号 n，删除序号为 n 的结点，并输出该链表。
#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct Nmb)
struct Nmb
{
    int number;
    struct Nmb *next;
};
struct Nmb *creatList(){
    struct Nmb * p=(struct Nmb *) malloc(LEN);
    p->next=NULL;
    return p;
}
struct Nmb *readList(){
    int num;
    struct Nmb * tail,* head,*p;
    head=tail=(struct Nmb *) malloc(LEN);
    tail->next=NULL;
    scanf("%d",&num);
    while(num!=0){
        p=creatList();
        p->number=num;
        tail->next=p;
        tail=p;
        scanf("%d",&num);
    }
    return head;
}
void printList(struct Nmb *p){
    struct Nmb*List=p;
    for(List=List->next;List->next!=NULL;List=List->next){
        printf("%d ",List->number);
    }
    printf("%d\n",List->number);
}
int search1(struct Nmb *List,int n){
    struct Nmb *temp=List;
    while (n--){
        temp=temp->next;
    }
    return temp->number;
}
void search2(struct Nmb *List,int n){
    struct Nmb *temp=List;
    int count=0;
    while (temp->number!=n){
        temp=temp->next;
        count++;
    }
    printf("%d %d\n",count,temp->number);
}
void inset(struct Nmb* List,int n,int x){
    struct Nmb *temp=List,*p=(struct Nmb *) malloc(LEN);;
    p->next=NULL;
    p->number=x;
    int count=0;
    while(count!=n){
        temp=temp->next;
        count++;
    }
    p->next=temp->next;
    temp->next=p;
}
void del(struct Nmb* List,int n){
    struct Nmb *temp=List,*pre;
    while (n--){
        pre=temp;//前驱结点；
        temp=temp->next;
    }
    pre->next=temp->next;
    free(temp);
}
int main()
{
    struct Nmb * List=readList();
    int n1,n2,n3,x,n4;
    scanf("%d%d",&n1,&n2);
    scanf("%d%d",&n3,&x);
    scanf("%d",&n4);
    printList(List);
    printf("%d\n",search1(List,n1));
    search2(List,n2);
    inset(List,n3,x);
    printList(List);
    del(List,n4);
    printList(List);
    return 0;
}