#include <iostream>
using namespace std;
#define MAX 1000001

int n;
string s;
int fail[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i=1, j=0; i<=s.length(); ++i) {
		while (j && s[i] != s[j])
			j = fail[j-1];

		if (s[i] == s[j])
			fail[i] = ++j;
	}

	cout << n - fail[n-1] << '\n';

	return 0;
}
