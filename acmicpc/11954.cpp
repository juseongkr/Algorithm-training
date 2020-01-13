#include <iostream>
using namespace std;

string s;
int space;

void print()
{
	for (int i=0; i<space; ++i)
		cout << "  ";
}

int main()
{
	cin >> s;
	for (int i=0; i<s.length(); ++i) {
		if (s[i] == '}' && s[i-1] != '{') {
			cout << '\n';
			space--;
			print();
			cout << "}";
		} else if (s[i] == '{') {
			cout << "{\n";
			if (s[i+1] == '}') {
				i++;
				print();
				cout << "}";
			} else {
				space++;
				print();
			}
		} else if (s[i] == ',') {
			cout  << ",\n";
			print();
		} else {
			cout << s[i];
		}
	}

	return 0;
}
