# cythonize numpylib.pyx
setup:
	python setup.py build_ext --inplace

run_py:
	python try_lib.py


pylibs := `python3-config --includes  --libs --embed`

# PYINCLUDE_PATH -> path to Python.h
try_lib:
	g++ try_lib.cc -o try_lib $(pylibs) ./numpylib.cpython-310-x86_64-linux-gnu.so -I ${PYINCLUDE_PATH}

run_cc : try_lib
	./try_lib