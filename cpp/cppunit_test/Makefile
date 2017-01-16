CXX = g++
INCLUDES = -I./
CXXFLAGS = -g $(INCLUDES)
SRCM= ./cbasicmath.cpp
OBJM= $(SRCM:.cpp=.o)
LINKFLAGS=-lcppunit

testbasicmath: testbasicmath.cpp $(OBJM)
	$(CXX) $(CXXFLAGS) -o $@ testbasicmath.cpp $(OBJM) $(LINKFLAGS) $(LINKFLAGSLOG4) $(LIBLOG)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

