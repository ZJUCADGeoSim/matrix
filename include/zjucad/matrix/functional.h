/*
	State Key Lab of CAD&CG Zhejiang Unv.

	Author: Jin Huang (hj@cad.zju.edu.cn)

	Copyright (c) 2004-2021 <Jin Huang>
	All rights reserved.

	Licensed under the MIT License.
*/

#ifndef _ZJUCAD_MATRIX_FUNCTIONAL_H_
#define _ZJUCAD_MATRIX_FUNCTIONAL_H_

#include <cmath>

namespace zjucad {
namespace matrix {

template <typename E1, typename E2>
struct matrix_matrix_type_traits {
    typedef typename E1::value_type return_type;
    typedef typename E1::const_reference arg_type1;
    typedef typename E2::const_reference arg_type2;
};

template <typename E>
struct matrix_scalar_type_traits {
    typedef typename E::value_type return_type;
    typedef typename E::const_reference arg_type1;
    typedef typename E::value_type arg_type2;
};

#define FUNC_SCALAR_FUNCTOR(f)                            \
    template <typename T>                                 \
    struct f##_scalar_functor {                           \
        T operator()(const T &a) const { return ::f(a); } \
    };

template <typename T1, typename T2>
struct pow_functor {
    T1 operator()(const T1 &a, const T2 &b) const { return std::pow(a, b); }
};

template <typename E>
struct base_type {
    typedef typename E::iterator iterator;
    typedef typename E::value_type value_type;
    typedef typename E::reference reference;
};

template <typename E>
struct base_type<const E> {
    typedef typename E::const_iterator iterator;
    typedef typename E::value_type value_type;
    typedef typename E::const_reference reference;
};

} // namespace matrix
} // namespace zjucad

#endif
