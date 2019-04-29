#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

int nation[101], cnt;
typedef tuple<int, int, int> tii;

bool cmp(tii a, tii b) { return get<0>(a) > get<0>(b); }

int main()
{
	vector<tii> vec;
	int n, a, b, c;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		vec.push_back({c, a, b});
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i=0; i<vec.size(); ++i) {
		if (nation[get<1>(vec[i])] >= 2)
			continue;

		if (cnt == 3)
			break;

		cnt++;
		nation[get<1>(vec[i])]++;
		cout << get<1>(vec[i]) << " " << get<2>(vec[i]) << '\n';
	}

	return 0;
}
