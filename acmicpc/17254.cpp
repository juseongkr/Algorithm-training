#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int main()
{
	vector<tuple<int, int, char>> vec;
	int n, m, a, b;
	char c;

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> a >> b >> c;
		vec.push_back({b, a, c});
	}

	sort(vec.begin(), vec.end());

	for (int i=0; i<vec.size(); ++i)
		cout << get<2>(vec[i]);

	return 0;
}
