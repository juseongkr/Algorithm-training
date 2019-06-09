#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x, y, z;

	cin >> x >> y >> z;
	int a = x - y + z;
	int b = x - y - z;
	if (a < 0 && b < 0)
		cout << "-\n";
	else if (a > 0 && b > 0)
		cout << "+\n";
	else if (a == 0 && b == 0)
		cout << "0\n";
	else
		cout << "?\n";

	return 0;
}
