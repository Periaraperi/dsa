#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*

Ex from CSES

You are given an array that contains each number between 1 - n exactly once.
Your task is to collect the numbers from 1 to n in increasing order.
On each round, you go through the array from left to right and collect as many numbers as possible.
Given m operations that swap two numbers in the array, your task is to report the number or rounds after each operation.


code is very ugly, need to implement in a more elegant way!!!!

*/

int upd(pair<int,int> pOld,pair<int,int> pNew)
{
    int d = 0;

    if(pOld.first  ==-1 && pNew.first  == 1) --d;
    if(pOld.first  == 1 && pNew.first  ==-1) ++d;
    if(pOld.second ==-1 && pNew.second == 1) --d;
    if(pOld.second == 1 && pNew.second ==-1) ++d;

    return d;
}

pair<int,int> check(int num,vector<pair<int,int>> &v)
{
    int l = 0,r = 0;
    if(num-1!=0)
    {
        if(v[num].second>v[num-1].second) l = 1;
        else                l = -1;
    }
    if(num+1!=v.size())
    {
        if(v[num].second<v[num+1].second) r = 1;
        else                r = -1;
    }
    return {l,r};
}

int main()
{
    int n,m; cin >> n >> m;
    vector<int> vec(n+1);
    vector<pair<int,int>> v(n+1);
    for(int i=1; i<=n; ++i)
    {
        cin >> v[i].first;
        v[i].second = i;
        vec[i] = v[i].first;
    }
    sort(v.begin(),v.end());

    int ans = 1;
    for(int i=2; i<=n; ++i)
        if(v[i].second<v[i-1].second)
            ++ans;

    while(m--)
    {
        int a,b; cin >> a >> b;

        pair<int,int> pOld1,pOld2,pNew1,pNew2;
        pOld1 = check(vec[a],v);
        pOld2 = check(vec[b],v);

        int tmp = v[vec[a]].second;
        v[vec[a]].second = v[vec[b]].second;
        v[vec[b]].second = tmp;

        pNew1 = check(vec[a],v);
        pNew2 = check(vec[b],v);

        ans += upd(pOld1,pNew1);
        ans += upd(pOld2,pNew2);

        if(abs(vec[a]-vec[b])==1) // if swapped values are same we double counted in upd so modify ans
        {
            if(vec[a]>vec[b])
            {
                if(pOld1.first==-1 && pNew1.first==1) ++ans;
                if(pOld1.first==1 && pNew1.first==-1) --ans;
            }
            else
            {
                if(pOld1.second==-1 && pNew1.second==1) ++ans;
                if(pOld1.second==1 && pNew1.second==-1) --ans;
            }
        }

        cout << ans << '\n';
        swap(vec[a],vec[b]);
    }

}

