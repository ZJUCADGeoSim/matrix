/*
	State Key Lab of CAD&CG Zhejiang Unv.

	Author: Jin Huang (hj@cad.zju.edu.cn)

	Copyright (c) 2004-2021 <Jin Huang>
	All rights reserved.

	Licensed under the MIT License.
*/
#ifndef _ZJUCAD_MATRIX_H_
#define _ZJUCAD_MATRIX_H_

#include <stddef.h>

namespace zjucad {
namespace matrix {

//! use machine pointer size as the type
//! try to avoid using unsigned.

typedef ptrdiff_t size_type;
typedef ptrdiff_t idx_type;
typedef ptrdiff_t offset_type;

#define ZJUCAD_MATRIX_VERSION 1

} // namespace matrix
} // namespace zjucad

#endif
