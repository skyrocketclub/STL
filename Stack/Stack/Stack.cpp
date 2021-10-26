// Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <vector>
#include <list>

template <typename T>

void display(std::stack<T> s) {
    std::cout << "[ ";
    while (!s.empty()) {
        T elem = s.top();
        s.pop();
        std::cout << elem << " ";
    }
    std::cout << " ]" << std::endl;
}

int main()
{
    std::stack<int>s;
    std::stack <int, std::vector<int>>s1;
    std::stack <int, std::vector<int>>s2;
    std::stack <int, std::vector<int>>s3;

    for (int i : {1, 2, 3, 4, 5})
        s.push(i);
    display(s);

    s.push(100);
    display(s);

    s.pop();
    s.pop();
    display(s);

    while (!s.empty())
        s.pop();
    display(s);

    std::cout << "Size: " << s.size() << std::endl;
    s.push(10);
    display(s);

    s.top() = 100;
    display(s);
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
