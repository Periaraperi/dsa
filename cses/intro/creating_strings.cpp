#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
 
using namespace std;

void permute(const string& s, string& curr_perm, vector<bool>& used, set<string>& st)
{
    if (curr_perm.size() == s.size()) {
        st.insert(curr_perm);
        return;
    }
    for (int i{}; i<(int)s.size(); ++i) {
        if (used[i]) continue;
        curr_perm.push_back(s[i]);
        used[i] = true;
        permute(s, curr_perm, used, st);
        used[i] = false;
        curr_perm.pop_back();
    }
}

void g(string& s)
{
    set<string> st;
    string curr_perm; curr_perm.reserve(s.size());
    vector<bool> used(s.size(), false);
    permute(s, curr_perm, used, st);
    cout << st.size() << '\n';
    for (const auto& str:st) {
        cout << str << '\n';
    }
}

// using next_permutation
void f(string& s)
{
    set<string> st;
    sort(s.begin(), s.end());
    do {
        st.insert(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << st.size() << '\n';
    for (const auto& str:st) {
        cout << str << '\n';
    }
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    //f(s);
    g(s);
    return 0;
}

