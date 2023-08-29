# LeetCode #2483: Minimum Penalty for a Shop (Daily Challenge 08/29/2023)
This repository contains a C++ solution to the LeetCode daily challenge #2483 for 08/29/2023. https://leetcode.com/problems/minimum-penalty-for-a-shop/

This solution beats 80.18% of users in runtime (24 ms) and 86.10% of users in memory usage (10.70 MB). 

## Running
Navigate to the directory containing the extracted implementation, then simply run `make` with the included Makefile.
```
cd LeetCode-2483-Minimum-Penalty-Shop
make
```

The exact commands run by `make` are as follows:

```
g++ -Wall -O2 -pipe -fno-plt -fPIC minimum_penalty.cpp -o minimum_penalty
```

There are no arguments; the test cases are hard-coded into the C++ file. Example output:

```
       Test case     Status                  Details
----------------------------------------------------
 customers: YYNY         OK        Expected 2, got 2
customers: NNNNN         OK        Expected 0, got 0
 customers: YYYY         OK        Expected 4, got 4
```

## Cleaning up
Navigate to the directory containing the extracted implementation, then simply run `make clean` with the included Makefile.

```
cd LeetCode-2483-Minimum-Penalty-Shop
make clean
```

The exact commands run by make clean are as follows:

```
rm -f minimum_penalty
```