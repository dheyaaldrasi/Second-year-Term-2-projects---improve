#include <iostream>

using namespace std;


// No padding control by declaring the data types in any order.
struct BeforePaddingControl{
    char a;
    int b;
    char c;
};


// minimize padding by declaring the largest data type first.
struct AfterPaddingControl{
    int b;
    char a;
    char c;
};

int main(){
    cout << "Size of BeforePaddingControl: " << sizeof(BeforePaddingControl) << endl;

    cout << "Size of AfterPaddingControl: " << sizeof(AfterPaddingControl) << endl;

    return 0;
}
