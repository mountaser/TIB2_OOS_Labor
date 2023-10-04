#include <iostream>
#include <list>
#include <string>
#include <map>
#include <exception>

using namespace std;

// Exception-Klasse implementieren
class OutOfStockException : public exception
{
public:
    OutOfStockException(unsigned int available, unsigned int requested)
        : _available(available), _requested(requested)
    {
        _message = "Es sind " + to_string(_available) + " Artikel vom Typ Galaxy verfügbar. Es können nicht " + to_string(_requested) + " Artikel verkauft werden.";
    }

    const char* what() const throw()
    {
        return _message.c_str();
    }

private:
    unsigned int _available;
    unsigned int _requested;
    string _message;
};

// Interface ISubscriber implementieren
class ISubscriber
{
public:
    virtual void update(const string& message) = 0;
};

// Klasse Customer implementieren
class Customer : public ISubscriber
{
public:
    Customer()
    {
        _id = ++_id_generator;
    }

    void update(const string& message) override
    {
        cout << "Customer " << _id << ": neue Nachricht verfügbar --> " << message << endl;
    }

private:
    static int _id_generator;
    int _id;
};

// Klasse GoldCustomer implementieren
class GoldCustomer : public ISubscriber
{
public:
    GoldCustomer()
    {
        _id = ++_id_generator;
    }

    void update(const string& message) override
    {
        cout << "GoldCustomer " << _id << ": neue Nachricht verfügbar --> " << message << endl;
    }

private:
    static int _id_generator;
    int _id;
};

class Store
{   
public:
    // Hier Methoden implementieren
    void subscribe(ISubscriber* subscriber)
    {
        _subscribers.push_back(subscriber);
    }

    void unsubscribe(ISubscriber* subscriber)
    {
        _subscribers.remove(subscriber);
    }

    void notify_subscribers(const string& message)
    {
        for (auto subscriber : _subscribers)
        {
            subscriber->update(message);
        }
    }

    void deliver_products(const string& product, unsigned int quantity)
    {
        unsigned int previous_availability = _product_availability[product];
        _product_availability[product] += quantity;

        cout << "Vorrätige Artikel vom Typ " << product << ": " << previous_availability << endl;
        cout << "Ausgelieferte Artikel vom Typ " << product << ": " << quantity << endl;
        cout << "Neuer Bestand: " << _product_availability[product] << endl;

        if (previous_availability == 0)
        {
            string message = "Neue Artikel vom Typ " + product + " verfügbar.";
            notify_subscribers(message);
        }
    }

    void sell_products(const string& product, unsigned int quantity)
    {
        if (_product_availability[product] >= quantity)
        {
            unsigned int previous_availability = _product_availability[product];
            _product_availability[product] -= quantity;

            cout << "Vorrätige Artikel vom Typ " << product << ": " << previous_availability << endl;
            cout << "Verkaufte Artikel vom Typ " << product << ": " << quantity << endl;
            cout << "Neuer Bestand: " << _product_availability[product] << endl;

            if (_product_availability[product] == 0)
            {
                string message = "Artikel vom Typ " + product + " nicht mehr verfügbar";
                notify_subscribers(message);
            }
        }
        else
        {
            throw OutOfStockException(_product_availability[product], quantity);
        }
    }
private:
    list<ISubscriber *> _subscribers;
    map<string, unsigned int> _product_availability{{"iPhone", 0}, {"Galaxy", 5}};
};


int Customer::_id_generator = 100;
int GoldCustomer::_id_generator = 0;

void manage_store()
{
    try
    {
        Store* store = new Store;
        ISubscriber* customer_1 = new Customer();
        store->subscribe(customer_1);
        ISubscriber* customer_2 = new GoldCustomer();
        store->subscribe(customer_2);
        ISubscriber* customer_3 = new GoldCustomer();
        store->subscribe(customer_3);
        store->deliver_products("iPhone", 5);
        store->unsubscribe(customer_3);
        store->sell_products("iPhone", 3);
        ISubscriber* customer_4 = new Customer();
        store->subscribe(customer_4);
        store->deliver_products("iPhone", 5);
        store->sell_products("iPhone", 7);
        store->unsubscribe(customer_1);
        ISubscriber* customer_5 = new GoldCustomer();
        store->subscribe(customer_5);
        store->deliver_products("iPhone", 15);
        store->sell_products("Galaxy", 8);
    }
    catch (OutOfStockException& e)
    {
        cout << e.what() << endl;
    }
    catch (...)
    {
        cout << "Ein unbekannter Fehler ist aufgetreten." << endl;
    }
}

int main(int argc, char* argv[])
{
    manage_store();
    return 0;
}
