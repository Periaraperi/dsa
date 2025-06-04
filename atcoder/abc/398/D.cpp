#include <iostream>
#include <set>
#include <string>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, R, C; cin >> N >> R >> C;
    string s; cin >> s;

    int br{}, bc{};
    set<pair<int, int>> st;
    st.insert({br, bc});
    for (const auto& d:s) {
        if (d == 'N') { ++br; ++R; }
        if (d == 'S') { --br; --R; }
        if (d == 'E') { --bc; --C; }
        if (d == 'W') { ++bc; ++C; }

        if (st.find({br, bc}) == st.end()) {
            st.insert({br, bc});
        }

        if (st.find({R, C}) != st.end()) cout << 1;
        else cout << 0;
    }
    cout << '\n';

    return 0;
}

