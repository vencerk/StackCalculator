#include <stdio.h>
#include <malloc.h> 
#include <string.h> 
#define MAX_SIZE 100
typedef struct{
	char *base;
	char *top;
	int stacksize;
}Optr;			//���������ջ
typedef struct{
	double *base;
	double *top;
	int stacksize;
}Opnd;			//������ջ