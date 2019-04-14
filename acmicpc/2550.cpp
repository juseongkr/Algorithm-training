#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> ans;
	vector<pair<int, int>> vec;
	int ori[10001], arr[10001], pos[10001];
	int num[10001];
	int n, t, len = 0;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &t);
		pos[t] = i;
		ori[i] = t;
	}

	for (int i=0; i<n; ++i) {
		scanf("%d", &t);
		arr[i] = pos[t];
	}

	for (int i=0; i<n; ++i) {
		auto it = lower_bound(num, num + len, arr[i]) - num;
		if (it == len)
			len++;
		num[it] = arr[i];
		vec.push_back({it, arr[i]});
	}

	printf("%d\n", len);
	for (int i=vec.size(); i>=0; i--) {
		if (vec[i].first == len-1) {
			auto bulb = ori[vec[i].second];
			ans.push_back(bulb);
			len--;
		}
	}

	sort(ans.begin(), ans.end());

	for (int i=0; i<ans.size(); ++i) 
		printf("%d ", ans[i]);

	return 0;
}
