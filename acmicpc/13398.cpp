#include <iostream>
using namespace std;
#define MAX 100001

int n;
int num[MAX], ldp[MAX], rdp[MAX];

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	ldp[0] = num[0];
	for (int i=1; i<n; ++i)
		ldp[i] = max(num[i], ldp[i-1] + num[i]);

	rdp[n-1] = num[n-1];
	for (int i=n-2; i>=0; i--)
		rdp[i] = max(num[i], rdp[i+1] + num[i]);

	int ans = ldp[0];
	for (int i=1; i<n; ++i)
		ans = max(ans, ldp[i]);

	for (int i=1; i<n-1; ++i)
		ans = max(ans, ldp[i-1] + rdp[i+1]);

	cout << ans << '\n';

	return 0;
}
