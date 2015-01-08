/*
** Author: Sebastien Maire
** Contribs:
*/

#pragma	once

#ifdef	RTYPE_CLIENT
# include <SFML/Graphics.hpp>
namespace Tools {
  template<typename T>
  class	Rect : public sf::Rect<T> {
  };
  // typedef sf::FloatRect<float> Rect;
}
#elif defined	RTYPE_SERVER
# include "rtypeRect.hpp"
namespace Tools {
  template<typename T>
  class	Rect : public RtypeRect<T> {
  };
  // typedef Tools::RtypeRect<float> Rect;
}
#else
# error	"You must define RTYPE_CLIENT or RTYPE_SERVER"
#endif
