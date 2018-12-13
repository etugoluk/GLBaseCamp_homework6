#pragma once

#include "port.h"

class VintagePort : public Port { // style always == "vintage"
private:
    char* nickname; // like "The Noble", "Old Velvet", etc.
    int year; // year of bottling
public:
    VintagePort();
    VintagePort(const char* br, int b, const char* nn, int y);
    VintagePort(const VintagePort& vp);
    ~VintagePort();

    VintagePort & operator=(const VintagePort & vp);
    void Show() const;
    friend std::ostream& operator<<(std::ostream& os, const VintagePort& vp);
};
