#include <bits/stdc++.h>

class Primes {
    int maxV;

    void sieve() {
        primes.push_back(2);
        for(int i=3; i<=maxV; i+=2) {
            if(isPrime[i]) {
                primes.push_back(i);
                for(int j=i+i; j<=maxV; j+=i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    void init() {
        isPrime = (bool*) malloc(sizeof(bool) * (maxV+1));
        memset(isPrime, true, sizeof(isPrime));
        sieve();
    }
public:
    std::vector<int> primes;
    bool * isPrime;

    Primes(int maxV) : maxV(maxV) {
        init();
    }
    Primes() {
        maxV = 1e6;
        init();
    }
};
