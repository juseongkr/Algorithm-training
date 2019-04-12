#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	vector<pair<int, int>> vec;
	stack<int> st;
	int num[1001];
	int n, t, len = 0;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &t);
		int it = lower_bound(num, num + len, t) - num;
		if (it == len)
			len++;
		num[it] = t;
		vec.push_back({it, t});
	}

	printf("%d\n", len);
	for (int i=n-1; i>=0; i--) {
		if (vec[i].first == len-1) {
			st.push(vec[i].second);
			len--;
		}
	}

	while (!st.empty()) {
		printf("%d ", st.top());
		st.pop();
	}

	return 0;
}
