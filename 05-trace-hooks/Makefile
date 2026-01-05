clean:
	rm -rf *.so
build: clean
	gcc -shared -fPIC -g -O2 -o libtracehooks.so trace_hooks.c -ldl
