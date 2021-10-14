// iterators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

void display(const std::vector<int>& vec) {
    std::cout << "[ ";
    for (auto const& i : vec) {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

void test1() {
    std::cout << "\n=============================================================" << std::endl;
    std::vector<int> nums1{ 1,2,3,4,5 };
    auto it = nums1.begin();//points to 1
    std::cout << *it << std::endl; //the iterator is being dereferenced...

    it++;
    std::cout << *it << std::endl;

    it += 2;
    std::cout << *it << std::endl;

    it -= 2;
    std::cout << *it << std::endl;

    it = nums1.end() - 1;
    std::cout << *it << std::endl;
}

void test2() {
    std::cout << "\n===========================================================" << std::endl;
    std::vector <int> nums1{ 1,2,3,4,5 };
    std::vector<int>::iterator it = nums1.begin();

    while (it != nums1.end()) {
        std::cout << *it << std::endl;
        it++;
    }

    it = nums1.begin();
    while (it != nums1.end()) {
        *it = 0;        //the iterator is dereferenced here...
        it++;
    }

    display(nums1);
}

void test3() {
    std::cout << "\n=============================================================" << std::endl;
    std::vector<int> nums1{ 1,2,3,4,5 };
   /* std::vector<int> ::const_iterator it1 = nums1.begin();*/
    auto it1 = nums1.cbegin();

    while (it1 != nums1.end()) {
        std::cout << *it1 << std::endl;
        it1++;
    }

    it1 = nums1.begin();
    while (it1 != nums1.end()) {
        it1++;
    }
}

void test4() {
    std::vector<int> vec{ 1,2,3,4,5 };
    auto it1 = vec.rbegin();
    while (it1 != vec.rend()) {
        std::cout << *it1 << std::endl;
        it1++;
    }
    std::list<std::string> name{ "larry", "Moe", "Curly" };
    auto it2 = name.crbegin();
    std::cout << *it2 << std::endl;
    it2++;
    std::cout << *it2 << std::endl;

    std::map<std::string, std::string> favorites{ {"Frank", "C++"}, {"Bill","Java"}, {"James", "Haskell"} };
    auto it3 = favorites.begin();
    while (it3 != favorites.end()) {
        std::cout << it3->first << " : " << it3->second << std::endl;
        it3++;
    }
}

void test5() {
    std::vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
    auto start = vec.begin() + 2;
    auto finish = vec.end() - 3;

    while (start != finish) {
        std::cout << *start << std::endl;
        start++;
    }
}

int main()
{
   /* test1();*/
    /*test2();*/
    test3();
    test4();
    test5();
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
