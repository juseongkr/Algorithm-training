#include <iostream>
using namespace std;
 
int T;
long long n, k;
 
int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
 
	cin >> T;
	while (T--) {
		string s;
		cin >> n >> k;
 
		if (k == 1) {
			for (int i=0; i<n-2; ++i)
				s += 'a';
			s += 'b';
			s += 'b';
			cout << s << '\n';
			continue;
		}
		for (int i=0; i<n; ++i)
			s += 'a';
 
		long long m = 2;
		while (1) {
			if (m*(m-1)/2 >= k)
				break;
			m++;
		}
 
		s[n-m] = 'b';
		long long cnt = m*(m-1)/2;
		s[n-m+(cnt-k+1)] = 'b';
 
		cout << s << '\n';
	}
 
	return 0;
}
