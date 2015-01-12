//
// main.cpp for  in /home/maire_s/Projects/Rush/pisicine/3
// 
// Made by sebastien maire
// Login   <maire_s@epitech.net>
// 
// Started on  Sat Jan 25 15:42:12 2014 sebastien maire
// Last update Mon Jan 12 12:19:35 2015 sebastien maire
//

#include <iostream>
#include <string>
#include <sstream>
#include <string>
#include <list>
#include <typeinfo>

// template<typename int>
// class	RawDataContainer {
// private:
//   size_t	offset_;
//   size_t	size_;
// };

class	Serializable {
protected:
  std::list<std::string>	flux;
public:
  template<typename T>
  void save(T& v) {
    std::stringstream ss;

    ss << sizeof(T);
    std::cout << "<offset=\"42\"" << " size=\"" << ss.str() << "\" value=\"" << v << "\" />" << std::endl;
    (void)v;
  }

  // template<>
  // void	save<Serializable>(Serializable& s) {
    
  // }
  template<typename T, size_t N>
  void	save(T (&tab)[N]) {
    std::stringstream ss;

    ss << sizeof(T);
    std::cout << "<type=\"array\" offset=\"42\"" << " size=\"" << ss.str() << ">" << std::endl;
    for (T& v : tab) {
      save(v);
    }
    std::cout << "<array/>" << std::endl;
  }

  template<typename T>
  void	save(T *ptr) {
    std::cout << "<type=\"pointer\">" << std::endl;
    save(*ptr);
    std::cout << "<pointer/>" << std::endl;;
  }
  template<typename T, typename... Args>
  void	save(T& v, Args&... args) {
    save(v);
    (void)v;
    save(args...);
  }
  void Serialize() {
  }
  void Deserialize(const std::string& src) {
    (void)src;
  }
};

class house : public Serializable {
public:
  int	width;
  int	height;
  house() :
    width(420), height(666) {
    save(width, height);
  }
};

class	toto : public Serializable {
  int	var_;
  char	*name;
  std::string name_;
  char	tab[5];
  
public:
  toto(int v, char *n) :
    var_(v), name(n), name_("z0rg"), tab({'U', 'E', 'S', 'H', '\0'}) {

    save(var_, name, name_, tab);
  }
};

int main() {
  char str[] = "salut";
  toto a(5, str);

  a.Serialize();
  a.Deserialize("toto.csv");
  return 0;
}
