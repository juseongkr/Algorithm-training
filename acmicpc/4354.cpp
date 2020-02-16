#include <iostream>
using namespace std;
#define MAX 1000001

string s;
int fail[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	while (1) {
		cin >> s;
		if (s == ".")
			break;

		int len = s.length();
		fill(fail, fail+MAX, 0);
		for (int i=1, j=0; i<=len; ++i) {
			while (j && s[i] != s[j])
				j = fail[j-1];

			if (s[i] == s[j])
				fail[i] = ++j;
		}

		int last = fail[len-1];
		if (!last || last % (len - last))
			cout << "1\n";
		else
			cout << last / (len - last) + 1 << '\n';
	}

	return 0;
}
