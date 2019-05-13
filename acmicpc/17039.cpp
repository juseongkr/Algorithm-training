#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int cow[3];

	for (int i=0; i<3; ++i)
		cin >> cow[i];

	sort(cow, cow+3);

	int min_val = 2;
	int max_val = 1e9 + 1;
	if (cow[2] - cow[0] == 2)
		min_val = 0;
	if (cow[1] - cow[0] == 2 || cow[2] - cow[1] == 2)
		min_val = 1;

	max_val = max(cow[1] - cow[0], cow[2] - cow[1])-1;

	cout << min_val << '\n' << max_val << '\n';

	return 0;
}
