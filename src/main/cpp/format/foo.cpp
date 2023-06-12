#include "foo.h"

#include <iomanip>
#include <sstream>

std::string example::to_hex(ushort value) {
    std::stringstream stream;
    stream << std::setw(4) << std::hex << value;
    return stream.str();
}