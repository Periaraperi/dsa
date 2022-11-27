#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n,m,k; cin >> n >> m >> k;
    vector<vector<pair<int,long long>>> graph(n,vector<pair<int,long long>>());
    for (int i=0; i<m; ++i) {
        int a,b; cin >> a >> b;
        long long c; cin >> c;
        graph[--a].push_back({--b,c});
    }

    vector<priority_queue<long long>> distances(n);
    auto comp = [](const pair<int,long long>& a, const pair<int,long long>& b) {return a.second>b.second;};
    priority_queue<pair<int,long long>,vector<pair<int,long long>>,decltype(comp)> pq(comp);
    distances[0].push(0);
    pq.push({0,0});

    while (!pq.empty()) {
        auto v = pq.top();
        pq.pop();
        
        for (auto& u:graph[v.first]) {
            long long new_dis = v.second+u.second;
            // if less then k distances found, just push new distance
            if ((int)distances[u.first].size()<k) {
                distances[u.first].push(new_dis);
                pq.push({u.first,new_dis});
            } else {
                // if new distances is better then worst distance among k distances
                if (new_dis<distances[u.first].top()) { 
                    distances[u.first].pop();
                    distances[u.first].push(new_dis);
                    pq.push({u.first,new_dis});
                }
            }
        }

    }

    vector<long long> ans;
    auto& q = distances[n-1];
    while (!q.empty()) {
        ans.push_back(q.top());
        q.pop();
    }
    reverse(ans.begin(),ans.end());
    for (auto& i:ans) cout << i << " ";
    cout << '\n';

    return 0;
}