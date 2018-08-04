//
//  Util.cpp
//  LimeysSDR
//
//  Created by Paul Ciarlo on 8/3/18.
//  Copyright © 2018 Paul Ciarlo. All rights reserved.
//

template <typename T>
std::ostream &operator<<(std::ostream &lhs, const std::vector<T> &rhs)
{
    int i = 0, sz = rhs.size();
    if (sz == 0) {
        lhs << "[]";
    } else if (sz == 1) {
        lhs << '[' << rhs[0] << ']';
    } else {
        lhs << '[';
        while (i < sz - 1) {
            lhs << rhs[i++] << ", ";
        }
        lhs << rhs[i] << ']';
    }
    return lhs;
}

template <typename K, typename V>
std::ostream &operator<<(std::ostream &lhs, const std::map<K,V> &rhs)
{
    if (rhs.size() == 0) {
        lhs << "{}";
    } else if (rhs.size() == 1) {
        auto it = rhs.begin();
        lhs << '{' <<
            it->first << ": " << it->second
        << '}';
    } else {
        auto it = rhs.begin();
        lhs << '{';
        while (it != rhs.end()) {
            lhs << it->first << ": " << it->second << ", ";
            ++it;
            if (it != rhs.end()) {
                lhs << ", ";
            } else {
                lhs << '}';
            }
        }
    }
    return lhs;
}
