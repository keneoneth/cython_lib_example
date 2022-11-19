# import numpy
import numpy as np


# function to be called from py script 
cpdef int sum3dpy(int[:, :, :] arr) nogil:
    cdef size_t i, j, k, I, J, K
    cdef int total = 0
    I = arr.shape[0]
    J = arr.shape[1]
    K = arr.shape[2]
    for i in range(I):
        for j in range(J):
            for k in range(K):
                total += arr[i, j, k]
    return total

# function to be called from cc
cdef public int sum3d(int * carr, int x, int y, int z):
    # cast to mem view
    cdef int [:,:,:] arr = <int[:x, :y, :z]> carr
    # return result
    return sum3dpy(arr)

# function to be called from py script 
cpdef int tozerospy(int[:, :, :] arr):
    np_arr = np.asarray(arr)
    np_arr[:,:,:] = np.zeros((arr.shape[0],arr.shape[1],arr.shape[2]))

# function to be called from cc
cdef public int tozeros(int * carr, int x, int y, int z):
    # cast to mem view
    cdef int [:,:,:] arr = <int[:x, :y, :z]> carr
    # perform operation
    tozerospy(arr)
    