#include <iostream>
using namespace std;
 
int T;
 
int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
 
	cin >> T;
	while (T--) {
		string s, t;
		cin >> t;
		int a = 0, b = 0;
		for (int i=0; i<t.length(); ++i) {
			if (t[i] == '0')
				a++;
			else
				b++;
		}
 
		if (a == 0 || b == 0) {
			cout << t << '\n';
			continue;
		}
 
		bool flag = false;
		int k = max(a, b);
		if (t[0] == '0')
			flag = true;
 
		for (int i=0; i<a+b-1; ++i) {
			if (flag)
				s += "01";
			else
				s += "10";
		}
		cout << s << '\n';
	}
 
	return 0;
}
