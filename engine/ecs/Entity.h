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
            this->m_Handle = entityHandle;
            this->m_RegistryHandle = registryHandle;
        }

        Entity(const Entity& other) = default;
        Entity() = default;
        ~Entity() = default;

        template<typename T, typename ... Args>
        T& AddComponent(Args&&... args)
        {
            CAROVAN_ASSERT(HasComponent<T>(), "Entity already has component");
            return this->m_RegistryHandle->emplace<T>(this->m_Handle, std::forward<Args>(args)...);
        }

        template<typename T>
        T& GetComponent()
        {
            CAROVAN_ASSERT(!HasComponent<T>(), "Entity does not have component");
            return this->m_RegistryHandle->get<T>(this->m_Handle);
        }

        template<typename T>
        void RemoveComponent()
        {
            CAROVAN_ASSERT(typeid(T) == typeid(TransformComponent), "Transform component cannot be deleted");
            CAROVAN_ASSERT(typeid(T) == typeid(TagComponent), "Tag component cannot be deleted");
            CAROVAN_ASSERT(!HasComponent<T>(), "Entity does not have component");
            this->m_RegistryHandle->remove<T>(this->m_Handle);
        }

        template<typename T>
        bool HasComponent()
        {
            return this->m_RegistryHandle->all_of<T>(this->m_Handle);
        }

        template<typename ... Types>
        bool HasMultipleComponents()
        {
            return this->m_RegistryHandle->all_of<Types...>(this->m_Handle);
        }

        operator bool() const { return this->m_Handle != entt::null; }
    };
};
