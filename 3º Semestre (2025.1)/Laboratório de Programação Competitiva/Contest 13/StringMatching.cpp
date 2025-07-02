#include <bits/stdc++.h>
using namespace std;

vector<int> pre(string &s) {
    int n = s.size();
    vector<int> lps(n);
    for (int i = 1; i < n; ++i) {
        int j = lps[i - 1];
        while (j > 0 && s[i] != s[j])
            j = lps[j - 1];
        if (s[i] == s[j])
            j++;
        lps[i] = j;
    }
    return lps;
}

int main() {
    string frase;
    string occur;

    cin >> frase >> occur;

    vector<int> lps = pre(occur);
    int n = frase.size();
    int m = occur.size();
    int count = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        while (j > 0 && frase[i] != occur[j]) {
            j = lps[j - 1];
        }
        if (frase[i] == occur[j])
            j++;
        if (j == m) {
            count++;
            j = lps[j - 1];
        }
    }

    cout << count << endl;
}
