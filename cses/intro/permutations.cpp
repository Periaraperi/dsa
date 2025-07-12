#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    vector<int> p; p.reserve(n);
    for (int i{}; i<n/2; ++i) {
        p.emplace_back(i+1);
        p.emplace_back(n-i);
    }

    if (n%2 == 0) {
        p.insert(p.begin(), p.back());
        p.pop_back();
    }
    else {
        p.insert(p.begin(), n/2+1);
    }

    for (const auto& i:p) {
        cout << i << " ";
    }
    cout << '\n';

    return 0;
}

