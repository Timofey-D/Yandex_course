#include <iostream>

struct Incognizable{
	int num_1 = 0;
	int num_2 = 0;
};

int main(int argc, const char * argv[]) {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}
