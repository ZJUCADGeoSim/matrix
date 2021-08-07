/*
	State Key Lab of CAD&CG Zhejiang Unv.

	Author: Jin Huang (hj@cad.zju.edu.cn)

	Copyright (c) 2004-2021 <Jin Huang>
	All rights reserved.

	Licensed under the MIT License.
*/

#pragma once

#include <algorithm>
#include <zjucad/matrix/matrix.h>


namespace zjucad {
namespace matrix {

f2c::integer inline lu(matrix<f2c::real> &A, matrix<f2c::integer> &ipiv) {
    f2c::integer M = A.size(1), N = A.size(2), info;
    ipiv.resize(std::min(M, N));
    clapack::sgetrf_(&M, &N, A.data().begin(), &M, ipiv.data().begin(), &info);
    return info;
}

f2c::integer inline lu(matrix<f2c::doublereal> &A, matrix<f2c::integer> &ipiv) {
    f2c::integer M = A.size(1), N = A.size(2), info;
    ipiv.resize(std::min(M, N));
    clapack::dgetrf_(&M, &N, A.data().begin(), &M, ipiv.data().begin(), &info);
    return info;
}

f2c::integer inline inv(matrix<f2c::real> &A) {
    matrix<f2c::integer> ipiv;
    lu(A, ipiv);
    f2c::integer N = A.size(1), info, lwork = std::max(f2c::integer(1), N);
    matrix<f2c::real> work(lwork);
    clapack::sgetri_(&N, A.data().begin(), &N, ipiv.data().begin(), work.data().begin(), &lwork, &info);
    return info;
}

f2c::integer inline inv(matrix<f2c::doublereal> &A) {
    matrix<f2c::integer> ipiv;
    lu(A, ipiv);
    f2c::integer N = A.size(1), info, lwork = std::max(f2c::integer(1), N);
    matrix<f2c::doublereal> work(lwork);
    clapack::dgetri_(&N, A.data().begin(), &N, ipiv.data().begin(), work.data().begin(), &lwork, &info);
    return info;
}

f2c::integer inline svd(matrix<f2c::real> &A, matrix<f2c::real> &U, matrix<f2c::real> &S, matrix<f2c::real> &VT) {
    f2c::integer m = A.size(1), n = A.size(2), info = -1;
    f2c::integer min_mn = std::min(m, n);
    f2c::integer lwork = std::max(3 * min_mn + std::max(m, n), 5 * min_mn);
    matrix<f2c::real> w(lwork), diagS(m);
    U.resize(m, min_mn);
    VT.resize(min_mn, n);
    static char sS[] = "S";
    clapack::sgesvd_(sS, sS, &m, &n, A.data().begin(), &m, diagS.data().begin(),
                     U.data().begin(), &m, VT.data().begin(), &min_mn, w.data().begin(), &lwork, &info);
    S = zeros<f2c::real>(min_mn);
    for (f2c::integer i = 0; i < min_mn; ++i)
        S(i, i) = diagS[i];
    return info;
}

f2c::integer inline svd(matrix<f2c::doublereal> &A, matrix<f2c::doublereal> &U, matrix<f2c::doublereal> &S, matrix<f2c::doublereal> &VT) {
    f2c::integer m = A.size(1), n = A.size(2), info = -1;
    f2c::integer min_mn = std::min(m, n);
    f2c::integer lwork = std::max(3 * min_mn + std::max(m, n), 5 * min_mn);
    matrix<f2c::doublereal> w(lwork), diagS(m);
    U.resize(m, min_mn);
    VT.resize(min_mn, n);
    static char sS[] = "S";
    clapack::dgesvd_(sS, sS, &m, &n, A.data().begin(), &m, diagS.data().begin(),
                     U.data().begin(), &m, VT.data().begin(), &min_mn, w.data().begin(), &lwork, &info);
    S = zeros<f2c::doublereal>(min_mn);
    for (f2c::integer i = 0; i < min_mn; ++i)
        S(i, i) = diagS[i];
    return info;
}

template <typename T>
T inline det(matrix<T> &A) {
    assert(A.size(1) == A.size(2));
    matrix<f2c::integer> ipiv;
    lu(A, ipiv);
    T rtn = 1.0f;
    zjucad::matrix::size_type i;
    for (i = 0; i < A.size(); i += A.size(1) + 1)
        rtn *= A[i];
    for (i = 0; i < ipiv.size(); ++i)
        if (i != ipiv[i] - 1)
            rtn *= -1.0f;
    return rtn;
};

f2c::integer inline eig(matrix<f2c::doublereal> &A, matrix<f2c::doublereal> &e) {
    f2c::integer N = A.size(1), lwork = -1, info;
    matrix<f2c::doublereal> work(1);
    static char V[] = "V", U[] = "U";
    clapack::dsyev_(V, U, &N, &A[0], &N, &e[0], &work[0], &lwork, &info);
    lwork = static_cast<f2c::integer>(work[0] + 0.5);
    work.resize(lwork);
    clapack::dsyev_(V, U, &N, &A[0], &N, &e[0], &work[0], &lwork, &info);
    return info;
}

f2c::integer inline eig(matrix<f2c::real> &A, matrix<f2c::real> &e) {
    f2c::integer N = A.size(1), lwork = -1, info;
    matrix<f2c::real> work(1);
    static char V[] = "V", U[] = "U";
    clapack::ssyev_(V, U, &N, &A[0], &N, &e[0], &work[0], &lwork, &info);
    lwork = static_cast<f2c::integer>(work[0] + 0.5);
    work.resize(lwork);
    clapack::ssyev_(V, U, &N, &A[0], &N, &e[0], &work[0], &lwork, &info);
    return info;
}

f2c::integer inline dgesv(matrix<f2c::doublereal> &A, matrix<f2c::doublereal> &bx) {
    f2c::integer n = A.size(1), nrhs = bx.size(2), info;
    matrix<f2c::integer> lpiv(n);
    clapack::dgesv_(&n, &nrhs,
                    &A[0], &n,
                    &lpiv[0],
                    &bx[0], &n,
                    &info);
    return info;
}

} // namespace matrix
} // namespace zjucad
