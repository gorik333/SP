
CXX 	 = g++
CXXFLAGS = -g -fPIC -Wall -Wextra
LDFLAGS  = -shared
RM 		 = rm -rf


BIN 	 = UserInterface
OBJ		 = UserInterface.o
HEADERS	 = Policy.h Database.h
DLIB	 = Database.so
DLIB_OBJ = Database.o Policy.o



all: $(BIN)


$(BIN): $(BIN).o $(DLIB)
	$(CXX) $(CXXFLAGS) $(BIN).o -o $(BIN) -L. -l:Database.a -Wl,--rpath -Wl,.


$(OBJ): UserInterface.cpp
	$(CXX) $(CXXFLAGS) -c $<


Database.so: $(DLIB_OBJ)
	$(CXX) $(LDFLAGS) -o $(DLIB) $(DLIB_OBJ)


Database.o: Database.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<


Policy.o: Policy.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<


clean:
	$(RM) $(BIN) $(OBJ) $(DLIB) $(DLIB_OBJ)
