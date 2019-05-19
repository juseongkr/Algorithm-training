#include <iostream>
using namespace std;

int main()
{
	string s;
	int n;

	cin >> n >> s;
	for (int i=0; i<n*2-2; ++i) {
		if (s[i] != s[i+2]) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	
	return 0;
}
