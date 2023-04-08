#include <bits/stdc++.h>
 
using namespace std;
 
struct Cell {
    int i,j;
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        int si,sj; cin >> si >> sj;
        int ei,ej; cin >> ei >> ej;
        string dir; cin >> dir;
        string tmp_dir = dir;

        map<string,int> dd = {{"DL",0},{"DR",1},{"UL",2},{"UR",3}};
        vector<vector<vector<bool>>> vis(n,vector<vector<bool>>(m,vector<bool>(4,false)));
        Cell curr = {si,sj};

        bool ok = false;
        int cnt = 0;
        while (1) {
            //cout << "curr: " << curr.i << " " << curr.j << " " << dir << '\n';
            if (curr.i==ei && curr.j==ej) {
                ok = true;
                break;
            }
            if (vis[curr.i-1][curr.j-1][dd[dir]]) {
                break;
            }
            vis[curr.i-1][curr.j-1][dd[dir]] = true;
            if (dir=="DL") {
                ++curr.i;
                --curr.j;
                if (curr.i==n+1 && curr.j==0) {
                    dir = "UR";
                } else if (curr.i==n+1) {
                    dir = "UL";
                } else if (curr.j==0) {
                    dir = "DR";
                }
                if (tmp_dir!=dir) {
                    --curr.i;
                    ++curr.j;
                }
            } else if (dir=="DR") {
                ++curr.i;
                ++curr.j;
                if (curr.i==n+1 && curr.j==m+1) {
                    dir = "UL";
                } else if (curr.i==n+1) {
                    dir = "UR";
                } else if (curr.j==m+1) {
                    dir = "DL";
                }
                if (tmp_dir!=dir) {
                    --curr.i;
                    --curr.j;
                }
            } else if (dir=="UL") {
                --curr.i;
                --curr.j;
                if (curr.i==0 && curr.j==0) {
                    dir = "DR";
                } else if (curr.i==0) {
                    dir = "DL";
                } else if (curr.j==0) {
                    dir = "UR";
                }
                if (tmp_dir!=dir) {
                    ++curr.i;
                    ++curr.j;
                }
            } else if (dir=="UR") {
                --curr.i;
                ++curr.j;
                if (curr.i==0 && curr.j==m+1) {
                    dir = "DL";
                } else if (curr.i==0) {
                    dir = "DR";
                } else if (curr.j==m+1) {
                    dir = "UL";
                }
                if (tmp_dir!=dir) {
                    ++curr.i;
                    --curr.j;
                }
            }

            if (tmp_dir!=dir)
                ++cnt;
            tmp_dir = dir;
        }
        cout << (ok?cnt:-1) << '\n';
    }
    return 0;
}

