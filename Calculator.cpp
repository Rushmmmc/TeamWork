//
// Created by Rush on 2021/10/20.
//

#include "Calculator.h"

 string Calculator::caculate(string text) {
  // 上一运算符 默认为+
  string mark = "+";
  const vector<string>& texts = substring(text, ' ');
  stack<int> numStack;
  string fraction;
  int num = 0;
  int result = 0;
  for (int i = 0; i < texts.size(); i++) {
    string cur = texts[i];
    if(stringIsNum(cur)) {
      num = stoi(cur);
      // 特殊情况：末尾
      // if (i == texts.size() - 1) {
      //   if (mark == "-")
      //     numStack.push(-num);
      //   else
      //     numStack.push(num);
      // }
    }
    else if (cur.size() >= 3) {
      num = 0;
    }
    // // 如果是分数
    // else if (cur.size() >= 3){
    //   // 如果前面已经有分数待和这个运算
    //   fraction = updateFraction(fraction, cur);
    // }
    // 如果是运算符
    if ((cur.size() == 1 && !stringIsNum(cur)) || i == texts.size() - 1){
      if (mark == "+") {
        numStack.push(num);
      }
      else if (mark == "-") {
        numStack.push(-num);
      }
      else if (mark == "x") {
        int temp = numStack.top();
        numStack.pop();
        numStack.push(temp * num);
      }
      else if (mark == "/") {
        cur = to_string(numStack.top()) + "/" + to_string(num);
        fraction = updateFraction(fraction, cur);
        num = 0;
        numStack.pop();
        // int temp = numStack.top();
        // numStack.pop();
        // numStack.push(temp / num);
      }
      mark = cur;
    }
  }

  //整理数据栈
  while (!numStack.empty()) {
    result += numStack.top();
    numStack.pop();
  }
  // 返回的是计算的结果和计算的分数两部分
  if (fraction.empty() && result == 0)
      return to_string(result);
  else if (result == 0)
      return fraction;
  return fraction.empty() ? to_string(result) : to_string(result) + "'" + fraction;
}