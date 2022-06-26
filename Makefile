dirs := $(subst .,,$(shell find . -type d))
algos := $(subst /,,$(dirs))
sort_bin := $(addsuffix /sort,$(algos))
#$(warning $(dirs))
#$(warning $(algos))
#$(warning $(sort_bin))

.PHONY: clean all

all: $(algos)

$(algos): %: %/sort
	$@/sort random
	$@/sort ascend
	$@/sort descend

$(sort_bin): %: %.c sort.h main.c
	$(CC) main.c $< -o $@

clean:
	rm $(shell find . -type f -name "sort")

