#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    long long t, x;
    stack<char>st;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> x;
        if (!st.empty()) {
            if (x % 2 == st.top())
                st.pop();
            else 
                st.push(x % 2);
        }
        else 
            st.push(x % 2);
    }
    
    if (st.size() <= 1)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
    
    return 0;
}