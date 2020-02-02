#include <iostream>
using namespace std;
#define MAX 100001

int n, q, x, y, cnt;
bool map[2][MAX];

int main()
{
	cin >> n >> q;
	for (int i=0; i<q; ++i) {
		cin >> x >> y;
		x--;
		map[x][y] ^= 1;
		if (map[x][y]) {
			for (int i=-1; i<=1; ++i)
				if (map[!x][y+i])
					cnt++;

		} else {
			for (int i=-1; i<=1; ++i)
				if (map[!x][y+i])
					cnt--;
		}
		if (cnt == 0)
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}
