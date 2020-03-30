#include <iostream>
using namespace std;

long long a, b;
int T;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> a >> b;
		if (a%b == 0)
			cout << "0\n";
		else
			cout << b-a%b << '\n';
	}

	return 0;
}
