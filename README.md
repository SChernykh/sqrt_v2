# sqrt_v2
Square root for Cryptonight variant 2 - integer only operations:
- 16 KB LUT table
- 4 integer multiplications to calculate square root
- First 2 multiplications can be done in parallel

This code is intended for CPUs with slow FPU or without FPU at all.
