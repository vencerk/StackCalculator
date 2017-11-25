#include <stdio.h>
#include <malloc.h> 
#include <string.h> 
#define MAX_SIZE 100
typedef struct{
	char *base;
	char *top;
	int stacksize;
}Optr;			//定义运算符栈
typedef struct{
	double *base;
	double *top;
	int stacksize;
}Opnd;			//定义数栈