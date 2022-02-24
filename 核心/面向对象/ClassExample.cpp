//
// Created by Alex Lin on 2022/1/27.
//
#include <iostream>

class Log {
 public:
  enum Level {
    LevelError = 0, LevelWarning, LevelInfo
  };

 private:
  Level m_LogLevel = LevelInfo;

 public:
  void SetLevel(Level Level) {
    m_LogLevel = Level;
  }
  void Warn(const char *message) {
    if (m_LogLevel >= LevelWarning)
      std::cout << "[Warning]" << message << std::endl;
  }
  void Error(const char *message) {
    if (m_LogLevel >= LevelError)
      std::cout << "[Error]" << message << std::endl;
  }
  void Info(const char *message) {
    if (m_LogLevel >= LevelInfo)
      std::cout << "[Info]" << message << std::endl;
  }
};

class Entity {
 public:
  float X, Y;
  // 构造函数，名字和类名一样，在实例化对象的时候运行
  // 在C++中，必须要手动设置构造函数的值，虽然默认有构造函数，但是相当于一个空函数
  // 并且，不像Java，int，float之类的默认值为0，C++默认为之前内存里的值
  Entity() {
    X = 0.0f;
    Y = 0.0f;
    std::cout << "Created Entity" << std::endl;
  }

  /*带参数的构造函数

  Entity(float x, float y) {
    X = x;
    Y = y;
  }

   */

  // 析构函数
  // 也就是一个在对象销毁时会被调用的特殊的函数和方法
  // 可以手动调用：例如这里我在main函数里实例化里一个叫做entity，即entity.~Entity();
  ~Entity() {
    std::cout << "Destroyed Entity!" << std::endl;
  }

  void Print() {
    std::cout << X << ", " << Y << std::endl;
  }
};

class Father {
 public:
  float x, y;

  void Move(float xa, float ya) {
    x += xa;
    y += ya;
  }

};

// 可以访问父类非private的内容，实例化之后变可以访问自己和父类的变量和方法
class Son : public Father {
 public:
  const char *name;

  void PrintName() {
    std::cout << name << std::endl;
  }
};

int main() {
  Log log;
  log.SetLevel(Log::LevelError);
  log.Warn("Shit");
  log.Error("shit");
  log.Info("shit");
//  Entity entity(1.00, 2.00); 有参数构造时候可以这么实例化
  Entity entity;
  entity.Print();
  return 0;
}