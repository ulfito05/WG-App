#pragma once
#include <vector>
#include "interfaces/ITaskManager.h"
#include "../model/Task.h"
#include "../model/Person.h"

class TaskManager : public ITaskManager {
private:
    std::vector<Task> tasks;
    std::vector<Person*> persons;

public:
    void registerPerson(Person* p);

    void addTask(const Task& task) override;
    void assignTask(int taskId, int personId) override;
    void setStatus(int taskId, int personId, int newStatus) override;
    std::vector<Task> getTasks() const override;
};
