/************************************************************
 FileName: DS_Project_1.c
 Author: 牛奔放、张倬豪、郭爽
 Date: 10.4
 Description: Compare two different algorithms of computing X^N
 Function List:
 1. double function1(double x, int N);
 2. double function2(double x, int N);
 3. double function3(double x, int N);
 Three ways of performing X^N
 ***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CLK_TCK 18.2    /*In case that const is not in the library*/

clock_t start, stop;    /* clock_t is a built-in type for processor time (ticks) */
double duration, total;        /* records the run time (seconds) of a function */
double function1(double x, int N);
double function2(double x, int N);
double function3(double x, int N);

int main()
{
    double i, ticks;
    int K, N;
    double x = 1.0001, sum = 0;
    
    printf("Enter N\n");
    scanf("%d", &N);/*input N*/
    
    printf("Enter K\n");
    scanf("%d", &K);/*input K*/

    start = clock();              /* records the ticks at the beginning of the function call */
    printf("input a number\n1 for simple multiply\n2 for iterative version\n3 for  recusivee version\n");
    scanf("%d",&m);
    
    switch(m)/* run your function here for K times*/
    {
        case 1: for(i=1;i<=K;i++)
            sum=function1(x,N);break;
        case 2: for(i=1;i<=K;i++)
            sum=function2(x,N);break;
        case 3: for(i=1;i<=K;i++)
            sum=function3(x,N);break;
        default: printf("Illegal Number!"); break;
    }
    stop = clock();               /* records the ticks at the end of the function call */
    ticks = stop - start;
    total = (double)ticks/CLK_TCK
    duration = total/k;
    printf("sum = %lf\n",sum);
    printf("totaltime = %lf\nticks = %lf\nduration = %lf\n", totaltime, ticks, duration);
    return 1;
}

/*************************************************
 Function: // function1
 Description: // simple multiply of X^N
 Calls: // none
 Called By: // main
 Input: // double x, int N
 Output: // none
 Return: // the result of multiply
 *************************************************/
double function1(double x, int N)
{
    double i;
    float M = 1;		            /*give M an initial number*/
    
    for(i = 0;i<N;i++)
        M = M*x;
    return M;
}

/*************************************************
 Function: // function2
 Description: // iterative algorithm of X^N
 Calls: // none
 Called By: // main
 Input: // double x, int N
 Output: // none
 Return: // the result of multiply
 *************************************************/
double function2(double x, int N)
{
    int a[20];		                /*set an array to store every MOD*/
    int i = 0;
    double M = 1;
    
    do
    {
        a[i] = N%2;
        i++;
        N = N/2;
    }
    while (N != 0);                 /*change N to a reverse order binary system*/
    i--;
    for(;i >= 0;i--)
    {
        if(a[i] == 1)	         	/*MOD = 1 means N is odd*/
            M = M*M*x;
        else			        	/*MOD  =  0 means N is even*/
            M = M*M;
    }
    return M;
}

/*************************************************
 Function: // function3
 Description: // recursive algorithm of X^N
 Calls: // none
 Called By: // main
 Input: // double x, int N
 Output: // none
 Return: // the result of multiply
 *************************************************/
double function3(double x, int N)
{
    double M;
    if(N == 1)
        M = x;
    else if(N == 0)
        M = 1;			            /*line 78 to 82: Base cases*/
    else if(N%2 == 0)               /*When N is even*/
    {
        M = function3(x,N/2);       /*To minimize the running time,we should calculate the function as less as possible*/
        M = M*M;
    }
    else                            /*When N is odd*/
    {
        M = function3(x,(N-1)/2);
        M = M*M*x;
    }
    return M;
}
