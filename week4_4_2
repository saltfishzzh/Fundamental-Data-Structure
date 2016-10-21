/*
4-2 Isomorphic   (20分)
Two trees, T1 and T2, are isomorphic if T1 can be transformed into T2 by swapping left and right children of (some of the) nodes in T1. For instance, the two trees in Figure 1 are isomorphic because they are the same if the children of A, B, and G, but not the other nodes, are swapped. Give a polynomial time algorithm to decide if two trees are isomorphic.

Format of functions:

int Isomorphic( Tree T1, Tree T2 );
where Tree is defined as the following:

typedef struct TreeNode *Tree;
struct TreeNode {
    ElementType Element;
    Tree  Left;
    Tree  Right;
};
The function is supposed to return 1 if T1 and T2 are indeed isomorphic, or 0 if not.
*/

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct TreeNode *Tree;
struct TreeNode {
    ElementType Element;
    Tree  Left;
    Tree  Right;
};

Tree BuildTree(); /* details omitted */

int Isomorphic( Tree T1, Tree T2 );

int main()
{
    Tree T1, T2;
    T1 = BuildTree();
    T2 = BuildTree();
    printf(“%d\n”, Isomorphic(T1, T2));
    return 0;
}

/* Your function will be put here */
int Isomorphic( Tree T1, Tree T2 )
{
    if  ( (T1==NULL )&& (T2==NULL) )
        return  1;
    if  ( ((T1==NULL)&&(T2!=NULL)) || ((T1!=NULL)&&(T2==NULL)) )
        return  0;
    if  ( T1->Element != T2->Element )
        return  0;
    if  ( ( T1->Left == NULL )&&( T2->Left == NULL ) )
        return  Isomorphic( T1->Right, T2->Right );
    if  ( ((T1->Left!=NULL)&&(T2->Left!=NULL))&&((T1->Left->Element)==(T2->Left->Element)) )
        return  ( Isomorphic( T1->Left, T2->Left ) &&  Isomorphic( T1->Right, T2->Right ) );
    else
        return ( Isomorphic( T1->Left, T2->Right) &&  Isomorphic( T1->Right, T2->Left ) );
}
