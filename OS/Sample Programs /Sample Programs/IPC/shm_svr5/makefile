CXX = CC

targets = test_shm test_shm2


all : $(targets)

$(targets) : $$@.C 
	$(CXX) -o $@ $@.C 

clean :
	/bin/rm -f  $(targets)
