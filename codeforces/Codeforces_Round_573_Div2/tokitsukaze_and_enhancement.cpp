#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;

	cin >> n;
	if (n % 4 == 1)
		cout << "0 A\n";
	else if (n % 4 == 2)
		cout << "1 B\n";
	else if (n % 4 == 3)
		cout << "2 A\n";
	else
		cout << "1 A\n";

	return 0;
}
