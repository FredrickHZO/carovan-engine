#pragma once

#include <string>
#include <functional>

#include "../math/Vector4.h"

namespace Carovan
{
    struct BehaviourComponent {
        std::function<void()> OnUpdate = [] {};
        std::function<void()> OnCreate = [] {};
        std::function<void()> OnDestroy = [] {};
        // Not sure about these
        std::function<void()> OnCollision = [] {};
        std::function<void()> OnCollisionEnter = [] {};
        std::function<void()> OnCollisionExit = [] {};

        BehaviourComponent() = default;
        BehaviourComponent(const BehaviourComponent&) = default;
        BehaviourComponent(BehaviourComponent&&) = default;
        BehaviourComponent& operator=(const BehaviourComponent&) = default;
        BehaviourComponent& operator=(BehaviourComponent&&) = default;
    };

    struct TransformComponent
    {
        Vector4<float> Transform{ 1.0f };

        TransformComponent() = default;
        TransformComponent(const Vector4<float>& transform)
            : Transform(transform) {}

        ~TransformComponent() = default;

        TransformComponent(const TransformComponent&) = default;

        operator Vector4<float>& () { return Transform; }
        operator const Vector4<float>& () { return Transform; }
    };

    struct SpriteComponent
    {
        Vector4<float> Color{ 1.0f, 1.0f, 1.0f, 1.0f };

        SpriteComponent() = default;
        SpriteComponent(const Vector4<float>& color)
            : Color(color) {}

        ~SpriteComponent() = default;

        SpriteComponent(const SpriteComponent&) = default;

        operator Vector4<float>& () { return Color; }
        operator const Vector4<float>& () const { return Color; }
    };

    struct TagComponent
    {
        std::string Tag;

        TagComponent() = default;
        TagComponent(const std::string& tag)
            : Tag(tag) {}

        ~TagComponent() = default;

        TagComponent(const TagComponent&) = default;

        operator std::string& () { return Tag; }
        operator const std::string& () const { return Tag; }
    };
};
