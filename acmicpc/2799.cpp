#include <iostream>
using namespace std;
#define MAX 501

int ans[5];

int main()
{
	int m, n;
	string map[MAX];

	cin >> m >> n;
	for (int i=0; i<m*5+1; ++i)
		cin >> map[i];

	for (int i=1; i<m*5+1; i+=5) {
		for (int j=1; j<n*5+1; j+=5) {
			for (int k=i; k<i+4; ++k) {
				if (map[k][j] == '.') {
					ans[k-i]++;
					break;
				}
				if (k == i+3)
					ans[4]++;
			}
		}
	}

	for (int i=0; i<5; ++i)
		cout << ans[i] << " ";

	return 0;
}
