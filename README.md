# sort_algorithms

Yet another algorithms study repository

## usage

`$ make <algo name>`

For example
```
$ make bubble
cc main.c bubble/sort.c -o bubble/sort
bubble/sort random
------- random array -------
0 1 2 3 4 5 6 7 8 9
compare: 45
swap: 19

bubble/sort ascend
------- ascend array -------
0 1 2 3 4 5 6 7 8 9
compare: 45
swap: 0

bubble/sort descend
------- descend array -------
0 1 2 3 4 5 6 7 8 9
compare: 45
swap: 45
```
