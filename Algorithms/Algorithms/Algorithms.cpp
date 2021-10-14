// Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

class Person {
    std::string name;
    int age;
public:
    Person() = default;

    Person(std::string name, int age)
        :name{ name }, age{ age }{

    }
    //overloading the less than operator
    bool operator <(const Person& rhs)const {
        return this->age < rhs.age;
    }

    //overloading the equality operator...
    bool operator == (const Person& rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

void find_test() {
    std::cout << "\n===================================================" << std::endl;

    std::vector<int>vec{ 1,2,3,4,5 };
    auto loc = std::find(vec.begin(), vec.end(), 1); //the first occurrence is what is sought here...
    if (loc != vec.end()) {
        std::cout << "Found the number: " << *loc << std::endl;
    }
    else {
        std::cout << "Couldn't find the number" << std::endl;
    }

    std::list<Person> players{ {"Larry",18},{"Moe", 20}, {"Curly",21} };

    auto loc1 = std::find(players.begin(), players.end(), Person{ "Moe",20 });
    if (loc1 != players.end()) {
        std::cout << "Found Moe" << std::endl;
    }
    else {
        std::cout << "Moe not found" << std::endl;
    }
}

void count_test() {
    std::cout << "\n====================================================" << std::endl;
    std::vector<int>vec{ 1,2,3,4,5,1,2,1 };
    int num = std::count(vec.begin(), vec.end(), 17);
    std::cout << num << " occurrences found" << std::endl;
}

void count_if_test() {
    std::cout << "\n=====================================================" << std::endl;
    std::vector<int> vec{ 1,2,3,4,5,1,2,1,100 };
    int num = std::count_if(vec.begin(), vec.end(), [](int x) {return x % 2 == 0;});
    std::cout << num << " even numbers found" << std::endl;

    num = std::count_if(vec.begin(), vec.end(), [](int x) {return x % 2 != 0;});
    std::cout << num << " odd numbers found " << std::endl;

    num = std::count_if(vec.begin(), vec.end(), [](int x) {return x >= 5;});
    std::cout << num << " numbers are greater than or equal to 5" << std::endl;
}

void replace_test() {
    std::cout << "\n======================================================" << std::endl;
    std::vector<int> vec{ 1,2,3,4,5,1,2,1 };
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::replace(vec.begin(), vec.end(), 1, 100);
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void all_of_test() {
    std::vector<int> vec1{ 1,3,5,7,9,1,3,12,19,5 };
    if (std::all_of(vec1.begin(), vec1.end(), [](int x) {return x > 10;}))
        std::cout << "All the elements are > 10" << std::endl;
    else {
        std::cout << "Not all the elements are > 10 " << std::endl;
    }
    if (std::all_of(vec1.begin(), vec1.end(), [](int x) {return x < 20;}))
        std::cout << "All the elements are <20" << std::endl;
    else
        std::cout << "Not all the elements are < 20" << std::endl;
}

void string_transform_test() {
    std::cout << "\n===================================================" << std::endl;

    std::string str1{ "This is a test" };
    std::cout << "Before transform: " << str1 << std::endl;
    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    std::cout << "After Transform " << str1 << std::endl;
}

int main()
{
   /* find_test();*/
  /*  count_test();
    count_if_test();*/
  /*  replace_test();*/
    all_of_test();
    string_transform_test();
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
