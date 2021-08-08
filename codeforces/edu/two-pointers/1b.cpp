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

    for(int i=0, j=0; j<m; j++) {
        while(i < n and a[i] < b[j]) {
            i++;
        }

        printf("%d ", i);
    }
    printf("\n");
}
