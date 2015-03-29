dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(cms-light, 1.0)

AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE()

AC_PROG_CXX
AC_PROG_RANLIB

AC_SEARCH_LIBS([grpc_init], [grpc], [], [
  AC_MSG_ERROR([unable to find the grpc_init() function])
])

AC_SEARCH_LIBS([redisFree], [hiredis], [], [
  AC_MSG_ERROR([unable to find the redisCommand() function])
])

AC_CHECK_HEADERS([grpc/grpc.h], [cms_found_int_headers=yes; break;])

AC_CHECK_HEADERS([hiredis/hiredis.h], [cms_found_int_headers=yes; break;])
	
AC_CONFIG_FILES(Makefile libcmslight/Makefile libaggregaterepo/Makefile frontend/Makefile services/Makefile services/content/Makefile services/aggregate/Makefile)
AC_OUTPUT

