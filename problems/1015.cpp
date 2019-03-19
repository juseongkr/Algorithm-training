#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<pair<int, int>> vec;
	int b[51];
	int n, t;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &t);
		vec.push_back({t, i});
	}

	sort(vec.begin(), vec.end());

	for (int i=0; i<n; ++i)
		b[vec[i].second] = i;

	for (int i=0; i<n; ++i)
		printf("%d ", b[i]);
	printf("\n");
	
	return 0;
}
