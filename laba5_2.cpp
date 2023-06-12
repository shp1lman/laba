#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <typeinfo>

class A
{
public:
    std::string s;
    A()
    {
        std::cout << "Конструктор по умолчанию класса А" << std::endl;
    }
    A(const char* a)
    {
        s = a;
        std::cout << "Пользовательский Конструктор класса A" << std::endl;
        std::cout << s << std::endl;
    }
    A(const A& other)
    {
        s = other.s;
        std::cout << "Копирующий конструктор класса A" << std::endl;
        std::cout << s << std::endl;
    }
    virtual A* clone() const
    {
        return new A(*this);
    }
    virtual ~A()
    {
        std::cout << "Деструктор класса A" << std::endl;
        std::cout << typeid(*this).name() << std::endl;
    }

};

class B : public A
{
public:
    B()
    {
        std::cout << "Конструктор класса B" << std::endl;
    }
    B(const char* a) : A(a)
    {
        std::cout << "Пользовательский Конструктор класса B" << std::endl;
        std::cout << a << std::endl;
    }
    B(const B& other) : A(other)
    {
        std::cout << "Копирующий конструктор класса B" << std::endl;
        std::cout << other.s << std::endl;
    }
    virtual B* clone() const override
    {
        return new B(*this);
    }
    ~B()
    {
        std::cout << "Деструктор класса B" << std::endl;
        std::cout << typeid(*this).name() << std::endl;
    }
};


template <typename Container>
void del(Container& c)
{
    for (A* element : c) {
        delete element;
    }
    c.clear();
}

std::vector<A*> v;
std::list<A*> l;

int main()
{
    setlocale(LC_ALL, "ru");
    l.push_back(new A("first"));
    l.push_back(new B("second"));
    std::cout << std::endl;
    std::cout << std::endl;
    //копирование
    for (A* i : l)
    {
        v.push_back(i->clone());
    }
    std::cout << std::endl;
    std::cout << std::endl;
    //очистка памяти
    std::cout << "очитска памяти вектора" << std::endl;
    del(v);
    std::cout << "очитска памяти листа" << std::endl;
    del(l);
    return 0;
}
