/*
4-1 Level-order Traversal   (25分)
Write a routine to list out the nodes of a binary tree in "level-order". List the root, then nodes at depth 1, followed by nodes at depth 2, and so on. You must do this in linear time.

Format of functions:

void Level_order ( Tree T, void (*visit)(Tree ThisNode) );
where void (*visit)(Tree ThisNode) is a function that handles ThisNode being visited by Level_order, and Tree is defined as the following:

typedef struct TreeNode *Tree;
struct TreeNode {
    ElementType Element;
    Tree  Left;
    Tree  Right;
};
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxTree 10 /* maximum number of nodes in a tree */
typedef int ElementType;

typedef struct TreeNode *Tree;
struct TreeNode {
    ElementType Element;
    Tree  Left;
    Tree  Right;
};

Tree BuildTree(); /* details omitted */
void PrintNode( Tree NodePtr )
{
   printf(" %d", NodePtr->Element);
}

void Level_order ( Tree T, void (*visit)(Tree ThisNode) );

int main()
{
    Tree T = BuildTree();
    printf("Level-order:");
    Level_order(T, PrintNode);
    return 0;
}

/* Your function will be put here */
typedef struct Ptr *queue;
struct Ptr {
    Tree tree;
    queue Next;
};

void Level_order ( Tree T, void (*visit)(Tree ThisNode) )
{
    queue front, rear;
    front = (queue)malloc(sizeof(struct Ptr));
    rear = (queue)malloc(sizeof(struct Ptr));
    if (T == NULL) return;
    front ->Next = rear;
    rear ->tree = T;
    rear ->Next = NULL;
    while (front != rear) {
        Tree temp = front ->Next ->tree;
        front = front ->Next;
        visit(temp);
        if (temp ->Left != NULL) {
            queue cur1 = (queue)malloc(sizeof(struct Ptr));
            cur1 ->tree = temp ->Left;
            rear ->Next = cur1;
            cur1 ->Next = NULL;
            rear = cur1;
        }
        if (temp ->Right != NULL) {
            queue cur2 = (queue)malloc(sizeof(struct Ptr));
            cur2 ->tree = temp ->Right;
            rear ->Next = cur2;
            cur2 ->Next = NULL;
            rear = cur2;
        }
    }
}
