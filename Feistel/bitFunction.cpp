#include"bitFunction.h"

std::string per(char vhod)
{
	std::string b = std::bitset<8>(vhod).to_string();
	return b;
}
std::string xr (std::string a, std::string b)
{
	std::string c;
	for (int i = 0; i < 8; i++)
		if (a.at(i) == b.at(i))
			c += "0";
		else
			c += "1";
	return c;
}