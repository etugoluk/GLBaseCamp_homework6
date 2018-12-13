#include "port.h"

Port::Port(const char* br, const char* st, int b) : bottles(b)
{
	if (br)
	{
		brand = new char [strlen(br)];
		strcpy(brand, br);
	}
	else
		brand = "none";

	if (st)
	{
		strcpy(style, st);
	}
	else
		strcpy(style, "none");
}

Port::Port(const Port& p) : bottles(p.bottles)
{
	brand = new char [strlen(p.brand)];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
}

Port::~Port()
{
	delete [] brand;
}

Port& Port::operator= (const Port & p)
{
	if (this != &p)
	{
		if (brand)
			delete [] brand;
		bottles = p.bottles;
		brand = new char [strlen(p.brand)];
		strcpy(brand, p.brand);
		strcpy(style, p.style);
	}
	return *this;
}

Port& Port::operator+= (int b)
{
	bottles += b;
	return *this;
}

Port& Port::operator-= (int b)
{
	bottles -= b;
	if (bottles < 0)
		bottles = 0;
	return *this;
}

int Port::BottleCount() const
{
	return bottles;
}

void Port::Show() const
{
	std::cout << "Brand: " << brand << std::endl;
	std::cout << "Kind: " << style << std::endl;
	std::cout << "Bottles: " << bottles << std::endl;
}


std::ostream& operator<< (std::ostream& os, const Port& p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}