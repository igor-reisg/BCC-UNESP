#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    
    int n = s.length();
    s += s;
    
    int i = 0, j = 1;
    
    while (i < n && j < n) {
        int k = 0;
        
        while (k < n && s[i + k] == s[j + k]) {
            k++;
        }
        
        if (k == n) break;
        
        if (s[i + k] > s[j + k]) {
            i += k + 1;
            if (i <= j) i = j + 1;
        } 
        else {
            j += k + 1;
            if (j <= i) j = i + 1;
        }
    }
    
    int inicio = min(i, j);
    
    for (int i = 0; i < n; i++) {
        cout << s[inicio + i];
    }
    cout << endl;
}