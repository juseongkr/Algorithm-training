#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

string s;
int d, len, T;
int sa[MAX], pos[MAX], lcp[MAX], t[MAX];

bool cmp(int i, int j)
{
	if (pos[i] != pos[j])
		return pos[i] < pos[j];

	i += d;
	j += d;
	return (i < len && j < len) ? (pos[i] < pos[j]) : (i > j);
}

void make_suffix()
{
	len = s.length();
	for (int i=0; i<len; ++i) {
		sa[i] = i;
		pos[i] = s[i];
	}

	for (d=1; ; d*=2) {
		sort(sa, sa+len, cmp);

		fill(t, t+MAX, 0);
		for (int i=0; i<len-1; ++i)
			t[i+1] = t[i] + cmp(sa[i], sa[i+1]);

		for (int i=0; i<len; ++i)
			pos[sa[i]] = t[i];

		if (t[len-1] == len-1)
			break;
	}
}

void make_lcp()
{
	for (int i=0, k=0; i<len; ++i, k=max(k-1, 0)) {
		if (pos[i] == len-1)
			continue;

		for (int j=sa[pos[i]+1]; ; ++k)
			if (s[i+k] != s[j+k])
				break;

		lcp[pos[i]] = k;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> s;
		make_suffix();
		make_lcp();

		int ans = 0;
		for (int i=1; i<s.length()-1; ++i)
			ans += max(0, lcp[i] - lcp[i-1]);

		cout  << ans + lcp[0] << '\n';
	}

	return 0;
}
