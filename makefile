CC = g++
SRC = .

foo = $(bar)
bar = bbaarr

MYDIR=./*

.PHONY: all clean print

all: $(MYDIR)
	for dir in $^; do \
		$(MAKE) -k -C $${dir};\
	done

MAKEFLAGS=-k

clean: $(MYDIR)
	for dir in $^; do \
		$(MAKE) clean -k -C $${dir};\
	done
	
print:
	@echo $(foo)




