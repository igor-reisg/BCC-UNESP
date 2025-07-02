#include <bits/stdc++.h>
using namespace std;

const int MAX_DEGRAUS = 1e6 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> D(N);
    vector<bool> on(MAX_DEGRAUS, false);
    unordered_map<int, int> contDiv;
    
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
    }
    
    for (int i = 0; i < N; ++i) {
        int d = D[i];
        bool ligar = !on[d];
        on[d] = ligar;
        int lim = sqrt(d);
        
        for (int k = 1; k <= lim; ++k) {
            if (d % k == 0) {
                int div1 = k;
                int div2 = d / k;
                
                if (div1 > 1)
                    contDiv[div1] += ligar ? 1 : -1;
                if (div2 > 1 && div2 != div1)
                    contDiv[div2] += ligar ? 1 : -1;
            }
        }

        int maxCont = 0;
        for (auto &[k, count] : contDiv) {
            if (count > maxCont)
                maxCont = count;
        }

        cout << maxCont << '\n';
    }
}
