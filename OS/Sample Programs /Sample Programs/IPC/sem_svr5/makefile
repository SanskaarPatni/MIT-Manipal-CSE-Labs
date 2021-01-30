CXX= CC

targets = test_sem


all : $(targets)

$(targets) : $$@.C 
	$(CXX) -o $@ $@.C 

clean :
	/bin/rm -f  $(targets)
