#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec;
	int n, t;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t;
		vec.push_back(t);
	}

	sort(vec.rbegin(), vec.rend());

	for (int i=0; i<n; ++i)
		cout << vec[i] << '\n';

	return 0;
}
