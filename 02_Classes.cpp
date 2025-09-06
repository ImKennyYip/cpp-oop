#include <iostream>
#include <string>
#include <vector>

class Student {
    std::vector<std::string> courses;

    public:
        std::string name;
        int age;
    
    // private:
    //     std::vector<std::string> courses;

    // public:
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
    // Access specifiers control how the members of a class can be accessed.
    //     public - members are accessible outside the class
    //     private - members cannot be accessed outside the class
    //     protected - members cannot be accessed outside the class, but can be accessed by inheritance
    // In C++, structs are public by default, classes are private

    Student student1;
    student1.name = "Kenny";
    student1.age = 18;
    // student1.courses.push_back("calculus");
    // student1.courses.push_back("french");
    // student1.courses.push_back("economics");

    student1.add_course("calculus");
    student1.add_course("french");
    student1.add_course("economics");
    student1.add_course("french");

    student1.print_information();
}

