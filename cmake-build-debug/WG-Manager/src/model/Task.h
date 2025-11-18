#pragma once
#include <string>

class Person;
class Room;

enum class TaskStatus { OPEN, ASSIGNED, IN_PROGRESS, DONE };

class Task {
private:
    int id;
    std::string title;
    std::string description;
    TaskStatus status;
    Person* assignedTo;
    Room* room;

public:
    Task(int id, const std::string& title, const std::string& description = "");

    int getId() const;
    const std::string& getTitle() const;
    const std::string& getDescription() const;
    TaskStatus getStatus() const;
    Person* getAssignedTo() const;

    void assignTo(Person* person);
    void setStatus(TaskStatus newStatus);
};
