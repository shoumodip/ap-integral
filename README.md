# Integration of Arithmetic Progressions
Track the error between integration and AP accumulation.

## Quick Start
```console
$ make
$ ./scale > output.log
```

## Usage
```console
$ ./scale [COUNT=10]
```

## Context
- Summation of an AP is basically an accumulation function
- Now since the AP has a constant difference, its sum is *almost* an integral
- However in the integral we are advancing the difference to 0, unlike in AP
- This program attempts to the find the constant `k` such that `ap_sum = k * ap_integral`

## Observations
- As `n` increases, the error decreases
- As `d` increases, the error increases

## Use Cases
None. Especially because Accumulation functions as well as **dedicated** AP
functions exist. The only purpose of this project is educational.
