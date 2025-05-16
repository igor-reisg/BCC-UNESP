#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    stack<int> st;
    int count = 0;
    int max_tam = 0;
    
    cin >> s;
    
    st.push(-1);

    for (unsigned int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } 
        else {
            st.pop();  
            if (!st.empty()) {
                int tam = i - st.top();
                if (tam > max_tam) {
                    max_tam = tam;
                    count = 1;
                } 
                else if (tam == max_tam) {
                    count++;
                }
            } 
            else 
                st.push(i);
        }
    }

    if (max_tam == 0) {
        cout << "0 1" << endl;
    } else {
        cout << max_tam << " " << count << endl;
    }
}
