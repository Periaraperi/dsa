#include <iostream>
#include <vector>
 
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    vector<vector<char>> S(N, vector<char>(N));
    vector<vector<char>> T(N, vector<char>(N));

    for (auto& row:S) {
        for (auto& ch:row) {
            cin >> ch;
        }
    }

    for (auto& row:T) {
        for (auto& ch:row) {
            cin >> ch;
        }
    }

    auto num_of_changes = [N, &T](const vector<vector<char>>& s) {
        int counter {};
        for (int i{}; i<N; ++i) {
            for (int j{}; j<N; ++j) {
                if (s[i][j] != T[i][j]) {
                    ++counter;
                }
            }
        }
        return counter;
    };

    auto rot = [N](vector<vector<char>>& grid) {
        vector<vector<char>> rotated(N, vector<char>(N));
        for (int i{}; i<N; ++i) {
            for (int j{}; j<N; ++j) {
                rotated[j][N-i-1] = grid[i][j];
            }
        }
        grid = rotated;
    };

    int ans{1000000};
    ans = min(ans, num_of_changes(S));

    rot(S);
    ans = min(ans, num_of_changes(S)+1);

    rot(S);
    ans = min(ans, num_of_changes(S)+2);

    rot(S);
    ans = min(ans, num_of_changes(S)+3);

    cout << ans << '\n';
    return 0;
}

