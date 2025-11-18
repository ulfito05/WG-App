#include <iostream>
#include "model/WG.h"

int main() {
    WG wg("Meine WG");

    wg.addPerson(Person(1, "Alice", true));
    wg.addPerson(Person(2, "Bob"));

    wg.getTaskManager().addTask(Task(1, "Bad putzen"));
    wg.getTaskManager().assignTask(1, 2);
    wg.getTaskManager().setStatus(1, 2, static_cast<int>(TaskStatus::IN_PROGRESS));

    for (const auto& t : wg.getTaskManager().getTasks()) {
        std::cout << "Task: " << t.getTitle()
                  << " | assigned to: "
                  << (t.getAssignedTo() ? t.getAssignedTo()->getName() : "none")
                  << " | status: " << static_cast<int>(t.getStatus())
                  << std::endl;
    }

    return 0;
}
