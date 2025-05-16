#include <bits/stdc++.h>
using namespace std;

int lcs(string string1, string string2) {
    int tam1 = string1.size(), tam2 = string2.size();

    vector<vector<int>> dp(tam1 + 1, vector<int>(tam2 + 1, 0));

    for (int i = 0; i <= tam1; i++) 
        dp[i][0] = i;

    for (int j = 0; j <= tam2; j++)
        dp[0][j] = j;

    for (int i = 1; i <= tam1; i++) {
        for (int j = 1; j <= tam2; j++) {
            if(string1[i - 1] == string2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
                dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
        }
    }
    return dp[tam1][tam2];
}

int main() {
    string string1, string2;

    cin >> string1 >> string2;

    lcs(string1, string2);

    cout << lcs(string1, string2) << endl;
}