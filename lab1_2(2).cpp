#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Car {
public:
    Car(const string& _producer, string _model) : m_producer(_producer), m_model(_model) {}

    virtual ~Car() {}

    virtual void print() const = 0;

protected:
    string m_producer;
    string m_model;
};

class Toyota : public Car {
public:
    Toyota(const string& _model) : Car("Toyota", _model) {}

    void print() const override
    {
        cout << "Producer: " << m_producer << ", Model: " << m_model << endl;
    }
};

class Nissan : public Car {
public:
    Nissan(string _model) : Car("Nissan", _model) {}

    void print() const override
    {
        cout << "Producer: " << m_brand << ", Model: " << m_model << endl;
    }
};

int main() {

    ifstream  inFile("cars.txt");
    if (inFile.fail()) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    vector<Car*> cars;
    string maker_company, model;
    while (inFile >> maker_company >> model) {
        if (maker_company == "Toyota") {
            cars.push_back(new Toyota(model));
        }
        else if (maker_company == "Nissan") {
            cars.push_back(new Nissan(model));
        }
        else {
            cerr << "Unknown car brand: " << maker_company << endl;
            continue;
        }
    }

    inFile.close();

    for (int i = 0; i < cars.count(); ++i)
    {
        cars[i]->print();
        delete cars[i];
    }

    return 0;
}
