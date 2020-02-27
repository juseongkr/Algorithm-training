#include <iostream>
using namespace std;

long long x, y, z;

int main()
{
	cin >> x >> y >> z;

	cout << (x+y)/z << " ";
	if (x%z + y%z < z)
		cout << "0\n";
	else
		cout << min(z-x%z, z-y%z) << '\n';

	return 0;
}
