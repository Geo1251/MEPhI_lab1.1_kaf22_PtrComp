#include "AutomaticFunctionalTests.cpp"
#include "AutomaticPerformanceTests.cpp"
#include "ManualFunctionalTests.cpp"
#include "ManualPerformanceTests.cpp"
#include "ComparisonTests.cpp"
#include <iostream>

using namespace std;

int main() {

    int constant = 1;
    cout << "Starting program...\n" << endl;
    
    while(constant != 0){
        cout << "1 - Run manual functional tests" << endl;
        cout << "2 - Run manual performance tests" << endl;
        cout << "3 - Run automatic functional tests" << endl;
        cout << "4 - Run automatic performance tests" << endl;
        cout << "5 - Run comparison tests (Raw/STL/SmrtPtr/UnqPtr/ShrdPtr/MsPtr)" << endl;
        cout << "6 - Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                runManualFunctionalTests();
                break;
            case 2:
                runManualPerformanceTests();
                break;
            case 3:
                runAutomaticFunctionalTests();
                break;
            case 4:
                runAutomaticPerformanceTests();
                break;
            case 5:
                runComparisonTests();
                break;
            case 6:
                constant = 0;
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Wrong choice!" << endl;
                break;
        }
    
    }

    return 0;
}