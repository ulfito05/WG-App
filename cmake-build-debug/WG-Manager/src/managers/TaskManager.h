#pragma once
#include <vector>
#include <optional>
#include "interfaces/ITaskManager.h"
#include "../model/Task.h"
#include "../model/Person.h"

class TaskManager : public ITaskManager {
private:
    std::vector<Task> tasks;
    std::vector<Person*> persons;

    Task* findTaskById(int id);

public:
    void registerPerson(Person* p);

    void addTask(const Task& task) override;
    void assignTask(int taskId, int personId) override;
    void setStatus(int taskId, int personId, int newStatus) override;
    std::vector<Task> getTasks() const override;
    Task* createTask(const std::string& title, const std::string& description = "");

};
