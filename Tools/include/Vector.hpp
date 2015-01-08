/*
** Author: Sebastien Maire
** Contribs:
*/

#pragma	once

#ifdef	RTYPE_CLIENT
	# include <SFML/Graphics.hpp>
	namespace Tools {
	  template<typename T>
	  class	Vector2 : public sf::Vector2<T> {
	  	public:
	  		Vector2() : sf::Vector2<T>(0, 0)
	  		{}

		  	Vector2(T x, T y) : sf::Vector2<T>(x, y)
		  	{}
	  };
	  // typedef sf::Vector<float> Vector;
	}
#elif defined	RTYPE_SERVER
	# include "rtypeVector.hpp"
	namespace Tools {
	  template<typename T>
	  class	Vector2 : public RtypeVector2<T> {
	  	public:
	  		Vector2() : RtypeVector2<T>(0, 0)
	  		{}
	  		
		  	Vector2(T x, T y) : RtypeVector2<T>(x, y)
		  	{}
	  };
	// typedef Tools::RtypeVector2<float> Vector;
	}
#else
	# error	"You must define RTYPE_CLIENT or RTYPE_SERVER"
#endif
