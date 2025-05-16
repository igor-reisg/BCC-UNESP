#include <bits/stdc++.h>
using namespace std;

int binary_search(int target, vector<int>& vet) {
    int left = 0, right = vet.size() - 1, res = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (vet[mid] >= target) {
            if (vet[mid] == target) {
                res = mid;
            }
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> vet(n);
    for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }

    while (q--) {
        int x;
        cin >> x;
        cout << binary_search(x, vet) << '\n';
    }

}
