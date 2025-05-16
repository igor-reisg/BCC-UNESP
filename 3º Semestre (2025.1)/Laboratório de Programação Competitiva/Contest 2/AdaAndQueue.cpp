#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;

    cin >> q;

    deque<int> dq;
    int reversed = 0;

    for (int i = 0; i < q; i++) {
        string comando;
        cin >> comando;

        if (comando == "toFront") {
            int n;
            cin >> n;
            if (reversed) {
                dq.push_back(n);
            } else {
                dq.push_front(n);
            }
        }
        else if (comando == "push_back") {
            int n;
            cin >> n;
            if (reversed) {
                dq.push_front(n);
            } else {
                dq.push_back(n);
            }
        }
        else if (comando == "front") {
            if(dq.empty()) {
                cout << "No job for Ada?" << endl;
            } else {
                if (reversed) {
                    cout << dq.back() << endl;
                    dq.pop_back();
                } else {
                    cout << dq.front() << endl;
                    dq.pop_front();
                }
            }
        }
        else if (comando == "back") {
            if(dq.empty()) {
                cout << "No job for Ada?" << endl;
            } else {
                if (reversed) {
                    cout << dq.front() << endl;
                    dq.pop_front();
                } else {
                    cout << dq.back() << endl;
                    dq.pop_back();
                }
            }
        }
        else if (comando == "reverse") {
            reversed = !reversed;
        }
    }
}