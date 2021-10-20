
#include "Examination.h"
#include "Calculator.h"
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
  vector<std::string> examinations = Examination::generate(count, maxNum);
  int index = 1;
  for (string& e : examinations) {
    string res = Calculator::caculate(e);
    e += " = ";
    e += res;
    cout << index++ << ": " << e << endl;
  }

  // cout << Calculator::caculate("1/5 + 1/25 + 1 + 2 + 3 + 4");
  return 0;
}
