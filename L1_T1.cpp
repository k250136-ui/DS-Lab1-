#include<iostream>
using namespace std;

void factor(int n)
{
    int sum=0;
    cout << "Factors of " << n << " are: ";
    for (int i = 1; i <= n; i++)
    {
        if (n%i == 0)
        {
            cout << i << " ";
            sum += i;
        }
    }
    cout << "\nSum of factors of " << n << " is: " << sum << endl;
    cout << "=========================" << endl;
}

int main(){
    int a;

    while (true)
    {
        cout << "Enter a positive number: ";
        cin >> a;
        if (a == -1)
            break;
        
        if (a <= 0)
        {
            cout << "Please enter positive number!!!" << endl;
            continue;
        }
        factor(a);
    }
    
    return 0;
}