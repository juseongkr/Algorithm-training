#include <iostream>
using namespace std;

int main()
{
	string s;
	int n, x, y, cnt = 0;

	cin >> n >> x >> y >> s;
	for (int i=n-1; i>n-1-x; i--) {
		if (i == n-1-y) {
			if (s[i] == '0')
				cnt++;
		} else {
			if (s[i] == '1')
				cnt++;
		}
	}
	cout << cnt << '\n';

	return 0;
}
