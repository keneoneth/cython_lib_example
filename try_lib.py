import numpylib as nl
import numpy as np
np.random.seed(123)


arr = (3*np.random.rand(3,2,1)).astype(np.int32)
print(f'arr {arr}')

sum = nl.sum3dpy(arr)
print(f'sum {sum}')

nl.tozerospy(arr)
print(f'zero {arr}')