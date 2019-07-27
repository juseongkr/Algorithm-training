#include <iostream>
using namespace std;
#define MAX 100001

int fail[MAX];

int main()
{
	string a, b;

	cin >> a >> b;
	b += b;
	for (int i=1, j=0; i<a.length(); ++i) {
		while (j && a[i] != a[j])
			j = fail[j-1];

		if (a[i] == a[j])
			fail[i] = ++j;
	}

	int ans = 0;
	for (int i=0, j=0; i<b.length()-1; ++i) {
		while (j && b[i] != a[j])
			j = fail[j-1];

		if (b[i] == a[j]) {
			if (j == a.length()-1) {
				j = fail[j];
				ans++;
			} else {
				j++;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
