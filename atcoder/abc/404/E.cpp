#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    vector<int> c(N-1);
    vector<int> a(N-1);

    for (auto& i:c) {cin >> i;}
    for (auto& i:a) {cin >> i;}

    c.insert(c.begin(), 0);
    a.insert(a.begin(), 0);
    
    int ans {};
    for (int i{(int)a.size()-1}; i>0; --i) {
        if (a[i] == 0) continue;
        int k {-1};
        for (int j{1}; j<=c[i]; ++j) {
            if (a[i-j] > 0) {
                k = i-j;
            }
        }
        if (k == -1) { // all were empty
            int mn {1000000};
            for (int j{1}; j<=c[i]; ++j) {
                if ((i-j)-c[i-j] <= mn) {
                    k = i-j;
                    mn = (i-j)-c[i-j];
                }
            }
        }
        a[k] += a[i];
        ++ans;
    }
    
    cout << ans << '\n';
    return 0;
}

