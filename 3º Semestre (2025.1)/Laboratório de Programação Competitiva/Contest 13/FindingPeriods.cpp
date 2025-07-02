#include <bits/stdc++.h>
using namespace std;

vector<int> pre(string& s) {
    int n = s.size();
    vector<int> lps(n);
    
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        
        while (j > 0 && s[i] != s[j])
            j = lps[j - 1];
        
        if (s[i] == s[j]) j++;
        
        lps[i] = j;
    }
    return lps;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;

    int n = s.length();
    vector<int> lps = pre(s);
    vector<int> periodos;
    
    int j = lps[n - 1];
    while (j > 0) {
        int tamPeriodo = n - j;
        periodos.push_back(tamPeriodo);
        j = lps[j - 1];
    }
    
    periodos.push_back(n);
    
    sort(periodos.begin(), periodos.end());
    
    for (unsigned int i = 0; i < periodos.size(); i++) {
        if (i > 0) cout << " ";
        cout << periodos[i];
    }
    cout << endl;
}