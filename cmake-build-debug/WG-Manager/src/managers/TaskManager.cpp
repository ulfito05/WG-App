#include "TaskManager.h"

void TaskManager::registerPerson(Person *p) {
    persons.push_back(p);
}

void TaskManager::addTask(const Task& task) {
    tasks.push_back(task);
}

void TaskManager::assignTask(int taskId, int personId) {
    for (auto& t : tasks) {
        if (t.getId() == taskId) {
            for (auto* p : persons) {
                if (p->getId() == personId) {
                    t.assignTo(p);
                    return;
                }
            }
        }
    }
}

void TaskManager::setStatus(int taskId, int /*personId*/, int newStatus) {
    for (auto& t : tasks) {
        if (t.getId() == taskId) {
            t.setStatus(static_cast<TaskStatus>(newStatus));
            return;
        }
    }
}

std::vector<Task> TaskManager::getTasks() const {
    return tasks;
}
