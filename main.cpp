
#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
using namespace std;


int main(int argc, char *argv[]) {
  int count,maxNum;
  for (int i = 1; i < argc; i += 2) {
    string curArgv = string(argv[i]);
    if (i + 1 >= argc) {

    }
    if (curArgv == "-n") {
      count = stoi(argv[i + 1]);
    }
    else if (curArgv == "-r") {
      maxNum = stoi(argv[i + 1]);
    }
  }
  printf("count: %d, maxNum: %d", count, maxNum);
  return 0;
}
