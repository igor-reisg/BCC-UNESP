#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        
        int index = (s[0] - 'a') * 25;
        
        for (char c = 'a'; c < s[1]; c++) {
            if (c != s[0]) index++;
        }
        
        index++;
        
        cout << index << '\n';
    }
}
