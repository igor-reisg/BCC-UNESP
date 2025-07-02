#include<bits/stdc++.h>
using namespace std;

#define ll long long
using l=int64_t;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n;
	cin>>n;
	
	while(n--){
		int t;
		cin>>t;

		map<tuple<l,l,l>,l> mp;
		l a, b, c, A{};
		
		cin >> b >> c;
		while(t---2){
			a = b;
			b = c;
			cin >> c;

			A += mp[{a,b,0}]++;
			A += mp[{a,0,c}]++;
			A += mp[{0,b,c}]++;
			A -= mp[{a,b,c}]++ * 3;
		}
		cout << A << '\n';
	}
}
