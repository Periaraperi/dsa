#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool compare1(pair<int,pair<int,int>> x,pair<int,pair<int,int>> y)
{
    if(x.first!=y.first) return (x.first<y.first);
    return (x.second.first>y.second.first);
}

bool compare2(pair<pair<int,int>,pair<int,int>> x,pair<pair<int,int>,pair<int,int>> y)
{
    if(x.first.first!=y.first.first) return (x.first.first<y.first.first);
    if(x.first.second!=y.first.second) return (x.first.second>y.first.second);
    return (x.second.first>y.second.first);
}

void update(vector<int> &fen,int i,int x)
{
    while(i<=fen.size()-1)
    {
        fen[i] += x;
        i += (i&-i);
    }
}

int query(vector<int> &fen,int i)
{
    int sum = 0;
    while(i>0)
    {
        sum += fen[i];
        i -= (i&-i);
    }
    return sum;
}

int main()
{
    int n; cin >> n;
    vector<pair<int,pair<int,int>>> v(n); // {left,right,original index};
    for(int i=0; i<n; ++i)
    {
        cin >> v[i].first >> v[i].second.first;
        v[i].second.second = i+1;
    }
    sort(v.begin(),v.end(),compare1);

    vector<pair<pair<int,int>,pair<int,int>>> vv; // input for fenwick
    for(int i=0; i<n; ++i)
    {
        vv.push_back({{v[i].first,1},{i+1,v[i].second.second}});
        vv.push_back({{v[i].second.first,-1},{i+1,v[i].second.second}});
    }
    sort(vv.begin(),vv.end(),compare2);
//    for(auto i:vv)
//        cout << i.first.first << " " << i.first.second << " " << i.second.first << " " << i.second.second << '\n';

    vector<int> fen(n+1,0);
    vector<int> ans1(n+1),ans2(n+1);

    for(auto i:vv)
    {
        if(i.first.second==-1)
        {
            ans1[i.second.second] += (query(fen,n)-query(fen,i.second.first));
            update(fen,i.second.first,1);
        }
    }
    for(auto &i:fen) i = 0;
    for(auto i:vv)
    {
        if(i.first.second==1) update(fen,i.second.first,1);
        else
        {
            ans2[i.second.second] += query(fen,i.second.first-1);
            update(fen,i.second.first,-1);
        }
    }

    for(int i=1; i<=n; ++i) cout << ans1[i] << " ";
    cout << '\n';
    for(int i=1; i<=n; ++i) cout << ans2[i] << " ";
}

