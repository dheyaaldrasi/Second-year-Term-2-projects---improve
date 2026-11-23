#include <iostream>

using namespace std;

namespace Sales{
    void Print(){
        cout << "Hi, I am in Sales namespace." << endl;
    }
}

namespace Marketing{
    void Print(){
        cout << "Hi, I am in Marketing namespace." << endl;
    }
}

namespace Company::Sales{
    void Print(){
        cout << "Hi, I am in Company::Sales namespace." << endl;
    }
}


int main(){

    Sales::Print();
    Marketing::Print();
    Company::Sales::Print();
    
    return 0;
}