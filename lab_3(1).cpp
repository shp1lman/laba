#include <iostream>
#include <vector>

using namespace std;

class Parent {
protected:
    float* m_var;
public:
    Parent() {
        m_var = new float(0);
    }
    Parent(const Parent& obj_copy) : m_var(new float) { *m_var = *obj_copy.m_var; }
    virtual Parent* copy() { return new Parent(*this); }
    virtual ~Parent() { delete m_var; }
};
class Child : public Parent {
public:
    Child() {};
    Child(const Child& obj_copy) : Parent (obj_copy){}
    virtual Parent* copy() { return new Child(*this); }
    ~Child() {}
};

vector <Parent*> Data_1;
vector <Parent*> Data_2;

int main()
{
    for (int i = 0; i < 4; i++) {
        Data1.push_back(new Parent);
        Data1.push_back(new Child);
    }
    for (int i = 0; i < 8; i++) {
        Parent* new_obj = (Data1[i])->copy();
        Data2.push_back(new_obj);
    }
}
