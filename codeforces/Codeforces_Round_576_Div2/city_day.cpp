#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec;
	int n, x, y, k;

	cin >> n >> x >> y;
	for (int i=0; i<n; ++i) {
		cin >> k;
		vec.push_back(k);
	}

	for (int i=0; i<n; ++i) {
		bool flag = true;
		for (int j=i-x; j<i; ++j)
			if (j > 0 && vec[j] < vec[i])
				flag = false;

		for (int j=i+1; j<=i+y; ++j)
			if (j < n && vec[i] > vec[j])
				flag = false;

		if (flag) {
			cout << i+1 << '\n';
			break;
		}
	}

	return 0;
}
