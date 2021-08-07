#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

const int MAXN = 1e5;

int main() {
    int a, b, c, d;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);

    if(a < b) {
        if(c < d) {
            printf("Go to the department store\n");
        }
        else {
            printf("Go to the grocery store\n");
        }
    }
    else {
        if(c < d) {
            printf("Go to the pharmacy\n");
        }
        else {
            printf("Stay home\n");
        }
    }
}
