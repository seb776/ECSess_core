/*
 * rtype, messages.cpp
 * Loic Lefloch
 */

#include <iostream>
#include <exception>
#include "Messages.hpp"

Msg::Msg() {}

Msg::~Msg() {}

Msg::Msg(Msg const&) {}

Msg const& Msg::operator=(Msg const&) {
  return *this;
}

void  Msg::Debug(std::string const& str) {
#ifdef DEBUG_MODE
  std::cout << "\033[0;32m" << str << "\033[0m" << std::endl;
#endif
}

void  Msg::Critical(std::string const& str) {
  std::cerr << "\033[1;31mCritical error: \033[0m" << str << std::endl;
}

void  Msg::Warning(std::string const& str) {
  std::cerr << "\033[4;33mWarning:\033[0m " << str << std::endl;
}

void  Msg::Message(std::string const& str) {
  std::cout << "\033[4;34mstr:\033[0m " << str << std::endl;
}

void  Msg::Info(std::string const& str) {
  std::cout << "\033[4;32mInfo:\033[0m " << str << std::endl;
}

void  Msg::Error(std::string const& str) {
  std::cerr << "\033[1;31mError: \033[0m" << str << std::endl;
}
