#include "input_handler.h"

namespace TempestEngine
{
    namespace Input
    {
        class teKey
        {
        public:
            teKey(void)
            {
                down = false;
                repeats = 0
            }
            bool down;
            int repeats;
        }

    }
}