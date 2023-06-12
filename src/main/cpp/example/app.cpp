#include <iostream>

#include <fmt/color.h>

int main(int argc, const char **args) {
    std::cout << "Hello World!" << std::endl;
    fmt::print(fg(fmt::terminal_color::cyan), "Hello fmt {}!\n", FMT_VERSION );
    return 0;
}