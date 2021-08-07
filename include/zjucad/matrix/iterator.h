/*
	State Key Lab of CAD&CG Zhejiang Unv.

	Author: Jin Huang (hj@cad.zju.edu.cn)

	Copyright (c) 2004-2021 <Jin Huang>
	All rights reserved.

	Licensed under the MIT License.
*/

#ifndef _ZJUCAD_MATRIX_ITERATOR_H_
#define _ZJUCAD_MATRIX_ITERATOR_H_

#include <iterator>

namespace zjucad {
namespace matrix {

template <typename T>
struct default_matrix_iterator {
    typedef std::forward_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef T &reference;
};

} // namespace matrix
} // namespace zjucad

#endif
