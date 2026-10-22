#include <iostream>
#include "Labs/Labs.h"
using namespace std;
int main() {
    cout << "CENG203 - Data Structures Lab\n4. Week 4 - Stacks and queues\nEnter your choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
    case 4: runWeek04(); break;
    default: cout << "Invalid choice" << endl;
    }
    return 0;
}
