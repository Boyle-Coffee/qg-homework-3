#include <stdio.h>
#include <stdlib.h>
#include "../head/AQueue.h"
#define TYPE(X) _Generic((X),\
    int:'I',\
    float:'F',\
    double:'D',\
    char:'C'\
)

char data_type[MAXQUEUE];  //��¼����Ԫ�ص�����
int cursor;  //���ڴ�ӡʱ��ʶԪ��λ�õ��α�
int flag=0;  //��������ջ����ջ�յı�־�����ʱflag��Ϊ1������ʱ��Ϊ0
/**************************************************************
 *    Prototype Declare Section
 **************************************************************/

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q){
    Q->front=Q->rear=0;
    Q->length=0;
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q){
    if(!(Q)){  //�ж϶����Ƿ����
        printf("Error!The queue do not exit\n");
        exit(-1);
    }
    free(Q);
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q){
    if(!(Q)){  //�ж϶����Ƿ����
        printf("Error!The queue do not exit\n");
        exit(-1);
    }
    if(Q->front==Q->rear&&flag==1)  //ͷβͬλ�ã�����һ������Ϊ���
        return TRUE;
    else
        return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q){
        if(!(Q)){  //�ж϶����Ƿ����
        printf("Error!The queue do not exit\n");
        exit(-1);
    }
    if(Q->front==Q->rear&&flag==0)  //ͷβͬλ�ã�����һ������Ϊ����
        return TRUE;
    else
        return FALSE;
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void **e){
        if(!(Q)){  //�ж϶����Ƿ����
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
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
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data){
    if(!(Q)){  //�ж϶����Ƿ����
        printf("Error!The queue do not exit\n");
        exit(-1);
    }
    if(Q->front==Q->rear&&flag==1)
        return FALSE;
    else{
        Q->data[Q->rear]=data;
        Q->rear=(Q->rear+1)%MAXQUEUE;
        Q->length++;
        flag=1;  //��ʶ���һ�β��������
        return TRUE;
    }
}




/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q){
    if(!(Q)){  //�ж϶����Ƿ����
        printf("Error!The queue do not exit\n");
        exit(-1);
    }
    if(Q->front==Q->rear&&flag==0)  //����ǰ�ж϶����Ƿ�Ϊ��
        return FALSE;
    else{
        Q->front=(Q->front+1)%MAXQUEUE;
        Q->length--;
        flag=0;  //��ʶ���һ�β����ǳ���
        return TRUE;
    }
}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q){
    if(!(Q)){  //�ж϶����Ƿ����
        printf("Error!The queue do not exit\n");
        exit(-1);
    }
    Q->front=Q->rear=0;
    Q->length=0;
    flag=0;  //flag��Ϊ�㣬��������Ϊ��
}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){
    int i;

    if(!(Q)){  //�ж϶����Ƿ����
        printf("Error!The queue do not exit\n");
        exit(-1);
    }
    i=Q->front;
    if(Q->front==Q->rear&&flag==0)  //����ǰ�ж϶����Ƿ�Ϊ��
        return FALSE;
    else{
        do{
            (*foo)(Q->data[i%MAXQUEUE]);
            i++;
        }while(i%MAXQUEUE!=Q->rear);  //���λ���Ƿ񵽵�β�ڵ�
        return TRUE;
    }
}





/**
 *  @name        : void APrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 *  @notice      : None
 */
void APrint(void *q){
    switch(data_type[cursor++]){  //���ñ�ʶ������α��ж���������
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
