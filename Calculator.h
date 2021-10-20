//
// Created by Rush on 2021/10/20.
//

#ifndef TEAMWORK_CALCULATOR_H
#define TEAMWORK_CALCULATOR_H

#include <string>
#include <unordered_map>
#include <stack>
#include <vector>
#include <ctype.h>
#include <iostream>

using namespace std;

class Calculator {
 public:
  static string caculate(string text);
 private:
  static string simpleFraction(const string& fraction) {
    vector<string> temp1 = substring(fraction, '/');
    int m = stoi(temp1[0]), n = stoi(temp1[1]);
    int gcd = getGcd(m, n);

    return n / gcd == 1 ? to_string(m / gcd) : to_string(m / gcd) + "/" + to_string(n / gcd);
  }

  static int getGcd(int a,int b) {
    if (a < b)
      return gcd(b, a);

    if(a % b == 0)
      return b;
    else;
    return gcd(b,a % b);
  }

  static string updateFraction(string fraction, string cur) {
    if (!fraction.empty()) {
      // 更新分数
      fraction = caculateFraction(fraction, cur);
    }
    else {
      fraction = cur;
    }
    return fraction;
  }
  static string caculateFraction(string fraction1, string fraction2) {
    vector<string> temp1 = substring(fraction1, '/');
    vector<string> temp2 = substring(fraction2, '/');
    // 分子
    int molecule1 = stoi(temp1[0]),molecule2 = stoi(temp2[0]);
    // 分母
    int denominator1 = stoi(temp1[1]), denominator2 = stoi(temp2[1]);
    // 获得最小公倍数
    int multiple = getLeastCommonMultiple(denominator1, denominator2);
    int res = molecule1 * (multiple / denominator1) + molecule2 * (multiple / denominator2);
    return to_string(res) + "/" + to_string(multiple);
  }

  static int getLeastCommonMultiple(int num1, int num2) {
    int cur1 = num1, cur2 = num2;
    int lol, res;
    while ((cur1 %= cur2) && (cur2 %= cur1));
    res = num1 * num2 / (cur1 + cur2);
    return res;
  }

  static vector<string> substring(const string& text, char separator) {
    vector<string> res;
    string cur;
    for(int i = 0; i < text.size(); i++) {
      char ch = text[i];
      if (ch != separator) {
        cur += ch;
        if (i == text.size() - 1)
          res.push_back(cur);
      }
      else {
        res.push_back(cur);
        cur = "";
      }
    }
    return res;
  }

  static bool stringIsNum(string text) {
    for (char c : text)
      if (!isdigit(c))
        return false;
    return true;
  }

  static unordered_map<int, string> operatorMap_;
};


#endif //TEAMWORK_CALCULATOR_H
