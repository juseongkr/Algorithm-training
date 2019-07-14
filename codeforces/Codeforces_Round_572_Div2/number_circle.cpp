#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100001

int main()
{
	vector<long long> num;
	long long t;
	int n;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t;
		num.push_back(t);
	}

	sort(num.begin(), num.end());

	if (num[n-1] >= num[n-2] + num[n-3]) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		swap(num[n-2], num[n-1]);
		for (int i=0; i<n; ++i)
			cout << num[i] << " ";
	}

	return 0;
}
