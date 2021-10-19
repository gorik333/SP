
CXX = g++
CXXFLAGS = -g -Wall -Wextra


BIN 	 = UserInterface
OBJ		 = UserInterface.o
HEADERS	 = Policy.h Database.h
SLIB	 = Database.a
SLIB_OBJ = Database.o Policy.o



all: $(BIN)


$(BIN): $(BIN).o $(SLIB)
	$(CXX) $(CXXFLAGS) $(BIN).o -o $(BIN) -L. -l:Database.a


$(OBJ): UserInterface.cpp
	$(CXX) $(CXXFLAGS) -c $<


Database.a: $(SLIB_OBJ)
	$(AR) $(ARFLAGS) $@ $^


Database.o: Database.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<


Policy.o: Policy.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<


clean:
	rm -rf $(BIN) $(OBJ) $(SLIB) $(SLIB_OBJ)
