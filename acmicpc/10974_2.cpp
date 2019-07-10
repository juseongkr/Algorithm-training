#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<int> vec;

	cin >> n;
	for (int i=1; i<=n; ++i)
		vec.push_back(i);

	do {
		for (int i=0; i<n; ++i)
			cout << vec[i] << " ";
		cout << '\n';
	} while (next_permutation(vec.begin(), vec.end()));

	return 0;
}
