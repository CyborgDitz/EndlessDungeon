// hashing.h
#ifndef HASHING_H
#define HASHING_H

#include <functional>

struct CellKey {
    int x;
    int y;
    bool operator==(const CellKey &other) const {
        return x == other.x && y == other.y;
    }
};

struct CellKeyHasher {
    std::size_t operator()(const CellKey &key) const {
        return std::hash<int>()(key.x) ^ (std::hash<int>()(key.y) << 1);
    }
};

#endif  // HASHING_H
