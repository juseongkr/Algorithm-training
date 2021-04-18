#include <iostream>
using namespace std;
#define MAX 501

int h, w, block[MAX];

int main()
{
	cin >> h >> w;
	for (int i=0; i<w; ++i)
		cin >> block[i];

	int ans = 0;
	int l = 0, r = w-1;
	int left_max = 0, right_max = 0;
	while (l < r) {
		if (block[l] < block[r]) {
			if (left_max <= block[l])
				left_max = block[l];
			else
				ans += left_max - block[l];
			l++;
		} else {
			if (right_max <= block[r])
				right_max = block[r];
			else
				ans += right_max - block[r];
			r--;
		}
	}

	cout << ans << '\n';

	return 0;
}
