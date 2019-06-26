#include <iostream>
using namespace std;
#define MAX 1001

int num[MAX];
int t, k = 1;

int check(int sum)
{
	for (int i=0; i<MAX; ++i)
		for (int j=i; j<MAX; ++j)
			for (int p=j; p<MAX; ++p)
				if (num[i] + num[j] + num[p] == sum)
					return 1;
	return 0;
}

int main()
{
	for (int i=0; i<MAX; ++i) {
		num[i] = k;
		k += i+2;
	}

	cin >> t;
	while (t--) {
		cin >> k;

		cout << check(k) << '\n';
	}

	return 0;
}
