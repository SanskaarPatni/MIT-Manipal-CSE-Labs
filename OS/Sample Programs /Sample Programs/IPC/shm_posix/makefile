CXX = CC 

targets = test_shmp


all : $(targets)

$(targets) : $$@.C 
	$(CXX) -o $@ -D_POSIX_C_SOURCE=4 $@.C  -lposix4

clean :
	/bin/rm -f  $(targets)
