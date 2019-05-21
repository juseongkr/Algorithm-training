#include <iostream>
using namespace std;
#define MAX 1000001

int main()
{
	int fail[MAX];
	string s;
	int n, len;

	cin >> n >> s;
	len = s.length();
	fill(fail, fail+MAX, 0);
	for (int i=1, j=0; i<len; ++i) {
		while (j && s[i] != s[j])
			j = fail[j-1];

		if (s[i] == s[j])
			fail[i] = ++j;
	}

	cout << len - fail[len-1] << '\n';

	return 0;
}
