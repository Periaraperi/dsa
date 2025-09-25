#include <iostream>
#include <string>
#include <stack>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    stack<char> stk;
    for (const auto& c:s) {
        if (stk.empty()) stk.push(c);
        else {
            if (c=='(' || c=='[' || c=='<') stk.push(c);
            else if (const auto t {stk.top()}; (c==')' && t=='(') || (c==']' && t=='[') || (c=='>' && t=='<')) stk.pop();
        }
    }
    if (stk.empty()) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

