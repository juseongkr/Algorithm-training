#include <iostream>
#include <cmath>
using namespace std;
#define MAX 26

int T, n;
int dict[MAX];
string s;

int solve(int l, int r, char c)
{
	if (l == r)
		return s[l] != c;

	int mid = (l+r)/2;
	int left = 0, right = 0;

	for (int i=l; i<=mid; ++i)
		if (s[i] != c)
			left++;

	for (int i=mid+1; i<=r; ++i)
		if (s[i] != c)
			right++;

	left += solve(mid+1, r, c+1);
	right += solve(l, mid, c+1);

	return min(left, right);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> s;

		cout << solve(0, n-1, 'a') << '\n';
	}

	return 0;
}
