// 通讯录管理系统
// Created by Alex Lin on 2021/11/27.
//

#include <iostream>

using namespace std;

const int MAX = 1000;

// 联系人结构体
struct Person {
  string m_name;
  int m_sex;
  int m_age;
  string m_phone;
  string m_address;
};

// 通讯录结构体
struct AddressBooks {
  Person person_array[MAX]; // 通讯录中保存联系人的数组
  int m_size; // 通讯录中当前联系人个数
};

// 菜单界面
void ShowMenu() {
  cout << "**************************" << endl;
  cout << "*****  1. 添加联系人  *****" << endl;
  cout << "*****  2. 显示联系人  *****" << endl;
  cout << "*****  3. 删除联系人  *****" << endl;
  cout << "*****  4. 查找联系人  *****" << endl;
  cout << "*****  5. 修改联系人  *****" << endl;
  cout << "*****  6. 清空联系人  *****" << endl;
  cout << "*****  0. 退出通讯录  *****" << endl;
  cout << "**************************" << endl;
}

int main() {
  int select = 0;

  AddressBooks abs;

  while (true) {

    ShowMenu();
    cin >> select;

    switch (select) {
      case 1: // 1
        break;
      case 2: // 2
        break;
      case 3: // 3
        break;
      case 4: // 4
        break;
      case 5: // 5
        break;
      case 6: // 2
        break;
      case 0:cout << "欢迎下次使用" << endl;
        return 0;
      default:break;
    }
  }
}
