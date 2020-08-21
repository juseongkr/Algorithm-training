#include <iostream>
using namespace std;
#define MAX 100001
#define LIMIT 500001

int n, m;
int card[MAX], dict[LIMIT];

bool check(int mid)
{
	fill(dict, dict+LIMIT, 0);
	int cnt = 0, ret = 0;

	for (int i=0, j=0; i<n; ++i) {
		if (dict[card[i]]++)
			cnt++;

		if (j == mid) {
			if (--dict[card[i-mid]])
				cnt--;
		} else {
			j++;
		}

		if (j == mid && cnt == 0) {
			if (++ret == m)
				break;
			while (j) {
				j--;
				dict[card[i-j]]--;
			}
		}
	}
	return ret < m;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> card[i];

	int l = 1, r = n+1;
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid))
			r = mid-1;
		else
			l = mid+1;
	}
	cout << r << '\n';

	return 0;
}
