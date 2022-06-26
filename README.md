# sort_algorithms

Yet another algorithms study repository

## usage

`$ make <algo name>`

For example
```
$ make shell
cc main.c shell/sort.c -o shell/sort
shell/sort random
------- random array -------
consumed 31.250ms
compare: 3947614
swap: 3021748

shell/sort ascend
------- ascend array -------
consumed 0.0ms
compare: 15
swap: 0

shell/sort descend
------- descend array -------
consumed 0.0ms
compare: 21
swap: 13
```
