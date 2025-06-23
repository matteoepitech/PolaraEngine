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

        /**
         * @brief Set camera front vector.
         *
         * @param front              New camera front vector
         */
        static void set_front(glm::vec3 front);
        
        /**
         * @brief Get camera yaw angle.
         *
         * @return Current yaw angle in degrees.
         */
        static pl_float get_yaw(void);
        
        /**
         * @brief Set camera yaw angle.
         *
         * @param yaw              New yaw angle in degrees
         */
        static void set_yaw(pl_float yaw);
        
        /**
         * @brief Get camera pitch angle.
         *
         * @return Current pitch angle in degrees.
         */
        static pl_float get_pitch(void);
        
        /**
         * @brief Set camera pitch angle.
         *
         * @param pitch              New pitch angle in degrees
         */
        static void set_pitch(pl_float pitch);
        
        /**
         * @brief Update camera front vector based on yaw and pitch.
         */
        static void update_front_vector(void);

        /**
         * @brief Is the cursor grabbed or not?
         *
         * @return PL_TRUE or PL_FALSE.
         */
        static pl_bool get_is_cursor_grab(void);

        /**
         * @brief Set the cursor grab or not value.
         *        @SHOULD NOT BE USED
         *
         * @param grab
         */
        static void __set_cursor_grab(pl_bool grab);

        /**
         * @brief Get the projection matrice of the camera.
         *
         * @return The projection matrice.
         */
        static glm::mat4 get_projection(void);
        
    private:
        static glm::vec3 m_camera_pos;
        static glm::vec3 m_camera_front;
        static glm::vec3 m_camera_up;
        static glm::mat4 m_projection;
        static pl_float m_pitch;
        static pl_float m_yaw;
        static pl_bool m_is_cursor_grab;
    };

} // namespace PL
