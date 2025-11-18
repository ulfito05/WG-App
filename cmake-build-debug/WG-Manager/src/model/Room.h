#pragma once
#include <string>

class Room {
private:
    std::string name;

public:
    Room(const std::string& name);

    const std::string& getName() const;
};
