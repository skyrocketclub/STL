// Array_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <algorithm>
#include <numeric> //for more algorithms like accumulate

void display(const std::array<int, 5>& arr){
std::cout << "[ ";
    for (const auto& pins : arr) {
        std::cout << pins << " ";
    }
    std::cout << "]" << std::endl;
}

void test1() {
    std::cout << "\nTest1====================================================================" << std::endl;
    std::array<int, 5>arr1{ 1,2,3,4,5 }; 
    std::array<int, 5>arr2;

    display(arr1);
    display(arr2);

    arr2 = { 10,20,30,40,50 };

    display(arr1);
    display(arr2);

    std::cout << "Size of arr1 is: " << arr1.size() << std::endl;
    std::cout << "Size of arr2 is: " << arr2.size() << std::endl;

    arr1[0] = 1000;
    arr1.at(1) = 2000;
    display(arr1);

    std::cout << "Front of arr2: " << arr2.front() << std::endl;
    std::cout << "Back of arr2: " << arr2.back() << std::endl;
}

void test2() {
    std::cout << "\nTest2============================================================" << std::endl;
    std::array<int, 5>arr1{ 1,2,3,4,5 }; 
    std::array<int, 5> arr2{ 10,20,30,40,50 };

    display(arr1);
    display(arr2);

    arr1.fill(0);

    display(arr1);
    display(arr2);

    arr1.swap(arr2);

    display(arr1);
    display(arr2);
}

void test3() {
    std::cout << "\nTest3===========================================================" << std::endl;
    std::array<int, 5> arr1{ 1,2,3,4,5 };

    int* ptr = arr1.data();
    std::cout << ptr << std::endl;
    *ptr = 100000;

    display(arr1);
}

void test4() {
    std::cout << "\nTest4=======================================================" << std::endl;

    std::array<int, 5> arr1{ 2,1,4,5,3 };
    display(arr1);

    std::sort(arr1.begin(), arr1.end());
    display(arr1);
}

void test5() {
    std::cout << "\nTest5=======================================================" << std::endl;
    std::array<int, 5> arr1{ 2,1,4,5,3 };
    std::array<int, 5> ::iterator min_num;
    min_num = std::min_element(arr1.begin(), arr1.end());

    auto max_num = std::max_element(arr1.begin(), arr1.end());
    std::cout << "min: " << *min_num << " ,max: " << *max_num << std::endl;
}

void test6() {
    std::cout << "\nTest6==================================================================" << std::endl;
    std::array<int, 5> arr1{ 2,1,3,3,5 };

    auto adjacent = std::adjacent_find(arr1.begin(), arr1.end());
    if (adjacent != arr1.end()) {
        std::cout << "Adjacent element found with value: " << *adjacent << std::endl;
    }
    else {
        std::cout << "No adjacent elements found" << std::endl;
    }
}

void test7() {
    std::cout << "Test7======================================================" << std::endl;
    std::array<int, 5> arr1{ 1,2,3,4,5 };

    //#include <numeric> needed to use the accumulate algorithm
    int sum = std::accumulate(arr1.begin(), arr1.end(), 2);// the number two serves as the base number to which the others are added
    std::cout << "Sum of the elements in arr1 is: " << sum << std::endl;
}

void test8() {
    std::cout << "\nTest8========================================================" << std::endl;
    std::array<int, 10> arr1{ 1,2,3,1,2,3,3,3,3,3 };

    int count = std::count(arr1.begin(), arr1.end(), 3);
    std::cout << "Founc 3: " << count << " times" << std::endl;
}

void test9() {
    std::cout << "\nTest9=========================================================" << std::endl;
    std::array<int, 10> arr1{ 1,2,3,50,60,70,80,200,300,400 };

    int count = std::count_if(arr1.begin(), arr1.end(), [](int x) {return x > 10 && x < 200;});
    std::cout << "Found " << count << " matches" << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
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
