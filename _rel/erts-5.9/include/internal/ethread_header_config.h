/* include/internal/i386-apple-darwin11.2.0/ethread_header_config.h.  Generated from ethread_header_config.h.in by configure.  */
/*
 * %CopyrightBegin%
 *
 * Copyright Ericsson AB 2004-2011. All Rights Reserved.
 *
 * The contents of this file are subject to the Erlang Public License,
 * Version 1.1, (the "License"); you may not use this file except in
 * compliance with the License. You should have received a copy of the
 * Erlang Public License along with this software. If not, it can be
 * retrieved online at http://www.erlang.org/.
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
 * the License for the specific language governing rights and limitations
 * under the License.
 *
 * %CopyrightEnd%
 */

/* Define to the size of pointers */
#define ETHR_SIZEOF_PTR 8

/* Define to the size of int */
#define ETHR_SIZEOF_INT 4

/* Define to the size of long */
#define ETHR_SIZEOF_LONG 8

/* Define to the size of long long */
#define ETHR_SIZEOF_LONG_LONG 8

/* Define to the size of __int64 */
#define ETHR_SIZEOF___INT64 0

/* Define to the size of __int128_t */
#define ETHR_SIZEOF___INT128_T 16

/* Define if bigendian */
/* #undef ETHR_BIGENDIAN */

/* Define if you want to disable native ethread implementations */
/* #undef ETHR_DISABLE_NATIVE_IMPLS */

/* Define if you have win32 threads */
/* #undef ETHR_WIN32_THREADS */

/* Define if you have pthreads */
#define ETHR_PTHREADS 1

/* Define if you need the <nptl/pthread.h> header file. */
/* #undef ETHR_NEED_NPTL_PTHREAD_H */

/* Define if you have the <pthread.h> header file. */
#define ETHR_HAVE_PTHREAD_H 1

/* Define if the pthread.h header file is in pthread/mit directory. */
/* #undef ETHR_HAVE_MIT_PTHREAD_H */

/* Define if you have the pthread_spin_lock function. */
/* #undef ETHR_HAVE_PTHREAD_SPIN_LOCK */

/* Define if you want to force usage of pthread rwlocks */
/* #undef ETHR_FORCE_PTHREAD_RWLOCK */

/* Define if you have the pthread_rwlockattr_setkind_np() function. */
/* #undef ETHR_HAVE_PTHREAD_RWLOCKATTR_SETKIND_NP */

/* Define if you have the PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP rwlock
   attribute. */
/* #undef ETHR_HAVE_PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP */

/* Define if you have a linux futex implementation. */
/* #undef ETHR_HAVE_LINUX_FUTEX */

/* Define if x86/x86_64 out of order instructions should be synchronized */
/* #undef ETHR_X86_OUT_OF_ORDER */

/* Define if only run in Sparc TSO mode */
/* #undef ETHR_SPARC_TSO */

/* Define if only run in Sparc PSO, or TSO mode */
/* #undef ETHR_SPARC_PSO */

/* Define if run in Sparc RMO, PSO, or TSO mode */
/* #undef ETHR_SPARC_RMO */

/* Define if you have __sync_add_and_fetch() for 32-bit integers */
#define ETHR_HAVE___SYNC_ADD_AND_FETCH32 1

/* Define if you have __sync_add_and_fetch() for 64-bit integers */
#define ETHR_HAVE___SYNC_ADD_AND_FETCH64 1

/* Define if you have __sync_fetch_and_and() for 32-bit integers */
#define ETHR_HAVE___SYNC_FETCH_AND_AND32 1

/* Define if you have __sync_fetch_and_and() for 64-bit integers */
#define ETHR_HAVE___SYNC_FETCH_AND_AND64 1

/* Define if you have __sync_fetch_and_or() for 32-bit integers */
#define ETHR_HAVE___SYNC_FETCH_AND_OR32 1

/* Define if you have __sync_fetch_and_or() for 64-bit integers */
#define ETHR_HAVE___SYNC_FETCH_AND_OR64 1

/* Define if you have __sync_val_compare_and_swap() for 32-bit integers */
#define ETHR_HAVE___SYNC_VAL_COMPARE_AND_SWAP32 1

/* Define if you have __sync_val_compare_and_swap() for 64-bit integers */
#define ETHR_HAVE___SYNC_VAL_COMPARE_AND_SWAP64 1

/* Define if you have __sync_val_compare_and_swap() for 128-bit integers */
#define ETHR_HAVE___SYNC_VAL_COMPARE_AND_SWAP128 1

/* Define if you prefer gcc native ethread implementations */
/* #undef ETHR_PREFER_GCC_NATIVE_IMPLS */

/* Define if you have the <sched.h> header file. */
#define ETHR_HAVE_SCHED_H 1

/* Define if you have the sched_yield() function. */
#define ETHR_HAVE_SCHED_YIELD 1

/* Define if you have the pthread_yield() function. */
/* #undef ETHR_HAVE_PTHREAD_YIELD */

/* Define if pthread_yield() returns an int. */
/* #undef ETHR_PTHREAD_YIELD_RET_INT */

/* Define if sched_yield() returns an int. */
#define ETHR_SCHED_YIELD_RET_INT 1

/* Define if you use a gcc that supports -msse2 and understand sse2 specific asm statements */
/* #undef ETHR_GCC_HAVE_SSE2_ASM_SUPPORT */

/* Define if you use a gcc that supports the double word cmpxchg instruction */
#define ETHR_GCC_HAVE_DW_CMPXCHG_ASM_SUPPORT 1

/* Define if you get a register shortage with cmpxchg8b and position independent code */
/* #undef ETHR_CMPXCHG8B_REGISTER_SHORTAGE */

/* Define if you have the pthread_rwlockattr_setkind_np() function. */
/* #undef ETHR_HAVE_PTHREAD_RWLOCKATTR_SETKIND_NP */

/* Define if you have the PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP rwlock
   attribute. */
/* #undef ETHR_HAVE_PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP */

/* Define if you have gcc atomic operations */
/* #undef ETHR_HAVE_GCC_ATOMIC_OPS */

/* Define if you prefer gcc native ethread implementations */
/* #undef ETHR_PREFER_GCC_NATIVE_IMPLS */

/* Define if you have libatomic_ops atomic operations */
/* #undef ETHR_HAVE_LIBATOMIC_OPS */

/* Define if you prefer libatomic_ops native ethread implementations */
/* #undef ETHR_PREFER_LIBATOMIC_OPS_NATIVE_IMPLS */

/* Define to the size of AO_t if libatomic_ops is used */
/* #undef ETHR_SIZEOF_AO_T */

/* Define if you have _InterlockedAnd() */
/* #undef ETHR_HAVE__INTERLOCKEDAND */

/* Define if you have _InterlockedAnd64() */
/* #undef ETHR_HAVE__INTERLOCKEDAND64 */

/* Define if you have _InterlockedCompareExchange() */
/* #undef ETHR_HAVE__INTERLOCKEDCOMPAREEXCHANGE */

/* Define if you have _InterlockedCompareExchange64() */
/* #undef ETHR_HAVE__INTERLOCKEDCOMPAREEXCHANGE64 */

/* Define if you have _InterlockedCompareExchange64_acq() */
/* #undef ETHR_HAVE__INTERLOCKEDCOMPAREEXCHANGE64_ACQ */

/* Define if you have _InterlockedCompareExchange64_rel() */
/* #undef ETHR_HAVE__INTERLOCKEDCOMPAREEXCHANGE64_REL */

/* Define if you have _InterlockedCompareExchange_acq() */
/* #undef ETHR_HAVE__INTERLOCKEDCOMPAREEXCHANGE_ACQ */

/* Define if you have _InterlockedCompareExchange_rel() */
/* #undef ETHR_HAVE__INTERLOCKEDCOMPAREEXCHANGE_REL */

/* Define if you have _InterlockedDecrement() */
/* #undef ETHR_HAVE__INTERLOCKEDDECREMENT */

/* Define if you have _InterlockedDecrement64() */
/* #undef ETHR_HAVE__INTERLOCKEDDECREMENT64 */

/* Define if you have _InterlockedDecrement64_rel() */
/* #undef ETHR_HAVE__INTERLOCKEDDECREMENT64_REL */

/* Define if you have _InterlockedDecrement_rel() */
/* #undef ETHR_HAVE__INTERLOCKEDDECREMENT_REL */

/* Define if you have _InterlockedExchange() */
/* #undef ETHR_HAVE__INTERLOCKEDEXCHANGE */

/* Define if you have _InterlockedExchange64() */
/* #undef ETHR_HAVE__INTERLOCKEDEXCHANGE64 */

/* Define if you have _InterlockedExchangeAdd() */
/* #undef ETHR_HAVE__INTERLOCKEDEXCHANGEADD */

/* Define if you have _InterlockedExchangeAdd64() */
/* #undef ETHR_HAVE__INTERLOCKEDEXCHANGEADD64 */

/* Define if you have _InterlockedExchangeAdd64_acq() */
/* #undef ETHR_HAVE__INTERLOCKEDEXCHANGEADD64_ACQ */

/* Define if you have _InterlockedExchangeAdd_acq() */
/* #undef ETHR_HAVE__INTERLOCKEDEXCHANGEADD_ACQ */

/* Define if you have _InterlockedIncrement() */
/* #undef ETHR_HAVE__INTERLOCKEDINCREMENT */

/* Define if you have _InterlockedIncrement64() */
/* #undef ETHR_HAVE__INTERLOCKEDINCREMENT64 */

/* Define if you have _InterlockedIncrement64_acq() */
/* #undef ETHR_HAVE__INTERLOCKEDINCREMENT64_ACQ */

/* Define if you have _InterlockedIncrement_acq() */
/* #undef ETHR_HAVE__INTERLOCKEDINCREMENT_ACQ */

/* Define if you have _InterlockedOr() */
/* #undef ETHR_HAVE__INTERLOCKEDOR */

/* Define if you have _InterlockedOr64() */
/* #undef ETHR_HAVE__INTERLOCKEDOR64 */

/* Define if you want to turn on extra sanity checking in the ethread library */
/* #undef ETHR_XCHK */

