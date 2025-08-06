#pragma once

#include <glm/glm.hpp>

namespace Carovan
{
    template <typename T>
    struct Vector2
    {
        T x;
        T y;

        Vector2() = default;
        explicit Vector2(T v): x(v), y(v){}
        Vector2(T v1, T v2): x(v1), y(v2) {}

        Vector2<T>& operator=(const glm::vec4& v)
        {
            this->x = v.x;
            this->y = v.y;
            return *this;
        }

        Vector2<T>& operator=(const Vector2<T>& v)
        {
            this->x = v.x;
            this->y = v.y;
            return *this;
        }

        glm::vec2 Convert() const { return glm::vec2(x, y); }
        std::string String() const { return "x: " + std::to_string(x) + ", y: " + std::to_string(y); }
    };

    template <typename T>
    struct Vector3
    {
        T x;
        T y;
        T z;

        Vector3() = default;
        explicit Vector3(T v): x(v), y(v), z(v) {}
        Vector3(T v1, T v2, T v3): x(v1), y(v2), z(v3) {}

        Vector3<T>& operator=(const glm::vec4& v)
        {
            this->x = v.x;
            this->y = v.y;
            this->z = v.z;
            return *this;
        }

        Vector3<T>& operator=(const Vector3<T>& v)
        {
            this->x = v.x;
            this->y = v.y;
            this->z = v.z;
            return *this;
        }

        glm::vec3 Convert() const { return glm::vec3(x, y, z); }
        std::string String() const { return "x: " + std::to_string(x) + ", y: " + std::to_string(y) +
            ", z: " + std::to_string(z); }
    };

    template <typename T>
    struct Vector
    {
        T x;
        T y;
        T z;
        T w;

        Vector() = default;
        explicit Vector(T v): x(v), y(v), z(v), w(v) {}
        Vector(T v1, T v2, T v3, T v4): x(v1), y(v2), z(v3), w(v4) {}

        Vector<T>& operator=(const glm::vec4& v)
        {
            this->x = v.x;
            this->y = v.y;
            this->z = v.z;
            this->w = v.w;
            return *this;
        }

        Vector<T>& operator=(const Vector<T>& v)
        {
            this->x = v.x;
            this->y = v.y;
            this->z = v.z;
            this->w = v.w;
            return *this;
        }

        glm::vec4 Convert() const { return glm::vec4(x, y, z, w); }
        std::string String() const { return "x: " + std::to_string(x) + ", y: " + std::to_string(y) +
            ", z: " + std::to_string(z) + ", w: " + std::to_string(w); }
    };
};

