//
// Created by Alex Lin on 2022/2/24.
//
#include <iostream>

// 实现计算器的抽象类
class AbstractCalculator {
 public:
  virtual int getResult() {
    return 0;
  }
 public:
  int m_Num1;
  int m_Num2;
};

class AddCalculator : public AbstractCalculator {
 public:
  int getResult() override {
    return m_Num1 + m_Num2;
  }
};

class SubCalculator : public AbstractCalculator {
 public:
  int getResult() override {
    return m_Num1 - m_Num2;
  }
};

class MulCalculator : public AbstractCalculator {
 public:
  int getResult() override {
    return m_Num1 * m_Num2;
  }
};

void test() {
  /**
   * 多态的使用条件
   * 父类指针或者引用指向子类对象
   */
  // 加法
  AbstractCalculator *abc = new AddCalculator;
  abc->m_Num1 = 10;
  abc->m_Num2 = 20;
  std::cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << std::endl;
  // 用完销毁
  delete abc;

  // 减法运算
  abc = new SubCalculator;
  abc->m_Num1 = 30;
  abc->m_Num2 = 20;
  std::cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << std::endl;
  delete abc;

  // 乘法运算
  abc = new MulCalculator;
  abc->m_Num1 = 3;
  abc->m_Num2 = 2;
  std::cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << std::endl;
  delete abc;
}
int main() {
  test();

  return 0;
}
