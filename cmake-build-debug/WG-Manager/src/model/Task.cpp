#include "Task.h"

Task::Task(int id, const std::string& title, const std::string& description)
        : id(id), title(title), description(description),
          status(TaskStatus::OPEN),
          assignedTo(nullptr),
          room(nullptr) {}

int Task::getId() const { return id; }
const std::string& Task::getTitle() const { return title; }
const std::string& Task::getDescription() const { return description; }
TaskStatus Task::getStatus() const { return status; }
Person* Task::getAssignedTo() const { return assignedTo; }

void Task::assignTo(Person* person) {
    assignedTo = person;
    status = TaskStatus::ASSIGNED;
}

void Task::setStatus(TaskStatus newStatus) {
    status = newStatus;
}
