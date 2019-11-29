#include <iostream>
using namespace std;
#define MAX 1001

int n;
string s[MAX];

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> s[i];

	for (int i=0; i<n-1; ++i) {
		for (int j=n-2; j>=i; j--) {
			if (s[j+1] + s[j] > s[j] + s[j+1])
				swap(s[j], s[j+1]);
		}
	}

	for (int i=0; i<n; ++i) {
		if (i == 0 && s[i] == "0") {
			cout << "0\n";
			return 0;
		}
		cout << s[i];
	}

	return 0;
}
