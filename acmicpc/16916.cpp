#include <iostream>
using namespace std;
#define MAX 1000001

int fail[MAX];

int main()
{
	int ans = 0;
	string a, b;

	cin >> a >> b;
	for (int i=1, j=0; i<b.length(); ++i) {
		while (j && b[i] != b[j])
			j = fail[j-1];

		if (b[i] == b[j])
			fail[i] = ++j;
	}

	for (int i=0, j=0; i<a.length(); ++i) {
		while (j && a[i] != b[j])
			j = fail[j-1];

		if (a[i] == b[j]) {
			if (j == b.length()-1) {
				j = fail[j];
				ans = 1;
			} else {
				j++;
			}
		}
	}
	cout << ans;
	
	return 0;
}
