#include "Mapping.hpp"

int Mapping::get(int in, bool inverse)
{
    return inverse ? mapping[in] : inverseMapping[in];
}

