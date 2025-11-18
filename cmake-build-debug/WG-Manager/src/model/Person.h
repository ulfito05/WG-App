#pragma once
#include <string>

class Person {
private:
    int id;
    std::string name;
    bool isAdmin;

public:
    Person(int id, const std::string& name, bool admin = false);

    int getId() const;
    const std::string& getName() const;
    bool getIsAdmin() const;

    void setName(const std::string& newName);
};
