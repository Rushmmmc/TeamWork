//
// Created by Rush on 2021/10/20.
//

#include "Calculator.h"

 string Calculator::calculate(string text) {
  // 上一运算符 默认为+
  char mark = '+';
  const vector<string>& texts = substring(text, ' ');
  stack<string> numStack;
  // curFraction用于连除的情况
  string fraction;
  string num;
  string result;
  for (int i = 0; i < texts.size(); i++) {
    string cur = texts[i];
    if(stringIsNum(cur)) {
      num = cur + "/1";
    }
    // 如果是分数
    else if (cur.size() >= 3){
      num = cur;
    }
    // 如果是运算符或者到达末尾
    if ((cur.size() == 1 && !stringIsNum(cur)) || i == texts.size() - 1) {
      switch (mark) {
        case '+': {
          numStack.push(num);
          break;
        }
        case '-': {
          numStack.push("-" + num);
          break;
        }
        case 'x': {
            multiplyFraction(num, numStack.top());
            numStack.pop();
            numStack.push(num);
          break;
        }
        case '/': {
          string temp = numStack.top();
          divideFraction(temp, num);
          numStack.pop();
          numStack.push(temp);
          break;
        }
        default: break;
      }
      mark = cur[0];
    }
  }
  // cout << "````````````````````````" << endl;
  // 整理数据栈
  while (!numStack.empty()) {
    // cout << numStack.top() << endl;
    addFraction(result, numStack.top());
    numStack.pop();
  }
  // cout << "````````````````````````" << endl;
  // 返回的是计算的结果和计算的分数两部分
  // if (fraction.empty() && result == 0)
  //     return to_string(result);
  // else if (result == 0)
  //     return fraction;
  // return fraction.empty() ? to_string(result) : to_string(result) + "'" + fraction;
  // cout << "-------------------------------------------:" << result << endl;

  simplyFraction(result);
  return result;
}