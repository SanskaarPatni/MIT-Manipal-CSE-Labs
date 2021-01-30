CXX = CC

targets = test_msgsnd  test_msgrcv test_msgctl \
          server client


all : $(targets)

$(targets) : $$@.C 
	$(CXX) -o $@ $@.C 

clean :
	/bin/rm -f  $(targets)
