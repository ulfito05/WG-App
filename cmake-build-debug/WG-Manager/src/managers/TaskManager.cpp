#include "TaskManager.h"
#include <stdexcept>

// Hilfsfunktion: Task anhand ID finden
Task* TaskManager::findTaskById(int id) {
    for (auto &t : tasks) {
        if (t.getId() == id) {
            return &t;
        }
    }
    return nullptr;
}

void TaskManager::registerPerson(Person* p) {
    persons.push_back(p);
}

void TaskManager::addTask(const Task& task) {
    tasks.push_back(task);
}

Task* TaskManager::createTask(const std::string& title, const std::string& description) {
    int id = tasks.size() + 1; // einfacher Auto-ID Counter
    tasks.emplace_back(id, title, description);
    return &tasks.back();
}


void TaskManager::assignTask(int taskId, int personId) {
    Task* task = findTaskById(taskId);
    if (!task) {
        throw std::runtime_error("TaskManager: Task ID existiert nicht.");
    }

    for (auto* p : persons) {
        if (p->getId() == personId) {
            task->assignTo(p);
            return;
        }
    }

    throw std::runtime_error("TaskManager: Person ID existiert nicht.");
}

void TaskManager::setStatus(int taskId, int personId, int newStatus) {
    Task* task = findTaskById(taskId);
    if (!task) {
        throw std::runtime_error("TaskManager: Task ID existiert nicht.");
    }

    TaskStatus status = static_cast<TaskStatus>(newStatus);
    task->setStatus(status);
}

std::vector<Task> TaskManager::getTasks() const {
    return tasks;
}
