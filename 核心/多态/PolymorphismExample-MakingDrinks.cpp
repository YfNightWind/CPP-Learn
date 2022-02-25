//
// Created by Alex Lin on 2022/2/25.
//
#include <iostream>
using namespace std;

class AbstractDrinking {
 public:
  // 烧水
  virtual void Boil() = 0;
  // 冲泡
  virtual void Brew() = 0;
  // 倒入杯中
  virtual void PourInCup() = 0;
  // 加入辅料
  virtual void PutSomething() = 0;
  // 制定流程
  void MakeDrink() {
    Boil();
    Brew();
    PourInCup();
    PutSomething();
  }
};

class Coffee : public AbstractDrinking {
  //烧水
  void Boil() override {
    cout << "煮农夫山泉!" << endl;
  }
  //冲泡
  void Brew() override {
    cout << "冲泡咖啡!" << endl;
  }
  //倒入杯中
  void PourInCup() override {
    cout << "将咖啡倒入杯中!" << endl;
  }
  //加入辅料
  void PutSomething() override {
    cout << "加入牛奶!" << endl;
  }
};

void DoWork(AbstractDrinking * abd) {
  abd->MakeDrink();
}

int main() {
  DoWork(new Coffee);
  return 0;
}