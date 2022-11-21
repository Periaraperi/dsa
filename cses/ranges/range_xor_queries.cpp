#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

void build(int v, int nl, int nr, vector<int>& tree, const vector<int>& arr)
{
    if(nl==nr) {
        tree[v] = arr[nl];
        return;
    }

    int m = (nl+nr)/2;
    build(2*v,nl,m,tree,arr);
    build(2*v+1,m+1,nr,tree,arr);
    tree[v] = tree[2*v]^tree[2*v+1];
}

int query(int v, int nl, int nr, int l, int r, const vector<int>& tree)
{
    if(nl>r || nr<l)
        return 0;
    if(nl>=l && nr<=r)
        return tree[v];

    int m = (nl+nr)/2;
    return query(2*v,nl,m,l,r,tree)^query(2*v+1,m+1,nr,l,r,tree);    
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,t; cin >> n >> t;
    vector<int> seg_tree(4*n), arr(n);
    for(auto& a:arr)
        cin >> a;
    build(1,0,n-1,seg_tree,arr);

    while(t--) {
        int a,b; cin >> a >> b;
        --a;
        --b;
        cout << query(1,0,n-1,a,b,seg_tree) << '\n';
    }
    return 0;
}


