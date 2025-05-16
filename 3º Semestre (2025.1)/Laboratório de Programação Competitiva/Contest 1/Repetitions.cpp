#include <bits/stdc++.h>
using namespace std;

int main() {
    string dna;
    cin >> dna;

    int max = 1, rep = 1;

    for (unsigned int i = 1; i < dna.length(); i++) {
        if (dna[i] == dna[i - 1]) {
            rep++;
        } else {
            rep = 1;
        }

        if (rep > max) {
            max = rep;
        }
    }

    cout << max << endl;
    
    return 0;
}
