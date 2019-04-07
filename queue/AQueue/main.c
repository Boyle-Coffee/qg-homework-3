#include <stdio.h>
#include <stdlib.h>
#include "../head/AQueue.h"
char get_first();
int get_int();
float get_float();
double get_double();

int main(){
    void *p;
    void *q;
    int *in;
    double *du;
    float *fl;
    char *ch,choice,type;
    AQueue queue;

    InitAQueue(&queue);
    printf("The queue has been created\n");
    while(1){
        puts("Please choose your operation:");
        puts("A.is it full    B.is it empty");
        puts("C.get head data D.length");
        puts("E.en queue      F.de queue");
        puts("G.clear         H.destroy(quit)");
        puts("I.print");
        printf("request:_____\b\b\b\b\b");
        choice=get_first();
        switch(choice){
            case'A':if(IsFullAQueue(&queue))
                        puts("\nthe queue is full\n");
                    else
                        puts("\nthe queue is not full\n");
                    break;
            case'B':if(IsEmptyAQueue(&queue))
                        puts("\nthe queue is empty\n");
                    else
                        puts("\nthe queue is not empty\n");
                    break;
            case'C':if(GetHeadAQueue(&queue,&q)){
                        cursor=queue.front;  //使游标指向队头
                        printf("\nthe head data is ");
                        APrint(q);
                        printf("\n");
                    }
                    else
                        puts("the queue is empty\n");
                    break;
            case'D':printf("\nthe length of queue is %d\n",LengthAQueue(&queue));
                    break;
            case'E':puts("please choose the type of data:");  //入队
                    puts("A.int    B.float");
                    puts("C.double D.char");
                    printf("type:_____\b\b\b\b\b");
                    type=get_first();  //获取元素的数据类型
                    switch(type){
                        case'A':printf("please enter the data: ");
                                in=(int*)malloc(sizeof(int));
                                *in=get_int();
                                p=in;
                                data_type[queue.rear]='I';  //添加数据类型标记
                                if(EnAQueue(&queue,p))
                                    printf("success\n");
                                else
                                    printf("the queue is full!fail to add new data\n");
                                break;
                        case'B':printf("please enter the data: ");
                                fl=(float*)malloc(sizeof(float));
                                *fl=get_float();
                                p=fl;
                                data_type[queue.rear]='F';  //添加数据类型标记
                                 if(EnAQueue(&queue,p))
                                    printf("success\n");
                                else
                                    printf("the queue is full!fail to add new data\n");
                                break;
                        case'C':printf("please enter the data: ");
                                du=(double*)malloc(sizeof(double));
                                *du=get_double();
                                p=du;
                                data_type[queue.rear]='D';  //添加数据类型标记
                                if(EnAQueue(&queue,p))
                                    printf("success\n");
                                else
                                    printf("the queue is full!fail to add new data\n");
                                break;
                        case'D':printf("please enter the data: ");
                                ch=(char*)malloc(sizeof(char));
                                *ch=get_first();
                                p=ch;
                                data_type[queue.rear]='C';  //添加数据类型标记
                                if(EnAQueue(&queue,p))
                                    printf("success\n");
                                else
                                    printf("the queue is full!fail to add new data\n");
                                break;
                        default:puts("Enter Error!fail to add new data");
                    }
                    break;
            case'F':if(DeAQueue(&queue))  //出队
                        printf("success\n");
                    else
                        printf("the queue is empty!fail to delete data\n");
                    break;
            case'G':ClearAQueue(&queue);
                    printf("the queue is cleared\n");
                    break;
            case'H':DestoryAQueue(&queue);  //摧毁队列
                    printf("the queue is destroyed\n");
                    getchar();
                    return 0;
                    break;
            case'I':printf("\nfront-> ");
                    cursor=queue.front;  //每次遍历前将游标还原到初始位置
                    TraverseAQueue(&queue,&APrint);  //遍历并打印游标
                    printf(" <-rear\n");
                    printf("length: %d\n",LengthAQueue(&queue));
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
		printf(" is not an integer. please enter an integer:");
	}

	return input;
}
float get_float(){  //获得浮点数以及处理错误输入
	float input;
	char ch;

	while(scanf("%f",&input)!=1){
		while((ch=getchar())!='\n')
			putchar(ch);
		printf(" is not a float. please enter an integer:");
	}

	return input;
}
double get_double(){  //获得双浮点型数据以及处理错误输入
	double input;
	char ch;

	while(scanf("%lf",&input)!=1){
		while((ch=getchar())!='\n')
			putchar(ch);
		printf(" is not a double. please enter an integer:");
	}

	return input;
}
