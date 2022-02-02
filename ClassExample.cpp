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
  }

  // 带参数的构造函数
  Entity(float x, float y) {
    X = x;
    Y = y;
  }
  void Print() {
    std::cout << X << ", " << Y << std::endl;
  }
};

int main() {
  Log log;
  log.SetLevel(Log::LevelError);
  log.Warn("Shit");
  log.Error("shit");
  log.Info("shit");
  Entity entity(1.00, 2.00);
  entity.Print();
  return 0;
}