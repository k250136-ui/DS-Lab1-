#include<iostream>
using namespace std;

class Numbers{
private:
    int size;
    int* ptr;
public:
    Numbers(int s=0) : size(s)
    {
        if (size > 0)
        {
            ptr = new int[size];
        }else{
            ptr = nullptr;
        }
    }

    void setvalues()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter value " << i+1 << " :";
            cin >> ptr[i];
        }
    }

    void displayvalues()
    {
        for (int i = 0; i < size; i++)
        {
            cout << ptr[i] << " ";
        }
    }

    Numbers(const Numbers &obj)
    {
        size = obj.size;
        if (size > 0)
        {
            ptr = new int[size];
            for (int i = 0; i < size; i++)
            {
                ptr[i] = obj.ptr[i];
            }   
        }else{
            ptr = nullptr;
        }    
    }

    Numbers& operator=(const Numbers &obj)
    {
        if (this != &obj)
        {
            delete[] ptr;
            size = obj.size;

            if (size > 0)
            {
                ptr = new int[size];
                for (int i = 0; i < size; i++)
                {
                    ptr[i] = obj.ptr[i];
                }
            }else{
                ptr = nullptr;
            }
        }
        return *this; 
    }

    ~Numbers()
    {
        delete[] ptr;
    }


};

int main(){
    cout << "Object 1:" << endl;

    Numbers n1(3);
    n1.setvalues();

    cout << "\nObject 1 values: ";
    n1.displayvalues();


    cout << "\nCreating Object 2 using Copy Constructor..." << endl;

    Numbers n2 = n1;

    cout << "Object 2 values: ";
    n2.displayvalues();


    cout << "\nCreating Object 3 and assigning Object 1..." << endl;

    Numbers n3(3);
    n3 = n1;

    cout << "Object 3 values: ";
    n3.displayvalues();
    return 0;
}