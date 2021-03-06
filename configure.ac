#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([pi-blaster], [0.1.2])
AC_CONFIG_SRCDIR([pi-blaster-mqtt.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE

# Default folders
AC_PREFIX_DEFAULT([/usr])

test "$sysconfdir" = '${prefix}/etc' && sysconfdir=/etc
test "$sharedstatedir" = '${prefix}/com' && sharedstatedir=/var
test "$localstatedir" = '${prefix}/var' && localstatedir=/var

# Checks for debian packaging.
AC_ARG_ENABLE(
  [debian-pkg],
  AS_HELP_STRING([--enable-debian-pkg], [build for debian pkg, no init file installed]),
  [
    case "${enableval}" in
      yes) enable_debian_pkg=yes ;;
      no) enable_debian_pkg=no ;;
      *) AC_MSG_ERROR([bad value ${enableval} for --enable-debian-pkg]) ;;
    esac],
  [enable_debian_pkg=no])

# Checks for systemd.
PKG_PROG_PKG_CONFIG
AC_ARG_WITH([systemdsystemunitdir],
 AS_HELP_STRING([--with-systemdsystemunitdir=DIR], [Directory for systemd service files]),
 [], [with_systemdsystemunitdir=$($PKG_CONFIG --variable=systemdsystemunitdir systemd)])
if test "x$with_systemdsystemunitdir" != xno; then
 AC_SUBST([systemdsystemunitdir], [$with_systemdsystemunitdir])
fi
AM_CONDITIONAL(HAVE_SYSTEMD, [test -n "$with_systemdsystemunitdir" -a "x$with_systemdsystemunitdir" != xno ])
AM_CONDITIONAL(CROSS_COMPILING, [test x"$cross_compiling" = x"yes" ])
AM_CONDITIONAL(DEBIAN_PKG, [test x"$enable_debian_pkg" = x"yes" ])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_MAKE_SET

# Check for libraries.
AC_SEARCH_LIBS([mosquitto_new], [mosquitto_subscribe])

# Check for header files.
AC_CHECK_HEADERS([fcntl.h stdint.h stdlib.h string.h sys/ioctl.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_HEADER_MAJOR
AC_FUNC_MMAP
AC_CHECK_FUNCS([memset mkfifo munmap])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
