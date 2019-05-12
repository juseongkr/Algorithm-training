#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> vec;
	int num[26];
	int a, b, m, t = 0;

	cin >> a >> b >> m;
	for (int i=1; i<=m; ++i)
		cin >> num[i];

	for (int i=1; i<=m; ++i)
		t = t * a + num[i];

	while (t) {
		vec.push_back(t%b);
		t /= b;
	}

	for (int i=vec.size()-1; i>=0; i--)
		cout << vec[i] << " ";

	return 0;
}
