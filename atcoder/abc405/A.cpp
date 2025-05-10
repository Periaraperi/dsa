#include <iostream>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int R, X; cin >> R >> X;

    auto is_rated_div1 = [](int r) {
        return r>=1600 && r<=2999;
    };

    auto is_rated_div2 = [](int r) {
        return r>=1200 && r<=2399;
    };

    if (X == 1) {
        if (is_rated_div1(R)) cout << "Yes\n";
        else cout << "No\n";
    }
    else {
        if (is_rated_div2(R)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

