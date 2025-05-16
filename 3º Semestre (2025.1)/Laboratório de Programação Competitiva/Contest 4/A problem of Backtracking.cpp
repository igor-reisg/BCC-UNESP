#include <bits/stdc++.h>
using namespace std;

bool solve(const vector<long long>& nums, vector<bool>& usado, vector<int>& permutation, long long k, int pos, long long soma_atual) {
    if (pos == 10) {
        return soma_atual <= k;
    }

    for (int i = 0; i <= 9; i++) {
        if (usado[i]) continue;
        
        long long soma_nova = soma_atual + (long long)i * nums[pos];
        
        if (soma_nova > k) continue;
        
        usado[i] = true;
        permutation[pos] = i;
        
        if (solve(nums, usado, permutation, k, pos + 1, soma_nova)) {
            return true;
        }
        usado[i] = false;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        vector<long long> nums(10);
        for (int i = 0; i < 10; i++) {
            cin >> nums[i];
        }
        
        long long k;
        cin >> k;
        
        vector<bool> usado(10, false);
        vector<int> permutation(10);
        
        if (solve(nums, usado, permutation, k, 0, 0)) {
            for (int i = 0; i < 10; i++) {
                cout << permutation[i];
                if (i < 9) cout << " ";
            }
            cout << endl;
        } 
        else 
            cout << "-1" << endl;
    }
}