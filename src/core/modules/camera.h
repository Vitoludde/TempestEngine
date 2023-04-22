#ifndef CAMERA_H
#define CAMERA_H

// Math includes
#include "../math/Matrix4.h"
#include "../math/Vector3.h"
#include "../math/Matrix_transform.h"
#include "../math/Matrix_clip_space.h"
#include "../math/Trigonometric_functions.h"

// Input includes
#include "../input/input_handler.h"

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement
{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

// Default camera values
const float _YAW = -90.0f;
const float _PITCH = 0.0f;
const float _SPEED = 2.5f;
const float _SENSITIVITY = 0.1f;
const float _ZOOM = 45.0f;

namespace TempestEngine
{
    class Camera
    {
    public:
        // Camera Vectors
        Vector3 Position;
        Vector3 Front;
        Vector3 Up;
        Vector3 Right;
        Vector3 WorldUp;
        // Euler angles
        float Yaw;
        float Pitch;

        Camera(Vector3 position = Vector3(0.0f, 0.0f, 0.0f), Vector3 up = Vector3(0.0f, 1.0f, 0.0f)) : Front(Vector3(0.0f, 0.0f, -1.0f))
        {
            Position = position;
            WorldUp = up;
            Yaw = _YAW;
            Pitch = _PITCH;
            updateCameraVectors();
        }

        Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float newyaw, float newpitch) : Front(Vector3(0.0f, 0.0f, -1.0f))
        {
            Position = Vector3(posX, posY, posZ);
            WorldUp = Vector3(upX, upY, upZ);
            Yaw = newyaw;
            Pitch = newpitch;
            updateCameraVectors();
        }

        Matrix4 GetViewMatrix()
        {
            return lookAt(Position, Position + Front, Up);
        }

        void Move(Vector3 MovementVector)
        {
            Position += Front * MovementVector.x;
            Position += Right * MovementVector.z;
            Position += Up * MovementVector.y;
        }

        void Move(Vector3 MovementVector, Vector2 EulerAngles)
        {
            Yaw = EulerAngles.x;
            Pitch = EulerAngles.y;
            updateCameraVectors();
            Position += Front * MovementVector.x;
            Position += Right * MovementVector.z;
            Position += Up * MovementVector.y;
        }

    private:
        // calculates the front vector from the Camera's (updated) Euler Angles
        void updateCameraVectors()
        {
            // calculate the new Front vector
            Vector3 front;
            front.x = cos(radians(Yaw)) * cos(radians(Pitch));
            front.y = sin(radians(Pitch));
            front.z = sin(radians(Yaw)) * cos(radians(Pitch));
            Front = Vector3::normalize(front);
            // also re-calculate the Right and Up vector
            Right = Vector3::normalize(Vector3::cross(Front, WorldUp)); // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
            Up = Vector3::normalize(Vector3::cross(Right, Front));
        }
    };
}

#endif