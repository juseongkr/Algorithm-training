#include <iostream>
using namespace std;
char office[110][110];
int result[256];
int width, height, sum = 0;
char president;

int main()
{
	cin >> width >> height >> president;

	for (int i=1; i<=width; ++i)
		for (int j=1; j<=height; ++j)
			cin >> office[i][j];

	for (int i=1; i<=width; ++i) {
		for (int j=1; j<=height; ++j) {
			if (office[i][j] == president) {
				result[office[i-1][j]] = 1;
				result[office[i+1][j]] = 1;
				result[office[i][j-1]] = 1;
				result[office[i][j+1]] = 1;
			}
		}
	}

	for (int i='A'; i<='Z'; ++i)
		sum += result[i];

	cout << sum - result[president] << '\n';

	return 0;
}
