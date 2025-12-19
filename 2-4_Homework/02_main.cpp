#include <iostream>
#include <string>
#include <vector>

class Task {
private:
    std::string description;
    bool completed;

public:
    Task(std::string desc) : description(desc), completed(false) {}

    void complete() {
        completed = true;
    }

    std::string getDescription() {
        return description;
    }

    bool isCompleted() {
        return completed;
    }


};

class IStorage {
public:
    virtual void addTask(Task task) = 0;
    virtual std::vector<Task> getTasks() = 0;
    virtual std::string getStorageType() = 0;
};

class MemoryStorage : public IStorage {
private:
    std::vector<Task> tasks;
public:
    void addTask(Task task) override {
        tasks.push_back(task);
    }

    std::vector<Task> getTasks() override {
        return tasks;
    }

    std::string getStorageType() override {
        return "메모리 저장소";
    }
};

class DBStorage : public IStorage {
private:
    std::vector<Task> tasks;
public:
    void addTask(Task task) override {
        std::cout << "DB에 할 일 추가: " << task.getDescription() << "\n";
        tasks.push_back(task);
    }

    std::vector<Task> getTasks() override {
        std::cout << "DB에서 할 일 가져오기\n";
        return tasks;
    }

    std::string getStorageType() override {
        return "DB 저장소 (시뮬레이션)";
    }
};

class TaskManager {
private:
    IStorage* storage;

public:
    TaskManager(IStorage* InStorage) : storage(InStorage) {}

    void addTask(const std::string& description) {
        storage->addTask(Task(description));
    }

    void showTasks() {
        std::cout << "저장 방식: " << storage->getStorageType() << "\n";
        std::vector<Task> tasks = storage->getTasks();
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].getDescription();
            if (tasks[i].isCompleted()) std::cout << " [완료]";
            std::cout << "\n";
        }
    }

    void completeTask(size_t index) {
        std::vector<Task> tasks = storage->getTasks();
        if (index > 0 && index <= tasks.size()) {
            tasks[index - 1].complete();
            storage->addTask(tasks[index - 1]); // 변경된 할 일 저장
        }
        else {
            std::cout << "잘못된 번호입니다.\n";
        }
    }
};


// 메인 함수
int main() {
    std::cout << "=== MemoryStorage로 작업 ===\n";
    MemoryStorage memoryStorage;
    TaskManager manager1(&memoryStorage);

    manager1.addTask("C++ 과제 작성하기");
    manager1.addTask("SOLID 원칙 공부하기");

    std::cout << "\n현재 할 일 목록:\n";
    manager1.showTasks();

    manager1.completeTask(1);

    std::cout << "\n업데이트된 할 일 목록:\n";
    manager1.showTasks();

    std::cout << "\n=== DBStorage로 작업 ===\n";
    DBStorage dbStorage;
    TaskManager manager2(&dbStorage);


    manager2.addTask("DB 작업 테스트");
    manager2.addTask("To-Do 목록 추가");

    std::cout << "\n현재 할 일 목록:\n";
    manager2.showTasks();

    manager2.completeTask(2);

    std::cout << "\n업데이트된 할 일 목록:\n";
    manager2.showTasks();

    return 0;
}