#include <bits/stdc++.h>

using namespace std;

struct Wavelet_Tree {
    struct Node {
        Node(int low_val, int high_val)
            :lo(low_val),hi(high_val),left(nullptr),right(nullptr)
        {}
        int lo,hi; // reprsents values, not indices
        vector<int> b; // tells how many elems are in the left subtree in prefix i
        Node* left;
        Node* right;

        friend std::ostream& operator<<(std::ostream& os, const Node& node)
        {
            os << "range: " << node.lo << " " << node.hi << '\n';
            os << "b array: ";
            for (auto i:node.b) os << i << " ";
            return os;
        }
    };

    Node* root;

    using Iterator = std::vector<int>::iterator;

    Wavelet_Tree(vector<int>& data)
        :root(nullptr)
    {
        assert(!data.empty());
        auto data_copy = data;
        root = init(data_copy.begin(),data_copy.end(),1,*max_element(data_copy.begin(),data_copy.end()),data_copy);
    }

    
    // [l,r) range
    Node* init(Iterator l, Iterator r, int x, int y, vector<int>& data)
    {
        auto node = new Node(x,y);
        if (node->lo==node->hi) {
            node->b.push_back(0);
            for (auto it=l; it!=r; ++it)
                node->b.push_back(1+node->b.back());
            return node;
        }
        
        int m = (x+y)/2;
        auto is_less = [m](int elem) -> bool {
            return elem<=m;
        };

        node->b.reserve(r-l+1);
        node->b.push_back(0);
        for (auto it=l; it!=r; ++it) {
            node->b.push_back(is_less(*it)+node->b.back());
        }

        auto p = std::stable_partition(l,r,is_less);
        node->left = init(l,p,x,m,data);
        node->right = init(p,r,m+1,y,data);
        return node;
    }

    int kth_min(Node* node, int l, int r, int k)
    {
        if (l>r || r-l+1<k) return -1;
        if (node->lo==node->hi) return node->lo;
        int in_left = node->b[r]-node->b[l-1];
        int ll = node->b[l-1];
        int rr = node->b[r];
        if (k<=in_left) return kth_min(node->left,ll+1,rr,k);
        return kth_min(node->right,l-ll,r-rr,k-in_left);
    }

    ~Wavelet_Tree()
    {
        if (root!=nullptr)
            clean(root);
    }

    void clean(Node* node) 
    {
        if (node->left==nullptr && node->right==nullptr) {
            delete node;
            return;
        }
        if (node->left!=nullptr)
            clean(node->left);
        if (node->right!=nullptr)
            clean(node->right);
        delete node;
    }

   void print(Node* node)
   {
       if (node==nullptr) return;
       cout << *node << '\n';
       print(node->left);
       print(node->right);
   }

};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
		int n,m; cin >> n >> m;
		vector<pair<int,int>> segs;
		map<pair<int,int>,bool> vis;
		for (int i=0; i<m; ++i) {
			int l,r; cin >> l >> r;
			--l, --r;
			if (vis[{l,r}]==false) {
				segs.push_back({l,r});
				vis[{l,r}] = true;
			}
		}
		int q; cin >> q;
		int INF = n+1;
		vector<int> a(n,INF);
		for (int i=0; i<q; ++i) {
			int x; cin >> x; --x;
			a[x] = i+1;
		}

        Wavelet_Tree tree(a);
        //tree.print(tree.root);

        int ans = INF;
        for (auto [l,r]:segs) {
            int k = (r-l+1)/2 + 1;
            ans = min(ans,tree.kth_min(tree.root,l+1,r+1,k));
        }
		if (ans==INF) cout << -1 << '\n';
        else cout << ans << '\n';
    }
    return 0;
}

