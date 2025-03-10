#include <iostream>
using namespace std;
int main() {
    int var = 20;
    int *ptr = &var;
    cout << "Initial Values:" << endl;
    cout << "Variable Value: " << var << endl;
    cout << "Pointer Value (memory address): " << ptr << endl;
    cout << "Pointer Value (value at memory address): " << *ptr << endl;

    *ptr = 30;
    cout << "\nModified Values:" << endl;
    cout << "Variable Value: " << var << endl;
    cout << "Pointer Value (memory address): " << ptr << endl;
    cout << "Pointer Value (value at memory address): " << *ptr << endl;
    return 0;
}
