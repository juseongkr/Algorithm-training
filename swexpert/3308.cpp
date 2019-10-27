#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

int num[MAX];

int main()
{
	int T, n, x;

	cin >> T;
	for (int t=1; t<=T; ++t) {
		cin >> n;
		int len = 0;
		fill(num, num+MAX, 0);
		for (int i=0; i<n; ++i) {
			cin >> x;
			int it = lower_bound(num, num+len, x) - num;
			if (it == len)
				len++;
			num[it] = x;
		}
		cout << "#" << t << " " << len << '\n';
	}

	return 0;
}
