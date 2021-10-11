// Class Templates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

template <typename T>

class Item {
private:
    std::string name;
    T value;
public:
    Item(std::string name ,T value)
        : name{ name }, value{ value }
    {

    }
    std::string get_name() const {
        return name;
    }
    T get_value() const {
        return value;
    }
};

template <typename T1,typename T2>
struct My_Pair {
    T1 first;
    T2 second;
};

int main()
{
    Item<int> item1{"Frank", 100};
    std::cout << item1.get_name() << " " << item1.get_value() << std::endl;

    Item<std::string> item2{ "Frank","Professor" };
    std::cout << item2.get_name() << " " << item2.get_value() << std::endl;

    Item<Item<std::string>> item3{ "Frank", {"C++", "Professor"} };
    std::cout << item3.get_name() << " "
        << item3.get_value().get_name() << " "
        << item3.get_value().get_value() << std::endl;

    std::cout << "\n==============================================================================" << std::endl;
    std::vector<Item<double>>vec{};
    vec.push_back(Item<double>("Larry", 100.00));
    vec.push_back(Item<double>("Moe", 200.00));
    vec.push_back(Item<double>("Curry", 300.00));

    for (const auto& item : vec) {
        std::cout << item.get_name() << " " << item.get_value() << std::endl;
    }
    std::cout << "\n==============================================================================" << std::endl;
    My_Pair <std::string, int> p1{ "Frank",100 };
    My_Pair <int, double> p2{ 124, 13.6 };

    std::cout << p1.first << " , " << p1.second << std::endl;
    std::cout << p2.first << " , " << p2.second << std::endl;

    return 0;

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
