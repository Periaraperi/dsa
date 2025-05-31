#include <iostream>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s; cin >> n >> s;
    int last {};
    for (int i{}; i<n; ++i) {
        int a; cin >> a;
        if (last + s + 0.5 <= (double) a) {
            cout << "No\n";
            return 0;
        }
        last = a;
    }
    cout << "Yes\n";

    return 0;
}

