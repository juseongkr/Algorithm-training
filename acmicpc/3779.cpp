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

	for (int t=1; ; ++t) {
		cin >> n;
		if (n == 0)
			break;
		cin >> s;

		fill(fail, fail+MAX, 0);
		for (int i=1, j=0; i<n; ++i) {
			while (j && s[i] != s[j])
				j = fail[j-1];

			if (s[i] == s[j])
				fail[i] = ++j;
		}

		cout << "Test case #" << t << '\n';
		for (int i=1; i<n; ++i)
			if (fail[i] && fail[i] % (i-fail[i]+1) == 0)
				cout << i+1 << " " << fail[i] / (i-fail[i]+1) + 1 << '\n';
		cout << '\n';
	}

	return 0;
}
