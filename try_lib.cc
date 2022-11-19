#include <iostream>
#include <vector>
#include <algorithm>
#include "numpylib.h"

using namespace std;

int main() {
    std::vector<int> vect = { 1, 2, 3, 4, 5, 6 };

    const int copy_size = 6;
    int arr[copy_size];
    std::copy(vect.begin(), vect.begin()+copy_size, arr);
    
    cout << "arr: ";
    for (int i=0; i<copy_size;i++)
        cout << arr[i] << ",";
    cout << endl;

    auto err = PyImport_AppendInittab("numpylib", PyInit_numpylib);
    if (err) {
        std::cout << "ERROR!\n";
        return 1;
    }

    Py_Initialize();
    PyObject* nl = PyImport_ImportModule("numpylib"); // you don't actually have to do anything with this module object
    
    int ret = sum3d(arr,3,2,1);
    std::cout << "sum:" << ret << std::endl;

    tozeros(arr,3,2,1);

    Py_Finalize();

    cout << "zero: "; 
    for (int i=0; i<copy_size;i++)
        cout << arr[i] << ",";
    cout << endl;

}