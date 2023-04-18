#ifndef TRIGO_FUNCTIONS_H
#define TRIGO_FUNCTIONS_H

#include "Math_defines.h"

namespace TempestEngine
{
    /**
     * @brief Converts degrees into radians
     *
     * @param degrees
     * @return float
     */
    float radians(const float &degrees)
    {
        return degrees * (Math_PI / 180);
    }
}

#endif