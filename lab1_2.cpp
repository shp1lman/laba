#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

struct Class_1
{
	string name;
	Class_1(string name="")
	{
		this->name = name;	
		cout << name << ": Class_1()" << endl;
	}
	
	virtual Class_1* copy()
	{
		return new Class_1(*this);
	}
	
	virtual ~Class_1()
	{
		cout << name << ": ~Class_1()" << endl;
	}
};

struct Class_2 : public Class_1
{
	Class_2(string name="")
	{
		this->name = name;	
		cout << name << ": Class_2()" << endl;
	}
	
	virtual Class_1* copy()
	{
		return new Class_2(*this);
	}
	
	virtual ~Class_2()
	{
		cout << name << ": ~Class_2()" << endl;
	}
};

void my_copy(vector<Class_1*>& data, Class_1& obj)
{
	Class_1 *p = obj.copy();
	data.push_back(p);
}

int main()
{
	cout << "Automatic variables: " << endl;
	Class_1 x1("x1"), x2("x2");
	Class_2 y1("y1"), y2("y2");

	vector<Class_1*> vec;
	
	my_copy(vec, x1);
	my_copy(vec, x2);
	my_copy(vec, y1);
	my_copy(vec, y2);
	
	// print all objects in vec
	cout << endl;
	cout << "objects in vector: " << endl;
	for(const Class_1* p : vec) {
		cout << p->name << " : " << typeid(*p).name() << endl;
	}
	cout << endl;
	
	// free memory
	cout << "Destroy dynamic copies: " << endl;
	for(const Class_1* p : vec) {
		delete p;
	}
	
	cout << endl;
	cout << "Destroy auto variables: " << endl;
}
