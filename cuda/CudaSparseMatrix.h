
/**
 * @license Apache 2.0
 * @author Marco Lourenço
 * @date 15.06.18.
 */

#pragma once

#include <cstddef>

#include "IMatrix.h"

/**
 *
 * @tparam T floating-point precision
 */
template<typename T>
class CudaSparseMatrix : public IMatrix<T> {
 private:
  //==== CSR ====//
  /// Points to the data array of length nnz that holds all nonzero values of this in row-major format
  T *csr_values_array;
  /** Points to the integer array of length m+1 that holds indices into the arrays csr_col_indices and csr_values_array.
   *  The first m entries of this array contain the indices of the first nonzero element in the ith row for i=i,...,m,
   *  while the last entry contains nnz+csr_row_ptr(0).
   *  In general, csr_row_ptr(0) is 0 or 1 for zero- and one-based indexing, respectively.
   */
  std::size_t *csr_row_ptr;
  /** Points to the integer array of length nnz that contains the column indices of the corresponding
   *  elements in array csr_col_indices.
   */
  std::size_t *csr_col_indices;

  //==== CSC ====//
  /// Points to the data array of length nnz that holds all nonzero values of this in column-major format.
  T *csc_values_array;
  /** Points to the integer array of length nnz that contains the row indices of the corresponding
   * elements in array cscValA.
   */
  std::size_t *csc_row_indices;
  /** Points to the integer array of length n+1 that holds indices into the arrays cscRowIndA and values_array.
   * The first n entries of this array contain the indices of the first nonzero element in the ith row for i=i,...,n,
   * while the last entry contains nnz+csc_col_ptr(0).
   * In general, csc_col_ptr(0) is 0 or 1 for zero- and one-based indexing, respectively.
   */
  std::size_t *csc_col_ptr;
};