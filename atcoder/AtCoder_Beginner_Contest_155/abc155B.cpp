#include <iostream>
using namespace std;
#define MAX 101

int n;
int num[MAX];

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	for (int i=0; i<n; ++i) {
		if (num[i] % 2 == 0) {
			if (num[i] % 3 != 0 && num[i] % 5 != 0) {
				cout << "DENIED\n";
				return 0;
			}
		}
	}
	cout << "APPROVED\n";

	return 0;
}
