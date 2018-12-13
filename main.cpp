#include "vintage_port.h"

int main()
{
	Port *p1 = new Port();

	VintagePort *vp = new VintagePort();
	Port *p2 = vp;

	std::cout << "p1 - show:" << std::endl;
	p1->Show();
	std::cout << "p2 - show:" << std::endl;
	p2->Show();

	std::cout << "p1 - out:" << std::endl;
	std::cout << *p1 << std::endl;
	std::cout << "p2 - out:" << std::endl;
	std::cout << *p2 << std::endl;

	return 0;
}