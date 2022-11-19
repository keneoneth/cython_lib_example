# cython_lib_example
An example of a hybrid cython library based on numpy that allows C++ or Python applications to interact directly, without the need of rewriting separate functions for C++/Python programs individually

The library is written in the file numpylib.pyx, containing two simple functions:  
1) sum3d - calculates the sum of all elements in a 3d array  
2) tozeros - set all elements of a 3d array to zero  

To cythonize the library, run `make setup`  

To run the python program that uses the library, run `make run_py`  

To run the C++ program that uses the library:  
1) export the env variable PYINCLUDE_PATH (the Python.h file should be under this path, usually should be usr/include/python{version}/)  
2) run `make run_cc`  

Note: the example requires installation of Cython and numpy
