// Associative_Containers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>

class Person {
    friend std::ostream& operator << (std::ostream& COUT, const Person& p);
    std::string name;
    int age;

public:
    Person()
        :name{ "Unknown" }, age{ 0 }{

    }
    Person(std::string name, int age)
        : name{ name }, age{ age }{

    }
    bool operator <(const Person& rhs)const {
        return this->age < rhs.age;
    }
    bool operator == (const Person& rhs) const {
        return (this->name == rhs.name && this-> age == rhs.age);
    }
};

std::ostream& operator<<(std::ostream& COUT, const Person& p) {
    COUT << p.name << " : " << p.age;
    return COUT;
}


template<typename T>
void display(const std::set<T>& l) {
    std::cout << "[ ";
    for (const auto& elem : l) {
        std::cout << elem << " ";
    }
    std::cout << " ]" << std::endl;
}

void test1() {
    std::cout << "\nTest1===============================================================" << std::endl;
    std::set<int> s1{ 1,4,3,5,2 };
    display(s1);

    s1 = { 1,2,3,1,1,2,2,3,3,4,5 };
    display(s1);

    s1.insert(0);
    s1.insert(10);
    display(s1);

    if (s1.count(10)) {
        std::cout << "10 is in the set" << std::endl;
    }
    else {
        std::cout << "10 is not in the set" << std::endl;
    }

    auto it = s1.find(5);
    if (it != s1.end()) {
        std::cout << "Found: " << *it << std::endl;
    }

    s1.clear();
    display(s1);
}

void test2() {
    std::cout << "\nTest1===============================================================" << std::endl;
    std::set<Person> stooges{
        {"Larry",1},{"Moe",2}, {"Curly",3}
    };
    display(stooges);
    stooges.emplace("James", 50);
    display(stooges);

    stooges.emplace("Frank", 50);
    display(stooges);

    auto it = stooges.find(Person{ "Moe",2 });
    if (it != stooges.end()) {
        stooges.erase(it);
    }
    display(stooges);

    it = stooges.find(Person{ "XXXX", 50 });
    if (it != stooges.end()) {
        stooges.erase(it);
    }
    display(stooges);
}

void test3() {
    std::cout << "\nTest3===============================================================" << std::endl;

    std::set<std::string> s{ "A","B","C" };
    display(s);

    auto result = s.insert("D");
    display(s);

    std::cout << std::boolalpha;
    std::cout << "first: " << *(result.first) << std::endl;
    std::cout << "second: " << result.second << std::endl;

    std::cout << std::endl;

    result = s.insert("A");
    display(s);

    std::cout << std::boolalpha;
    std::cout << "first: " << *(result.first) << std::endl;
    std::cout << "second: " << result.second << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
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
