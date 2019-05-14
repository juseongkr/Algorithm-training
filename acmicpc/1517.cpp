#include <iostream>
using namespace std;

#define MAX 500001
int num[MAX], temp[MAX];
int n;

long long solve(int left, int right)
{
	if (left == right)
		return 0;

	int mid = (left+right)/2;
	long long ret = solve(left, mid) + solve(mid+1, right);

	int i = left;
	int j = mid+1;
	int cur = 0;
	while (i <= mid || j <= right) {
		if (i <= mid && (j > right || num[i] <= num[j])) {
			temp[cur++] = num[i++];
		} else {
			ret += (mid+1-i);
			temp[cur++] = num[j++];
		}
	}

	for (int i=left; i<=right; ++i)
		num[i] = temp[i-left];

	return ret;
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	cout << solve(0, n-1) << '\n';

	return 0;
}
