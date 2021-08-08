#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int n, m;
int a[MAXN], b[MAXN];

int main() {
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i=0; i<m; i++) {
        scanf("%d", &b[i]);
    }

    for(int i=0, j=0; i<n or j<m; ) {
        if(i == n) {
            printf("%d ", b[j++]);
        }
        else if(j == m) {
            printf("%d ", a[i++]);
        }
        else if(a[i] < b[j]) {
            printf("%d ", a[i++]);
        }
        else {
            printf("%d ", b[j++]);
        }
    }
    printf("\n");
}
