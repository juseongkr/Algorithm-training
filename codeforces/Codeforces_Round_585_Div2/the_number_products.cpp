#include <iostream>
using namespace std;
#define MAX 200001

int n, t;
long long pos, neg, x, y;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t;
		if (t < 0) {
			swap(x, y);
			y++;
			pos += x;
			neg += y;
		} else {
			x++;
			pos += x;
			neg += y;
		}
	}
	cout << neg << " " << pos << '\n';

	return 0;
}
