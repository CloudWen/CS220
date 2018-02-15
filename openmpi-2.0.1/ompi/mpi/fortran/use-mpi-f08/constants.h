/* WARNING! THIS IS A GENERATED FILE!!
 * ANY EDITS YOU PUT HERE WILL BE LOST!
 * Instead, edit topdir/ompi/include/mpif-values.pl
 */

/*
 * Copyright (c) 2004-2005 The Trustees of Indiana University and Indiana
 *                         University Research and Technology
 *                         Corporation.  All rights reserved.
 * Copyright (c) 2004-2006 The University of Tennessee and The University
 *                         of Tennessee Research Foundation.  All rights
 *                         reserved.
 * Copyright (c) 2004-2007 High Performance Computing Center Stuttgart,
 *                         University of Stuttgart.  All rights reserved.
 * Copyright (c) 2004-2005 The Regents of the University of California.
 *                         All rights reserved.
 * Copyright (c) 2007-2009 Cisco Systems, Inc.  All rights reserved.
 * Copyright (c) 2008-2009 Sun Microsystems, Inc.  All rights reserved.
 * Copyright (c) 2009      Oak Ridge National Labs.  All rights reserved.
 * Copyright (c) 2009-2012 Los Alamos National Security, LLC.
 *                         All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */

#ifndef USE_MPI_F08_CONSTANTS_H
#define USE_MPI_F08_CONSTANTS_H

#define OMPI_MPI_ANY_SOURCE -1
#define OMPI_MPI_ANY_TAG -1
#define OMPI_MPI_APPNUM 4
#define OMPI_MPI_BSEND_OVERHEAD 128
#define OMPI_MPI_CART 1
#define OMPI_MPI_COMBINER_CONTIGUOUS 2
#define OMPI_MPI_COMBINER_DARRAY 13
#define OMPI_MPI_COMBINER_DUP 1
#define OMPI_MPI_COMBINER_F90_COMPLEX 15
#define OMPI_MPI_COMBINER_F90_INTEGER 16
#define OMPI_MPI_COMBINER_F90_REAL 14
#define OMPI_MPI_COMBINER_HINDEXED 8
#define OMPI_MPI_COMBINER_HINDEXED_BLOCK 18
#define OMPI_MPI_COMBINER_HINDEXED_INTEGER 7
#define OMPI_MPI_COMBINER_HVECTOR 5
#define OMPI_MPI_COMBINER_HVECTOR_INTEGER 4
#define OMPI_MPI_COMBINER_INDEXED 6
#define OMPI_MPI_COMBINER_INDEXED_BLOCK 9
#define OMPI_MPI_COMBINER_NAMED 0
#define OMPI_MPI_COMBINER_RESIZED 17
#define OMPI_MPI_COMBINER_STRUCT 11
#define OMPI_MPI_COMBINER_STRUCT_INTEGER 10
#define OMPI_MPI_COMBINER_SUBARRAY 12
#define OMPI_MPI_COMBINER_VECTOR 3
#define OMPI_MPI_COMM_TYPE_SHARED 0
#define OMPI_MPI_CONGRUENT 1
#define OMPI_MPI_DISTRIBUTE_BLOCK 0
#define OMPI_MPI_DISTRIBUTE_CYCLIC 1
#define OMPI_MPI_DISTRIBUTE_DFLT_DARG -1
#define OMPI_MPI_DISTRIBUTE_NONE 2
#define OMPI_MPI_DIST_GRAPH 3
#define OMPI_MPI_ERROR 3
#define OMPI_MPI_ERR_ACCESS 20
#define OMPI_MPI_ERR_AMODE 21
#define OMPI_MPI_ERR_ARG 13
#define OMPI_MPI_ERR_ASSERT 22
#define OMPI_MPI_ERR_BAD_FILE 23
#define OMPI_MPI_ERR_BASE 24
#define OMPI_MPI_ERR_BUFFER 1
#define OMPI_MPI_ERR_COMM 5
#define OMPI_MPI_ERR_CONVERSION 25
#define OMPI_MPI_ERR_COUNT 2
#define OMPI_MPI_ERR_DIMS 12
#define OMPI_MPI_ERR_DISP 26
#define OMPI_MPI_ERR_DUP_DATAREP 27
#define OMPI_MPI_ERR_FILE 30
#define OMPI_MPI_ERR_FILE_EXISTS 28
#define OMPI_MPI_ERR_FILE_IN_USE 29
#define OMPI_MPI_ERR_GROUP 9
#define OMPI_MPI_ERR_INFO 34
#define OMPI_MPI_ERR_INFO_KEY 31
#define OMPI_MPI_ERR_INFO_NOKEY 32
#define OMPI_MPI_ERR_INFO_VALUE 33
#define OMPI_MPI_ERR_INTERN 17
#define OMPI_MPI_ERR_IN_STATUS 18
#define OMPI_MPI_ERR_IO 35
#define OMPI_MPI_ERR_KEYVAL 36
#define OMPI_MPI_ERR_LASTCODE 92
#define OMPI_MPI_ERR_LOCKTYPE 37
#define OMPI_MPI_ERR_NAME 38
#define OMPI_MPI_ERR_NOT_SAME 40
#define OMPI_MPI_ERR_NO_MEM 39
#define OMPI_MPI_ERR_NO_SPACE 41
#define OMPI_MPI_ERR_NO_SUCH_FILE 42
#define OMPI_MPI_ERR_OP 10
#define OMPI_MPI_ERR_OTHER 16
#define OMPI_MPI_ERR_PENDING 19
#define OMPI_MPI_ERR_PORT 43
#define OMPI_MPI_ERR_QUOTA 44
#define OMPI_MPI_ERR_RANK 6
#define OMPI_MPI_ERR_READ_ONLY 45
#define OMPI_MPI_ERR_REQUEST 7
#define OMPI_MPI_ERR_RMA_ATTACH 69
#define OMPI_MPI_ERR_RMA_CONFLICT 46
#define OMPI_MPI_ERR_RMA_FLAVOR 70
#define OMPI_MPI_ERR_RMA_RANGE 68
#define OMPI_MPI_ERR_RMA_SHARED 71
#define OMPI_MPI_ERR_RMA_SYNC 47
#define OMPI_MPI_ERR_ROOT 8
#define OMPI_MPI_ERR_SERVICE 48
#define OMPI_MPI_ERR_SIZE 49
#define OMPI_MPI_ERR_SPAWN 50
#define OMPI_MPI_ERR_TAG 4
#define OMPI_MPI_ERR_TOPOLOGY 11
#define OMPI_MPI_ERR_TRUNCATE 15
#define OMPI_MPI_ERR_TYPE 3
#define OMPI_MPI_ERR_UNKNOWN 14
#define OMPI_MPI_ERR_UNSUPPORTED_DATAREP 51
#define OMPI_MPI_ERR_UNSUPPORTED_OPERATION 52
#define OMPI_MPI_ERR_WIN 53
#define OMPI_MPI_GRAPH 2
#define OMPI_MPI_HOST 1
#define OMPI_MPI_IDENT 0
#define OMPI_MPI_IO 2
#define OMPI_MPI_KEYVAL_INVALID -1
#define OMPI_MPI_LASTUSEDCODE 5
#define OMPI_MPI_LOCK_EXCLUSIVE 1
#define OMPI_MPI_LOCK_SHARED 2
#define OMPI_MPI_MODE_NOCHECK 1
#define OMPI_MPI_MODE_NOPRECEDE 2
#define OMPI_MPI_MODE_NOPUT 4
#define OMPI_MPI_MODE_NOSTORE 8
#define OMPI_MPI_MODE_NOSUCCEED 16
#define OMPI_MPI_ORDER_C 0
#define OMPI_MPI_ORDER_FORTRAN 1
#define OMPI_MPI_PROC_NULL -2
#define OMPI_MPI_ROOT -4
#define OMPI_MPI_SIMILAR 2
#define OMPI_MPI_SOURCE 1
#define OMPI_MPI_SUBVERSION 1
#define OMPI_MPI_SUCCESS 0
#define OMPI_MPI_TAG 2
#define OMPI_MPI_TAG_UB 0
#define OMPI_MPI_THREAD_FUNNELED 1
#define OMPI_MPI_THREAD_MULTIPLE 3
#define OMPI_MPI_THREAD_SERIALIZED 2
#define OMPI_MPI_THREAD_SINGLE 0
#define OMPI_MPI_TYPECLASS_COMPLEX 3
#define OMPI_MPI_TYPECLASS_INTEGER 1
#define OMPI_MPI_TYPECLASS_REAL 2
#define OMPI_MPI_T_ERR_CANNOT_INIT 56
#define OMPI_MPI_T_ERR_CVAR_SET_NEVER 64
#define OMPI_MPI_T_ERR_CVAR_SET_NOT_NOW 63
#define OMPI_MPI_T_ERR_INVALID 72
#define OMPI_MPI_T_ERR_INVALID_HANDLE 59
#define OMPI_MPI_T_ERR_INVALID_INDEX 57
#define OMPI_MPI_T_ERR_INVALID_ITEM 58
#define OMPI_MPI_T_ERR_INVALID_SESSION 62
#define OMPI_MPI_T_ERR_MEMORY 54
#define OMPI_MPI_T_ERR_NOT_INITIALIZED 55
#define OMPI_MPI_T_ERR_OUT_OF_HANDLES 60
#define OMPI_MPI_T_ERR_OUT_OF_SESSIONS 61
#define OMPI_MPI_T_ERR_PVAR_NO_ATOMIC 67
#define OMPI_MPI_T_ERR_PVAR_NO_STARTSTOP 65
#define OMPI_MPI_T_ERR_PVAR_NO_WRITE 66
#define OMPI_MPI_UNDEFINED -32766
#define OMPI_MPI_UNEQUAL 3
#define OMPI_MPI_UNIVERSE_SIZE 6
#define OMPI_MPI_VERSION 3
#define OMPI_MPI_WIN_BASE 7
#define OMPI_MPI_WIN_CREATE_FLAVOR 10
#define OMPI_MPI_WIN_DISP_UNIT 9
#define OMPI_MPI_WIN_FLAVOR_ALLOCATE 2
#define OMPI_MPI_WIN_FLAVOR_CREATE 1
#define OMPI_MPI_WIN_FLAVOR_DYNAMIC 3
#define OMPI_MPI_WIN_FLAVOR_SHARED 4
#define OMPI_MPI_WIN_MODEL 11
#define OMPI_MPI_WIN_SEPARATE 1
#define OMPI_MPI_WIN_SIZE 8
#define OMPI_MPI_WIN_UNIFIED 0
#define OMPI_MPI_WTIME_IS_GLOBAL 3
#define OMPI_OMPI_COMM_TYPE_BOARD 8
#define OMPI_OMPI_COMM_TYPE_CLUSTER 11
#define OMPI_OMPI_COMM_TYPE_CORE 2
#define OMPI_OMPI_COMM_TYPE_CU 10
#define OMPI_OMPI_COMM_TYPE_HOST 9
#define OMPI_OMPI_COMM_TYPE_HWTHREAD 1
#define OMPI_OMPI_COMM_TYPE_L1CACHE 3
#define OMPI_OMPI_COMM_TYPE_L2CACHE 4
#define OMPI_OMPI_COMM_TYPE_L3CACHE 5
#define OMPI_OMPI_COMM_TYPE_NODE 0
#define OMPI_OMPI_COMM_TYPE_NUMA 7
#define OMPI_OMPI_COMM_TYPE_SOCKET 6

#define OMPI_MPI_2COMPLEX 26
#define OMPI_MPI_2DOUBLE_COMPLEX 27
#define OMPI_MPI_2DOUBLE_PRECISION 24
#define OMPI_MPI_2INT 52
#define OMPI_MPI_2INTEGER 25
#define OMPI_MPI_2REAL 23
#define OMPI_MPI_AINT 66
#define OMPI_MPI_BAND 6
#define OMPI_MPI_BOR 8
#define OMPI_MPI_BXOR 10
#define OMPI_MPI_BYTE 1
#define OMPI_MPI_CHAR 34
#define OMPI_MPI_CHARACTER 5
#define OMPI_MPI_COMM_NULL 2
#define OMPI_MPI_COMM_SELF 1
#define OMPI_MPI_COMM_WORLD 0
#define OMPI_MPI_COMPLEX 18
#define OMPI_MPI_COMPLEX16 20
#define OMPI_MPI_COMPLEX32 21
#define OMPI_MPI_COMPLEX8 19
#define OMPI_MPI_COUNT 72
#define OMPI_MPI_CXX_BOOL 54
#define OMPI_MPI_CXX_COMPLEX 55
#define OMPI_MPI_CXX_DOUBLE_COMPLEX 56
#define OMPI_MPI_CXX_FLOAT_COMPLEX 55
#define OMPI_MPI_CXX_LONG_DOUBLE_COMPLEX 57
#define OMPI_MPI_C_BOOL 73
#define OMPI_MPI_C_COMPLEX 68
#define OMPI_MPI_C_DOUBLE_COMPLEX 70
#define OMPI_MPI_C_FLOAT_COMPLEX 69
#define OMPI_MPI_C_LONG_DOUBLE_COMPLEX 71
#define OMPI_MPI_DATATYPE_NULL 0
#define OMPI_MPI_DOUBLE 46
#define OMPI_MPI_DOUBLE_COMPLEX 22
#define OMPI_MPI_DOUBLE_INT 49
#define OMPI_MPI_DOUBLE_PRECISION 17
#define OMPI_MPI_ERRHANDLER_NULL 0
#define OMPI_MPI_ERRORS_ARE_FATAL 1
#define OMPI_MPI_ERRORS_RETURN 2
#define OMPI_MPI_FLOAT 45
#define OMPI_MPI_FLOAT_INT 48
#define OMPI_MPI_GROUP_EMPTY 1
#define OMPI_MPI_GROUP_NULL 0
#define OMPI_MPI_INFO_ENV 1
#define OMPI_MPI_INFO_NULL 0
#define OMPI_MPI_INT 39
#define OMPI_MPI_INT16_T 60
#define OMPI_MPI_INT32_T 62
#define OMPI_MPI_INT64_T 64
#define OMPI_MPI_INT8_T 58
#define OMPI_MPI_INTEGER 7
#define OMPI_MPI_INTEGER1 8
#define OMPI_MPI_INTEGER16 12
#define OMPI_MPI_INTEGER2 9
#define OMPI_MPI_INTEGER4 10
#define OMPI_MPI_INTEGER8 11
#define OMPI_MPI_LAND 5
#define OMPI_MPI_LB 4
#define OMPI_MPI_LOGICAL 6
#define OMPI_MPI_LOGICAL1 29
#define OMPI_MPI_LOGICAL2 30
#define OMPI_MPI_LOGICAL4 31
#define OMPI_MPI_LOGICAL8 32
#define OMPI_MPI_LONG 41
#define OMPI_MPI_LONG_DOUBLE 47
#define OMPI_MPI_LONG_DOUBLE_INT 50
#define OMPI_MPI_LONG_INT 51
#define OMPI_MPI_LONG_LONG 43
#define OMPI_MPI_LONG_LONG_INT 43
#define OMPI_MPI_LOR 7
#define OMPI_MPI_LXOR 9
#define OMPI_MPI_MAX 1
#define OMPI_MPI_MAXLOC 11
#define OMPI_MPI_MESSAGE_NO_PROC 1
#define OMPI_MPI_MESSAGE_NULL 0
#define OMPI_MPI_MIN 2
#define OMPI_MPI_MINLOC 12
#define OMPI_MPI_NO_OP 14
#define OMPI_MPI_OFFSET 67
#define OMPI_MPI_OP_NULL 0
#define OMPI_MPI_PACKED 2
#define OMPI_MPI_PROD 4
#define OMPI_MPI_REAL 13
#define OMPI_MPI_REAL16 16
#define OMPI_MPI_REAL2 28
#define OMPI_MPI_REAL4 14
#define OMPI_MPI_REAL8 15
#define OMPI_MPI_REPLACE 13
#define OMPI_MPI_REQUEST_NULL 0
#define OMPI_MPI_SHORT 37
#define OMPI_MPI_SHORT_INT 53
#define OMPI_MPI_SIGNED_CHAR 36
#define OMPI_MPI_SUM 3
#define OMPI_MPI_UB 3
#define OMPI_MPI_UINT16_T 61
#define OMPI_MPI_UINT32_T 63
#define OMPI_MPI_UINT64_T 65
#define OMPI_MPI_UINT8_T 59
#define OMPI_MPI_UNSIGNED 40
#define OMPI_MPI_UNSIGNED_CHAR 35
#define OMPI_MPI_UNSIGNED_LONG 42
#define OMPI_MPI_UNSIGNED_LONG_LONG 44
#define OMPI_MPI_UNSIGNED_SHORT 38
#define OMPI_MPI_WCHAR 33
#define OMPI_MPI_WIN_NULL 0

#if OMPI_PROVIDE_MPI_FILE_INTERFACE
#define OMPI_MPI_DISPLACEMENT_CURRENT -54278278
#define OMPI_MPI_MODE_APPEND 128
#define OMPI_MPI_MODE_CREATE 1
#define OMPI_MPI_MODE_DELETE_ON_CLOSE 16
#define OMPI_MPI_MODE_EXCL 64
#define OMPI_MPI_MODE_RDONLY 2
#define OMPI_MPI_MODE_RDWR 8
#define OMPI_MPI_MODE_SEQUENTIAL 256
#define OMPI_MPI_MODE_UNIQUE_OPEN 32
#define OMPI_MPI_MODE_WRONLY 4
#define OMPI_MPI_SEEK_CUR 602
#define OMPI_MPI_SEEK_END 604
#define OMPI_MPI_SEEK_SET 600

#define OMPI_MPI_FILE_NULL 0
#endif /* OMPI_PROVIDE_MPI_FILE_INTERFACE */

#endif /* USE_MPI_F08_CONSTANTS_H */
