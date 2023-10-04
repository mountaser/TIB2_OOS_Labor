#include <iostream>
#include <vector>

using namespace std;

// Interface für Komponenten
class IComponent {
public:
    virtual int get_price() = 0;
    virtual void add(IComponent* component) {}
};

// Produktklasse
class Product : public IComponent {
private:
    int price;

public:
    Product(int price) : price(price) {}

    int get_price() override {
        return price;
    }
};

// Boxklasse, die Komponenten enthält
class Box : public IComponent {
private:
    vector<IComponent*> components;

public:
    int get_price() override {
        int total_price = 0;
        for (IComponent* component : components) {
            total_price += component->get_price();
        }
        return total_price;
    }

    void add(IComponent* component) override {
        components.push_back(component);
    }
};

void calculate_price(IComponent* component) {
    cout << "Preis: " << component->get_price() << endl;
}

int main(int argc, char* argv[]) {
    cout << "Preisermittlung für ein einfaches Produkt:" << endl;
    IComponent* product = new Product(10);
    calculate_price(product);
    cout << endl << endl;

    cout << "Preisermittlung für eine verschachtelte Box:" << endl;
    IComponent* outer_box = new Box;
    IComponent* inner_box_1 = new Box;
    IComponent* product_1 = new Product(10);
    IComponent* product_2 = new Product(5);
    IComponent* product_3 = new Product(4);
    inner_box_1->add(product_1);
    inner_box_1->add(product_2);
    IComponent* inner_box_2 = new Box;
    inner_box_2->add(product_3);
    outer_box->add(inner_box_1);
    outer_box->add(inner_box_2);
    IComponent* product_4 = new Product(7);
    inner_box_2->add(product_4);
    calculate_price(outer_box);
    cout << endl << endl;

    return 0;
}
