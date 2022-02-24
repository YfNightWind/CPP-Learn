//
// Created by Alex Lin on 2022/2/16.
//
#include <iostream>

class Person {
 public:
  Person() {
    std::cout << "Person默认构造函数调用" << std::endl;
  }

  Person(int age, int height) {
    m_Age = age;
    m_Height = new int(height); // new就是在堆区申请空间
    std::cout << "Person默认有参构造函数调用" << std::endl;
  }

  /**
   * 我们需要自己实现一个拷贝构造函数
   * 因为在析构函数中释放m_Height的时候，出现了重复释放同一块内存区域的错误，因为析构函数调用是先进后出
   * ❕问题在这：我们在p2中利用了编辑器提供的浅拷贝对p1的m_Height进行了浅拷贝
   * ❕但是因为是浅拷贝，所以只是单纯的复制了内存地址，所以导致了p2和p1的m_Height都是指向同一块内存区域
   * ❕然而释放的时候，p2先释放了该内存区域，p1释放的时候发现是空的，没法释放，所以就出现了错误。
   * 所以我们需要重新写一个深拷贝，也就是重新开一块内存区域来存储拷贝过来的这个数据，这样子就不会都指向同一块内存区域了。
   */
  Person(const Person &p) {
    std::cout << "Person拷贝构造函数调用" << std::endl;
    m_Age = p.m_Age;
    // m_Height = p.m_Height; 编译器默认实现是这行代码
    // 深拷贝操作
    m_Height = new int(*p.m_Height);
  }
  ~Person() {
    // 堆区开辟堆数据，需要程序员手动分配和手动释放
    // 当然也可以直接delete m_Height
    if (m_Height != nullptr) {
      delete m_Height;
      m_Height = nullptr;
    }
    std::cout << "Person的析构函数调用" << std::endl;
  }

  int m_Age;
  int *m_Height; // 用指针是可以讲数据创建在堆区
};

void test01() {
  Person p1(18, 160);
  std::cout << "p1年龄为: " << p1.m_Age << "身高为: " << *p1.m_Height << std::endl;
  Person p2(p1); // 编辑器做的简单的浅拷贝，也就是简单的赋值操作
  std::cout << "p2年龄为: " << p2.m_Age << "身高为: " << *p2.m_Height << std::endl;

}

int main() {
  test01();
  return 0;
}
