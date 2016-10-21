/*
4-2 Reverse Linked List   (20分)
Write a nonrecursive procedure to reverse a singly linked list in O(N) time using constant extra space.

Format of functions:

List Reverse( List L );
where List is defined as the following:

typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node {
    ElementType Element;
    Position Next;
};
The function Reverse is supposed to return the reverse linked list of L, with a dummy header.

Sample Input:

5
1 3 4 5 2
Sample Output:

2 5 4 3 1
2 5 4 3 1
*/


#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node {
    ElementType Element;
    Position Next;
};

List Read(); /* details omitted */
void Print( List L ); /* details omitted */
List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

/* Your function will be put here */

List Reverse( List L )
{
    Position temp, p, head, tail;
    ElementType i = 0, a[1000];
    head = (Position)malloc(sizeof(struct Node));
    tail = (Position)malloc(sizeof(struct Node));
    head = tail;
    head ->Next = NULL;
    temp = L;
    while(temp != NULL){
        if(i != 0)
            a[i] = temp ->Element;
        temp = temp ->Next;
        i++;
    }
    i--;
    L = L->Next;
    while(i != 0){
        p = (Position)malloc(sizeof(struct Node));
        p ->Element = a[i];
        p ->Next = NULL;
        L ->Element = a[i];
        tail ->Next = p;
        tail = p;
        L = L ->Next;
        i--;
    }
    return head;
}
