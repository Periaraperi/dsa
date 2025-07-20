#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;

void create_code(vector<vector<int>>& curr, int n)
{
    vector<vector<int>> code(curr.size()*2, vector<int>(n+1));

    for (int i{}; i<(int)curr.size(); ++i) {
        code[i][0] = 0;
        for (int j{1}; j<n+1; ++j) {
            code[i][j] = curr[i][j-1];
        }
    }
    reverse(curr.begin(), curr.end());
    for (int i{}; i<(int)curr.size(); ++i) {
        code[i+(int)curr.size()][0] = 1;
        for (int j{1}; j<n+1; ++j) {
            code[i+(int)curr.size()][j] = curr[i][j-1];
        }
    }
    curr = code;
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<vector<int>> code {{0}, {1}};
    for (int i{1}; i<n; ++i) {
        create_code(code, i);
    }
    for (const auto& i:code) {
        for (const auto& j:i) {
            cout << j;
        }
        cout << '\n';
    }
    return 0;
}

