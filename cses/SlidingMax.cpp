#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,k; cin >> n >> k;
    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin >> v[i];

    deque<pair<int,int>> chain;
    chain.push_back({v[0],0});
    for(int i=1; i<k; ++i)
    {
        while(!chain.empty() && v[i]>=chain.back().first) chain.pop_back();
        chain.push_back({v[i],i});
    }
    cout << chain.front().first << " ";
    for(int i=k; i<n; ++i)
    {
        if(chain.front().second<i-k+1) chain.pop_front();
        while(!chain.empty() && v[i]>=chain.back().first) chain.pop_back();
        chain.push_back({v[i],i});
        cout << chain.front().first << " ";
    }

}
