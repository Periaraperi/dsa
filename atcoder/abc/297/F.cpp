#include <bits/stdc++.h>
 
using namespace std;
 
/*
    upsolving problem on binomial coefficients, probability, modular arithmetic, modular inverse
    new topic
*/

int64_t bin_pow(int64_t a, int64_t b, int64_t MOD)
{
    int64_t res = 1;
    while (b>0) {
        if (b%2==1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }
    return res;
}

int64_t binom(int n, int k, const vector<int64_t>& fact, const vector<int64_t>& fact_inv, int64_t MOD)
{
    if (n<k) return 0;
    return (fact[n]*((fact_inv[k]*fact_inv[n-k])%MOD))%MOD;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    constexpr int64_t MOD = 998244353;
    int w,h,k; cin >> w >> h >> k;
    vector<int64_t> fact(w*h+1);
    fact[0] = 1;
    vector<int64_t> fact_inv(w*h+1);

    for (int64_t i=1; i<=w*h; ++i) {
        fact[i] = (i*fact[i-1])%MOD;
    }
    fact_inv[0] = 1;
    for (int64_t i=1; i<=w*h; ++i) {
        fact_inv[i] = bin_pow(fact[i],MOD-2,MOD);
    }

    auto possible_combs = binom(h*w,k,fact,fact_inv,MOD);

    int64_t cum = 0;
    for (int i=1; i<=h; ++i) {
        for (int j=1; j<=w; ++j) {
            // how many min rectangles are there so that cell i,j does not contribute to
            int64_t not_included = 0;
            if (i>1) { // above 
                not_included += binom(w*(i-1),k,fact,fact_inv,MOD);
                not_included %= MOD;
            }
            if (i<h) { // below
                not_included += binom(w*(h-i),k,fact,fact_inv,MOD);
                not_included %= MOD;
            }
            if (j>1) { // left
                not_included += binom(h*(j-1),k,fact,fact_inv,MOD);
                not_included %= MOD;
            }
            if (j<w) { // right
                not_included += binom(h*(w-j),k,fact,fact_inv,MOD);
                not_included %= MOD;
            }
            // remove double counts
            if (i>1 && j>1) { // above left
                not_included -= binom((i-1)*(j-1),k,fact,fact_inv,MOD);
                not_included %= MOD;
            }
            if (i>1 && j<w) { // above right
                not_included -= binom((i-1)*(w-j),k,fact,fact_inv,MOD);
                not_included %= MOD;
            }
            if (i<h && j>1) { // below left
                not_included -= binom((h-i)*(j-1),k,fact,fact_inv,MOD);
                not_included %= MOD;
            }
            if (i<h && j<w) { // below right
                not_included -= binom((h-i)*(w-j),k,fact,fact_inv,MOD);
                not_included %= MOD;
            }
            cum += ((possible_combs-not_included+MOD)%MOD);
            cum %= MOD;
        }
    }
    auto exp_val = (cum*bin_pow(possible_combs,MOD-2,MOD))%MOD;
    cout << exp_val << '\n';

    return 0;
}

