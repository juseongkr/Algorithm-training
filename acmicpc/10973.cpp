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

	if (prev_permutation(vec.begin(), vec.end())) {
		for (int i=0; i<vec.size(); ++i)
			cout << vec[i] << " ";
	} else {
		cout << "-1\n";
	}

	return 0;
}
