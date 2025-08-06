#pragma once

#include "Component.h"
#include "../utils/Assertion.h"

namespace Carovan
{
    class Entity
    {
    private:
        entt::entity m_Handle = entt::null;
        entt::registry* m_RegistryHandle;

    public:
        Entity(const entt::entity entityHandle, entt::registry* registryHandle)
        {
            m_Handle = entityHandle;
            m_RegistryHandle = registryHandle;
        }

        Entity(const Entity& other) = default;
        Entity() = default;
        ~Entity() = default;

        template<typename T, typename ... Args>
        T& AddComponent(Args&&... args)
        {
            CAROVAN_ASSERT(HasComponent<T>(), "Entity already has component");
            return m_RegistryHandle->emplace<T>(m_Handle, std::forward<Args>(args)...);
        }

        template<typename T>
        T& GetComponent()
        {
            CAROVAN_ASSERT(!HasComponent<T>(), "Entity does not have component");
            return m_RegistryHandle->get<T>(m_Handle);
        }

        template<typename T>
        void RemoveComponent()
        {
            CAROVAN_ASSERT(typeid(T) == typeid(TransformComponent), "Transform component cannot be deleted");
            CAROVAN_ASSERT(typeid(T) == typeid(TagComponent), "Tag component cannot be deleted");
            CAROVAN_ASSERT(!HasComponent<T>(), "Entity does not have component");
            m_RegistryHandle->remove<T>(m_Handle);
        }

        template<typename T>
        bool HasComponent()
        {
            return m_RegistryHandle->all_of<T>(m_Handle);
        }

        template<typename ... Types>
        bool HasMultipleComponents()
        {
            return m_RegistryHandle->all_of<Types...>(m_Handle);
        }

        operator bool() const { return m_Handle != entt::null; }
    };
};
