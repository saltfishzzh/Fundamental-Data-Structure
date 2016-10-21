/*
4-1 CheckBST[1]   (30分)
Given a binary tree, you are supposed to tell if it is a binary search tree. If the answer is yes, try to find the K-th largest key, else try to find the height of the tree.

Format of function:

int CheckBST ( BinTree T, int K );
where BinTree is defined as the following:

typedef struct TNode *BinTree;
struct TNode{
    int Key;
    BinTree Left;
    BinTree Right;
};
The function CheckBST is supposed to return the K-th largest key if T is a binary search tree; or if not, return the negative height of T (for example, if the height is 5, you must return −5).

Here the height of a leaf node is defined to be 1. T is not empty and all its keys are positive integers. K is positive and is never more than the total number of nodes in the tree.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TNode *BinTree;
struct TNode{
    int Key;
    BinTree Left;
    BinTree Right;
};

BinTree BuildTree(); /* details omitted */
int CheckBST ( BinTree T, int K );

int main()
{
    BinTree T;
    int K, out;

    T = BuildTree();
    scanf("%d", &K);
    out = CheckBST(T, K);
    if ( out < 0 )
        printf("No.  Height = %d\n", -out);
    else
        printf("Yes.  Key = %d\n", out);

    return 0;
}
/* 你的代码将被嵌在这里 */
int Jugde (BinTree T){
    if ((T ->Left != NULL && T ->Key < T ->Left ->Key) || (T ->Right != NULL && T ->Key > T ->Right ->Key)) return 0;
    if (T ->Left != NULL && T ->Right != NULL) return Jugde(T ->Left) && Jugde(T ->Right);
    else if (T ->Left != NULL) return Jugde(T ->Left);
    else if (T ->Right != NULL) return Jugde(T ->Right);
    else return 1;
}

int i;

void tra(BinTree T, int a[]){
    if (T != NULL) {
        tra(T ->Left, a);
        a[i] = T ->Key;
        i++;
        tra(T ->Right, a);
    }
}

int depth(BinTree T){
    if (T ->Left == NULL && T ->Right == NULL) return 1;
    else if (T ->Left != NULL && T ->Right == NULL) return depth(T ->Left) + 1;
    else if (T ->Right != NULL && T ->Left == NULL) return depth(T ->Right) + 1;
    else {
        if (depth(T ->Left) > depth(T ->Right)) return depth(T ->Left) + 1;
        else return depth(T ->Right) + 1;
    }
}

int CheckBST ( BinTree T, int K )
{
    int a[1000];
    if (T ->Left == NULL && T -> Right == NULL) return T ->Key;
    if (Jugde(T)) {
        tra(T, a);
        return a[i-K];
    }
    else return -depth(T);
}
