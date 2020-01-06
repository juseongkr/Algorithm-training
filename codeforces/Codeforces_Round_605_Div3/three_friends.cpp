#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int v[3], t;

	cin >> t;
	while (t--) {
		cin >> v[0] >> v[1] >> v[2];
		sort(v, v+3);
		cout << max(0, v[1]-v[0] + v[2]-v[1] + v[2]-v[0]-4) << '\n';
	}

	return 0;
}
