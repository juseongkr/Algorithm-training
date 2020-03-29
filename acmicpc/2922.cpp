#include <iostream>
using namespace std;
#define MAX 101

string s;

inline bool vowel(char c) { return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'); }

long long solve(int cur, bool l)
{
	for (int i=cur; i<s.length(); ++i) {
		if (s[i] == '_') {
			long long ans = 0;
			s[i] = 'A';
			ans += solve(i, l) * 5;
			s[i] = 'Z';
			ans += solve(i, l) * 20;
			s[i] = 'L';
			ans += solve(i, 1);
			s[i] = '_';
			return ans;
		} else {
			l = s[i] == 'L' ? 1 : l;
			if (i >= 2) {
				if ((vowel(s[i-2]) && vowel(s[i-1]) && vowel(s[i])) || (!vowel(s[i-2]) && !vowel(s[i-1]) && !vowel(s[i])))
					return 0;
			}
		}
	}

	return l;
}

int main()
{
	cin >> s;
	cout << solve(0, 0) << '\n';

	return 0;
}
