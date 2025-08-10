#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
 
using namespace std;

struct Node {
    string s{};
    int prev{-1};
};
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;

    vector<Node> strs; strs.reserve(q);
    vector<int> ptrs(n+1, -1);

    while (q--) {
        int x; cin >> x;
        if (x == 1) {
            int p; cin >> p;
            ptrs[p] = ptrs[0];
        }
        else if (x == 2) {
            int p; string s; cin >> p >> s;
            strs.push_back({s, ptrs[p]});
            ptrs[p] = (int)strs.size()-1;
        }
        else {
            int p; cin >> p;
            ptrs[0] = ptrs[p];
        }
    }

    vector<string> ans_strs;
    for (int i{ptrs[0]}; i != -1; i = strs[i].prev) {
        ans_strs.push_back(strs[i].s);
    }
    reverse(ans_strs.begin(), ans_strs.end());
    for (const auto& s:ans_strs) {
        cout << s;
    }
    cout << '\n';
    return 0;
}

