#include <iostream>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin >> s;
    int n {(int)s.size()};

    int ans {1 + (s[n-1]-'0')};
    int increments {s[n-1]-'0'};
    for (int i{n-2}; i>=0; --i) {
        int curr {s[i]-'0'};
        int x {((curr - increments) + 10*increments)%10}; // + 10*increments to make number positive.
        ans += (x+1);
        increments += x;
    }
    cout << ans << '\n';
    return 0;
}

