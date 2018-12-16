#include "vintage_port.h"
#include <cstring>

VintagePort::VintagePort() : Port("none", "vintage", 0), nickname(strcpy(new char[6], "noname")), year(0) {} 

VintagePort::VintagePort(const char* br, int b, const char* nn, int y) : Port(br, "vintage", b), year(y)
{
	if (nn)
	{
		nickname = new char [strlen(nn)];
		strcpy(nickname, nn);
	}
	else
	  nickname = (char*)"none";
} 


VintagePort::VintagePort(const VintagePort& vp) : Port((Port)vp), nickname(strcpy(new char [strlen(vp.nickname)], vp.nickname)), year(vp.year) {}

VintagePort::~VintagePort() { delete [] nickname; }

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
	if (this != &vp)
	{
		delete [] brand;
		delete [] nickname;

		bottles = vp.bottles;
		brand = new char [strlen(vp.brand)];
		strcpy(brand, vp.brand);
		strcpy(style, vp.style);
		nickname = new char [strlen(vp.nickname)];
		strcpy(nickname, vp.nickname);
		year = vp.year;
	}
	return *this;
}

void VintagePort::Show() const
{
	std::cout << "Brand: " << brand << std::endl;
	std::cout << "Kind: " << style << std::endl;
	std::cout << "Bottles: " << bottles << std::endl;
	std::cout << "Nickname: " << style << std::endl;
	std::cout << "Year: " << bottles << std::endl;

}

std::ostream& operator<<(std::ostream& os, const VintagePort& vp)
{
	os << vp.brand << ", " << vp.style << ", " << vp.bottles << ", " << vp.nickname << ", " << vp.year;
	return os;
}
