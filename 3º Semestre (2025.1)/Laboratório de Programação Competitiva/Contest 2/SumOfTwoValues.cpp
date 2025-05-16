#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;

    cin >> n >> x;

    vector<pair<int, int>> array(n);

    for (int i =0; i < n; i++) {
        cin >> array[i].first;
        array[i].second = i + 1;
    }

    sort(array.begin(), array.end());

    int left = 0, right = n - 1;

    while (left < right) {
        int sum = array[left].first + array[right].first;

        if (sum == x) {
            cout << array[right].second << " " << array[left].second << endl;
            return 0;
        }
        else if (sum < x) {
            left++;
        }
        else
            right--;
    }

    cout << "IMPOSSIBLE" << endl;
}
