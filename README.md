# zjucad::matrix

## What is it?

This is matrix library in C++ which provides an interface similar (or
nearly identical) to Matlab/Octave.  The technique is similar to
Eigen.

Some most important features include:

* matrix and vector are unified.
* index can be integer, range, and another integer-valued vector/matrix.

If you are familiar with MATLAB, you may find that this lib can easily
bring your experience in MATLAB to your C++ code.

## Usage

* Installation: One can add it as a dependency with
[CPM](https://github.com/cpm-cmake/CPM.cmake):

```cmake
CPMAddPackage(
  NAME zjucad.matrix
  GITHUB_REPOSITORY ZJUCADGeoSim/matrix
  GIT_TAG v0.1.0
)
```

Or, just include the headers.

* About the ":" in Matlab

In C++, use "colon()" for ":", and use "colon(beg, end)" for "beg:end".

* A=A*B will give wrong answer

This is a common behavior of many libraries using C++ Expression
Templates.

The correct way is A=temp(A*B).  It should be noticed that A=A+B is
correct.  One can refer "Eigen: Aliasing" to understand this.

## History

Jin Huang learned some about Matlab and when he was a bachelor
student.  Inspired by the design of mwArray in Matlab, he began to
write C++ matrix library in 2001. After several rounds of code
refactoring, he found the current design in 2004, and intensively
applied it to all his projects, which makes the library mature enough.
Now, many of his research work are still based on it.
