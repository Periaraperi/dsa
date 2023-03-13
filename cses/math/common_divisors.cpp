#include <bits/stdc++.h>
 
using namespace std;
 
int solution1() // O(n*sqrt(max(xi)))
{
    int n; cin >> n;
    vector<int> v(n);
    for (auto& i:v) cin >> i;
    int mx_elem = *max_element(v.begin(),v.end());
    vector<int> divisor_count(mx_elem+1);
    vector<int> vis(mx_elem+1);
    for (const auto x:v) {
        if (vis[x]>=2) continue;
        ++vis[x];
        for (int i=1; i*i<=x; ++i) {
            if (x%i==0) {
                ++divisor_count[i];
                if (x/i!=i) ++divisor_count[x/i];
            }
        }
    }
    int g = 1;
    for (int i=mx_elem; i>=1; --i) {
        if (divisor_count[i]>=2) {
            g = i;
            break;
        }
    }
    return g;
}

int solution2() // O(nlog(n)) -- better solution
{
    int n; cin >> n;
    vector<int> v(n);
    for (auto& i:v) cin >> i;
    int mx_elem = *max_element(v.begin(),v.end());
    vector<int> fix(mx_elem+1);
    for (const auto i:v) ++fix[i];
    for (int g=mx_elem; g>=1; --g) { // loop through all possible gcds
        // check if 2 elements in v are divisible by g
        int cnt = 0; // count how many elements are multiple of g in v
        for (int i=g; i<=mx_elem; i+=g) { // if g divides v[j] ==> v[j] must be multiple of g
            cnt += fix[i];
            if (cnt>=2) return g;
        } 
    }
    return 1; 
}


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        cout << solution2() << '\n';
    }
    return 0;
}

