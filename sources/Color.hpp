#include <string>

#pragma once

namespace pandemic{
    enum class Color {
            Yellow,
            Red,
            Blue,
            Black,
    };
    const std::map<std::string , Color> string2color{
            {"Yellow",Color::Yellow},
            {"Red",Color::Red},
            {"Blue",Color::Blue},
            {"Black",Color::Black},
    };
        const std::map<Color, std::string> color2string{
            {Color::Yellow,"Yellow"},
            {Color::Red,"Red"},
            {Color::Blue,"Blue"},
            {Color::Black,"Black"},
    };
}