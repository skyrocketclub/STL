// QUEUE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>


template <typename T>

void display(std::queue<T> s) {
    std::cout << "[ ";
    while (!s.empty()) {
        T elem = s.front();
        s.pop();
        std::cout << elem << " ";
    }
    std::cout << " ]" << std::endl;

}
int main()
{
    std::queue<int> q;

    for (int i : {1, 2, 3, 4, 5})
        q.push(i);
    display(q);

    q.pop();
    q.pop();
    display(q);

    while (!q.empty())
        q.pop();
    display(q);

    std::cout << "Size: " << q.size() << std::endl;

    q.push(10);
    q.push(100);
    q.push(1000);
    display(q);

    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;

    q.front() = 5;
    q.back() = 5000;

    display(q);
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;
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
