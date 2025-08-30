#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
 
using namespace std;

int64_t f(string s) 
{
    reverse(s.begin(), s.end());
    return stoll(s);
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int64_t x, y; cin >> x >> y;
    vector<int64_t> v(10);
    v[0] = x;
    v[1] = y;
    for (int i=2; i<10; ++i) {
        v[i] = f(to_string(v[i-1]+v[i-2]));
    }
    cout << v.back() << '\n';
    return 0;
}

