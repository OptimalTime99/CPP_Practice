#include <iostream>
#include <string>

class Student {
public:
    void setName(const std::string& name) {
        this->name = name;
    }

    void displayDetails() {
        std::cout << "Student Name: " << name << std::endl;
    }

    void calculateGrade(int score) {
        if (score >= 90) {
            std::cout << "Grade: A" << std::endl;
        }
        else if (score >= 80) {
            std::cout << "Grade: B" << std::endl;
        }
        else {
            std::cout << "Grade: C" << std::endl;
        }
    }

private:
    std::string name;
};
