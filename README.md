# sqrt_v2
Square root for Cryptonight variant 2 - integer only operations. This code is intended for CPUs with slow FPU or without FPU at all. CPUs with 32 KB or larger L1 cache will be faster with large LUT version. CPUs with very small L1 cache will be faster with small LUT version.

#### SqrtV2::get() function (fast_sqrt_v2.h)
- 16 KB LUT table
- 4 integer multiplications to calculate square root
- First 2 multiplications can be done in parallel
- 3 multiplications on the longest dependency chain

#### SqrtV2SmallLUT::get() function (fast_sqrt_v2_small_LUT.h)
- 1.5 KB LUT table
- 6 integer multiplications to calculate square root
- First 2 pairs of multiplications can be done in parallel
- 4 multiplications on the longest dependency chain

#### SqrtV2LargeLUT::get() function (fast_sqrt_v2_large_LUT.h)
- 256 KB LUT table
- 2 integer multiplications to calculate square root
- 2 multiplications on the longest dependency chain
