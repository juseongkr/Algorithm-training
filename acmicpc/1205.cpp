#include <iostream>
using namespace std;
#define MAX 51

int main()
{
	long long score[MAX];
	int n, k, p;

	cin >> n >> k >> p;
	for (int i=0; i<n; ++i)
		cin >> score[i];

	int j = 1;
	for (int i=0; i<n; ++i) {
		if (score[i] > k)
			j++;
	}
	if (score[n-1] >= k && n == p)
		cout << "-1\n";
	else
		cout << j << '\n';

	return 0;
}
