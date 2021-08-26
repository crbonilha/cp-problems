#include <bits/stdc++.h>

template <class T>
class Modular {
    T maxN, mod;
    vector<T> factorial;
    vector<T> inverseFactorial;

    void init() {
        factorial = vector<T>(maxN+1);
        factorial[0] = 1;
        for(int i=1; i<=maxN; i++) {
            factorial[i] = (factorial[i-1] * i) % mod;
        }

        inverseFactorial = vector<T>(maxN+1);
        for(int i=0; i<=maxN; i++) {
            inverseFactorial[i] = inverse(factorial[i]);
        }
    }
public:
    Modular(T maxN, T mod) : maxN(maxN), mod(mod) {
        init();
    }
    Modular() {
        maxN = 1e5;
        mod = 1e9+7;
        init();
    }

    static T gcd(T a, T b) {
        return __gcd(a, b);
    }

    static T extendedGcd(T a, T b, T& x, T& y) {
        if(b == 0) {
            x = 1;
            y = 0;
            return a;
        }

        T x1, y1;
        T d = extendedGcd(b, a%b, x1, y1);
        x = y1;
        y = x1 - y1 * (a / b);
        return d;
    }

    static T powMod(T a, T b, T m) {
        if(b == 0) {
            return 1;
        }
        else if(b&1) {
            return a * powMod(a, b-1, m) % m;
        }
        else {
            T cand = powMod(a, b/2, m);
            return cand * cand % m;
        }
    }

    T powMod(T a, T b) {
        return powMod(a, b, mod);
    }

    static T inverse(T a, T m) {
        return powMod(a, m-2, m);
    }

    T inverse(T a) {
        return inverse(a, mod);
    }

    T binomialCoefficient(T n, T k) {
        if(k > n) {
            return 0;
        }
        return (factorial[n] * inverseFactorial[k] % mod) * inverseFactorial[n - k] % mod;
    }
};
