#include <iostream>
using namespace std;
#define MAX 4000002

int A[MAX];
string s, p;

void manacher(string s)
{
	int r = 0, p = 0;
	for (int i=0; i<s.length(); ++i) {
		if (i <= r) {
			A[i] = min(A[2*p-i], r-i);
		} else {
			A[i] = 0;
		}

		while (0 <= i - A[i] - 1 && i + A[i] + 1 < s.length() && s[i - A[i] - 1] == s[i + A[i] + 1])
			A[i]++;

		if (r < i + A[i]) {
			r = i + A[i];
			p = i;
		}
	}
}

int main()
{
	cin >> p;
	for (int i=0; i<p.length(); ++i) {
		s += '#';
		s += p[i];
	}
	s += '#';

	manacher(s);

	long long ans = 0;
	for (int i=0; i<s.length(); ++i)
		ans += (A[i]+1)/2;

	cout << ans << '\n';

	return 0;
}
