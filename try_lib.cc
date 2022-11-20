#include <iostream>
#include <vector>
#include <algorithm>
#include "numpylib.h"

using namespace std;

int main() {
    vector<int> vect = { 1, 2, 3, 4, 5, 6 };

    const int copy_size = 6;
    int arr[copy_size];
    copy(vect.begin(), vect.begin()+copy_size, arr);
    
    cout << "arr: ";
    for (int i=0; i<copy_size;i++)
        cout << arr[i] << ",";
    cout << endl;

    auto err = PyImport_AppendInittab("numpylib", PyInit_numpylib);
    if (err) {
        cout << "ERROR!\n";
        return 1;
    }

    Py_Initialize();
    PyObject* nl = PyImport_ImportModule("numpylib"); // you don't actually have to do anything with this module object
    
    int ret = sum3d(arr,3,2,1);
    cout << "sum:" << ret << endl;

    tozeros(arr,3,2,1);

    Py_Finalize();

    cout << "zero: "; 
    for (int i=0; i<copy_size;i++)
        cout << arr[i] << ",";
    cout << endl;

}