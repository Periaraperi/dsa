#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Segment_tree {
public:
    Segment_tree(vector<T>& data) 
        :n((int)data.size()), tn(4*(int)data.size()),
        lo(vector<int>(tn)),
        hi(vector<int>(tn)),
        mn(vector<T>(tn,1))
    {
        init(1,0,n-1,data);
    }
    
    Segment_tree(const Segment_tree&) = delete;
    Segment_tree& operator=(const Segment_tree&) = delete;
 
    void point_update(int pos, T val)
    {
        point_update(1,pos,val); 
    }
 
    T query_min(int l, int r)
    {
        if (l>r) return std::numeric_limits<T>::min();
        return query_min(1,l,r);
    }
 
private:
    int n;
    int tn;
    vector<int> lo,hi;
    vector<T> mn;
    
    void init(int v, int l, int r, const vector<T>& data)
    {
        lo[v] = l;
        hi[v] = r;
        if (l==r) {
            mn[v] = data[l];
            return;
        }
        int m = (l+r)/2;
        init(2*v,l,m,data);
        init(2*v+1,m+1,r,data);
        update_step(v);
    }
    
    void update_step(int v)
    {
        mn[v] = std::min(mn[2*v],mn[2*v+1]);
    }
    
    void point_update(int v, int pos, T val)
    {
        if (lo[v]==hi[v]) {
            mn[v] += val;
            return;
        }
        int m = (lo[v]+hi[v])/2;
        if (pos<=m) {
            point_update(2*v,pos,val);
        } else {
            point_update(2*v+1,pos,val);
        }
        update_step(v);
    }

    T query_min(int v, int l, int r)
    {
        if (lo[v]>r || hi[v]<l) 
            return std::numeric_limits<T>::max();
        if (lo[v]>=l && hi[v]<=r) 
            return mn[v];
        
        T left = query_min(2*v,l,r);
        T right = query_min(2*v+1,l,r);
 
        update_step(v);
 
        return std::min(left,right);
    }
 
};
 
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n,q; cin >> n >> q;
    vector<int> v(n);
    for (auto& i:v)
        cin >> i;
    
    vector<int> v_down(n);
    vector<int> v_up(n);
    for (int i=0; i<n; ++i) {
        v_down[i] = v[i]-i;
        v_up[i] = v[i]+i;
    }
 
    Segment_tree<int> tree_down(v_down);
    Segment_tree<int> tree_up(v_up);
 
    while (q--) {
        int x; cin >> x;
        switch (x) {
            case 1: {
                int k,u; cin >> k >> u;
                --k;
                int val = u-v[k];
                tree_down.point_update(k,val);
                tree_up.point_update(k,val);
                v[k] = u;
                break;
            }
            case 2: {
                int k; cin >> k;
                --k;
                cout << min(tree_down.query_min(0,k)+k,tree_up.query_min(k,n-1)-k) << '\n';
                break;
            }
        }
 
    }
 
    return 0;
}
