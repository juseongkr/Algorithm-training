#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1001
const int INF = 1e9+7;

int T, n;

bool check(vector<int> vec)
{
	int mi = INF;
	for (int i=vec.size()-1; i>=0; i--) {
		for (int j=0; j<i; ++j)
			if (vec[j] < vec[i] && mi < vec[j])
				return false;

		mi = min(mi, vec[i]);
	}

	sort(vec.begin(), vec.end());
	if (unique(vec.begin(), vec.end()) != vec.end())
		return false;

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	while (1) {
		vector<int> vec;
		while (cin >> n) {
			if (n < 0)
				break;
			vec.push_back(n);
		}

		if (vec.size() == 0)
			break;

		if (check(vec))
			cout << "Case " << ++T << ": yes\n";
		else
			cout << "Case " << ++T << ": no\n";
	}

	return 0;
}
