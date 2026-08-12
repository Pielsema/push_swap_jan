*This project has been created as part of the 42 curriculum by jsobotka, pielsema.*

# push_swap

## Description

`push_swap` is a sorting project based on two stacks, `a` and `b`. The program receives a list of unique integers and prints the operations needed to sort stack `a` in ascending order from the smallest number.

## Instructions

Run the program with a list of integers:

```sh
./push_swap 4 67 3 87 23
```

or as a string:

```sh
./push_swap "4 67 3 87 23"
```

If no selector is provided, `--adaptive` is used.

```sh
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

also, `--debug` prints the final state of both stacks to stderror.

```sh
./push_swap --debug --adaptive 3 2 1
```

The required `--bench` mode reports disorder, strategy name, complexity class,
total operation count, and per-operation counts on standard error.

```sh
./push_swap --bench --adaptive 3 2 1
```

Benchmark output is sent to standard error, so the operation stream on standard
output can still be piped into `checker_linux`.

## Operations

The program may output only the following Push_swap instructions:

- `sa`, `sb`, `ss`
- `pa`, `pb`
- `ra`, `rb`, `rr`
- `rra`, `rrb`, `rrr`

Each operation is printed on its own line. For normal runs, nothing other than
operations is printed to standard output.

## Algorithms

### Simple - O(n2)

The baseline method intended for low-disorder inputs and
small stacks. It uses specialized handling for two to five values, an
almost-sorted path, and a generic minimum-extraction approach for larger cases.

In the generic path, the current minimum is rotated to the top of stack `a`,
pushed to stack `b`, and later pushed back to stack `a`. This can require a
linear scan and a linear number of rotations for each element, giving an
O(n2) upper bound in the Push_swap operation model.

### Medium - O(n sqrt(n))

Uses chunk-based sorting. The stack is divided into ranges
whose size is based on `sqrt(n)`. Values are pushed from `a` to `b` according to
their index range, then pushed back from `b` to `a` in descending index order.


### Complex - O(n log n)

Uses binary radix sorting on normalized indexes. Each
number receives an index from `0` to `n - 1`, then the algorithm processes each
bit from least significant to most significant.

For each bit, all elements are inspected once and moved or rotated according to
that bit.

### Adaptive

This method measures disorder before making any move. Disorder being
the ratio of inverted pairs in relation to total pairs.

```text
disorder = inverted_pairs / total_pairs
```

The current thresholds follow the subject:

- Low disorder: `disorder < 0.2` uses the simple O(n2) strategy.
- Medium disorder: `0.2 <= disorder < 0.5` uses the medium O(n sqrt(n))
  strategy.
- High disorder: `disorder >= 0.5` uses the complex O(n log n) strategy.


## Error Handling

Invalid input prints:

```text
Error
```

to stderror.

Errors include non-integer values, duplicate values, empty arguments, and values
outside the signed 32-bit integer range.

## Resources And AI Usage

Resources used or useful for this project:
Code Vault's "Linked lists for beginners" series was fundamental for the development of this project. As well as geeksforgeeks.org explanations of the functionality of the most common sorting algorithms.
AI was used as a review and implementation assistant for repetitive or
cross-checking tasks. 

## Contributions

`jsobotka` created and developed the original project structure and the initial
sorting implementation.

`pielsema` is responsible for wiring adaptive sorting to the disorder metric, moving debug stack output behind `--debug`, fixing error output, hardening integer validation, norminette compliance and implementing benchmark mode.
