#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
	vector<int> vec;
	int num[101];
	int n, k, cnt = 0;

	scanf("%d %d", &n, &k);
	for (int i=0; i<k; ++i)
		scanf("%d", &num[i]);

	for (int i=0; i<k; ++i) {
		bool flag = false;
		int max_val = 0;
		int idx = 0;
		for (int j=0; j<vec.size(); ++j)
			if (num[i] == vec[j])
				flag = true;
		if (flag)
			continue;

		if (vec.size() < n) {
			vec.push_back(num[i]);
			continue;
		}

		for (int t=0; t<vec.size(); ++t) {
			int tar = INT_MAX;
			for (int j=i+1; j<k; ++j) {
				if (vec[t] == num[j]) {
					tar = j;
					break;
				}
			}
			if (max_val < tar) {
				max_val = tar;
				idx = t;
			}
		}
		vec[idx] = num[i];
		cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}
