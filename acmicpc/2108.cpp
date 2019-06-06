#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
#define MAX 500001

int dict[8001], num[MAX];
int min_val = 4001, max_val = -4001;
int n, sum, t, idx;
bool flag = false;

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> num[i];
		sum += num[i];
		min_val = min(min_val, num[i]);
		max_val = max(max_val, num[i]);
		dict[num[i]+4000]++;
	}

	cout << fixed << setprecision(0) << (double)sum/(double)n << '\n';

	sort(num, num+n);

	cout << num[n/2] << '\n';

	for (int i=0; i<8001; ++i) {
		if (t < dict[i]) {
			t = dict[i];
			idx = i;
			flag = true;
		} else if (t == dict[i] && flag) {
			idx = i;
			flag = false;
		}
	}

	cout << idx - 4000 << '\n';

	cout << max_val - min_val << '\n';

	return 0;
}
