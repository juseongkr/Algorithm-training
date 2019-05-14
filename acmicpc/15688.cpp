#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec;
	int n, t;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &t);
		vec.push_back(t);
	}

	sort(vec.begin(), vec.end());

	for (int i=0; i<n; ++i)
		printf("%d\n", vec[i]);

	return 0;
}
