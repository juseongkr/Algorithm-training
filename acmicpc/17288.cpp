#include <iostream>
using namespace std;

int main()
{
	int cnt = 0, ans = 0;
	string s;
	
	cin >> s;
	for (int i=0; i<s.length()-1; ++i) {
		if (s[i+1] - s[i] == 1) {
			cnt++;
		} else {
			if (cnt == 2)
				ans++;
			cnt = 0;
		}
	}
	if (cnt == 2)
		ans++;

	cout << ans << '\n';

	return 0;
}
