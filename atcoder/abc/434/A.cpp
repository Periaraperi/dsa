#include <iostream>
 
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int w, b; std::cin >> w >> b;
    w *= 1000;
    std::cout << w/b + 1 << '\n';
    return 0;
}

