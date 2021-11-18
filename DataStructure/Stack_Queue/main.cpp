#include <stdio.h>
#define m 100
typedef struct
{
    char data[m];
    int top;
}stack;//定义一个栈空间
void begin_stack(stack* s)//初始化栈
{
    s->top = 0;
}
int judge_stack(stack* s)//判断栈是否为空
{
    if(s->top == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void join_stack(stack* s, char x)//进入栈
{
    if (s->top == m)
    {
        printf("栈空\n");
    }
    else {
        s->data[++s->top] = x;
    }
}
char go_stack(stack* s)//出栈
{
    char y;
    if (s->top == 0)
    {
        printf("栈空\n");
        return 0;
    }
    else {
        y = s->data[s->top];
        s->top = s->top - 1;
        return y;
    }
}
typedef struct {
    char data[m];
    int front;
    int rear;
}queue;//定义一个队列
void begin_queue(queue* q)//初始化队列
{
    q->front = q->rear = 0;
}
void join_queue(queue* q, char e)//进入队列
{
    if ((q->rear + 1) % m == q->front)
    {
        printf("队列为空\n");
    }
    else {
        q->data[q->rear] = e;
        q->rear = (q->rear + 1);
    }
}
char go_queue(queue* q)//出队
{
    char f;
    if (q->front == q->rear)
    {
        printf("队列为空\n");
        return 0;
    }
    else {
        f = q->data[q->front];
        q->front = (q->front + 1);
        return f;
    }
}
int main()
{

}
