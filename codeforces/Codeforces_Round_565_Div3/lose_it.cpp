#include <iostream>
#include <climits>
#include <map>
using namespace std;

int num[5];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	map<int, int> d = {{4,0}, {8,1}, {15,2}, {16,3}, {23,4}, {42,5}};
	int n, t, cnt = 0;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t;
		t = d[t];
		if (t == 0) {
			num[0]++;
		} else {
			if (t == 1 && num[0]) {
				num[0]--;
				num[1]++;
			} else if (t == 2 && num[1]) {
				num[1]--;
				num[2]++;
			} else if (t == 3 && num[2]) {
				num[2]--;
				num[3]++;
			} else if (t == 4 && num[3]) {
				num[3]--;
				num[4]++;
			} else if (t == 5 && num[4]) {
				num[4]--;
				num[5]++;
			} else {
				cnt++;
			}
		}
	}

	if (n == 0)
		cnt = 0;
	else if (n < 6)
		cnt = n;
	else
		for (int i=0; i<5; ++i)
			cnt += num[i] * (i+1);

	cout << cnt << '\n';

	return 0;
}
