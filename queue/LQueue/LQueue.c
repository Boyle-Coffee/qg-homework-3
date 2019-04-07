#include <stdio.h>
#include <stdlib.h>
#include "../head/LQueue.h"
typedef struct type{  //标志队列结点
    char sign;
    struct type *next;
}type_node;

typedef struct type_queue{  //标志队列，用于标识变量的类型
    type_node *front;
    type_node *rear;
}type_queue;

type_queue *tq;  //创建标志队列
type_node *ts,*st;

char type_data;
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
    Q->front=Q->rear=(Node*)malloc(sizeof(Node));  //创建头结点，与尾节点同位置
    if(!(Q->front))  //判断头结点是否创建
        exit(-1);
    Q->front->next=NULL;  //空队列
    Q->length=0;  //元素个数为零
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
    if(!Q){  //判断队列是否存在
        printf("Error!");
        exit(-1);
    }
    ClearLQueue(Q);  //清空结点
    free(Q->front);  //是否头元素
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
    if(!Q){  //判断队列是否存在
        printf("Error!");
        exit(-1);
    }
    if(Q->front==Q->rear)  //头结点与尾节点同位置
        return TRUE;
    else
        return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void **e){
    if(!Q){  //判断队列是否存在
        printf("Error!");
        exit(-1);
    }
    if(Q->front==Q->rear)  //判断空队列
        return FALSE;
    else
        *e=Q->front->next->data;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
    if(!Q){  //判断队列是否存在
        printf("Error!");
        exit(-1);
    }
    return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data){
    Node* s;

    if(!Q){  //判断队列是否存在
        printf("Error!");
        return FALSE;
    }
    s=(Node*)malloc(sizeof(Node));  //创建一个新的结点
    s->data=data;  //指定数据域
    Q->rear->next=s;  //入队
    Q->rear=s;
    Q->rear->next=NULL;
    Q->length++;

    return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
    Node *s;

    if(!Q){  //判断队列是否存在
        printf("Error!");
        exit(-1);
    }
    if(Q->front==Q->rear)  //判断队列是否为空
        return FALSE;
    else{
        s=Q->front->next;
        Q->front->next=s->next;  //使第一个结点往后退一位
        free(s);  //释放原来的第一个结点
        Q->length--;
        Q->rear->next=NULL;
        return TRUE;
    }
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
    if(!Q){  //判断队列是否存在
        printf("Error!");
        exit(-1);
    }
    while(Q->front->next!=NULL){
        DeLQueue(Q);  //删除结点
    }
    Q->length=0;  //元素个数初始化
}



/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
    Node *s;
    if(!Q){  //判断队列是否存在
        printf("Error!");
        return FALSE;
    }
    s=Q->front->next;  //第一个有数据结点
    st=tq->front->next;  //对应的标志队列结点
    type_data=st->sign;  //导出标志队列的标志
    while(s){
        (*foo)(s->data);
        s=s->next;  //指向下一个结点
        st=st->next;
        type_data=st->sign;  //导出标志队列的标志
    }
    return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(void *q){
    switch(type_data){  //来自标志队列的字符，标识数据类型
        case'I':printf("%d  ",*(int*)q);
                break;
        case'F':printf("%.2f  ",*(float*)q);
                break;
        case'D':printf("%.2f  ",*(double*)q);
                break;
        case'C':printf("%c  ",*(char*)q);
                break;
        default:puts("Error!");
                exit(-1);
    }
}
