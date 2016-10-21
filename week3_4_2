/*
4-2 Two Stacks In One Array   (20分)
Write routines to implement two stacks using only one array. Your stack routines should not declare an overflow unless every slot in the array is used.

Format of functions:

Stack CreateStack( int MaxElements );
int IsEmpty( Stack S, int Stacknum );
int IsFull( Stack S );
int Push( ElementType X, Stack S, int Stacknum );
ElementType Top_Pop( Stack S, int Stacknum );
where int Stacknum is the index of a stack which is either 1 or 2; int MaxElements is the size of the stack array; and Stack is defined as the following:

typedef struct StackRecord *Stack;
struct StackRecord  {
    int Capacity;       /* maximum size of the stack array */
    int Top1;           /* top pointer for Stack 1 */
    int Top2;           /* top pointer for Stack 2 */
    ElementType *Array; /* space for the two stacks */
}
Note: Push is supposed to return 1 if the operation can be done successfully, or 0 if fails. If the stack is empty, Top_Pop must return ERROR which is defined by the judge program.
Sample Input:

5
Push 1 1
Pop 2
Push 2 11
Push 1 2
Push 2 12
Pop 1
Push 2 13
Push 2 14
Push 1 3
Pop 2
End
Sample Output:

Stack 2 is Empty!
Stack 1 is Full!
Pop from Stack 1: 1
Pop from Stack 2: 13 12 11
*/

#include <stdio.h>
#include <stdlib.h>
#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;

typedef struct StackRecord *Stack;
struct StackRecord  {
    int Capacity;       /* maximum size of the stack array */
    int Top1;           /* top pointer for Stack 1 */
    int Top2;           /* top pointer for Stack 2 */
    ElementType *Array; /* space for the two stacks */
};

Stack CreateStack( int MaxElements );
int IsEmpty( Stack S, int Stacknum );
int IsFull( Stack S );
int Push( ElementType X, Stack S, int Stacknum );
ElementType Top_Pop( Stack S, int Stacknum );

Operation GetOp();  /* details omitted */
void PrintStack( Stack S, int Stacknum ); /* details omitted */

int main()
{
    int N, Sn, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while ( !done ) {
        switch( GetOp() ) {
        case push: 
            scanf("%d %d", &Sn, &X);
            if (!Push(X, S, Sn)) printf("Stack %d is Full!\n", Sn);
            break;
        case pop:
            scanf("%d", &Sn);
            X = Top_Pop(S, Sn);
            if ( X==ERROR ) printf("Stack %d is Empty!\n", Sn);
            break;
        case end:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
    }
    return 0;
}

/* Your function will be put here */
Stack CreateStack ( int MaxElements ) {
    Stack S;
    S = (Stack)malloc( sizeof ( struct StackRecord ) );
    S->Array = (int*)malloc( sizeof (int) * (MaxElements) );
    S->Capacity = MaxElements;
    S->Top1 = 0;
    S->Top2 = MaxElements - 1;
    return ( S );
}

int IsEmpty(Stack S, int Stacknum) {
    if (Stacknum == 1 && S->Top1 == 0)return 1;
    if (Stacknum == 2 && S->Top2 == S->Capacity-1)return 1;
    return 0;
}
int IsFull(Stack S) {
    if (S->Top1 - 1 == S->Top2)return 1;
    return 0;
}
int Push(ElementType X, Stack S, int Stacknum) {
    if (IsFull(S))return 0;
    switch (Stacknum) {
        case 1:
            (S->Top1)++;
            S->Array[S->Top1 - 1] = X;
            break;
        case 2:
            (S->Top2)--;
            S->Array[S->Top2 + 1] = X;
            break;
    }
    return 1;
}

ElementType Top_Pop( Stack S, int Stacknum ){
    if ( Stacknum == 1 ) {
        if (S->Top1 == 0) return ERROR;
        else return S->Array[--S->Top1];
    }
    else {
        if (S->Top2 == S->Capacity - 1) return ERROR;
        return S->Array[++S->Top2];
    }
    
}
