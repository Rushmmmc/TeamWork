//
// Created by Rush on 2021/10/20.
//

#include "Examination.h"

unordered_map<int, char> Examination::operatorMap_ = {
        {1, '+'},
        {2, '-'},
        {3, 'x'},
        {4, '/'}
};

vector<std::string> Examination::generate(int count, int maxNum) {
  srand((int)time(0));
  unordered_set<int> results;
  vector<std::string> res;
  for (int i = 0; i < count; i++) {
    // 生成本题目的运算符个数 最多3个
    int operatorCount = random(4);
    string curExamination;
    for (int j = 0; j < operatorCount + 1; j++) {
      curExamination += to_string(random(maxNum + 1));
      // 最后一轮不需要再加操作运算符了
      if (j != operatorCount) {
        curExamination += " ";
        curExamination += operatorMap_[random(5)];
        curExamination += " ";
      }
    }
    res.push_back(curExamination);
  }
  return res;
}