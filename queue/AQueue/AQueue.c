#include <stdio.h>
#include <stdlib.h>
#include "../head/AQueue.h"
#define TYPE(X) _Generic((X),\
    int:'I',\
    float:'F',\
    double:'D',\
    char:'C'\
)

char data_type[MAXQUEUE];  //记录队列元素的类型
int cursor;  //用于打印时标识元素位置的游标
int flag=0;  //用于区别栈满与栈空的标志，入队时flag变为1，出队时变为0
/**************************************************************
 *    Prototype Declare Section
 **************************************************************/

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q){
    Q->front=Q->rear=0;
    Q->length=0;
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q){
    if(!(Q)){  //判断队列是否存在
        printf("Error!The queue do not exit\n");
        exit(-1);
    }
    free(Q);
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q){
    if(!(Q)){  //判断队列是否存在
        printf("Error!The queue do not exit\n");
        exit(-1);
    }
    if(Q->front==Q->rear&&flag==1)  //头尾同位置，且上一个操作为入队
        return TRUE;
    else
        return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q){
        if(!(Q)){  //判断队列是否存在
        printf("Error!The queue do not exit\n");
        exit(-1);
    }
    if(Q->front==Q->rear&&flag==0)  //头尾同位置，且上一个操作为出队
        return TRUE;
    else
        return FALSE;
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void **e){
        if(!(Q)){  //判断队列是否存在
        printf("Error!The queue do not exit\n");
        exit(-1);
    }
    if(Q->front==Q->rear&&flag==0)
        return FALSE;
    else{
        *e=Q->data[Q->front];
        return TRUE;
    }
}

/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q){
    if(!(Q)){
        printf("Error!The queue do not exit\n");
        exit(-1);
    }
    return Q->length;
}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data){
    if(!(Q)){  //判断队列是否存在
        printf("Error!The queue do not exit\n");
        exit(-1);
    }
    if(Q->front==Q->rear&&flag==1)
        return FALSE;
    else{
        Q->data[Q->rear]=data;
        Q->rear=(Q->rear+1)%MAXQUEUE;
        Q->length++;
        flag=1;  //标识最后一次操作是入队
        return TRUE;
    }
}




/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q){
    if(!(Q)){  //判断队列是否存在
        printf("Error!The queue do not exit\n");
        exit(-1);
    }
    if(Q->front==Q->rear&&flag==0)  //出队前判断队列是否为空
        return FALSE;
    else{
        Q->front=(Q->front+1)%MAXQUEUE;
        Q->length--;
        flag=0;  //标识最后一次操作是出队
        return TRUE;
    }
}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q){
    if(!(Q)){  //判断队列是否存在
        printf("Error!The queue do not exit\n");
        exit(-1);
    }
    Q->front=Q->rear=0;
    Q->length=0;
    flag=0;  //flag变为零，表明队列为空
}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){
    int i;

    if(!(Q)){  //判断队列是否存在
        printf("Error!The queue do not exit\n");
        exit(-1);
    }
    i=Q->front;
    if(Q->front==Q->rear&&flag==0)  //遍历前判断队列是否为空
        return FALSE;
    else{
        do{
            (*foo)(Q->data[i%MAXQUEUE]);
            i++;
        }while(i%MAXQUEUE!=Q->rear);  //检查位置是否到底尾节点
        return TRUE;
    }
}





/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q){
    switch(data_type[cursor++]){  //利用标识数组和游标判断数据类型
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


/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
