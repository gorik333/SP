
CXX = g++
CXXFLAGS = -g -Wall -Wextra


OBJECTS = policyTest.o Policy.o
HEADERS = Policy.h
TEST    = policyTest


all: $(TEST)

$(TEST): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TEST)

policyTest.o: policyTest.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

Policy.o: Policy.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf $(OBJECTS) $(TEST)