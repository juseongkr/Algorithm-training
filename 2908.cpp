#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string a, b;

	cin >> a >> b;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	cout << max(stoi(a), stoi(b)) << '\n';

	return 0;
}
