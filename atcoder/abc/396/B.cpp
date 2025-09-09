#include <iostream>
#include <stack>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<int> stk;
    for (int i{}; i<100; ++i) stk.push(0);
    int n; cin >> n;
    while (n--) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            stk.push(x);
        }
        else {
            const auto x {stk.top()};
            stk.pop();
            cout << x << '\n';
        }
    }
    return 0;
}

