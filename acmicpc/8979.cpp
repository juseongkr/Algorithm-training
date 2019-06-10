#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;
typedef tuple<int, int, int, int> ti4;

ti4 num[1001];
int n, k, t, a, b, c;

bool cmp(ti4 a, ti4 b)
{
	if (get<1>(a) > get<1>(b)) {
		return true;
	} else if (get<1>(a) == get<1>(b)) {
		if (get<2>(a) > get<2>(b)) {
			return true;
		} else if (get<2>(a) == get<2>(b)) {
			if (get<3>(a) > get<3>(b))
				return true;
			else if (get<3>(a) == get<3>(b))
				return get<0>(a) == k;
		}
	}
	return false;
}

int main()
{
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> t >> a >> b >> c;
		num[i] = {t, a, b, c};
	}

	sort(num, num+n, cmp);

	for (int i=0; i<n; ++i) {
		if (get<0>(num[i]) == k) {
			cout << i+1 << '\n';
			break;
		}
	}

	return 0;
}
