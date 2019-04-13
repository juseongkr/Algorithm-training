#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> num;
	int n, k, t;

	scanf("%d %d", &n, &k);
	for (int i=0; i<n; ++i) {
		scanf("%d", &t);
		num.push_back(t);
	}

	sort(num.begin(), num.end());

	printf("%d\n", num[k-1]);

	return 0;
}
