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
int Judge(char a,char b);		//判断运算符优先级函数
double Operate(double x,double y,char c);		//运算函数
//运算符栈的基本操作
void InitStack(Optr &S);
void Push(Optr &S, char e);
void Pop(Optr &S,char &e);
char GetTop(Optr S);
//数栈的基本操作
void InitStack(Opnd &S);
void Push(Opnd &S, double e);
void Pop(Opnd &S,double &e);
double GetTop(Opnd S);
//主函数
int main(){
	double x,y,d=0;
	char s,c;
	Optr tr;
	Opnd nd;
	InitStack(tr);
	InitStack(nd);
	Push(tr,'#');		//先将‘#’压入栈
	s=getchar();		//得到第一个字符
	while(s!='#'||*(tr.top-1)!='#'){		//循环判断是否为数字或运算符
		if(s >= '0'&&s <= '9'){
			while (s >= '0'&&s <= '9'){
				d = d * 10 + s - 48;
				s = getchar();
			}
			Push(nd, d);
			d = 0;
			if(s=='\n')s='#';
		}
		else{
			switch(Judge(GetTop(tr),s)){
			case -1:
				Push(tr,s);
				s = getchar();
				break;
			case 0:
				Pop(tr,c);
				s = getchar();
				break;
			case 1:
				Pop(tr,c);
				Pop(nd,y);
				Pop(nd,x);
				Push(nd,Operate(x,y,c));
				break;
			
			}
			if(s=='\n')s='#';
		}
	}
	Pop(nd,x);

	printf("%.2lf\n",x);		//输出
	
  
	return 0;
}

int Judge(char a,char b){
	int c;
	switch(a){
	case '+':
		if(b=='*'||b=='/'||b=='(')
			c=-1;
		else
			c=1;
		break;
	case '-':
		if(b=='*'||b=='/'||b=='(')
			c=-1;
		else
			c=1;
	case '*':
		if(b=='(')
			c=-1;
		else
			c=1;
		break;
	case '/':
		if(b=='(')
			c=-1;
		else
			c=1;
		break;
	case '(':
		if(b==')')
			c=0;
		else
			c=-1;
		break;
	case ')':
		c=1;
		break;
	case '#':
		if(b=='#')
			c=0;
		else
			c=-1;
		break;
	}
	return c;
}
double Operate(double x,double y,char c){
	double z;
	switch(c){
	case '+':
		z=x+y;
		break;
	case '-':
		z=x-y;
		break;
	case '*':
		z=x*y;
		break;
	case '/':
		z=x/y;
		break;
	}
	return z;
}

void InitStack(Optr &S){
	S.base = (char*)malloc(MAX_SIZE*sizeof(char));
	S.top=S.base;
	S.stacksize=MAX_SIZE;
}

void Push(Optr &S, char e){
	*S.top++=e;
}

void Pop(Optr &S,char &e){
	e=*--S.top;
}

char GetTop(Optr S){
	return *(S.top - 1);
}


void InitStack(Opnd &S){
	S.base = (double*)malloc(MAX_SIZE*sizeof(double));
	S.top=S.base;
	S.stacksize=MAX_SIZE;
}

void Push(Opnd &S, double e){
	*S.top++=e;
}

void Pop(Opnd &S,double &e){
	e=*--S.top;
}

double GetTop(Opnd S){
	return *(S.top-1);
}

