#include <iostream>
#include <cstring>
using namespace std;

class Product
{
private:
    char name[50];
    int *quantity;

public:
    Product(const char *n, int q)
    {
        strcpy(name, n);

        quantity = new int;
        *quantity = q;
    }

    Product(const Product &obj)
    {
        strcpy(name, obj.name);

        quantity = new int;
        *quantity = *(obj.quantity);
    }

    Product& operator=(const Product &obj)
    {
        if (this != &obj)
        {
            strcpy(name, obj.name);

            delete quantity;

            quantity = new int;
            *quantity = *(obj.quantity);
        }

        return *this;
    }

    void setQuantity(int q)
    {
        *quantity = q;
    }

    void display()
    {
        cout << "Product Name: " << name << endl;
        cout << "Quantity: " << *quantity << endl;
    }

    ~Product()
    {
        delete quantity;
    }
};

int main()
{
    Product p1("Laptop", 10);

    cout << "Original Product:" << endl;
    p1.display();

    Product p2 = p1;

    cout << "\nCopied Product:" << endl;
    p2.display();

    p2.setQuantity(20);

    cout << "\nAfter modifying copied object:" << endl;

    cout << "\nOriginal Product:" << endl;
    p1.display();

    cout << "\nCopied Product:" << endl;
    p2.display();

    Product p3("Mobile", 5);

    cout << "\nBefore assignment:" << endl;
    p3.display();

    p3 = p1;

    cout << "\nAfter assigning p1 to p3:" << endl;
    p3.display();

    p3.setQuantity(50);

    cout << "\nAfter modifying p3:" << endl;

    cout << "\np1:" << endl;
    p1.display();

    cout << "\np3:" << endl;
    p3.display();

    return 0;
}