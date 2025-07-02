#include <bits/stdc++.h>
using namespace std;

int main() {
    string frase;
    int palavras = 0;
    bool dentro;

    getline(cin, frase);

    for (char c : frase) {
        if (isalnum(c)) {
            if (!dentro) {
                dentro = true;
                palavras++;
            }
        }
        else
            dentro = false;
    }

    cout << palavras << endl;
}