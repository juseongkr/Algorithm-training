#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, ans;
int num[8], pos[8];
bool visit[101];

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> num[i];
		pos[i] = i;
	}

	do {
		int cnt = 0, sum = 0;
		fill(visit, visit+101, 0);
		for (int i=0; i<n; ++i) {
			sum += num[pos[i]];
			if (50 <= sum && visit[sum-50])
				cnt++;
			visit[sum] = 1;
		}
		ans = max(ans, cnt);
	} while (next_permutation(pos, pos+n));

	cout << ans << '\n';

	return 0;
}
