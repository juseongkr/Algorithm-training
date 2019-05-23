#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n[4];

	for (int i=0; i<4; ++i)
		cin >> n[i];

	sort(n, n+4);

	cout << min(n[3], n[2]) * min(n[0], n[1]) << '\n';

	return 0;
}
