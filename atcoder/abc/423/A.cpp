#include <iostream>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int64_t n, c; cin >> n >> c;
    cout << (n / (1000+c)) * 1000 << '\n';
    return 0;
}

