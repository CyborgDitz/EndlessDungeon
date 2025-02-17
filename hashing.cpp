
#include "hashing.h"

bool CellKey::operator==(const CellKey& other) const {
    return x == other.x && y == other.y;
}

// Implement the custom hash function for CellKey.
std::size_t CellKeyHasher::operator()(const CellKey &key) const {
    return std::hash<int>()(key.x) ^ (std::hash<int>()(key.y) << 1);
}
