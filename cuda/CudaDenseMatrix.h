
/**
 * @license Apache 2.0
 * @author Marco Lourenço
 * @date 15.06.18.
 */

#pragma once

#include "IMatrix.h"

/**
 * @note For maximum compatibility with existing Fortran environments, the cuBLAS library uses column-major storage,
 * and 1-based indexing. Since C and C++ use row-major storage, applications written in these languages can not use
 * the native array semantics for two-dimensional arrays. Instead, macros or inline functions should be defined
 * to implement matrices on top of one-dimensional arrays.
 * @tparam T floating-point precision
 */
template<typename T>
class CudaDenseMatrix : public IMatrix<T> {
 private:
  //==== CSC ====//
  /// Points to the data array of length nnz that holds all nonzero values of this in column-major format.
  T *csc_values_array;
};


