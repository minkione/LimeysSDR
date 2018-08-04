//
//  Util.hpp
//  LimeysSDR
//
//  Created by Paul Ciarlo on 8/3/18.
//  Copyright © 2018 Paul Ciarlo. All rights reserved.
//

#ifndef Util_hpp
#define Util_hpp

#include <SoapySDR/Types.hpp>

#include <iostream>
#include <vector>
#include <map>

template <typename T>
std::ostream &operator<<(std::ostream &lhs, const std::vector<T> &rhs);

template <typename K, typename V>
std::ostream &operator<<(std::ostream &lhs, const std::map<K,V> &rhs);

#include "Util.cpp"

#endif /* Util_hpp */
