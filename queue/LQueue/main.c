#include <stdio.h>
#include <stdlib.h>
#include "LQueue.c"
#include "../head/LQueue.h"
char get_first();
int get_int();
float get_float();
double get_double();

int main(){
    type_node *s;
    void *p;
    void *q;
    int *in;
    double *du;
    float *fl;
    char *ch,choice,type;
    LQueue queue;


    tq=(type_queue*)malloc(sizeof(type_queue));
    ts=(type_node*)malloc(sizeof(type_node));
    tq->front=tq->rear=ts;
    InitLQueue(&queue);
    printf("The queue has been created\n");
    while(1){
        puts("Please choose your operation:");
        puts("A.print   B.is it empty");
        puts("C.get head data D.length");
        puts("E.en queue      F.de queue");
        puts("G.clear         H.destroy(quit)");
        printf("request:_____\b\b\b\b\b");
        choice=get_first();
        switch(choice){
            case'B':if(IsEmptyLQueue(&queue))
                        puts("\nthe queue is empty\n");
                    else
                        puts("\nthe queue is not empty\n");
                    break;
            case'C':if(GetHeadLQueue(&queue,&q)){
                        type_data=tq->front->next->sign;  //导出相应的标志
                        printf("\nthe head data is ");
                        LPrint(q);
                        printf("\n");
                    }
                    else
                        puts("the queue is empty\n");
                    break;
            case'D':printf("\nthe length of queue is %d\n",LengthLQueue(&queue));
                    break;
            case'E':puts("please choose the type of data:");
                    puts("A.int    B.float");
                    puts("C.double D.char");
                    printf("type:_____\b\b\b\b\b");
                    type=get_first();
                    switch(type){
                        case'A':printf("please enter the data: ");
                                in=(int*)malloc(sizeof(int));
                                ts=(type_node*)malloc(sizeof(type_node));  //创建相应标志结点
                                tq->rear->next=ts;
                                tq->rear=ts;
                                *in=get_int();
                                p=in;
                                ts->sign='I';  //在标志队列中加入相应标志
                                if(EnLQueue(&queue,p))
                                    printf("success\n");
                                else
                                    printf("the queue is full!fail to add new data\n");
                                break;
                        case'B':printf("please enter the data: ");
                                fl=(float*)malloc(sizeof(float));
                                ts=(type_node*)malloc(sizeof(type_node));  //创建相应标志结点
                                tq->rear->next=ts;
                                tq->rear=ts;

                                *fl=get_float();
                                p=fl;
                                ts->sign='F';  //在标志队列中加入相应标志
                                 if(EnLQueue(&queue,p))
                                    printf("success\n");
                                else
                                    printf("the queue is full!fail to add new data\n");
                                break;
                        case'C':printf("please enter the data: ");
                                du=(double*)malloc(sizeof(double));
                                ts=(type_node*)malloc(sizeof(type_node));  //创建标志队列结点
                                tq->rear->next=ts;
                                tq->rear=ts;
                                *du=get_double();
                                p=du;
                                ts->sign='D';  //在标志队列中加入相应标志
                                if(EnLQueue(&queue,p))
                                    printf("success\n");
                                else
                                    printf("the queue is full!fail to add new data\n");
                                break;
                        case'D':printf("please enter the data: ");
                                ch=(char*)malloc(sizeof(char));
                                ts=(type_node*)malloc(sizeof(type_node));  //创建标志队列结点
                                tq->rear->next=ts;
                                tq->rear=ts;
                                *ch=get_first();
                                p=ch;
                                ts->sign='C';  //在标志队列中加入相应标志
                                if(EnLQueue(&queue,p))
                                    printf("success\n");
                                else
                                    printf("the queue is full!fail to add new data\n");
                                break;
                        default:puts("Enter Error!fail to add new data");
                    }
                    break;
            case'F':if(DeLQueue(&queue)){  //出队
                        s=tq->front->next;
                        tq->front->next=s->next;  //同时标志队列也出队
                        free(s);
                        printf("success\n");}
                    else
                        printf("the queue is empty!fail to delete data\n");
                    break;
            case'G':ClearLQueue(&queue);
                    ClearLQueue(&tq);  //清空标志队列
                    printf("the queue is cleared\n");
                    break;
            case'H':DestoryLQueue(&queue);  //摧毁队列
                    DestoryLQueue(&tq);  //同时摧毁标志队列
                    free(&st);
                    free(&ts);
                    printf("the queue is destroyed\n");
                    printf("queue is destroyed");
                    getchar();
                    return 0;
                    break;
            case'A':printf("\nfront-> ");
                    type_data=tq->front->next->sign;
                    TraverseLQueue(&queue,&LPrint);  //遍历并打印游标
                    printf(" <-rear\n");
                    printf("length: %d\n",LengthLQueue(&queue));
                    break;
            default:printf("The choice you entered is wrong!please try again!");
        }
        puts("\nAny key continue\n");
        getchar();
        while(getchar()!='\n')
            continue;
    }

    return 0;
}

char get_first(){  //获得第一个输入的字符，舍弃其他字符
	char ch;

	ch=getchar();
	while(getchar()!='\n')
		continue;

	return ch;
}

int get_int(){  //获得整数以及处理错误输入
	int input;
	char ch;

	while(scanf("%d",&input)!=1){
		while((ch=getchar())!='\n')
			putchar(ch);
		printf(" is not an integer. please enter again:");
	}

	return input;
}
float get_float(){  //获得浮点数以及处理错误输入
	float input;
	char ch;

	while(scanf("%f",&input)!=1){
		while((ch=getchar())!='\n')
			putchar(ch);
		printf(" is not a float. please enter again:");
	}

	return input;
}
double get_double(){  //获得双浮点型数据以及处理错误输入
	double input;
	char ch;

	while(scanf("%lf",&input)!=1){
		while((ch=getchar())!='\n')
			putchar(ch);
		printf(" is not a double. please enter again:");
	}

	return input;
}
