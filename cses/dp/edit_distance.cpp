#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

int main()
{
    string a,b; cin >> a >> b;
    int len_a = a.size();
    int len_b = b.size();
    vector<vector<int>> dp(len_a+1,vector<int>(len_b+1,0));
    for(int i=0; i<=len_a; ++i) 
        dp[i][0] = i;   
    for(int i=0; i<=len_b; ++i)
        dp[0][i] = i;

    for(int i=1; i<=len_a; ++i) {
        for(int j=1; j<=len_b; ++j) {
            if(a[i-1]==b[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
            }
        }
    }

    cout << dp[len_a][len_b] << '\n';
    return 0;
}