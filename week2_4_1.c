/*
4-1 Add Two Polynomials   (20分)
Write a function to add two polynomials. Do not destroy the input. Use a linked list implementation with a dummy head node. Note: The zero polynomial is represented by an empty list with only the dummy head node.

Format of functions:

Polynomial Add( Polynomial a, Polynomial b );
where Polynomial is defined as the following:

typedef struct Node *PtrToNode;
struct Node {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;
// Nodes are sorted in decreasing order of exponents.
The function Add is supposed to return a polynomial which is the sum of a and b.

Sample Input:

4
3 4 -5 2 6 1 -2 0
3
5 20 -7 4 3 1
Sample Output:

5 20 -4 4 -5 2 9 1 -2 0
*/

//code:

#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node  {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;

Polynomial Read(); /* details omitted */
void Print( Polynomial p ); /* details omitted */
Polynomial Add( Polynomial a, Polynomial b );

int main()
{
    Polynomial a, b, s;
    a = Read();
    b = Read();
    s = Add(a, b);
    Print(s);
    return 0;
}

/* Your function will be put here */

Polynomial Add( Polynomial a, Polynomial b )
{
    Polynomial p, ptr, res, p1, p2;
    int flag = 1;
    p1 = a ->Next;
    p2 = b ->Next;
    res = ptr = (Polynomial)malloc(sizeof(struct Node));
    res ->Next = NULL;
    while(p1 != NULL){
        while(p2 != NULL){
            p = (Polynomial)malloc(sizeof(struct Node));
            if(p2 ->Exponent == p1 ->Exponent){
                if(p2 ->Coefficient + p1 ->Coefficient != 0){
                    p ->Exponent = p1 ->Exponent;
                    p ->Coefficient = p2 ->Coefficient + p1->Coefficient;
                    p ->Next = NULL;
                    ptr = ptr ->Next = p;
                }
                flag = 0;
            }
            else if(p2 -> Exponent > p1 -> Exponent)
            {
                p ->Exponent = p2 ->Exponent;
                p ->Coefficient = p2 ->Coefficient;
                p ->Next = NULL;
                ptr = ptr ->Next = p;
            }
            else if(p2 ->Exponent<p1 ->Exponent)
                break;
            p2 = p2 ->Next;
        }
        if(flag == 1)
        {
            p = (Polynomial)malloc(sizeof(struct Node));
            p ->Coefficient = p1 ->Coefficient;
            p ->Exponent = p1 ->Exponent;
            p ->Next = NULL;
            ptr = ptr ->Next = p;
        }
        flag = 1;
        p1 = p1 ->Next;
    }
    while(p2!=NULL)
    {
        p = (Polynomial)malloc(sizeof(struct Node));
        p ->Coefficient = p2->Coefficient;
        p ->Exponent = p2->Exponent;
        p ->Next = NULL;
        ptr = ptr->Next = p;
        p2 = p2->Next;
    }
    return res;
}
