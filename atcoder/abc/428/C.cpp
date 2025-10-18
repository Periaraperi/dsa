#include <iostream>
#include <stack>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q{1}; cin >> q;
    struct info {
        char c;
        int level;
    };
    stack<info> s;
    int cnt {};
    while (q--) {
        int x; cin >> x;
        if (x == 1) {
            char ch; cin >> ch;
            if (s.empty()) {
                if (ch == ')') s.push({ch, 0});
                else s.push({ch, 1});
            }
            else {
                if (ch == ')') {
                    if (s.top().c == ')') s.push({ch, s.top().level-1});
                    else s.push({ch, s.top().level});
                }
                else {
                    if (s.top().c == '(') s.push({ch, s.top().level+1});
                    else s.push({ch, s.top().level});
                }
            }
            if (s.top().level < 1) ++cnt;
        }
        else {
            if (!s.empty()) {
                if (s.top().level < 1) --cnt;
                s.pop();
            }
        }
        if (s.empty()) {
            cout << "Yes\n";
            continue;
        }

        if (cnt != 0 || (s.size()%2) == 1 || s.top().level != 1) {
            cout << "No\n";
        }
        else {
            cout << "Yes\n";
        }
    }
    return 0;
}

