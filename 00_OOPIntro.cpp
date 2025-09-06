#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class SortedList : public std::vector<std::string> {
    public:
        void push_back_sort(const std::string& item) {
            push_back(item);
            std::sort(begin(), end());
        }
};

int main() {
    // Object Oriented Programming is a paradigm that involves representing abstract and physical objects
    // Data: string (text), int/float/double (numbers), bool (switches/enablement)

    // e.g. vector (list), video games (characters, items, weapons)
    //      shopping (customer, products, cart), shapes (circle, triangle, square)

    // OOP involves creating classes, and objects (instances)
    // In C++, there is also the struct.

    // e.g. vector is a class https://cplusplus.com/reference/vector/vector/
    std::vector<std::string> shoppingList; //shoppingList is an instance (object) of a vector

    // objects have properties (fields, member variables, data members, attributes)
    // e.g. vector (list) has an int size, int capacity, and array
    
    //objects have behaviors (methods, member functions)
    // e.g can remove and add to a vector (list)
    shoppingList.push_back("pencil");
    shoppingList.push_back("notebook");
    shoppingList.pop_back();





    // Abstraction
    // Classes/Objects are provided as a black box.
    // (Implementation detail is not too important)
    // vectors is implemented with an array but a user doesn't need to worry about that
    // users are provided with methods to add/remove from the array without directly modifying it
    
    std::vector<std::string> shoppingList; //shoppingList is an instance (object) of a vector
    shoppingList.push_back("notebook"); //no need to figure out the last index of array
    std::cout << shoppingList.empty() << std::endl; //no need to check if size == 0





    // Encapsulation
    // Structuring class in a single unit with controlled access (data hiding, delegation)
    // users are not allowed to directly access this underlying array and write past the memory
    // users must instead use the provided methods to add/remove
    
    std::vector<std::string> shoppingList; //shoppingList is an instance (object) of a vector
    // shoppingList.size = 10; //size variable is not exposed
    // std::cout << shoppingList.size << std::endl;
    std::cout << shoppingList.size() << std::endl;





    // Polymorphism
    // the word has greek origin - poly "many" and morph (form). Polymorphism refers to many forms
    // multiple constructors (initialization)
    // std::vector<std::string> shoppingList({"notebook", "pencil", "eraser"});
    // std::vector<std::string> shoppingList;

    // multiple methods that do the same thing
    std::cout << shoppingList.at(0) << std::endl;
    std::cout << shoppingList[0] << std::endl;

    



    // Inheritance
    // the process of creating a new child class (derived or sub/supra class) for code reusability
    // that inherits attributes and methods from an existing parent class (base or super class). 
    // can be used to add new features upon an existing class

    SortedList shoppingList2;
    shoppingList2.push_back_sort("pencil");    
    shoppingList2.push_back_sort("eraser");
    shoppingList2.push_back_sort("notebook");

    for (auto it = shoppingList2.begin(); it != shoppingList2.end(); it++) {
        std::cout << *it << std::endl;
    }
}

