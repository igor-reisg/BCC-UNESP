#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;

    cin >> n >> x;

    vector<pair<int, int>> array(n);

    for (int i = 0; i < n; i++) {
        cin >> array[i].first;
        array[i].second = i + 1;
    }

    sort(array.begin(), array.end());

    for (int i = 0; i < n; i++) {
        int target = x - array[i].first;
        int left = i + 1, right = n - 1;

        while (left < right) {
            int sum = array[left].first + array[right].first;

            if (sum == target) {
                cout << array[left].second << " " << array[right].second << " " << array[i].second << endl;
                return 0;
            }
            else if (sum > target) {
                right--;
            } else {
                left++;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}