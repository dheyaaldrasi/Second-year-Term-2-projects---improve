#include <iostream>

using namespace std;

// Class template for a simple calculator
template <typename T>
    class Calculator {
        private:
            T num1;
            T num2;
        public:
            Calculator(T a, T b) : num1(a), num2(b) {}

            T add() {
                return num1 + num2;
            }

            T subtract() {
                return num1 - num2;
            }

            T multiply() {
                return num1 * num2;
            }

            T divide() {
                if (num2 != 0) {
                    return num1 / num2;
                } else {
                    throw std::invalid_argument("Division by zero is not allowed.");
                }
            }
    };



// Function template to add two numbers of any type
template <typename T>
T add(T a, T b) {
    return a + b;
}


int main(){

    cout << "Welcome to my templates." << endl;

    int a = 7;
    int b = 5;
    cout << "Sum of two integers: " << add(a, b) << endl;

    double c = 3.5;
    double d = 4.2;
    cout << "The sum of two double is: " << add(c,d) << endl;

    string e = "x";
    string f = "X";
    cout << "The sum of two string is: " << add(e,f) << endl;


    cout << "Now we will use the Calculator class to perform operations on different data types." << endl;


    Calculator<int> calcInt(a,b);
    cout << "The sum of two integers using Calculator class: " << calcInt.add() << endl;
    cout << "The difference of two integers using Calculator class: " << calcInt.subtract() << endl;
    cout << "The product of two integers using Calculator class: " << calcInt.multiply() << endl;
    cout << "The quotient of two integers using Calculator class: " << calcInt.divide() << endl;

    Calculator<double> calcDouble(c,d);
    cout << "The sum of two doubles using Calculator class: " << calcDouble.add() << endl;
    cout << "The difference of two doubles using Calculator class: " << calcDouble.subtract() << endl;
    cout << "The product of two doubles using Calculator class: " << calcDouble.multiply() << endl;
    cout << "The quotient of two doubles using Calculator class: " << calcDouble.divide() << endl;

    Calculator<string> calcString(e,f);
    cout << "The sum of two strings using Calculator class: " << calcString.add() << endl;
    cout << "The difference of two strings using Calculator class: " << calcString.subtract() << endl;
    cout << "The product of two strings using Calculator class: " << calcString.multiply() << endl;
    cout << "The quotient of two strings using Calculator class: " << calcString.divide() << endl;

    return 0;
}