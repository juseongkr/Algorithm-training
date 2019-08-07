#include <iostream>
using namespace std;
#define MAX 1000001

int fail[MAX], cnt[MAX];
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	for (int i=1, j=0; i<s.length(); ++i) {
		while (j && s[i] != s[j])
			j = fail[j-1];

		if (s[i] == s[j])
			fail[i] = ++j;
	}

	for (int i=0; i<s.length()-1; ++i)
		cnt[fail[i]]++;

	for (int i=s.length(); i!=0; i=fail[i-1]) {
		if (cnt[i] != 0) {
			for (int j=0; j<i; ++j)
				cout << s[j];
			return 0;
		}
	}
	cout << "-1\n";

	return 0;
}
