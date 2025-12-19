#include <iostream>
#include <string>


class Student {
private:
    std::string name;
    int age;

public:
    Student(std::string studentName, int studentAge) : name(studentName), age(studentAge) {}

    std::string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    std::string getInfo() {
        return  "학생 이름: " + name + "\n학생 나이: " + std::to_string(age);
    }
};

class StudentPrinter {
public:
    void print(Student& student) {
        std::cout << student.getInfo() << "\n";
    }
};

int main() {
    Student s("John Doe", 20);

    StudentPrinter printer;

    printer.print(s);

    return 0;
}