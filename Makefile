dirs := $(subst .,,$(shell find . -maxdepth 1 -type d))
algos := $(subst /,,$(dirs))
algos := $(subst git,,$(algos))
algos := $(subst vscode,,$(algos))
sort_bin := $(addsuffix /sort,$(algos))
#$(warning $(dirs))
#$(warning $(algos))
#$(warning $(sort_bin))

CFLAGS += -g

.PHONY: clean all performance

all: $(algos)

$(algos): %: %/sort
	$@/sort random
	$@/sort ascend
	$@/sort descend

$(sort_bin): %: %.c sort.h main.c
	$(CC) $(CFLAGS) main.c $< -o $@

performance: $(sort_bin)
	@for alg in $(algos); do echo "$$alg"; $$alg/sort random | grep consumed; echo ""; done

clean:
	rm $(shell find . -type f -name "sort")

