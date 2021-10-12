// Generic_Array_template_class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

template <typename T, int N> //to enable the compiler create the array...
class Array {
    int size{ N };
    T values[N]; 

    friend std::ostream& operator<<(std::ostream& COUT, const Array<T,N> &arr) {
        COUT << "[ ";
        for (const auto& val : arr.values)
            COUT << val << " ";
        COUT << "]" << std::endl;
        return COUT;
    }

public:
    Array() = default; //default constructor

    Array(T init_val) {   //constructor with an initial value
        for (auto& item : values)
            item = init_val;
    }
    void fill(T val) {
        for (auto& item : values)
            item = val;
    }
    int get_size() const {
        return size;
    }

    //overloaded subscript operator for easy use as array indexing...
    T& operator[](int index) {
        return values[index];
    }
};
int main()
{
    Array<int, 5> nums;
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(0);
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(10);
    std::cout << nums << std::endl;

    nums[0] = 1000;
    nums[3] = 2000;
    std::cout << nums << std::endl;

    Array<int,100> nums2{ 1 };
    std::cout << "The size of nums2 is: " << nums2.get_size() << std::endl;
    std::cout << nums2 << std::endl;

    std::string word = "Frank";
    Array<std::string, 10> strings{ word };
    std::cout << "The size of strings is : " << strings.get_size() << std::endl;
    std::cout << strings << std::endl;

    strings[0] = std::string{ "Larry" };
    std::cout << strings << std::endl;
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
