// Palindrome_Challenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cctype>
#include <deque>
#include <vector>
#include <algorithm>
#include <iomanip>

std::string capitalise(std::string);
bool is_palindrome(std::string);
std::string extract(std::string);

int main()
{
    std::vector <std::string> test_strings{"a","aa","abba","A man, a plan, a cat, a ham, a yak,a yam, a hat, a canal-Panama!", "A santa at NASA"};

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for (auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }
    std::cout << std::endl;
}


std::string capitalise(std::string word) {
    std::transform(word.begin(), word.end(), word.begin(), toupper);
    return word;
}

bool is_palindrome(std::string test) {
    bool status{ false };
    test = extract(test);
    test = capitalise(test);
    //std::cout << test << std::endl;

    std::deque<char> fr;
    std::deque<char>bck;

    for (auto elem : test) {
        fr.push_front(elem);
        bck.push_back(elem);
    }
    if (fr == bck) {
        status = true;
    }
    
    return status;
}

std::string extract(std::string test) {
    std::string test_case;
    auto it = test.begin();
    //remember it acts like a pointer

    for (auto item : test) {
        if (isalpha(*it)) {
            test_case += item;
        }
        it++;
    }
    return test_case;
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
