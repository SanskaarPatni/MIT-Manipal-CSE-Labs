CXX = CC

targets = test_mmap


all : $(targets)

$(targets) : $$@.C 
	$(CXX) $(CFLAGS) -o $@ $@.C 

clean :
	/bin/rm -f  $(targets)
