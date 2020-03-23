#pragma once

#include "frgpch.h"

#include <assert.h>

#define FRG_BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

#define FRG_BIT(x) (1 << x)

#ifdef FRG_ENABLE_ASSERTS

#define FRG_ASSERT(x, ...)                                   \
	{                                                        \
		if (!x) {                                            \
			FRG_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
			assert(false);                                   \
		}                                                    \
	}
#define FRG_CORE_ASSERT(x, ...)                                   \
	{                                                             \
		if (!x) {                                                 \
			FRG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
			assert(false);                                        \
		}                                                         \
	}
#else

#define FRG_ASSERT(x, ...)
#define FRG_CORE_ASSERT(x, ...)

#endif