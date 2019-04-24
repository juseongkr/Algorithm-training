#include <iostream>
#include <climits>
using namespace std;

int main()
{
	string a, b;
	int ans = INT_MAX;

	cin >> a >> b;
	int sub = b.length() - a.length();
	for (int i=0; i<=sub; ++i) {
		int cnt = 0;
		for (int j=0; j<a.length(); ++j)
			if (a[j] != b[j+i])
				cnt++;
		ans = min(ans, cnt);
	}

	cout << ans << '\n';

	return 0;
}
