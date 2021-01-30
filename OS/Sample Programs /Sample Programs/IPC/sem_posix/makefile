CXX = CC

targets = test_semp2 test_semp


all : $(targets)

$(targets) : $$@.C 
	$(CXX) -o $@ $@.C  -lposix4

clean :
	/bin/rm -f  $(targets)
