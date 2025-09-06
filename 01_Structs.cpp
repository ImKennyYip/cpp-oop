#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int age;
    std::vector<std::string> courses;

    void print_information() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;

        std::cout << "Courses: ";
        for (const std::string& course : courses) {
            std::cout << course << " ";
        }
        std::cout << std::endl;
    }

    void add_course(const std::string& newCourse) {
        for (const std::string& course : courses) {
            if (course == newCourse) {
                std::cout << "cannot add duplicate course: " << newCourse << std::endl;
                return; //end function
            }
        }
        courses.push_back(newCourse);
        std::cout << "course added: " << newCourse << std::endl;
    }
}; //must add semicolon

int main() {
    // In C++, structs are similar to classes
    // We can use a struct to define an entity with member variables and functions

    Student student1;
    student1.name = "Kenny";
    student1.age = 18;
    // student1.courses.push_back("calculus");
    // student1.courses.push_back("french");
    // student1.courses.push_back("economics");

    // std::cout << "Name: " << student1.name << std::endl;
    // std::cout << "Age: " << student1.age << std::endl;

    // std::cout << "Courses: ";
    // for (const std::string& course : student1.courses) {
    //     std::cout << course << " ";
    // }
    // std::cout << std::endl;

    student1.add_course("calculus");
    student1.add_course("french");
    student1.add_course("economics");
    student1.add_course("french");

    student1.print_information();

}

