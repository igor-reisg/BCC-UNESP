#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int total = 0;

    cin >> n;
    vector<int> students(n);

    for (int i = 0; i < n; i++) {
        cin >> students[i];
    }

    sort(students.begin(), students.end());

    for (int i = 0; i < n; i += 2) {
        total += students[i + 1] - students[i]; 
    }

    cout << total << endl;
}