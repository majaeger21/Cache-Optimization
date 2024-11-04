# Edit this line to change the optimization level
CXXFLAGS = -g -Wall -O2
CXX = g++
CXXSRCS = matmul.cpp matmul-driver.cpp 
COL_CXXSRCS = matmul-column-maj.cpp matmul-driver.cpp 
UNROLL_CXXSRCS = matmul-unrolled.cpp matmul-driver.cpp 
COL_UNROLL_CXXSRCS = matmul-col-unrolled.cpp matmul-driver.cpp 
BIN = mm mm-col mm-unrolled mm-col-unrolled

all: $(BIN)

mm: $(patsubst %.cpp,%.o,$(CXXSRCS))
	$(CXX) $(CXXFLAGS) -o $@ $^

mm-col: $(patsubst %.cpp,%.o,$(COL_CXXSRCS))
	$(CXX) $(CXXFLAGS) -o $@ $^

mm-unrolled: $(patsubst %.cpp,%.o,$(UNROLL_CXXSRCS))
	$(CXX) $(CXXFLAGS) -o $@ $^

mm-col-unrolled: $(patsubst %.cpp,%.o,$(COL_UNROLL_CXXSRCS))
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<


clean:
	rm -f *.o $(BIN)
