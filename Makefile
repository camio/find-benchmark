.PHONY: all clean

CXX:= clang++ -std=c++2b
CXXFLAGS:= -O3
CPPFLAGS:= -Iexpected/include `pkg-config --cflags benchmark`

all: benchmark

%.o %.S: %.C
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^ -o $@
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -S $^ -o $@.S

clean:
	$(RM) benchmark *.o *.o.S

benchmark: benchmark.o f.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@ `pkg-config --libs --static benchmark`
