#include <iostream>
using namespace std;
#define MAX 100001

int main()
{
	int num[MAX];
	int n, m;

	cin >> n >> m;
	for (int i=0; i<m; ++i)
		cin >> num[i];

	int ans = max(num[0], n - num[m-1]);
	for (int i=1; i<m; ++i)
		ans = max(ans, (num[i]-num[i-1]+1)/2);

	cout << ans << '\n';

	return 0;
}
