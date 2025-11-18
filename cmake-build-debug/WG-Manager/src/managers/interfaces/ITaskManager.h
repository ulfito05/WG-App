#pragma once
#include <vector>

class Task;

class ITaskManager {
public:
    virtual void addTask(const Task& task) = 0;
    virtual void assignTask(int taskId, int personId) = 0;
    virtual void setStatus(int taskId, int personId, int newStatus) = 0;
    virtual std::vector<Task> getTasks() const = 0;

    virtual ~ITaskManager() = default;
};
