#include <iostream>
#include <vector>
using namespace std;

int k;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> s >> k;
	int len = s.length();
	vector<int> fail(len+1, 0);
	for (int i=1, j=0; i<=len; ++i) {
		while (j && s[i] != s[j])
			j = fail[j-1];

		if (s[i] == s[j])
			fail[i] = ++j;
	}

	cout << 1LL * (k-1) * (len - fail[len-1]) + len << '\n';

	return 0;
}
