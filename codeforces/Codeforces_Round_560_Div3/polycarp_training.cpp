#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 200001

int main()
{
	int num[MAX];
	int n, cnt = 0;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	sort(num, num+n);

	for (int i=0; i<n; ++i)
		if (cnt < num[i])
			cnt++;

	cout << cnt << '\n';
		
	return 0;
}
