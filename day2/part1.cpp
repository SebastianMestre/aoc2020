#include <sstream>
#include <iostream>
#include <string>

bool is_valid(std::string const& line){
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

	int eq_count = 0;
	for(char c : password)
		eq_count += c == x;
	
	return lo <= eq_count && eq_count <= hi;
}

int main () {

	int result = 0;
	std::string line;
	while(std::getline(std::cin, line))
		result += is_valid(line);
	std::cout << result << '\n';
}
