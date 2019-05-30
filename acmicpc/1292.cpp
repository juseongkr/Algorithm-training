#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a, b, sum = 0;
	vector<int> num;

	cin >> a >> b;
	for (int i=0, k=1; i<b; ++i, ++k)
		for (int j=0; j<=i; ++j)
			num.push_back(k);

	for (int i=a-1; i<b; ++i)
		sum += num[i];

	cout << sum << '\n';

	return 0;
}
