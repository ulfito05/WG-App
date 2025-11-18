#include "Room.h"

Room::Room(const std::string& name)
        : name(name) {}

const std::string& Room::getName() const { return name; }
