#include <string>

#pragma once

namespace pandemic{
    enum class Color {
            Yellow,
            Red,
            Blue,
            Black,
    };
    const std::map<std::string , Color> color2string{
            {"Yellow",Color::Yellow},
            {"Red",Color::Red},
            {"Blue",Color::Blue},
            {"Black",Color::Black},
    };
}