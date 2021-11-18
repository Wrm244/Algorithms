#include <cstdio>
#include <cstdlib>

typedef int DataType;
typedef struct {
    int n;//Init
    DataType *record;
}SortObject;

/*初始化输入排序序列*/
SortObject *InitSortObject(){
    SortObject *List = (SortObject*)malloc(sizeof(SortObject) );
    scanf("%d",&List->n);
    List->record = (DataType *)malloc(sizeof (DataType)*List->n);
    for (int i = 0; i < List->n; i++) { scanf("%d", &List->record[i]); }
    return List;
}
/*打印排序数列*/
void print(SortObject *List){
    printf("After Sorting: ");
    for (int i = 0; i < List->n - 1; i++) { printf("%d ", List->record[i]); }
    printf("%d\n",List->record[List->n-1]);
}
/*交换*/
void swap(DataType *a,DataType *b){
    DataType temp;
    temp=*a;*a=*b;*b=temp;
}

/*直接插入排序*/
void insertSort(SortObject *pVector){
    int i,j;
    DataType temp;
    DataType *data = pVector->record;
    for(i=1;i<pVector->n;i++){
        temp=data[i];
        for(j=i-1;temp<data[j]&&j>=0;j--) {swap(&data[j], &data[j + 1]);}
    }
}

/*二分法插入排序*/
void binSort(SortObject* pVector){
    int i,j,left,mid,right;
    DataType temp;
    DataType *data=pVector->record; //待排序数组
    for(int i=1;i<pVector->n;i++){
        temp=data[i];
        left=0;
        right=i-1;
        while (left<=right){// 新遍历的值等待插入到前面的有序数组
            mid=(left+right)/2;
            if(temp<data[mid]){
                right=mid-1;
            } else{
                left=mid+1;
            }
        }
        for(j=i-1;j>=left;j--){
            data[j+1]=data[j];
        }
        if(left!=i)data[left]=temp;
    }
}

/*shell排序*/
void shellSort(SortObject* pVector){
    int i,j,inc=pVector->n/2;
    DataType temp;
    DataType *data=pVector->record;
    for(;inc>0;inc/=2){
        for(i=inc;i<pVector->n;i++){
            temp=data[i];
            for(j=i-inc;j>=0;j-=inc){
                if(data[j]>data[j+inc])
                    swap(&data[j],&data[j+inc]);
            }
        }
    }
}

/*选择排序*/
void selectSort(SortObject *pVector){
    int i,j,k;
    DataType temp;
    DataType *data=pVector->record;
    for(i=0;i<pVector->n-1;i++){
        k=i;
        for(j=i+1;j<pVector->n;j++){//去跑一边有没有比待排序的小
            if(data[j]<data[k])k=j;
        }
        if(k!=i){
            swap(&data[i],&data[k]);
        }
    }
}

/*冒泡排序*/
void bubbleSort(SortObject* pVector){
    int i,j;
    bool flag;
    DataType *data=pVector->record;
    for(i=0;i<pVector->n;i++){
        flag= true;
        for(j=0;j<pVector->n-i-1;j++){
            if(data[j+1]<data[j])
                swap(&data[j+1],&data[j]);
            flag= false;
        }
        if(flag)break;
    }
}

/*快速排序*/
void quickSort(SortObject *pVector,int l,int r){
    int i,j,temp;
    DataType *data=pVector->record;
    if(l>=r)return; //递归终止条件
    i=l;j=r;temp=data[i];
    while(i!=j){
        while(i<j&&data[j]>=temp)j--;
        if(i<j)data[i++]=data[j];
        while(i<j&&data[i]<=temp)i++;
        if(i<j)data[j--]=data[i];
    }
    data[i]=temp;
    quickSort(pVector,l,i-1);
    quickSort(pVector,i+1,r);
}
 
/*归并排序*/
void merge(DataType* r,DataType *r1,int low,int m,int high){
    int i,j,k;
    i=low;j=m+1;k=low;
    while ((i<=m)&&(j<=high)){//合并两文件
        if(r[i]<=r[j])r1[k++]=r[i++];
        else r1[k++]=r[j++];
    }
    while(i<=m)r1[k++]=r[i++];
    while(j<=high)r1[k++]=r[j++];
}
void mergePass(DataType *r,DataType *r1,int n,int length){//length有序子文件的长度
    int j,i=0;
    while(i+2*length-1<n){
        merge(r,r1,i,i+length-1,i+2*length-1);
        i+=2*length;
    }
    if(i+length-1<n-1)
        merge(r,r1,i,i+length-1,n-1);
    else
        for(j=i;j<n;j++){r1[j]=r[j];}
}
void mergeSort(SortObject *pVector){
    DataType record[pVector->n];
    int length=1;
    while(length<pVector->n){
        mergePass(pVector->record,record,pVector->n,length);
        length*=2;
        mergePass(record,pVector->record,pVector->n,length); //把有序序列放回pVector
        length*=2;
    }
}

/*堆排序*/
void sift(SortObject *pVector,int size,int p){//建堆
    DataType temp=pVector->record[p];
    int child=2*p+1;
    while(child<size){
        if((child<size-1)&&pVector->record[child]<pVector->record[child+1])
            child++;
        if(temp<pVector->record[child]){
            pVector->record[p]=pVector->record[child];
            p=child;child=2*p+1;
        }
        else break;
    }
    pVector->record[p]=temp;
}
void heapSort(SortObject *pVector){
    int i,n;
    n=pVector->n;
    for (i =n/2-1; i >= 0; i--) { sift(pVector, n, i); }//n/2-1:有叶子结点的最大结点位置
    for(i=n-1;i>0;i--){
        swap(&pVector->record[0],&pVector->record[i]);
        sift(pVector,i,0);
    }
}

/*表插入排序*/

typedef struct LNode
{
    DataType data;
    struct LNode *next;
}LNode, *LinkList;

LinkList CreatLink(int num);
LinkList LinkInsertSort(LinkList head);
int PrintLink(LinkList head);


LinkList CreatLink(int num)
{
    int i, data;
    //p指向当前链表中最后一个结点，q指向准备插入的结点。
    LinkList head = NULL, p = NULL, q;

    for (i = 0; i < num; i++)
    {
        scanf("%d", &data);
        q = (LinkList)malloc(sizeof(LNode));
        q->data = data;
        q->next = NULL;
        if (i == 0)
        {
            head = q;
        }
        else
        {
            p->next = q;
        }
        p = q;
    }
    return head;
}

/*表插入排序*/
LinkList LinkInsertSort(LinkList head)
{
    //current指向当前待插入的结点。
    LinkList head2, current, p, q;
    if (head == NULL)return head;//第一次拆分。
    head2 = head->next;
    head->next = NULL;
    while (head2)
    {   current = head2;
        head2 = head2->next;
        //寻找插入位置，插入位置为结点p和q中间。
        for (p = NULL, q = head; q && q->data <= current->data; p = q, q = q->next);
        if (q == head)
        {//将current插入最前面。
            head = current;
        }
        else
        {
            p->next = current;
        }
        current->next = q;
    }
    return head;
}
int PrintLink(LinkList head)
{
    LinkList p;
    for (p = head; p ;p = p->next)
        printf("%d ", p->data);
    return 0;
}

int main(){
    //SortObject *List=InitSortObject();
    //排序函数
    //print(List);
}
/* 6
12 1 5 16 10 7
 */