#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s, r;
	int n;

	cin >> n;
	for (int i=0; i<n; ++i) {
		bool flag = true;
		cin >> s >> r;
		if (s.length() > r.length())
			flag = false;

		int a = 0, b = 0;
		while (1) {
			if (s[a] == r[b]) {
				a++;
				b++;
			} else {
				if (s[a-1] == r[b]) {
					b++;
				} else {
					flag = false;
					break;
				}
			}
			if (a == s.length() && b == r.length())
				break;
		}
	
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	
	return 0;
}
