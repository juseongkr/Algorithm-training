#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 101

int main()
{
	int arr[MAX];
	pair<int, int> num[MAX];
	int n, a, b, len = 0;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a >> b;
		if (a < b)
			num[i] = {b, a};
		else
			num[i] = {a, b};
	}

	sort(num, num+n);

	for (int i=0; i<n; ++i) {
		int it = upper_bound(arr, arr+len, num[i].second) - arr;
		if (it == len)
			len++;
		arr[it] = num[i].second;
	}
	cout << len << '\n';

	return 0;
}
