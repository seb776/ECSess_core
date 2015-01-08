/*
 * rtype, messages.hpp
 * Loic Lefloch
 */

#pragma once

#include <string>

class Msg
{
  private:
    Msg();
    ~Msg();
    Msg(Msg const&);
    Msg const& operator=(Msg const&);

  public:
    static void Debug(std::string const&);
    static void Critical(std::string const&);
    static void Warning(std::string const&);
    static void Message(std::string const&);
    static void Info(std::string const&);
    static void Error(std::string const&);
};
