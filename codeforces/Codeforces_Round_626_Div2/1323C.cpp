#include <iostream>
#include <stack>
using namespace std;
 
int n, sum;
string s;
 
int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
 
	cin >> n >> s;
	for (int i=0; i<n; ++i) {
		if (s[i] == '(')
			sum++;
		else
			sum--;
	}
 
	if (sum) {
		cout << "-1\n";
	} else {
		int idx = -1, prev = 0, ans = 0;
		for (int i=0; i<n; ++i) {
			prev = sum;
			if (s[i] == '(')
				sum++;
			else
				sum--;

			if (sum == 0) {
				if (prev < 0)
					ans += (i - idx);
				idx = i;
			}
		}
		cout << ans << '\n';
	}
 
	return 0;
}
