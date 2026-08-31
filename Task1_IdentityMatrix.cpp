#include<iostream>
using namespace std;

int main(){
    int arr[3][3] = {{1,0,0},
                    {6,1,0},
                    {0,0,1}};
    bool isI = true;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i == j)
            {
                if(arr[i][j] != 1)
                {
                isI = false;
                    break;
                }
            }else{
                if (arr[i][j] != 0)
                {
                    isI = false;
                    break;
                }
            }
        }
    }

    if (isI)
    {
        cout << "The matrix is identity" << endl;
    }else
    {
        cout << "The matrix is not identity" << endl;
    }
    
    return 0;
}