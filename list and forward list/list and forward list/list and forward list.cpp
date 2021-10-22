// list and forward list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator> 
#include <string>

using namespace std;
class Person {
    friend std::ostream& operator<<(std::ostream& COUT, const Person& p);
    std::string name;
    int age;

public:
    Person() //default constructor
        :name{ "Unknown" }, age{ 0 }{

    }
    Person(std::string name, int age)
        :name{ name }, age{ age }{

    }
    bool operator < (const Person& rhs)const {
        return this->age < rhs.age;
    }
    bool operator == (const Person& rhs)const {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

std::ostream &operator <<(std::ostream& COUT, const Person& p) {
    COUT << p.name << " : " << p.age;
    return COUT;
}

template <typename T>
void display(const std::list<T>& i) {
    std::cout << "[ ";
    for (const auto& elem : i) {
        std::cout << elem << " ";
    }
    std::cout << " ]" << std::endl;
}

void test1() {
    std::cout << "\nTest1====================================================================" << std::endl;

    std::list<int> l1{ 1,2,3,4,5 };
    display(l1);

    std::list <std::string> l2;
    l2.push_back("Back");
    l2.push_front("Front");
    display(l2);

    std::list<int> l3;
    l3 = { 1,2,3,4,5,6,7,8,9,10 };
    display(l3);

    std::list < int> l4 (10, 100);
    display(l4);
}

void test2() {
    std::cout << "\nTest2====================================================================" << std::endl;
    std::list<int> l{ 1,2,3,4,5,6,7,8,9,10 };
    display(l);
    std::cout << "Size: " << l.size() << std::endl;
    std::cout << "Front: " << l.front() << std::endl;
    std::cout << "Back: " << l.back() << std::endl;

    l.clear();
    display(l);
    std::cout << "Size: " << l.size() << std::endl;
}

void test3() {
    std::cout << "\nTest3====================================================================" << std::endl;
    std::list<int> l{ 1,2,3,4,5,6,7,8,9,10 };
    display(l);
    l.resize(5);
    display(l);
    l.resize(10);
    display(l);

    std::list<Person> persons;
    persons.resize(5);
    display(persons);
}

void test4() {
    std::cout << "\nTest4====================================================================" << std::endl;
    std::list<int> l {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l);
    auto it = std::find(l.begin(), l.end(), 5);
    if (it != l.end()) {
        l.insert(it, 100);
    }
    display(l);

    std::list<int> l2{ 1000,2000,3000 };
    l.insert(it, l2.begin(), l2.end());
    display(l);

    std::advance(it, -4);
    std::cout << *it << std::endl;

    l.erase(it);
    display(l);
}

void test5() {
    std::cout << "\nTest5====================================================================" << std::endl;

    std::list<Person> stooges{
        {"Larry",18},{"Moe", 25}, {"Curly", 17}
    };

    display(stooges);
    std::string name;
    int age{};
    std::cout << "\nEnter the name of the next stooge: ";
    std::getline(std::cin, name);
    std::cout << "Enter their age: ";
    std::cin >> age;

    stooges.emplace_back(name, age);
    display(stooges);

    auto it = std::find(stooges.begin(), stooges.end(), Person{ "Moe", 25 });
    if (it!= stooges.end()) { //this checks if it is there...
        stooges.emplace(it, "Frank", 18);
    }
    display(stooges);
}

void test6() {
    std::cout << "\nTest6====================================================================" << std::endl;
    std::list<Person> stooges{
        {"Larry",18},{"Moe", 25}, {"Curly", 17}
    };
    display(stooges);
    stooges.sort();
    display(stooges);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
