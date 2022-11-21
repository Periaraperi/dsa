#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Segment_tree {
public:
    Segment_tree(const vector<T>& data) 
        :n((int)data.size()), tree_size(4*(int)data.size()),
        lo(vector<int>(tree_size)),
        hi(vector<int>(tree_size)),
        max_subarray(vector<T>(tree_size)),
        sum(vector<T>(tree_size)),
        max_prefix(vector<T>(tree_size)),
        max_suffix(vector<T>(tree_size))
    {
        init(1,0,n-1,data);
    }

    void point_update(int pos, int val)
    {
        point_update(1,pos,val);
    }

    T query()
    {
        return query(1);
    }


private:
    int n,tree_size;
    vector<int> lo,hi;
    vector<T> max_subarray;
    vector<T> sum;
    vector<T> max_prefix;
    vector<T> max_suffix;

    void init(int v, int l, int r, const vector<T>& data)
    {
        lo[v] = l;
        hi[v] = r;
        if (lo[v]==hi[v]) {
            max_subarray[v] = sum[v] = max_prefix[v] = max_suffix[v] = data[l];
            return;
        }
        int m = (lo[v]+hi[v])/2;
        init(2*v,l,m,data);
        init(2*v+1,m+1,r,data);
        merge(v);
    }

    void merge(int v)
    {
        max_subarray[v] = std::max(std::max(max_subarray[2*v],max_subarray[2*v+1]),max_suffix[2*v]+max_prefix[2*v+1]);
        sum[v] = sum[2*v]+sum[2*v+1];
        max_prefix[v] = std::max(max_prefix[2*v],sum[2*v]+max_prefix[2*v+1]);
        max_suffix[v] = std::max(max_suffix[2*v+1],sum[2*v+1]+max_suffix[2*v]);
    }

    void point_update(int v, int pos, T val)
    {
        if (lo[v]==hi[v]) {
            sum[v] += val;
            max_subarray[v] += val;
            max_prefix[v] += val;
            max_suffix[v] += val;
            return;
        }
        int m = (lo[v]+hi[v])/2;
        if (pos<=m) {
            point_update(2*v,pos,val);
        } else {
            point_update(2*v+1,pos,val); 
        }
        merge(v);
    }

    T query(int v)
    {
        // we are only interested in root
        return max_subarray[v]; 
    }

};


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n,m; cin >> n >> m;
    vector<long long> v(n);
    for (auto& i:v) cin >> i;
    Segment_tree<long long> tree(v);
    
    while (m--) {
        int k, u; cin >> k >> u;
        --k;
        long long val = u-v[k];
        tree.point_update(k,val);
        v[k] = u;
        cout << std::max(tree.query(),0LL)<< '\n';
    }

}

