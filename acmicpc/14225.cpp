#include <iostream>
using namespace std;
#define MAX 21

int n;
int num[MAX], check[100001*20];

void solve(int cur, int sum)
{
	if (cur == n) {
		check[sum] = 1;
		return;
	}

	solve(cur+1, sum + num[cur]);
	solve(cur+1, sum);
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	solve(0, 0);

	for (int i=1; ; ++i) {
		if (!check[i]) {
			cout << i << '\n';
			break;
		}
	}

	return 0;
}
