#include "../inc/2darray.h"
#include <iostream>
#include <cassert>

using namespace std;


int main()
{
    libspu::TDArray tab(10, 6);
    // libspu::TDArray tab(0, 6);

    tab.display(true);
    cout << "Assertion tab.cardinal() == 60 ... ";
    assert(tab.cardinal() == 60);
    cout << "Passed !" << endl;
    cout << "Assertion tab.sum() == 0 ... ";
    assert(tab.sum() == 0);
    cout << "Passed !" << endl;

    cout << endl << "Doing: - tab.set(0,0,1);" << endl;
    cout << "       - tab.set(1,0,5);" << endl;
    cout << "       - tab.set(0,1,3);" << endl;
    tab.set(0,0,1);
    tab.set(1,0,5);
    tab.set(0,1,3);
    tab.display(true);
    cout << "Assertion tab.at(0,0) == 1 ... ";
    assert(tab.at(0,0) == 1);
    cout << "Passed !" << endl;
    cout << "Assertion tab.at(1,0) == 5 ... ";
    assert(tab.at(1,0) == 5);
    cout << "Passed !" << endl;
    cout << "Assertion tab.at(0,1) == 3 ... ";
    assert(tab.at(0,1) == 3);
    cout << "Passed !" << endl;

    cout << endl << "Doing: - tab.set(0,0,7, true);" << endl;
    cout << "       - tab.set(1,0,2, true);" << endl;
    cout << "       - tab.set(0,1,4, true);" << endl;
    tab.set(0,0,7, true);
    tab.set(1,0,2, true);
    tab.set(0,1,4, true);
    tab.display(true);
    cout << "Assertion tab.at(0,0) == 7 ... ";
    assert(tab.at(0,0, true) == 7);
    cout << "Passed !" << endl;

    cout << "Assertion tab.at(1,0) == 2 ... ";
    assert(tab.at(1,0, true) == 2);
    cout << "Passed !" << endl;

    cout << "Assertion tab.at(0,1) == 4 ... ";
    assert(tab.at(0,1, true) == 4);
    cout << "Passed !" << endl << endl;

    cout << "Assertion tab.sum() == 22 ... ";
    assert(tab.sum() == 22);
    cout << "Passed !" << endl;

    cout << "Assertion tab.sumOnRow(0) == 6 ... ";
    assert(tab.sumOnRow(0) == 6);
    cout << "Passed !" << endl;

    cout << "Assertion tab.sumOnRow(0, true) == 9 ... ";
    assert(tab.sumOnRow(0, true) == 9);
    cout << "Passed !" << endl;

    cout << "Assertion tab.sumOnCol(0) == 15 ... ";
    assert(tab.sumOnCol(0) == 15);
    cout << "Passed !" << endl;

    
    cout << endl << endl << "All tests passed succesfully. Exiting with code 0" << endl;
    return 0;
}