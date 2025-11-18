#include "Person.h"

Person::Person(int id, const std::string& name, bool admin)
        : id(id), name(name), isAdmin(admin) {}

int Person::getId() const {
        return id;
}

const std::string& Person::getName() const {
        return name;
}

bool Person::getIsAdmin() const {
        return isAdmin;
}

void Person::setName(const std::string& newName) {
        name = newName;
}
