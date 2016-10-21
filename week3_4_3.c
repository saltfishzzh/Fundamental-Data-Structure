/*
4-3 Evaluate Postfix Expression   (25分)
Write a program to evaluate a postfix expression. You only have to handle four kinds of operators: +, -, x, and /.

Format of functions:

ElementType EvalPostfix( char *expr );
where expr points to a string that stores the postfix expression. It is guaranteed that there is exactly one space between any two operators or operands. The function EvalPostfix is supposed to return the value of the expression. If it is not a legal postfix expression, EvalPostfix must return a special value Infinity which is defined by the judge program.

Sample Input 1:

11 -2 5.5 * + 23 7 / -
Sample Output 1:

-3.285714
Sample Input 2:

11 -2 5.5 * + 23 0 / -
Sample Output 2:

ERROR
Sample Input 3:

11 -2 5.5 * + 23 7 / - *
Sample Output 3:

ERROR
*/

#include <stdio.h>
#include <stdlib.h>

typedef double ElementType;
#define Infinity 1e8
#define Max_Expr 30   /* max size of expression */

ElementType EvalPostfix( char *expr );

int main()
{
    ElementType v;
    char expr[Max_Expr];
    gets(expr);
    v = EvalPostfix( expr );
    if ( v < Infinity )
        printf("%f\n", v);
    else
        printf("ERROR\n");
    return 0;
}

/* Your function will be put here */
typedef struct                     /*定义数值栈*/
{
    double num[100];
    int top;                           /*栈顶指针*/
    int size;
} numstack;

ElementType EvalPostfix( char *expr ) {
    double  pop2(numstack *a);
    void push2(numstack *a,double num);
    
    char c;
    numstack numst;                            /*建立数值栈*/
    double d1,d2,dr;
    int k=0;                                    /*后缀表达式的索引*/
    int i=0;	                                   /*将字符转化为浮点数的索引*/
    char *s;
    char trans[100];                             /*存字符表示的一段数字*/
    numst.size=0;
    numst.top=0;                              /*实现数值栈*/
    c=expr[k++];
    while (c!='\0')                              /*开始扫描后缀表达式*/
    {
        if((c=='+'||c=='-'||c=='*'||c=='/'||c=='%') && !((expr[k]>='0'&&expr[k]<='9')||c=='.'))
        {
            if (numst.top == 1) return Infinity;
            switch(c)
            {
                case '+' :                            /*如果是加法操作*/
                    d2=pop2(&numst);
                    d1=pop2(&numst);
                    dr=d1+d2;                     /*相加后入栈*/
                    push2(&numst,dr);
                    break;
                case '-' :                           /*如果是减法操作*/
                    d2=pop2(&numst);
                    d1=pop2(&numst);
                    dr=d1-d2;                     /*相减后入栈*/
                    push2(&numst,dr);
                    break;
                case '*' :                        /*如果是乘法操作*/
                    d2=pop2(&numst);
                    d1=pop2(&numst);
                    dr=d1*d2;                   /*相乘后入栈*/
                    push2(&numst,dr);
                    break;
                case '/' :                   /*如果是除法操作*/
                    d2=pop2(&numst);
                    d1=pop2(&numst);
                    if (d2 == 0) return Infinity;
                    dr=d1/d2;               /*相除后入栈*/
                    push2(&numst,dr);
                    break;
                case '%' :                  /*如果是取余操作*/
                    d2=pop2(&numst);
                    d1=pop2(&numst);
                    dr=(double)((int)d1%(int)d2);      /*类型转化并取余后入栈*/
                    push2(&numst,dr);
                    break;
            }
        }
        if ((c>='0'&&c<='9')||c=='.' || (c == '-' && ((expr[k]>='0'&&expr[k]<='9')||expr[k]=='.')))                 /*如果是字符表示的数字*/
        {
            while(c>='0'&&c<='9'||c=='.' || (c == '-'))
            {
                trans[i++]=c;                /*将字符存入数组进行下一个的扫描*/
                c=expr[k++];
            }
            trans[i++]='\0';                  /*将表示数字的字符串结束*/
            i=0;
            s=trans;                         /*将指针指向该数组*/
            d1=atof(s);			           /*利用函数将字符串转化为浮点数*/
            push2(&numst,d1);
        }
        c=expr[k++];
    }
    return pop2(&numst);	                    /*最后结果将在数值栈中，取出作为返回值*/
}

double  pop2(numstack *a)               /*数值栈出栈*/
{
    if (a->size==0)                        /*出栈前的判空*/
    {
        exit(-1);
    }
    a->size--;
    return a->num[--(a->top)];             /*得到栈顶的值*/
}
void push2(numstack *a,double num)          /*入栈*/
{
    a->size++;
    a->num[(a->top)++]=num;
}
