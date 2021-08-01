#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5;

int n, k;
int v[MAXN+1];

int gcd(int a, int b) {
    if(a < b) {
        return gcd(b, a);
    }
    if(!b) {
        return a;
    }
    return gcd(b, a%b);
}

int tree[MAXN*4];
int initTree(int idx, int l, int r) {
    if(l == r) {
        return tree[idx] = v[l];
    }

    int mid = (l+r)/2;
    return tree[idx] = gcd(
        initTree(idx*2, l, mid),
        initTree(idx*2+1, mid+1, r)
    );
}

int queryTree(int idx, int l, int r, int ql, int qr) {
    if(qr < l or r < ql) {
        return 0;
    }
    if(ql <= l and r <= qr) {
        return tree[idx];
    }

    int mid = (l+r)/2;
    return gcd(
        queryTree(idx*2, l, mid, ql, qr),
        queryTree(idx*2+1, mid+1, r, ql, qr)
    );
}

bool solve(int len) {
    for(int i=0; i+len<=n; i++) {
        if(queryTree(1, 1, n, i+1, i+len) >= k) {
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i+1]);
    }

    initTree(1, 1, n);

    int ans = 0, ini = 1, mid, fim = n+1;
    while(ini < fim) {
        mid = (ini+fim)/2;

        if(solve(mid)) {
            ans = mid;
            ini = mid+1;
        }
        else {
            fim = mid;
        }
    }
    printf("%d\n", ans);
}
