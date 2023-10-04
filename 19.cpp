#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

class Meal
{
protected:
    string name;
    vector<string> toppings;

public:
    Meal(const string& mealName) : name(mealName) {}

    void add_topping(const string& topping)
    {
        toppings.push_back(topping);
    }

    virtual void prepare() = 0;
};

class Pizza : public Meal
{
public:
    Pizza(const string& pizzaName) : Meal(pizzaName) {}

    void prepare() override
    {
        cout << "Pizza " << name << ". Pizzaboden, belegt mit:" << endl;
        for (const string& topping : toppings)
        {
            cout << "- " << topping << endl;
        }
    }
};

class Burger : public Meal
{
public:
    Burger(const string& burgerName) : Meal(burgerName) {}

    void prepare() override
    {
        cout << name << ". Brötchen mit:" << endl;
        for (const string& topping : toppings)
        {
            cout << "- " << topping << endl;
        }
    }
};

int main(int argc, char* argv[])
{
    Pizza *mista = new Pizza("Mista");
    mista->add_topping("Salami");
    mista->add_topping("Pilzen");
    Meal *hawaii = new Pizza("Hawaii");
    hawaii->add_topping("Schinken");
    hawaii->add_topping("Ananas");
    Burger *hamburger = new Burger("Hamburger");
    hamburger->add_topping("Hackfleisch");
    Meal *cheesburger = new Burger("Cheesburger");
    cheesburger->add_topping("Hackfleisch");
    cheesburger->add_topping("Käse");
    array<Meal *, 4> menu = {mista, hawaii, hamburger, cheesburger};
    for (Meal *g : menu)
    {
        g->prepare(); //*[1]
    }
    return 0;
}

