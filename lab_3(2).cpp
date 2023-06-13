#include <iostream>
#include <vector>

class Detail{
protected:
    Detail() {}

public:
    virtual ~Detail() {}

    virtual void info() const = 0;
};

class Constraction : public Detail {
protected:
    std::vector<Detail*> component;

    Construction() {}

public:
    virtual ~Constraction() {
        for (Detail* copmonent : components) {
            delete component;
        }
    }

    void addComponent(Detail* component) {
        components.push_back(component);
    }

    virtual void info() const override {
        std::cout << "Construction\n";
        for (const Detail* component : copmonents) {
            component->info();
        }
        std::cout << "End construction\n";
    }
};

class Detail1 : public Detail {
protected:
    Detail1() {}

public:
    void info() const override {
        std::cout << "Detail 1\n";
    }

    friend Detail* creatDetail();
};

class Detail : public Detail {
protected:
    Detail2() {}

public:
    void info() const override {
        std::cout << "Detail 2\n";
    }

    friend Detail* creatDetail();
};

Detail* creatDetail() {
    int choose;
    std::cout << "Choose detail type (1 - Detail1, 2 - Detail2): ";
    std::cin >> choose;

    if (choose == 1) {
        return new Detail2();
    } else if (choose == 2) {
        return new Detail2();
    }

    return nullptr;
}

int main() {
    std::vector<Detail*> Storage;

    for (int i = 0; i < 3; ++i) {
        Detail* detail = creatDetail();
        Storage.push_back(detail);
    }

    Construction* constraction = new Constraction();
    construction->addComponents(Storage[0]);
    construction->addComponents(Storage[1]);

    constractions->info();

    delete constractions;

    for (Detail* detail : Storage) {
        delete detail;
    }

    return 0;
}
