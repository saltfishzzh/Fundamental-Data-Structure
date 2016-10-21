/*
5-1 Tree Traversals Again   (25分)
An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. Your task is to give the postorder traversal sequence of this tree.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (≤30) which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N). Then 2N lines follow, each describes a stack operation in the format: "Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.

Output Specification:

For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is guaranteed to exist. All the numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:

6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
Sample Output:

3 4 2 6 5 1
*/

//
//  main.c
//  fds_w4_3
//
//  Created by 张倬豪 on 2016/10/9.
//  Copyright © 2016年 Icarus. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node *Tree;
struct Node
{
    int val;
    Tree left;
    Tree right;
};

char input[8];

int n = 0, ids = 0, ids2 = 0;

struct Node * buildTree()
{
    struct Node * r;
    r = (Tree)malloc(sizeof(struct Node));
    int tmp = 0;
    if(ids < 2*n)
    {
        scanf("%s",input);
        if(input[1]=='u')
        {
            scanf("%d",&tmp);
            r->val = tmp;
            ids++;
        }
        else if(input[1]=='o')
        {
            ids++;
            return NULL;
        }
        r->left = buildTree();
        r->right = buildTree();
    }
    return r;
}
void Doit(struct Node *r)
{
    if(r!=NULL)
    {
        Doit(r->left);
        Doit(r->right);
        if (r ->val != 0) {
            printf("%d",r->val);
            ids2++;
            if(ids2<n){
                printf(" ");
            }
            else
            {
                printf("\n");
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    struct Node * root = buildTree();
    Doit(root);
    return 0;
}
