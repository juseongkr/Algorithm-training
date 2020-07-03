#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define MAX 300001
#define X(v) get<0>(v)
#define Y1(v) get<1>(v)
#define Y2(v) get<2>(v)
#define S(v) get<3>(v)
typedef tuple<int, int, int, int> node;

int n, x1, x2, y1, y2;
int tree[MAX*4], cnt[MAX*4];
vector<node> vec;

void __update(int cur, int left, int right, int start, int end, int val)
{
	if (end < left || right < start)
		return;

	if (left <= start && end <= right) {
		cnt[cur] += val;
	} else {
		int mid = (start+end)/2;
		__update(2*cur, left, right, start, mid, val);
		__update(2*cur+1, left, right, mid+1, end, val);
	}

	if (cnt[cur]) {
		tree[cur] = end - start + 1;
	} else {
		tree[cur] = (start == end) ? 0 : tree[cur*2] + tree[cur*2+1];
	}
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		vec.push_back({x1, y1, y2-1, 1});
		vec.push_back({x2, y1, y2-1, -1});
	}

	sort(vec.begin(), vec.end());

	int ans = 0;
	for (int i=0; i<vec.size(); ++i) {
		if (i > 0)
			ans += (X(vec[i]) - X(vec[i-1])) * tree[1];
		__update(1, Y1(vec[i]), Y2(vec[i]), 0, MAX-1, S(vec[i]));
	}
	cout << ans << '\n';

	return 0;
}
