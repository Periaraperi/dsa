#include <iostream>
#include <string>

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s; std::cin >> s;
    for (const auto& ch:s) {
        if (ch >= '0' && ch <= '9') 
            std::cout << ch;
    }
    std::cout << '\n';

    return 0;
}

