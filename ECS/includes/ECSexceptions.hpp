/*
** Author: Sebastien Maire
** Contribs:
*/

#pragma once

#include <sstream>
#include <exception>

namespace ECS {
  class exception : public std::exception {
  private:
    std::string	message_;
    int	level_;
  public:
    exception(int level, const char *msg) :
      level_(level) {
      static std::string colors[] = {
	"\033[33m",
	"\033[35m",
	"\033[31m"
      };
      std::ostringstream oss;

      if (level > 2 || level < 0)
	level = 2;
      oss << colors[level] << "Error Level: " << level << " \033[0m" << msg;
      this->message_ = oss.str();
    }
    int getLevel(void) const {
      return level_;
    }
    virtual ~exception() throw() {
    }

    virtual const char *what(void) const throw() {
      return message_.c_str();
    }
  };
}
