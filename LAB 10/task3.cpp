// Assume you are tasked to schedule computer tasks. Given task from t1 to tn you must
// schedule them in the given manner down below.
// Note:
// Each task that is being pooled comes with a priority (generate this priority randomly
// between values 1 to 10). The value with the highest priority gets the first treatment and
// then subsequent nodes will get later priorities. Once the tree is built up delete the nodes
// accordingly to the priority (Max to min) while also printing the order.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct TaskNode {
    string taskName;
    int taskPriority;
    TaskNode* nextTask;

    TaskNode(string name, int priority) {
        this->taskName = name;
        this->taskPriority = priority;
        this->nextTask = NULL;
    }
};

class TaskScheduler {
private:
    TaskNode* topTask;

public:
    TaskScheduler() {
        topTask = NULL;
    }

    void addTask(string name, int priority) {
        TaskNode* newTask = new TaskNode(name, priority);
        if (topTask == NULL || newTask->taskPriority > topTask->taskPriority) {
            newTask->nextTask = topTask;
            topTask = newTask;
        } else {
            TaskNode* current = topTask;
            while (current->nextTask != NULL && current->nextTask->taskPriority >= newTask->taskPriority) {
                current = current->nextTask;
            }
            newTask->nextTask = current->nextTask;
            current->nextTask = newTask;
        }
    }

    void processTask() {
        if (topTask == NULL) {
            cout << "No tasks to process." << endl;
        } else {
            TaskNode* toProcess = topTask;
            cout << "Processing: " << toProcess->taskName << " with priority " << toProcess->taskPriority << endl;
            topTask = topTask->nextTask;
            delete toProcess;
        }
    }

    bool hasTasks() {
        return topTask != NULL;
    }
};

int main() {
    TaskScheduler scheduler;

    srand(time(0));

    string tasks[] = {"TaskA", "TaskB", "TaskC", "TaskD", "TaskE"};
    int totalTasks = sizeof(tasks) / sizeof(tasks[0]);

    for (int i = 0; i < totalTasks; i++) {
        int randomPriority = rand() % 10 + 1;
        scheduler.addTask(tasks[i], randomPriority);
        cout << "Added: " << tasks[i] << " with priority " << randomPriority << endl;
    }

    cout << "\nOrder of Task Execution:" << endl;
    while (scheduler.hasTasks()) {
        scheduler.processTask();
    }

    return 0;
}
