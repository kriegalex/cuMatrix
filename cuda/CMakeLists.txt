find_package(CUDA REQUIRED)
if (CUDA_FOUND)

  # check cuda and GCC version
  if (CUDA_VERSION VERSION_GREATER_EQUAL 9.2) # cuda version >= 9.2
    if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 7.2) # gcc > 7.2.0
      message(FATAL_ERROR "CUDA 9.2 doesn't support GCC greater than 7.2.0")
    endif ()
  else () # cuda version 9.1 and lower
    # as of CUDA 9.1, GCC 7 is not supported
    if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 7.0)
      set(CMAKE_CUDA_HOST_COMPILER "/usr/bin/g++-6" CACHE STRING
          "Host compiler used for all CUDA cmake targets" FORCE)
    endif ()
  endif ()

  set(cu_srcs CudaSparseMatrix.cu CudaDenseMatrix.cu)
  set(cu_hdrs CudaSparseMatrix.h CudaDenseMatrix.h)

  add_library(cuda SHARED ${cu_srcs} ${cu_hdrs})
  # include dirs with this lib (crt dir and cuda headers)
  target_include_directories(cuda PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES})
  # cuda depends on core
  target_link_libraries(cuda PUBLIC core)

endif (CUDA_FOUND)