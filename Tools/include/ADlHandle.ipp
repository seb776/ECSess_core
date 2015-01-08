/*
** Author: Yessin Abd-el rahman
** Contribs: Sebastien Maire
*/

#pragma once

template<typename T>
template<typename U>
U	ADlHandle<T>::getSym(std::string const& symName) {
  return reinterpret_cast<U>(loadSym(symName));
}

