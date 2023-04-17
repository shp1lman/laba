#include <iostream>
#include <vector>
#include <typeinfo>

class First_class
{
public:
    First_class() {}
    virtual ~First_class() {}
    virtual First_class* clone() const
    {
        return new First_class(*this);
    }
};

class Second_class : public First_class
{
public:
    Second_class() {}
    virtual ~Second_class() {}
    virtual First_class* clone() const
    {
        return new Second_class(*this);
    }
};

void my_copy(const First_class& obj, std::vector<First_class*>& dB)
{
    dB.push_back(obj.clone());
}

int main()
{
    std::vector<First_class*> dataBase;
    First_class obj1;
    Second_class obj2;

    my_copy(obj1, dataBase);
    my_copy(obj2, dataBase);

    for (int i = 0; i < dataBase.size(); ++i)
    {
        std::cout << typeid(*dataBase[i]).name() << std::endl;
        delete dataBase[i];
    }

    return 0;
}
