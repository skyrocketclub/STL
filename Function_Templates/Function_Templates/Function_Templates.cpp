// Function_Templates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

template <typename T>
T min(T a, T b) {
    return (a < b) ? a : b;
}

template <typename T1, typename T2>
void func(T1 a, T2 b) {
    std::cout << a << " " << b << std::endl;
}

struct Person { //in struct everything is public
    std::string name;
    int age;
    bool operator <(const Person& rhs) const { //the less than operator is overloaded here........
        return this->age < rhs.age;
    }
};

std::ostream& operator<<(std::ostream& COUT, const Person& p) {
    COUT << p.name;
    return COUT;
}


template <typename T>
void my_swap(T &a, T &b) {// we do not want to modify a copy but we want to swap the main arguments
    T temp = a;
    a = b;
    b = temp;
}
int main()
{

    int x{ 100 };
    int y{ 200 };
    std::cout << x << "," << y << std::endl;
    my_swap <int> (x, y);
    std::cout << x << "," << y << std::endl;

    Person p1{ "Curly",5 };
    Person p2{ "Moe", 30 };

    Person p3 = min(p1, p2);
    std::cout << p3.name << " is younger" << std::endl;

    func(p1, p2);



    std::cout << min<int>(2, 3) << std::endl; //In this case, the typename is an integer
    std::cout << min(2, 3) << std::endl;
    std::cout<< min('A', 'B') << std::endl;
    std::cout << min(12.5, 9.2) << std::endl;
    std::cout << min(5 + 2 * 2, 7 + 40) << std::endl;

    func <int, int>(10, 20);
    func(10, 20);
    func<char, double>('A', 12.4);
    func('A', 12.4);
    func(1000, "Testing");
    func(2000, std::string{ "Frank" });
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
