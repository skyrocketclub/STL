// Function_Objects.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

struct Square_Functor {
    void operator()(int x) {
        std::cout << x * x << " ";
    }
};

template <typename T>
struct Displayer {
    void operator()(const T& data) {
        std::cout << data << " ";
    }
};

class Multiplier {
private:
    int num{};
public:
    Multiplier(int n)
        :num{ n } {

    }
    int operator()(int n)const {
        return n * num;
    }
};

int main()
{
    std::cout << "\nTest1=============================================================" << std::endl;
    Square_Functor square;
    square(4);

    Displayer <int> d1;
    Displayer <std::string> d2;
    d1(100);
    d2("Frank");

    std::cout << "\nTest2=============================================================" << std::endl;
    std::vector<int> vec1{ 1,2,3,4,5 };
    std::vector <std::string> vec2{ "Larry","Moe","Curly" };

    std::for_each(vec1.begin(), vec1.end(), square);
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), Displayer<int>());
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), d1);
    std::cout << std::endl;

    std::for_each(vec2.begin(), vec2.end(), Displayer<std::string>());
    std::cout << std::endl;

    std::for_each(vec2.begin(), vec2.end(), d2);
    std::cout << std::endl;

    std::cout << "\nTest3=============================================================" << std::endl;
    std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x * x << " ";});
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x * 10 << " ";});
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x  << " ";});
    std::cout << std::endl;

    std::for_each(vec2.begin(), vec2.end(), [](std::string s) {std::cout << s << " ";});
    std::cout << std::endl;

    std::cout << "\nTest4=================================================================" << std::endl;
    Multiplier mult(100);
    vec1 = { 1,2,3,4 };

    std::transform(vec1.begin(), vec1.end(), vec1.begin(), mult);
    std::for_each(vec1.begin(), vec1.end(), d1);
    std::cout << std::endl;

    vec1 = { 1,2,3,4 };
    std::transform(vec1.begin(), vec1.end(), vec1.begin(), [](int x) {return x * 100;});
    std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x << " ";});

    std::cout << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use he Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
