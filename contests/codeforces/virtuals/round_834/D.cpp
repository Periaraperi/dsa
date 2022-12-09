#include <bits/stdc++.h>

using namespace std;

int get_zeros(long long x) 
{
    int zero = 0;
    while (x>0) {
        if (x%10==0) ++zero;
        else break;
        x /= 10;
    }
    return zero;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // pre compute
    vector<vector<int>> vec(10);
    vec[1] = {10};
    vec[2] = {5,10};
    vec[3] = {10};
    vec[4] = {5,10}; 
    vec[5] = {2,4,6,8,10}; 
    vec[6] = {5,10}; 
    vec[7] = {10};
    vec[8] = {5,10}; 
    vec[9] = {10};

    int t = 1; cin >> t;
    while (t--) {
        long long n,m; cin >> n >> m;
        long long nn = n;

        int zeros_to_add = 0;
        while (n%10==0) {
            ++zeros_to_add;
            n/=10;
        }

        long long ans = 0;
        int last_zeros = zeros_to_add;
        int k = n%10;
        for (auto& a:vec[k]) {
            long long b = m;
            while (b%a!=0) --b;
            for (int i=0; i<10000; ++i) {
                auto new_price = n*(b);
                auto num_trailing_zeros = get_zeros(new_price) + zeros_to_add;
                if (num_trailing_zeros>last_zeros) {
                    ans = new_price;
                    last_zeros = num_trailing_zeros;
                } else if (num_trailing_zeros==last_zeros) {
                    ans = max(ans,new_price);
                }
                b -= a;
                if (b<=0) break;
            }
        }
        //cout << "asd" << ans <<'\n';
        for (int i=0; i<zeros_to_add; ++i) ans *= 10;
        cout << ((ans==0) ? nn*m:ans) << '\n';
    }

    return 0;
}