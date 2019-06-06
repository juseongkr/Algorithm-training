#include <iostream>
using namespace std;

int main()
{
	string s;
	int n, cnt = 0;

	cin >> n >> s;
	for (int i=0; i<n; ++i) {
		if (s[i] == 'S') {
			cnt++;
		} else {
			cnt++;
			i++;
		}
	}
	if (cnt+1 < n)
		cout << cnt+1 << '\n';
	else
		cout << n << '\n';

	return 0;
}
