/*
** POLARA PROJECT, 2025
** include/core/camera
** File description:
** camera Header file
*/

#pragma once

#include "polara.hpp"

namespace PL::core
{
    class Camera {

    public:

        /**
         * @brief Init the camera.
         *
         * @param position              The position of the camera
         */
        static void init(glm::vec3 position);
        
        /**
         * @brief Get camera position.
         *
         * @return Current camera position.
         */
        static glm::vec3 get_position(void);
        
        /**
         * @brief Set camera position.
         *
         * @param position              New camera position
         */
        static void set_position(glm::vec3 position);
        
        /**
         * @brief Get camera front vector.
         *
         * @return Current camera front vector.
         */
        static glm::vec3 get_front(void);
        
        /**
         * @brief Get camera up vector.
         *
         * @return Current camera up vector.
         */
        static glm::vec3 get_up(void);
        
    private:
        static glm::vec3 m_camera_pos;
        static glm::vec3 m_camera_front;
        static glm::vec3 m_camera_up;
    };

} // namespace PL
