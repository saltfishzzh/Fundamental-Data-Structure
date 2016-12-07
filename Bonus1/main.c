/* Author: 张倬豪; ID: 3150102418; No.1 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 105

int n, m, s;
int weight[MAXN] = {0}, map[MAXN][MAXN] = {0}, previous[MAXN] = {0}, path[MAXN] = {0};
int res[MAXN][MAXN] = {0}, pathnum = 0;

void match(int next){
    int num = 0, nnext = next;
    do {
        res[pathnum][num++] = weight[nnext];
        nnext = previous[nnext];
    } while (nnext != -1);
    pathnum++;
    //Store the correct paths
}

void Find(int now) {
    int next, i = 0;
    while (map[now][i] != 0) {
        next = map[now][i];
        path[next] = path[now] + weight[map[now][i]];
        if (path[next] == s){
            if (map[next][0] == 0) match(next);// If matches
        }
        else if (path[next] < s) Find(next);
        i++;
    }
}

int Compare(int i, int j) {
    int leni = 0, lenj = 0;
    while (res[i][leni] > 0) leni++;
    while (res[j][lenj] > 0) lenj++;
    while ((res[i][leni] == res[j][lenj]) && leni > 0 && lenj > 0) {
        leni--;
        lenj--;
    }
    return res[i][leni] - res[j][lenj];// Compare the first numbers that are different
}

void Print() {
    int si, sj, temp[MAXN] = {0}, length;
    for (si = 0; si < pathnum - 1; si++) {
        for (sj = 0; sj <pathnum - 1 - si; sj++) {
            if (Compare(sj, sj + 1) < 0) {// If the first path is "bigger" than the second
                memcpy(temp, res[sj], sizeof(res[sj]));
                memset(res[sj], 0, sizeof(res[sj]));
                memcpy(res[sj], res[sj + 1], sizeof(res[sj+1]));
                memset(res[sj + 1], 0, sizeof(res[sj+1]));
                memcpy(res[sj + 1], temp, sizeof(res[sj]));
            }
        }
    }// Simple Bubble sort in non-increasing order
    for (si = 0; si < pathnum; si ++) {
        length = 0;
        while (res[si][length] > 0) length++;
        printf("%d", res[si][--length]);
        while (length--) printf(" %d", res[si][length]);
        printf("\n");
    }// Print all the correct paths
}

int main(int argc, const char * argv[]) {
    int i, j, nleaf, childnum;
    scanf("%d%d%d", &n, &m, &s);
    for (i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
        path[i] = weight[i];
    }
    for (i = 0; i < m; i++) {
        scanf("%d%d", &nleaf, &childnum);
        for (j = 0; j < childnum; j++) {
            scanf("%d", &map[nleaf][j]);
            previous[map[nleaf][j]] = nleaf;
        }
    }// Read all the data
    previous[0] = -1;// Set the first node's previous node as -1
    if (map[0][0] != 0) {
        Find(0);
        Print();
    }
    else if (weight[0] == s) printf("%d\n", s);// If there is only one node
    return 0;
    
}
