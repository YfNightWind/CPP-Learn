# 入门

#### 1. 数组

- ##### 一维数组定义方式
  > 1. 数据类型 数组名[数组长度]
  > 2. 数据类型 数据名[数据长度] = {值1, 值2, ...}
  > 3. 数据类型 数据名[ ] = {值1, 值2, ...}
- ##### 一维数组获取数组长度以及查看数组首地址
  ```cpp
  sizeof(arr) / sizeof(arr[0])
  cout << arr << endl; or cout << &arr[0]; // 访问具体数据需要加地址符
  ```
- ##### 二维数组定义方式
  > 1.数据类型 数组名[ 行数 ][ 列数 ]
  > 2.数据类型 数组名[ 行数 ][ 列数 ] = {{数据1,数据2},{数据3,数据4}}
  > 3.数据类型 数组名[ 行数 ][ 列数 ] = { 数据1,数据2,数据3,数据4 };
  > 4.数据类型 数组名[  ][ 列数 ] = { 数据1,数据2,数据3,数据4 };

---

#### 2. 指针

***先记住一个概念，指针就是一个地址***

- ##### 定义指针
    ```cpp
    int a = 10;
    int *p; // 定义一个指针 int *p = &a也可
    p = &a; // 让指针p记录a的地址
    cout << "a的地址为" << &a; // 00AFF77C
    cout << "指针p为" << p; // 00AFF77C
    ```
- ##### 使用指针
    ```cpp
    // 可以通过解引用的方式来找到指针指向的内存
    // 指针前加 * 代表"解引用"，找到指针指向的内存中的数据
    *p = 1000;
    cout << "a为" << a; // 1000
    cout << "*p为" << *p; // 1000
    ```
  小知识：在32位系统下指针占用内存空间为4，64位为8。
- ##### 空指针和野指针
    ```cpp
    // 空指针用于给指针变量初始化
    int *p = NULL;
    // 空指针不可以进行访问
    *p = 10; // ❗️报错
    cout << *p; // ❗️报错

    // 野指针变量指向非法内存空间
    // (int *)强行将地址类型转换为指针类型
    int *p = (int *)0x1100; // 没有0x1100内存空间访问权限
    cout << *p; // ❗️报错：读取访问权限冲突
    ```
- ##### const修饰指针
    1. const修饰指针➡️常量指针
    2. const修饰常量➡️指针常量
    3. const既修饰指针，又修饰常量
    ```cpp
    int a = 10;
    int b = 10;
    int *p = &a;

    // 1.常量指针
    const int *p = &a; // 特点：指针的指向可以改，指向的值不可以改
    *p = 20; // ❌指针指向的值不可以改 
    p = &b; // 正确，指针指向可以改，可以指向其他内存地址

    // 2.指针常量
    int *const p = &a; // 特点：指针的指向不可以改，指向的值可以改
    *p = 20; // 正确，指针指向的值可以改
    p = &b; // ❌指针的指向不可以改

    // 3.const既修饰指针，又修饰常量
    const int *const p = &a; // 特点：指针的指向和指针指向的值都不可以改
    *p = 20; // ❌
    p = &b; // ❌
    ```
  🌟**小技巧：**
  const后面跟着的是p的话，说明是指针，const限定p，那么想用p操作(p = &b)的那就是错误，同理，const后面是 *p，那么const限定的是*p，故*p的操作也不允许
- ##### 指针和数组
    ```cpp
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr; // arr就是数组的首地址
    cout << *p; // 1
    p++; // 让指针向后偏移4个字节（int为4字节）
    cout << *p; // 2

    // 利用指针遍历数组
    int *p2 = arr;
    for (int i = 0; i < 5; i++) {
      cout << *p2;
      p2++;
    }
    ```
- ##### 指针和函数
  这么做实参和形参都有变化
    ```cpp
    // 里面用指针来接收
    void swap(int *a, int *b) {
      int temp = *a;
      *a = *b;
      *b = temp;
    }
    int main() {
      int a = 10;
      int b = 20;
      // 地址传递，可以改变实参
      /*
      但如果只是单纯值传递（swap(a, b)），不会改变实参
      */
      swap(&a, &b);
      return 0;
    }

    ```
  **如果不想修改实参，就用值传递，如果想修改实参，就用地址传递。**

---

#### 3. 结构体

- ##### 结构体数组
    ```cpp
    struct Student {
      string name;
      int age;
      int score;
    };

    // 创建结构体数组
    struct Student array[3] = {
      {"alex", 18, 100},
      {"peter", 28 99},
      {"bob", 30, 90}
    };

    // 可以给结构体数组中的元素赋值
    array[2].name = "Mary";
    ```
- ##### 结构体指针
  利用操作符 ```->``` 可以通过结构体指针访问结构体属性
    ```cpp
    struct Student {
      string name;
      int age;
      int score;
    };
    int main() {
      // struct关键词可以省略

      // 创建学生结构体变量
      Student s = {"alex", 18, 100};

      // 通过指针指向结构体的变量
      Student *p = &s;

      // 通过指针访问结构体变量中的数据
      cout << p->name; // alex
    }
    ```
- ##### 结构体嵌套结构体
    ```cpp
    struct Student {
      string name;
      int age;
      int score;
    };
    struct Teacher {
      string name;
      int age;
      int score;
      struct Student stu;
    };

    // 访问里面的学生
    Teacher t;
    cout << t.stu.name;
    ```
- ##### 结构体做函数参数
  传递方式有两种：
    - 值传递
    - 地址传递
    ```cpp
    struct Student {
      string name;
      int age;
      int score;
    };

    // 值传递
    void printStudent(struct Student s) {
      cout << s.name;
    }

    void printStudent1(struct Student *s) {
      cout << s->name;
    }

    int main() {
      struct Student s;
      printStudent(s);
      printStudent1(&s);
    }
    ```
  有涉及到指针，访问数据就用```->```，反之用```.```
  同时，在面对大数据的时候，使用值传递会消耗大量内存，因为该过程是对内容进行拷贝，这样每次调用都会复制一次。所以地址传递对好处就凸显出来了。
  一个指针只占4个字节，而且不会复制新的副本出来。❕但是也有坏处，直接修改了原地址对内容，本意只想"读"，却变成了"写"。所以我们要避免这个情况的
  引入```const```⬇️
- ##### const在结构体中的使用
    ```cpp
    struct Student {
      string name;
      int age;
      int score;
    };
  
    void printStudent1(const Student *s) {
      s->age = 100; // ❌ 加入const之后，一旦有修改的操作就会报错，可以防止我们误操作
      cout << s->name;
    }
    ```
  Date: 2021.11.27