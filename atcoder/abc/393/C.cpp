#include <iostream>
#include <set>
#include <utility>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    int ans {};
    set<pair<int, int>> st;
    for (int i{}; i<m; ++i) {
        int a, b; cin >> a >> b;
        if (a == b) { 
            ++ans;
            continue;
        }
        if (a>b) swap(a, b);
        if (st.find({a, b}) != st.end()) ++ans;
        else st.insert({a, b});
    }
    cout << ans << '\n';
    return 0;
}

