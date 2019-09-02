#include <iostream>
using namespace std;
#define MAX 360000

int fail[MAX];
bool a[MAX*2], b[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, t;
	bool ans = false;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t;
		a[t] = true;
	}
	for (int i=0; i<MAX; ++i)
		a[i+MAX] = a[i];

	for (int i=0; i<n; ++i) {
		cin >> t;
		b[t] = true;
	}

	for (int i=1, j=0; i<MAX; ++i) {
		while (j && b[i] != b[j])
			j = fail[j-1];

		if (b[i] == b[j])
			fail[i] = ++j;
	}

	for (int i=0, j=0; i<MAX*2; ++i) {
		while (j && a[i] != b[j])
			j = fail[j-1];

		if (a[i] == b[j]) {
			if (j == MAX-1) {
				ans = true;
				break;
			} else {
				j++;
			}
		}
	}

	if (ans)
		cout << "possible\n";
	else
		cout << "impossible\n";

	return 0;
}
