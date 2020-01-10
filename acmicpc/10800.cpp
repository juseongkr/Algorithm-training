#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 200001

class Ball {
public:
	int size, color, idx;
	Ball(int s, int c, int i) : size(s), color(c), idx(i) { }
	bool operator<(const Ball &x) const {
		return size < x.size;
	}
};

int n, c, s, sum;
int ans[MAX], total[MAX];
vector<Ball> b;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> c >> s;
		b.push_back({s, c, i});
	}

	sort(b.begin(), b.end());

	for (int i=0, j=0; i<n; ++i) {
		while (b[i].size > b[j].size) {
			sum += b[j].size;
			total[b[j].color] += b[j].size;
			j++;
		}
		ans[b[i].idx] = sum - total[b[i].color];
	}

	for (int i=0; i<n; ++i)
		cout << ans[i] << '\n';

	return 0;
}
