// 通讯录管理系统
// Created by Alex Lin on 2021/11/27.
//

#include <iostream>
#include <cstdlib>

using namespace std;

const int MAX = 1000;

// 联系人结构体
struct Person {
  string m_name;
  int m_sex{};
  int m_age{};
  string m_phone;
  string m_address;
};

// 通讯录结构体
struct AddressBooks {
  Person person_array[MAX]; // 通讯录中保存联系人的数组
  int m_size{}; // 通讯录中当前联系人个数
};

// 判断是否存在，存在返回联系人所在数组具体位置，不存在返回-1
int isExist(AddressBooks *abs, const string *name) {
  for (int i = 0; i < abs->m_size; i++) {
    if (abs->person_array[i].m_name == *name) {
      return i;
    }
  }
  return -1;
}
// 添加联系人
void addPerson(AddressBooks *abs) {
  if (abs->m_size == MAX) {
    cout << "通讯录已满，无法添加！";
    return;
  } else {
    // 添加具体联系人
    // name
    string name;
    cout << "请输入姓名：" << endl;
    cin >> name;
    abs->person_array[abs->m_size].m_name = name;

    // sex
    int sex = 0;
    while (true) {
      cout << "请输入性别：1--男 2--女" << endl;
      cin >> sex;
      if (sex == 1 || sex == 2) {
        abs->person_array[abs->m_size].m_sex = sex;
        break;
      } else {
        cout << "输入有误，请重试！" << endl;
      }
    }

    // age
    int age = 0;
    cout << "请输入年龄：" << endl;
    cin >> age;
    abs->person_array[abs->m_size].m_age = age;

    // phone
    string phone;
    cout << "请输入电话：" << endl;
    cin >> phone;
    abs->person_array[abs->m_size].m_phone = phone;

    // address
    string address;
    cout << "请输入地址：" << endl;
    cin >> address;
    abs->person_array[abs->m_size].m_address = address;

    // update
    abs->m_size++;
    cout << "更新成功！" << endl;

    system("read"); // 按任意键继续 windows下为pause
    system("clear"); // 清空屏幕 windows下为cls
  }
}

// 显示所有联系人
void showPerson(AddressBooks *abs) {
  if (abs->m_size == 0) {
    cout << "当前记录为空" << endl;
  } else {
    for (int i = 0; i < abs->m_size; i++) {
      cout << "姓名：" << abs->person_array[i].m_name << "\t";
      cout << "性别：" << (abs->person_array[i].m_sex == 1 ? "男" : "女") << "\t";
      cout << "年龄：" << abs->person_array[i].m_age << "\t";
      cout << "电话：" << abs->person_array[i].m_phone << "\t";
      cout << "地址：" << abs->person_array[i].m_address << endl;
    }
  }

  system("read");
  system("clear");
}

// 删除指定联系人
void deletePerson(AddressBooks *abs) {
  cout << "请输入要删除的联系人：" << endl;
  string name;
  cin >> name;
  int result = isExist(abs, &name);
  if (result != -1) {
    // 查找成功，进行删除操作
    for (int i = result; i < abs->m_size; i++) {
      // 数据前移，查找到的下标被后面的覆盖，实现删除
      abs->person_array[i] = abs->person_array[i + 1];
    }
    abs->m_size--; // 更新人数
    cout << "删除成功！" << endl;

  } else {
    cout << "查无此人！" << endl;
  }

  system("read");
  system("clear");
}

// 查找联系人信息
void findPerson(AddressBooks *abs) {
  cout << "输入要查找的联系人：" << endl;
  string name;
  cin >> name;

  int result = isExist(abs, &name);
  if (result != -1) {
    cout << "姓名：" << abs->person_array[result].m_name << "\t";
    cout << "性别：" << (abs->person_array[result].m_sex == 1 ? "男" : "女") << "\t";
    cout << "年龄：" << abs->person_array[result].m_age << "\t";
    cout << "电话：" << abs->person_array[result].m_phone << "\t";
    cout << "地址：" << abs->person_array[result].m_address << endl;
  } else {
    cout << "查无此人" << endl;
  }

  system("read");
  system("clear");
}

// 修改联系人
void modifyPerson(AddressBooks *abs) {
  cout << "输入要修改的联系人姓名：" << endl;
  string origin_name;
  cin >> origin_name;

  int result = isExist(abs, &origin_name);
  if (result != -1) {
    // name
    string name;
    cout << "输入姓名：" << endl;
    cin >> name;
    abs->person_array[result].m_name = name;

    // sex
    int sex = 0;
    cout << "请输入性别：1--男 2--女" << endl;
    while (true) {
      cin >> sex;
      if (sex == 1 || sex == 2) {
        abs->person_array[abs->m_size].m_sex = sex;
        break;
      } else {
        cout << "输入有误，请重试！" << endl;
      }
    }

    // age
    cout << "请输入年龄：" << endl;
    int age = 0;
    cin >> age;
    abs->person_array[result].m_age = age;

    // phone
    cout << "请输入手机号码：" << endl;
    string phone;
    cin >> phone;
    abs->person_array[result].m_phone = phone;

    // address
    cout << "请输入家庭住址：" << endl;
    string address;
    cin >> address;
    abs->person_array[result].m_address = address;

    cout << "修改成功！" << endl;
  } else {
    cout << "查无此人！" << endl;
  }

  system("read");
  system("clear");
}

void clearPerson(AddressBooks *abs) {
  abs->m_size = 0;
  cout << "通讯录已清空！" << endl;

  system("read");
  system("clear");
}
// 菜单界面
void showMenu() {
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

  // 创建通讯录结构体变量
  AddressBooks abs;

  //初始化通讯录当前人员个数
  abs.m_size = 0;

  while (true) {
    showMenu();

    cin >> select;
    switch (select) {
      case 1:addPerson(&abs); // 利用地址传递可以修饰实参数
        break;
      case 2:showPerson(&abs);
        break;
      case 3: deletePerson(&abs);
        break;
      case 4: findPerson(&abs);
        break;
      case 5: modifyPerson(&abs);
        break;
      case 6: clearPerson(&abs);
        break;
      case 0:cout << "欢迎下次使用" << endl;
        return 0;
      default:break;
    }
  }
}
