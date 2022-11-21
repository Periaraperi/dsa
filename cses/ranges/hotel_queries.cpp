#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

void build(int v, int nl, int nr, vector<int>& tree, const vector<int>& arr)
{
    if(nl==nr) {
        tree[v] = arr[nl];
    } else {
        int m = (nl+nr)/2;
        build(2*v,nl,m,tree,arr);
        build(2*v+1,m+1,nr,tree,arr);
        tree[v] = max(tree[2*v],tree[2*v+1]);
    }
}

int query(int v, int nl, int nr, int val, vector<int>& tree)
{
    if(val>tree[v]) {
        return 0;
    }

    if(nl==nr) {
        tree[v] -= val;
        return (nl+1);
    }

    int m = (nl+nr)/2;
    int left = query(2*v,nl,m,val,tree);
    if(left!=0) {
        tree[v] = max(tree[2*v],tree[2*v+1]);
        return left;
    } else {
        int right = query(2*v+1,m+1,nr,val,tree);
        if(right!=0) {
            tree[v] = max(tree[2*v],tree[2*v+1]);
            return right;
        }
    }
    return 0;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m; cin >> n >> m;
    vector<int> hotels(n), groups(m);
    for(auto& h:hotels) cin >> h;
    for(auto& g:groups) cin >> g;

    vector<int> tree(4*n);
    build(1,0,n-1,tree,hotels);

    for(int i=0; i<m; ++i) {
        cout << query(1,0,n-1,groups[i],tree) << " ";
    }
    

    return 0;
}
