#include <bits/stdc++.h>
using namespace std;

int main() {
    string manchete;
    string frase;
    map<char, int> map;
    bool res = true;
    


    getline(cin, manchete);
    getline(cin, frase);

    for (char c : manchete) {
        if (isalpha(c)) {
            map[c]++;
        }
    }

    for (char c : frase) {
        if (isalnum(c)) {
            if (map[c] > 0) {
                map[c]--;
            }
            else {
                res = false;
                break;
            }
        }
    }

    cout << (res ? "YES" : "NO") << endl;
}