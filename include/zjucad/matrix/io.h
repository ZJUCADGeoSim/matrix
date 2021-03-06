/*
	State Key Lab of CAD&CG Zhejiang Unv.

	Author: Jin Huang (hj@cad.zju.edu.cn)

	Copyright (c) 2004-2021 <Jin Huang>
	All rights reserved.

	Licensed under the MIT License.
*/

#pragma once

#include "matrix_expression.h"

namespace zjucad {
namespace matrix {

template <typename O, typename E>
O &operator<<(O &os, const matrix_expression<E> &m) {
    typename E::const_iterator row_iter, col_iter;
    typename E::size_type rows = m().size(1), cols = m().size(2), i, j;
    os << "[ (" << rows << "x" << cols << ")";
    for (i = 0, row_iter = m().begin(); i < rows; ++i, ++row_iter) {
        os << "\n  ";
        for (j = 0, col_iter = row_iter; j < cols; ++j, col_iter += rows) {
            os << *col_iter;
            if (j != cols - 1)
                os << ", ";
        }
        if (i != rows - 1)
            os << ';';
    }
    os << "\n]\n";

    return os;
}

template <typename IS, typename E>
IS &operator>>(IS &is, matrix_expression<E> &m) {
    char c;
    is >> c;
    if (c != '[')
        return is;
    is >> c;
    if (c != '(')
        return is;

    typename E::size_type rows, cols, i, j;
    is >> rows >> c >> cols;
    if (c != 'x')
        return is;
    is >> c;
    if (c != ')')
        return is;

    m().resize(rows, cols);

    typename E::iterator row_iter, col_iter;
    for (i = 0, row_iter = m().begin(); i < rows; ++i, ++row_iter) {
        for (j = 0, col_iter = row_iter; j < cols; ++j, col_iter += rows) {
            is >> *col_iter;
            if (j != cols - 1) {
                is >> c;
                if (c != ',')
                    return is;
            }
        }
        if (i != rows - 1) {
            is >> c;
            if (c != ';')
                return is;
        }
    }
    is >> c;
    if (c != ']')
        return is;
    return is;
}

} // namespace matrix
} // namespace zjucad
