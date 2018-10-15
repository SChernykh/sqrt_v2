#pragma once

#include <stdint.h>

#ifdef __GNUC__
#define FORCEINLINE __attribute__((always_inline)) inline
#else
#define FORCEINLINE __forceinline
#endif

static FORCEINLINE uint64_t sqrt_v2_single_precision(const uint64_t n0)
{
	const __m128 z = _mm_setzero_ps();

	__m128 x = reinterpret_cast<__m128&>(_mm_cvtsi64_si128((n0 >> 41) + ((64U + 127U) << 23)));

	__m128 x1 = _mm_rsqrt_ss(x);
	x = _mm_sqrt_ss(x);
	int64_t x0 = (_mm_cvtsi128_si64(reinterpret_cast<__m128i&>(x)) - (158L << 23)) << 9;
	__m128 dx = _mm_cvtsi64_ss(z, static_cast<int64_t>(n0) - x0 * x0);
	x0 <<= 1;
	x1 = _mm_mul_ss(x1, dx);
	x0 += _mm_cvtss_si64(x1);

	const uint32_t s = static_cast<uint32_t>(x0 >> 1);
	const uint32_t b = static_cast<uint32_t>(x0 & 1);

	const uint64_t x2 = uint64_t(s) * (s + b) + (x0 << 32) - n0;
	x0 += ((int64_t(x2 + b) > 0) ? -1 : 0) + ((int64_t(x2 + s + (1ULL << 32)) < 0) ? 1 : 0);
	return x0;
}
