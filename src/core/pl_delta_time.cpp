/*
** POLARA PROJECT, 2025
** src/core/pl_delta_time
** File description:
** Polara delta time manager
*/

#include "polara.hpp"

/**
 * @brief Get the delta time of the program.
 *
 * @return The delta time.
 */
pl_float
PL::core::pl_get_delta_time(void)
{
    static float last_frame = 0.0f;
    static pl_bool first_call = PL_TRUE;    
    float current_frame = glfwGetTime();
    float delta_time = 0.0f;

    if (first_call == PL_TRUE) {
        first_call = false;
        delta_time = 0.0f;
    } else {
        delta_time = current_frame - last_frame;
    }
    last_frame = current_frame;
    return delta_time;
}
