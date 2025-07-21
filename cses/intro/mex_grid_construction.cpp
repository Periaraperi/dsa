#include <iostream>
#include <set>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector grid(n, vector<int>(n, 0));
    
    for (int i{}; i<n; ++i) {
        for (int j{}; j<n; ++j) {
            set<int> st;
            for (int r{}; r<i; ++r) {
                st.insert(grid[r][j]);
            }
            for (int c{}; c<j; ++c) {
                st.insert(grid[i][c]);
            }
            for (int k{}; k<2*n; ++k) {
                auto it {st.lower_bound(k)};
                if (it == st.end() || *it != k) {
                    grid[i][j] = k;
                    break;
                }
            }
        }
    }

    for (int i{}; i<n; ++i) {
        for (int j{}; j<n; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}

