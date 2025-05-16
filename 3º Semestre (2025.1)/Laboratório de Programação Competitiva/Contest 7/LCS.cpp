#include <bits/stdc++.h>
using namespace std;

string lcs(string s, string t) {
    int tam1 = s.size(), tam2 = t.size();

    vector<vector<int>> dp (tam1 + 1, vector<int>(tam2 + 1, 0));

    for (int i = 1; i <= tam1; i++) {
        for (int j = 1; j <= tam2; j++) {
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string lcs = "";
    int i = tam1, j = tam2;

    while(i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            lcs += s[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else
            j--;
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    string s, t;

    cin >> s >> t;

    lcs(s, t);

    cout << lcs(s, t) << endl;
}