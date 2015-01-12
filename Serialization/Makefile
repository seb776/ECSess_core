##
## Makefile for  in /home/maire_s/Projects/Rush/pisicine/3
## 
## Made by sebastien maire
## Login   <maire_s@epitech.net>
## 
## Started on  Sat Jan 25 17:13:51 2014 sebastien maire
## Last update Mon Jan 12 11:18:10 2015 sebastien maire
##

NAME=	test

SRC=	main.cpp

OBJ=	$(SRC:.cpp=.o)

CXXFLAGS=	-Wall -W -Wextra -std=c++11 ##-Werror

LDFLAGS=

CXX=	g++

RM=	rm -vf

all:	$(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
