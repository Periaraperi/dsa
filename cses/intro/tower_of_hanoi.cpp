#include <iostream>
#include <vector>
 
using namespace std;

struct Move {
    int from;
    int to;
};

void hanoi(int n, int s, int m, int e, vector<Move>& moves)
{
    if (n == 1) {
        moves.push_back({s, e});
        return;
    }
    hanoi(n-1, s, e, m, moves);
    moves.push_back({s, e});
    hanoi(n-1, m, s, e, moves);
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<Move> moves;
    hanoi(n, 1, 2, 3, moves);
    cout << moves.size() << '\n';
    for (const auto& [from, to]:moves) {
        cout << from << " " << to << '\n';
    }
    return 0;
}

