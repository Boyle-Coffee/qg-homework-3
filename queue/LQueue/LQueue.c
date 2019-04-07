#include <stdio.h>
#include <stdlib.h>
#include "../head/LQueue.h"
typedef struct type{  //��־���н��
    char sign;
    struct type *next;
}type_node;

typedef struct type_queue{  //��־���У����ڱ�ʶ����������
    type_node *front;
    type_node *rear;
}type_queue;

type_queue *tq;  //������־����
type_node *ts,*st;

char type_data;
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
    Q->front=Q->rear=(Node*)malloc(sizeof(Node));  //����ͷ��㣬��β�ڵ�ͬλ��
    if(!(Q->front))  //�ж�ͷ����Ƿ񴴽�
        exit(-1);
    Q->front->next=NULL;  //�ն���
    Q->length=0;  //Ԫ�ظ���Ϊ��
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
    if(!Q){  //�ж϶����Ƿ����
        printf("Error!");
        exit(-1);
    }
    ClearLQueue(Q);  //��ս��
    free(Q->front);  //�Ƿ�ͷԪ��
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
    if(!Q){  //�ж϶����Ƿ����
        printf("Error!");
        exit(-1);
    }
    if(Q->front==Q->rear)  //ͷ�����β�ڵ�ͬλ��
        return TRUE;
    else
        return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void **e){
    if(!Q){  //�ж϶����Ƿ����
        printf("Error!");
        exit(-1);
    }
    if(Q->front==Q->rear)  //�жϿն���
        return FALSE;
    else
        *e=Q->front->next->data;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
    if(!Q){  //�ж϶����Ƿ����
        printf("Error!");
        exit(-1);
    }
    return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data){
    Node* s;

    if(!Q){  //�ж϶����Ƿ����
        printf("Error!");
        return FALSE;
    }
    s=(Node*)malloc(sizeof(Node));  //����һ���µĽ��
    s->data=data;  //ָ��������
    Q->rear->next=s;  //���
    Q->rear=s;
    Q->rear->next=NULL;
    Q->length++;

    return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
    Node *s;

    if(!Q){  //�ж϶����Ƿ����
        printf("Error!");
        exit(-1);
    }
    if(Q->front==Q->rear)  //�ж϶����Ƿ�Ϊ��
        return FALSE;
    else{
        s=Q->front->next;
        Q->front->next=s->next;  //ʹ��һ�����������һλ
        free(s);  //�ͷ�ԭ���ĵ�һ�����
        Q->length--;
        Q->rear->next=NULL;
        return TRUE;
    }
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
    if(!Q){  //�ж϶����Ƿ����
        printf("Error!");
        exit(-1);
    }
    while(Q->front->next!=NULL){
        DeLQueue(Q);  //ɾ�����
    }
    Q->length=0;  //Ԫ�ظ�����ʼ��
}



/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
    Node *s;
    if(!Q){  //�ж϶����Ƿ����
        printf("Error!");
        return FALSE;
    }
    s=Q->front->next;  //��һ�������ݽ��
    st=tq->front->next;  //��Ӧ�ı�־���н��
    type_data=st->sign;  //������־���еı�־
    while(s){
        (*foo)(s->data);
        s=s->next;  //ָ����һ�����
        st=st->next;
        type_data=st->sign;  //������־���еı�־
    }
    return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q

 *  @notice      : None
 */
void LPrint(void *q){
    switch(type_data){  //���Ա�־���е��ַ�����ʶ��������
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
