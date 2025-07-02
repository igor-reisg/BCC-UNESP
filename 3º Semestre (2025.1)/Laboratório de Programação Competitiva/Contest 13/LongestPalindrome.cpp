#include <bits/stdc++.h>
using namespace std;

string preprocess(string& s) {
    string t = "#";
    for (char c : s) {
        t += c;
        t += '#';
    }
    return t;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    string t = preprocess(s);
    int n = t.size();
    vector<int> p(n, 0);
    int center = 0, right = 0;
    int max_len = 0, max_center = 0;

    for(int i = 0; i < n; ++i){
        int mirror = 2 * center - i;
        if (i < right)
            p[i] = min(right - i, p[mirror]);

        while(i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t[i - p[i] - 1] == t[i + p[i] + 1])
            ++p[i];

        if(i + p[i] > right){
            center = i;
            right = i + p[i];
        }

        if(p[i] > max_len){
            max_len = p[i];
            max_center = i;
        }
    }

    int start = (max_center - max_len) / 2;
    cout << s.substr(start, max_len) << "\n";

}