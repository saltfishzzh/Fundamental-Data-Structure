/*
5-1 Build A Binary Search Tree   (30分)
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
Given the structure of a binary tree and a sequence of distinct integer keys, there is only one way to fill these keys into the tree so that the resulting tree satisfies the definition of a BST. You are supposed to output the level order traversal sequence of that tree. The sample is illustrated by Figure 1 and 2.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (≤100) which is the total number of nodes in the tree. The next N lines each contains the left and the right children of a node in the format left_index right_index, provided that the nodes are numbered from 0 to N-1, and 0 is always the root. If one child is missing, then -1 will represent the NULL child pointer. Finally N distinct integer keys are given in the last line.

Output Specification:

For each test case, print in one line the level order traversal sequence of that tree. All the numbers must be separated by a space, with no extra space at the end of the line.

Sample Input:

9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
Sample Output:

58 25 82 11 38 67 45 73 42
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode *Node;
struct TreeNode{
    int left;
    int right;
    int data;
};

Node T;
int *table;

typedef struct Queue_struct *Queue;
struct Queue_struct{
    struct TreeNode Elements[101];
    int front;
    int rear;
};

Queue createQueue(){
    
    Queue q = (Queue)malloc(sizeof(struct Queue_struct));
    q->front = q->rear = 0;
    return q;
}

void EnQueue(Queue q, struct TreeNode item){
    if (q->rear >= 100)
    {
        return;
    }
    q->Elements[q->rear++] = item;
    
}

struct TreeNode DeQueue(Queue q){
    if (q->front == q->rear){
        exit(0);
    }
    return q->Elements[q->front++];
}


void preOrder(struct TreeNode node){
    
    if (node.left != -2){
        printf("%d ",node.data);
        preOrder(T[node.left]);
        preOrder(T[node.right]);
    }
    
}

void countNodes(struct TreeNode node, int* count){
    
    if (node.left != -2){
        (*count)++;
        countNodes(T[node.left], count);
        countNodes(T[node.right], count);
    }
    
}

int countChilds(struct TreeNode node){
    
    int count = 0;
    countNodes(node, &count);
    return count;
}

int compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

void InsetToBST(int start, int end, Node node){
    
    if (node->left != -2){
        int begin = start;
        int stop = start + countChilds(T[node ->left]);
        node->data = table[stop];
        InsetToBST(begin, stop - 1, T + node->left);
        begin = stop + 1;
        stop = begin + countChilds(T[node->right]);
        InsetToBST(begin, stop - 1, T + node->right);
    }
    
}

void MediaOrder(Node T){
    int count = 0;;
    Queue q = createQueue();
    EnQueue(q, T[0]);
    while (q->front != q->rear){
        struct TreeNode t = DeQueue(q);
        if (count == 0){
            count = 1;
            printf("%d", t.data);
        }
        else{
            printf(" %d", t.data);
        }
        if (T[t.left].data!=-1){
            EnQueue(q, T[t.left]);
        }
        if (T[t.right].data!=-1){
            EnQueue(q, T[t.right]);
        }
    }
    printf("\n");
}

int main(){
    
    int N;
    scanf("%d", &N);
    Node TempTree = (Node)malloc(sizeof(struct TreeNode)*(N+1));
    TempTree->left = -2;
    TempTree->right = -2;
    TempTree->data = -1;
    T = TempTree + 1;
    for (int i = 0; i < N; i++){
        Node node = T + i;
        node->data = 0;
        scanf("%d%d", &node->left, &node->right);
    }
    
    table = (int*)malloc(sizeof(int)*N);
    
    for (int i = 0; i < N; i++){
        scanf("%d", table + i);
    }
    
    qsort(table, N, sizeof(int), compare);
    
    InsetToBST(0, N - 1, T + 0);
    
    MediaOrder(T);
    return 0;
    
}
