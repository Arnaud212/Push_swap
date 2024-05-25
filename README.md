# Push_swap

## Description

The `push_swap` project involves sorting a stack of data using a limited set of instructions. The goal is to perform the sort with the fewest possible operations. This requires manipulating different sorting algorithms to choose the most optimal solution for sorting the data.

## Usage Instructions

### Compilation

To compile the project, use the provided Makefile. You can execute the following commands:

```sh
make
```

### Usage

The push_swap program takes a list of integers as arguments and returns a sequence of instructions to sort these integers. For example:

``` sh
./push_swap 2 1 3 6 5 8
```

This command will display a series of instructions to sort the given list of integers.

### Example Output

If you execute:

```sh
./push_swap 2 1 3 6 5 8
```

The output might be:

```
sa
pb
pb
pb
sa
pa
pa
pa
```