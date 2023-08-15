//Task-4 To-Do list
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void addTask() {
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!\n";
}

void viewTasks() {
    cout << "----- To-Do List -----\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". ";
        cout << (tasks[i].completed ? "[X] " : "[ ] ");
        cout << tasks[i].description << endl;
    }
    cout << "----------------------\n";
}

void markTaskCompleted() {
    int index;
    cout << "Enter the task number to mark as completed: ";
    cin >> index;
    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed!\n";
    }
    else {
        cout << "Invalid task number.\n";
    }
}

void removeTask() {
    int index;
    cout << "Enter the task number to remove: ";
    cin >> index;
    if (index >= 1 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + (index - 1));
        cout << "Task removed successfully!\n";
    }
    else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n----- To-Do List Manager -----\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
