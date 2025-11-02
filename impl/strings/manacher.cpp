#include <iostream>
#include <vector>
#include <string>
 
using namespace std;

struct manacher {
    vector<int> odd;  // count of palindromes centered at i
    vector<int> even; // count of palindromes centered at i and i-1
    string s;
    int longest_palindrome{};

    explicit manacher(const string& s_)
        :odd(s_.size()), 
         even(s_.size()),
         s(s_)
    {
        int l{1}, r{0};
        int n{(int)s.size()};
        // odd lengthed
        for (int i{}; i<n; ++i) {
            if (i<r) {
                int j {l+r-i};
                if (j-(odd[j]-1) > l) {
                    odd[i] = odd[j];
                }
                else {
                    odd[i] = j-l+1;
                    expand_odd(i, l, r);
                }
            }
            else {
                expand_odd(i, l, r);
            }
        }

        l = 1;
        r = 0;
        // even lengthed
        for (int i{1}; i<n; ++i) {
            if (s[i] == s[i-1]) {
                if (i<r) {
                    int j {l+r-i+1};
                    if (j-even[j] > l) {
                        even[i] = even[j];
                    }
                    else {
                        even[i] = j-l;
                        expand_even(i, l, r);
                    }
                }
                else {
                    expand_even(i, l, r);
                }
            }
        }
        for (int i{}; i<n; ++i) {
            longest_palindrome = max(longest_palindrome, max(2*odd[i]-1, 2*even[i]));
        }
    }

    void expand_odd(int i, int& l, int& r)
    {
        int n = (int)s.size();
        while (i-odd[i]>=0 && i+odd[i]<n && s[i-odd[i]] == s[i+odd[i]]) {
            ++odd[i];
        }
        if (i+odd[i]-1 > r) {
            r = i+odd[i]-1;
            l = i-odd[i]+1;
        }
    }

    void expand_even(int i, int& l, int& r)
    {
        int n = (int)s.size();
        while (i-even[i]-1>=0 && i+even[i]<n && s[i-even[i]-1] == s[i+even[i]]) {
            ++even[i];
        }
        if (i+even[i]-1 > r) {
            r = i+even[i]-1;
            l = i-even[i];
        }
    }
};
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int n {(int)s.size()};
    manacher m{s};
    int l{};
    int max_len{};
    for (int i{}; i<n; ++i) {
        if (i+m.odd[i]-1 == n-1) {
            if (2*m.odd[i]-1 > max_len) {
                max_len = 2*m.odd[i]-1;
                l = i-m.odd[i]+1;
            }
        }
        if (i>0 && i+m.even[i]-1 == n-1) {
            if (2*m.even[i] > max_len) {
                max_len = 2*m.even[i];
                l = i-m.even[i];
            }
        }
    }
    return 0;
}

