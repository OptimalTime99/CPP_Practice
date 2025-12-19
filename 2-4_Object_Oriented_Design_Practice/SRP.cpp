#include <iostream>
#include <string>

// 학생 정보 관리 클래스
class Student {
public:
    void setName(const std::string& name) {
        this->name = name;
    }

    std::string getName() const {
        return name;
    }

private:
    std::string name;
};

// 성적 계산 클래스
class GradeCalculator {
public:
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
};

// 출력 클래스
class StudentPrinter {
public:
    void displayDetails(const Student& student) {
        std::cout << "Student Name: " << student.getName() << std::endl;
    }
};
