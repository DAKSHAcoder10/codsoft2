#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void addTask(vector<Task> &tasks, const string &description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully.\n";
}

void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks found.\n";
        return;
    }

    cout << "Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed)
            cout << " [Completed]";
        cout << endl;
    }
}

void markTaskCompleted(vector<Task> &tasks, size_t index) {
    if (index >= tasks.size()) {
        cout << "Invalid task index.\n";
        return;
    }

    tasks[index].completed = true;
    cout << "Task marked as completed.\n";
}

void removeTask(vector<Task> &tasks, size_t index) {
    if (index >= tasks.size()) {
        cout << "Invalid task index.\n";
        return;
    }

    tasks.erase(tasks.begin() + index);
    cout << "Task removed successfully.\n";
}

int main() {
    vector<Task> tasks;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string description;
                cout << "Enter task description: ";
                cin.ignore(); // Clear input buffer
                getline(cin, description);
                addTask(tasks, description);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                size_t index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                markTaskCompleted(tasks, index - 1);
                break;
            }
            case 4: {
                size_t index;
                cout << "Enter task index to remove: ";
                cin >> index;
                removeTask(tasks, index - 1);
                break;
            }
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please choose again.\n";
        }
    }

    return 0;
}

