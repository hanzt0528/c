new_contents = "hello:\n\ttouch inside_file"
all:
	mkdir -p subdir
	#printf1 $(new_contents) | sed -e 's/^ //' > subdir/makefile
	printf $(new_contents)  > subdir/makefile
	cd subdir && $(MAKE)

clean:
	rm -rf subdir