#include <bits/stdc++.h>
using namespace std;

bool Matrioshka(vector<int>& brinquedos) {
    stack<int> s;
    stack<int> somas;
    somas.push(0);
    
    for (size_t i = 0; i < brinquedos.size(); i++) {
        int brinquedo = brinquedos[i];
        if (brinquedo < 0) {
            s.push(brinquedo);
            somas.push(0);
        } else {
            if (s.empty() || s.top() + brinquedo != 0) {
                return false;
            }
            
            int inicio = s.top();
            s.pop();
            
            int soma_interna = somas.top();
            somas.pop();
            
            if (soma_interna >= -inicio) {
                return false;
            }
            
            somas.top() += -inicio;
        }
    }
    
    return s.empty();
}

int main() {
    string lin;

    while (getline(cin, lin)) {
        stringstream ss(lin);
        vector<int> brinquedos;
        int num;

        while(ss >> num) {
            brinquedos.push_back(num);
        }

        if (Matrioshka(brinquedos)) {
            cout << ":-) Matrioshka!" << endl;
        } else {
            cout << ":-( Try again." << endl;
        }
    }
}