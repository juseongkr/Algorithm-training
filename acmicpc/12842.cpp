#include <iostream>
using namespace std;
#define MAX 100001

int num[MAX];

int main()
{
	int n, s, m;

	cin >> n >> s >> m;
	for (int i=0; i<m; ++i)
		cin >> num[i];

	int sum = 0, k = 0;
	while (1) {
		for (int i=0; i<m; ++i) {
			if (k % num[i] == 0) {
				sum++;
				if (sum >= n-s) {
					cout << i+1 << '\n';
					return 0;
				}
			}
		}
		k++;
	}

	return 0;
}
