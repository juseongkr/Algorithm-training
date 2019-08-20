#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	int ans = 0;

	cin >> s;
	sort(s.begin(), s.end());
	do {
		bool flag = true;
		for (int i=0; i<s.size()-1; ++i)
			if (s[i] == s[i+1])
				flag = false;
		ans += flag;
	} while (next_permutation(s.begin(), s.end()));

	cout << ans << '\n';

	return 0;
}
