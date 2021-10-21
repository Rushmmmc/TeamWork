
#include <fstream>
#include "Examination.h"
#include "Calculator.h"
using namespace std;

void output(vector<string>& examinations, const vector<string>& results) {
  remove("./Exercises.txt");
  ofstream examination("./Exercises.txt",ios::app);

  if(!examination){
    cout << "Unable to open otfile";
    exit(1);
  }
  int index = 0;
  // 输出题目
  for (string& e : examinations) {
    e += " = ";
    examination << ++index << "." << e << endl;
  }
  examination.close();

  index = 0;
  // 输出答案
  remove("./Answers.txt");
  ofstream res("./Answers.txt",ios::app);
  if(!res){
    cout << "Unable to open otfile";
    exit(1);
  }
  for (const auto& r : results) {
    res << ++index << "." << r << endl;
  }
  res.close();
}

int main(int argc, char *argv[]) {
  int count = 0,maxNum = 0;
  string exerciseFile = "", answerFile = "";
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
    else if (curArgv == "-e") {
      exerciseFile = argv[i + 1];
    }
    else if (curArgv == "-a") {
      answerFile = argv[i + 1];
    }
  }
  if (argc != 5) {
    cout << "请在运行本文件时输入正确的参数" << endl;
    cout << "示例：" << endl;
    cout << "  模式一：-n 10000 -r 100" << endl;
    cout << "  模式二：-e exerciseFile.txt -a answerFile.txt" << endl;
    return 0;
  }
  // 模式一
  if (count != 0 && maxNum != 0) {
    vector<string> results;
    vector<std::string> examinations = Examination::generate(count, maxNum, results);
    output(examinations, results);
  }
  else if (!exerciseFile.empty() && !answerFile.empty()) {
    fstream exe(exerciseFile), an(answerFile);
    if (!exe || !an) {
      cout << "文件不存在！";
    }
    else {
      remove("./Grade.txt");
      ofstream res("./Grade.txt",ios::app);
      string string1,string2;
      int index = 1;
      string correct, wrong;
      int correctCount = 0, wrongCount = 0;
      while (getline(exe,string1) && getline(an, string2)) {
        // 去掉序号
        string1 =  string1.substr(string1.find('.') + 1);
        string res = Calculator::calculate(string1);

        string2 =  string2.substr(string2.find('.') + 1);
        // 答对了
        if (res == string2) {
          ++correctCount;
          correct += to_string(index) + "，";
        }
        else {
          ++wrongCount;
          wrong += to_string(index) + "，";
        }
        index++;
        // printf("string1: %s, string2: %s\n", res.c_str(), string2.c_str());
      }
      // -3是去掉最后的逗号
      correct = "Correct:"+ to_string(correctCount) + "(" + correct.substr(0, correct.size() - 3) + ")";
      wrong = "Wrong:"+ to_string(wrongCount) + "(" + wrong.substr(0, wrong.size() - 3) + ")";
      res << correct << endl;
      res << wrong << endl;
    }
  }
  return 0;
}
