#include <sstream>
#include <iostream>
#include <string>
#include <tuple>

std::tuple<int, int, char, std::string> parse(std::string const& line) {
	std::stringstream ss;
	ss << line;

	int lo;
	ss >> lo;
	ss.get();

	int hi;
	ss >> hi;
	ss.get();

	char x;
	ss >> x;
	ss.get();
	ss.get();

	std::string password;
	ss >> password;

	return {lo, hi, x, password};
}

bool is_valid(std::string const& line){
	auto [i, j, letter, password] = parse(line);
	return (password[i-1] == letter) != (password[j-1] == letter);
}

int main () {

	int result = 0;
	std::string line;
	while(std::getline(std::cin, line))
		result += is_valid(line);
	std::cout << result << '\n';
}
