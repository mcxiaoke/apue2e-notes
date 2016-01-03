objects= hello.o

a.out: $(objects)
	cc $(objects)

.PHONY: hello clean run

hello: a.out

run: a.out
	./a.out

clean:
	-rm a.out $(objects)

# 在Makefile中的命令，必须要以 Tab 键开始
# http://htwm.readthedocs.org/zh_CN/latest/introduction.html
