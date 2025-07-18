#include <iostream>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;

    /*
       for k >= 4 pattern is the following:
       2 3 4 4 ... 4 4 3 2
       2 3 4 4 ... 4 4 3 2
       2 3 4 4 ... 4 4 3 2
       ... k-2 layers ....
       1 1 2 2 ... 2 2 1 1
       0 0 0 0 ... 0 0 0 0
       
       below formula works for k = {1, 2, 3} as well.
     */
    
    for (int64_t k{1}; k<=n; ++k) {
        int64_t c {k*k};
        cout << (c*(c-1)/2) - (k-2)*2*2 - (k-2)*2*3 - (k-2)*(k-4)*4 - 4 - (k-4)*2 << '\n';
    }

    return 0;
}
