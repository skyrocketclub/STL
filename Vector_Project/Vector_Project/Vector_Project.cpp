// Vector_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

//When using your own class with the STL, always overload the equality and the less than operator
class Person {
	friend std::ostream& operator <<(std::ostream& COUT, const Person& p);
	std::string name;
	int age;

public:
	Person() = default;
	Person(std::string name, int age)
		:name{ name }, age{ age }{

	}

	bool operator < (const Person& rhs) const {
		return this->age < rhs.age;
	}

	bool operator == (const Person& rhs) const {
		return (this->name == rhs.name && this->age == rhs.age);

	}
};

std::ostream& operator<<(std::ostream& COUT, const Person& p) {
	COUT << p.name << " : " << p.age;
	return COUT;
}

void display2(const std::vector<int>& vec) {
	std::cout << "[ ";
	std::for_each(vec.begin(), vec.end(), [](int x) {std::cout << x << " ";});
	std::cout << " ]" << std::endl;
}

template <typename T>
void display(const std::vector<T> &vec) {
	std::cout << "[ ";
	for (const auto& elem : vec) {
		std::cout << elem << " ";
	}
	std::cout << " ]" << std::endl;
}

void test1() {
	std::cout << "\nTest1=================================================================" << std::endl;
	std::vector<int> vec{ 1,2,3,4,5 };
	display(vec);

	vec = { 2,4,5,6 };
	display2(vec);

	std::vector <int>vec1(10, 100);
	display(vec1);
}

void test2() {
	std::cout << "\nTest2====================================================================" << std::endl;
	std::vector<int> vec{ 1,2,3,4,5 };
	display(vec);
	std::cout << "\nvec size: " << vec.size() << std::endl;
	std::cout << "vec max size: " << vec.max_size() << std::endl;
	std::cout << "vec capacity: " << vec.capacity() << std::endl;

	vec.push_back(6);
	display(vec);
	std::cout << "\nvec size: " << vec.size() << std::endl;
	std::cout << "vec max size: " << vec.max_size() << std::endl;
	std::cout << "vec capacity: " << vec.capacity() << std::endl;

	vec.shrink_to_fit(); //when you try to conserve resources... 
	display(vec);
	std::cout << "\nvec size: " << vec.size() << std::endl;
	std::cout << "vec max size: " << vec.max_size() << std::endl;
	std::cout << "vec capacity: " << vec.capacity() << std::endl;

	vec.reserve(100); //you are preparing 100 spaces
	display(vec);
	std::cout << "\nvec size: " << vec.size() << std::endl;
	std::cout << "vec max size: " << vec.max_size() << std::endl;
	std::cout << "vec capacity: " << vec.capacity() << std::endl;
	
}
void test3() {
	std::cout << "\nTest3========================================" << std::endl;
	std::vector<int> vec{ 1,2,3,4,5 };
	display(vec);
	vec[0] = 100;
	vec.at(1) = 200;
	display(vec);
}

void test4() {
	std::cout << "\nTest4========================================" << std::endl;
	std::vector<Person> stooges;
	Person p1{ "Larry",18 };
	display(stooges);

	stooges.push_back(p1);
	display (stooges);
	stooges.push_back(Person{ "Moe",25 });
	display(stooges);

	stooges.emplace_back("Curly", 30);
	display(stooges);
}

void test5() {
	std::cout << "\nTest5================================================================" << std::endl;
	std::vector <Person> stooges{
		{"Larry",18},{"Moe", 25}, {"Curly",30}
	};
	display(stooges);
	std::cout << "\nFront: " << stooges.front() << std::endl;
	std::cout << "\nBack: " << stooges.back() << std::endl;

	stooges.pop_back();
	display(stooges);
}

void test6() {
	std::cout << "\nTest6=====================================================" << std::endl;
	std::vector<int> vec{ 1,2,3,4,5 };
	display(vec);

	vec.clear();
	display(vec);

	vec = { 1,2,3,4,5,6,7,8,9,10 };
	display(vec);
	vec.erase(vec.begin(), vec.begin() + 2);
	display(vec);

	auto it = vec.begin();
	while (it != vec.end()) {
		if (*it % 2 == 0) {
			vec.erase(it);
		}
		else {
			it++;
		}
	}
	display(vec);
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
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
