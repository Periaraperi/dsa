#include <iomanip>
#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y; cin >> x >> y;

    int a{};
    int b{};
    vector<vector<bool>> v(13, vector<bool>(13, false));
    for (int i{1}; i<=6; ++i) {
        for (int j{1}; j<=6; ++j) {
            if (i+j >= x && !v[i][j]) {
                ++a;
                v[i][j] = true;
            }
            if (abs(i-j) >= y && !v[i][j]) {
                ++b;
                v[i][j] = true;
            }
        }
    }
    cout << setprecision(15) << (a+b) / 36.0 << '\n';

    return 0;
}

