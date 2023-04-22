#ifndef MATH_H
#define MATH_H

namespace TempestEngine
{
    float static clamp(float value, float min, float max)
    {
        if (value < min)
        {
            return min;
        }
        else if (value > max)
        {
            return max;
        }

        return value;
    }
}

#endif