#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 500;

vector<int> primes;
bool notPrime[MAXN+1];
void sieve(int n) {
    primes.push_back(2);
    for(int i=3; i<=n; i+=2) {
        if(!notPrime[i]) {
            primes.push_back(i);
            for(int j=i+i; j<=n; j+=i) {
                notPrime[j] = true;
            }
        }
    }
}

ll myPow(int a, int b, ll p) {
    if(!b) {
        return 1;
    }
    if(b == 1) {
        return a;
    }

    if(b%2) {
        return (myPow(a, b-1, p) * ll(a)) % p;
    }
    return (myPow(a, b/2, p) * myPow(a, b/2, p)) % p;
}

int n;
ll p;

vector<int> chosen;
ll countValues(int pos, ll v) {
    if(v > n) {
        return 0;
    }
    return 1 + countValues(pos, v*chosen[pos]) + countValues(pos+1, v*chosen[pos+1]);
}

bool invalid[MAXN+1];
ll solve(int pos, ll v) {
    memset(invalid, false, sizeof(bool)*(n+1));
    for(int i=0; i<chosen.size(); i++) {
        for(int j=chosen[i]; j<=n; j+=chosen[i]) {
            invalid[j] = true;
        }
    }
    ll rem = 0;
    for(int i=2; i<=n; i++) {
        rem += !invalid[i];
    }

    ll cur = countValues(0, chosen[0]);

    rem = myPow(2, rem, p);
    cur = myPow(2, cur-1, p);
    printf("solve %d %lld, cur %lld, rem %lld\n", pos, v, cur, rem);

    ll ans = (cur * rem) % p;
    for(int i=pos+1; i<primes.size(); i++) {
        if(v*primes[i] > n) {
            break;
        }

        chosen.push_back(primes[i]);
        ans = (ans + solve(i, v*primes[i])) % p;
        chosen.pop_back();
    }
    return ans;
}

int main() {
    scanf("%d %lld", &n, &p);

    sieve(n);

    ll ans = myPow(2, n-1, p);
    for(int i=0; i<primes.size(); i++) {
        chosen.push_back(primes[i]);
        ans = (ans + solve(i, primes[i])) % p;
        chosen.pop_back();
    }
    printf("%lld\n", ans);
}
