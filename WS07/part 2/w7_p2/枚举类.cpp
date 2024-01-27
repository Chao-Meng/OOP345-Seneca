// Scoped Enumerations
// Colour.h
#include <iostream>
#ifndef COLOUR_H
#define COLOUR_H

// define the Colour type
enum class Colour { white, red, green, blue };
std::ostream& operator<<(std::ostream& os,
	const Colour& colour);
#endif
//main

// Scoped Enumerations
// scoped_enum.cpp

#include <iostream>
#include "Colour.h"

int main() {
    Colour bedroom, kitchen, living_room; // rooms to paint
    bedroom = Colour::red;
    kitchen = Colour::white;
    living_room = Colour::blue;
    std::cout
        << bedroom << ' '
        << kitchen << ' '
        << living_room << std::endl;
}


//源文件
// Scoped Enumerations
// Colour.cpp

#include <string>
#include "Colour.h"

std::ostream& operator<<(std::ostream& os,
    const Colour& colour) {
    std::string str;
    switch (colour) {
    case Colour::white:
        str = "white";
        break;
    case Colour::red:
        str = "red";
        break;
    case Colour::green:
        str = "green";
        break;
    case Colour::blue:
        str = "blue";
        break;
    default:
        str = "none";
    }
    os << str.c_str();
    return os;
}
