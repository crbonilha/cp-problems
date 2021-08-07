#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

const int MAXN = 2e3;

int k, d;
int v[10];

char ans[MAXN+1];

int main() {
    scanf("%d", &k);
    scanf("%d", &d);
    for(int i=0; i<d; i++) {
        scanf("%d", &v[i]);
    }

    sort(v, v+d);

    if(d == 1 and v[0] == 0 and k > 1) {
        printf("-1\n");
        return 0;
    }
    else if(d == 1 and v[0] == 0 and k == 1) {
        printf("0\n");
        return 0;
    }

    ans[0] = ans[k-1] = v[0] == 0 ? v[1]+'0' : v[0]+'0';
    for(int i=1; i<k-1; i++) {
        ans[i] = v[0]+'0';
    }

    ans[k] = 0;
    printf("%s\n", ans);
}
