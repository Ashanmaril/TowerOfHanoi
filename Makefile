COMPILER = g++
DRIVER = main
FILE1 = hanoi

$(DRIVER): $(DRIVER).o $(FILE1).o
	$(COMPILER) -o $(DRIVER) $(DRIVER).o $(FILE1).o

$(DRIVER).o: $(DRIVER).cpp $(FILE1).cpp $(FILE1).h
	$(COMPILER) -c $(DRIVER).cpp

$(FILE1).o: $(FILE1).cpp $(FILE1).h
	$(COMPILER) -c $(FILE1).cpp $(FILE1).h

clean:
	rm *.o
