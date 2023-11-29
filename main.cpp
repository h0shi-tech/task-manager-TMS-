#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& desc) {
        tasks.emplace_back(desc);
        std::cout << "Задача добавлена: " << desc << std::endl;
    }

    void markComplete(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            std::cout << "Задача выполнена: " << tasks[index].description << std::endl;
        } else {
            std::cout << "Некорректный индекс задачи" << std::endl;
        }
    }

    void displayTasks() const {
        if (tasks.empty()) {
            std::cout << "Список задач пуст." << std::endl;
        } else {
            std::cout << "Список задач:" << std::endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". ";
                if (tasks[i].completed) {
                    std::cout << "[x] ";
                } else {
                    std::cout << "[ ] ";
                }
                std::cout << tasks[i].description << std::endl;
            }
        }
    }
};

int main() {
    TaskManager taskManager;

    while (true) {
        std::cout << "1. Добавить задачу\n";
        std::cout << "2. Пометить задачу выполненной\n";
        std::cout << "3. Вывести список задач\n";
        std::cout << "4. Выйти\n";

        int choice;
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore(); // Очистка буфера перед вводом строки
                std::cout << "Введите описание задачи: ";
                std::string desc;
                std::getline(std::cin, desc);
                taskManager.addTask(desc);
                break;
            }
            case 2: {
                std::cout << "Введите номер задачи для отметки выполненной: ";
                int index;
                std::cin >> index;
                taskManager.markComplete(index - 1);
                break;
            }
            case 3:
                taskManager.displayTasks();
                break;
            case 4:
                return 0;
            default:
                std::cout << "Некорректный выбор. Попробуйте снова." << std::endl;
        }
    }

    return 0;
}