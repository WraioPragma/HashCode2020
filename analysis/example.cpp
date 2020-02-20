#include "example_help.hpp"
#include <iostream>

int main()
{
    const auto data  = toml::parse("example.toml");
    const auto title = toml::find<int>(data, "x");
    // const auto title = toml::find<std::string>(data, "x");
    std::cout << "the title is " << title << std::endl;
    const auto& fruit = toml::find(data, "fruit");
const auto  name  = toml::find<std::string>(fruit, "apple");

const auto& physical = toml::find(fruit, "physical");
const auto  color    = toml::find<std::string>(fruit, "color");
const auto  shape    = toml::find<std::string>(fruit, "shape");
    return 0;
}

