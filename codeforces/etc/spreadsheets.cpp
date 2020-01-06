#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <vector>

long long toNumber(std::string str)
{
	long long result = 0;
	std::reverse(str.begin(), str.end());

	for (int i = 0; i < str.size(); i++)
		result += (str[i] - 64) * pow(26, i);

	return result;
}

std::string toString(int num)
{	
	int remainder;
	std::string result;

	while (num >= 26) {
		remainder = num % 26;
		if (remainder == 0) {
			result += 'Z';
			num--;
		} else {
			result += (remainder + 64);
		}
		num = num / 26;
	}
	if (num != 0)
		result += (num + 64);

	std::reverse(result.begin(), result.end());

	return result;
}

bool is_rc_type(std::string str)
{
	if (str[0] == 'R' && isdigit(str[1])) {
		for (int i = 2; i < str.size(); i++) {
			if (str[i] == 'C') {
				return true;
			}
		}
	}

	return false;
}

std::string spread_sheets(std::string str)
{	
	if (is_rc_type(str)) {
		std::string row, col;
		int pos = 0;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'C')
				pos = i;
		}

		for (int i = 1; i < pos; i++) {
			row += str[i];
		}

		for (int i = pos + 1; i < str.size(); i++) {
			col += str[i];
		}
		
		return toString(std::stoi(col)) + row;

	} else {
		std::string row, col;
		int pos = 0;

		for (int i = 0; i < str.size(); i++) {
			if (isdigit(str[i])) {
				pos = i;
				break;
			}
		}

		for (int i = 0; i < pos; i++) {
			row += str[i];
		}

		for (int i = pos; i < str.size(); i++) {
			col += str[i];
		}

		return 'R' + col + 'C' + std::to_string(toNumber(row));
	}
}

int main(int argc, char **argv)
{
	int cnt;
	std::string input, output;
	std::vector<std::string> ans;

	std::cin >> cnt;

	for (int i = 0; i < cnt; i++) {
		std::cin >> input;
		output = spread_sheets(input);
		ans.push_back(output);
	}

	for (auto v : ans) {
		std::cout << v << std::endl;
	}

	return 0;
}
