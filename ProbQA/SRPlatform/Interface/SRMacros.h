// Probabilistic Question-Answering system
// @2017 Sarge Rogatch
// This software is distributed under GNU AGPLv3 license. See file LICENSE in repository root for details.

#pragma once

// Disable "conditional expression is constant" warning in `do { } while(false);` loops
#define WHILE_FALSE               \
  __pragma(warning(push))         \
  __pragma(warning(disable:4127)) \
  while(false)                    \
  __pragma(warning(pop))

#define SR_STRINGIZE(x) SR_STRINGIZE2(x)
#define SR_STRINGIZE2(x) #x
#define SR_LINE_STRING SR_STRINGIZE(__LINE__)

#define SR_COMBINE2(x, y) x ## y
#define SR_COMBINE(x, y) SR_COMBINE2(x, y)

#define SR_FILE_LINE __FILE__ "(" SR_LINE_STRING "): "

#define ATTR_NOALIAS __declspec(noalias)
#define ATTR_RESTRICT __declspec(restrict)
#define ATTR_NORETURN __declspec(noreturn)
#define ATTR_NOINLINE __declspec(noinline)
#define ATTR_NOVTABLE __declspec(novtable)

#define PTR_RESTRICT __restrict
#define SR_UNREACHABLE __assume(0)

// Cast for *printf format
#define CASTF_HU(var) static_cast<unsigned short>(var)
#define CASTF_DU(var) static_cast<unsigned int>(var)
