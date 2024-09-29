#include <iostream>

using namespace std;

int main()
    {
        int x[5] = {2,2,3,2,3};
        for (int i =0; i<sizeof(x)/sizeof(x[0]); i++)
            {
                cout << i << endl;
            }
        
    }