//
// Created by Alex Lin on 2022/1/27.
//
#include <iostream>

class Log {
 public:
  const int ErrorLevel = 0;
  const int WarnLevel = 1;
  const int InfoLevel = 2;

 private:
  int m_LogLevel = InfoLevel;

 public:
  void SetLevel(int Level) {
    m_LogLevel = Level;
  }
  void Warn(const char *message) {
    if (m_LogLevel >= WarnLevel)
      std::cout << "[Warn]" << message << std::endl;
  }
  void Error(const char *message) {
    if (m_LogLevel >= ErrorLevel)
      std::cout << "[Error]" << message << std::endl;
  }
  void Info(const char *message) {
    if (m_LogLevel >= InfoLevel)
      std::cout << "[Info]" << message << std::endl;
  }
};

int main() {
  Log log;
  log.SetLevel(log.InfoLevel);
  log.Warn("Shit");
  return 0;
}