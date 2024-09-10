//Name: Brandon Alvarez De La Cruz
//CS-303 Assigment 1
// 9/09/2024

#include "Functions.h"

int main() {
    int* arr = nullptr;
    int size = 0;

    readArrayFromFile(arr, size, "input.txt"); // Replace with the actual file path
    //test to see if array is correct
   /*
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
    */
    char userChoice = '0';
    int findValue = 0, Index = 0, newInt;
    while (userChoice != 'q') {
        try {
            cout << "MENU" << endl;
            cout << "1. Find value\n" << "2. Change number\n" << "3. Add number to end of line\n" << "4. remove number\n" << "q. Quit" << endl;
            cin >> userChoice;
            //checks for all options for choices 
            if (userChoice == '1') {
                cout << "Enter to find value to find index in array: ";
                cin >> findValue;
                int Index = findIndex(arr, size, findValue);
                if (Index == -1) {
                    cout << "Number not found" << endl;
                }
                else {
                    cout << Index << endl;
                }
            }
            else if (userChoice == '2') {
                cout << "Enter index of number to modify: ";
                cin >> Index;
                cout << "Enter new number: ";
                cin >> newInt;
                modifyValue(arr, size, Index, newInt);
            }
            else if (userChoice == '3') {
                cout << "Enter new number to add to array: ";
                cin >> newInt;
                try {
                    addValue(arr, size, newInt);
                }
                catch (const bad_alloc& e) {
                    cout << "Memory allocation failed: " << e.what() << endl;
                }
            }
            else if (userChoice == '4') {
                cout << "Enter index to remove: ";
                cin >> Index;
                removeValue(arr, size, Index);
                //test for correct array deletion 
                /*
                for (int i = 0; i < size; i++) {
                    cout << arr[i] << endl;
                }
                */
            }
        }
        catch (...) {
            cout << "Error" << endl;
        }
    }
    return 0;
}
