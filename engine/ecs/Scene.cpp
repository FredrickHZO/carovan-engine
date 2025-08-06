#include "Scene.h"
#include "Component.h"
#include "../core/Logger.h"

namespace Carovan
{
    Scene::Scene() = default;
    Scene::~Scene() = default;

    Entity Scene::CreateEntity(const std::string& name)
    {
        Entity entity{ m_Registry.create(), &m_Registry };
        entity.AddComponent<TransformComponent>();
        entity.AddComponent<TagComponent>(name);
        LOG_INFO("Entity '{}' created", name);

        return entity;
    }

    /**
     * Listen for events, retrieves all the scripts for the scriptable
     * objects and update their status.
     */
    void Scene::OnUpdate()
    {
        // Generates events such as KeyPressedEvent
        // InputManager::ProcessInput();

        // Events listener react to generated events
        // dispatcher.ProcessEvents();

        auto behaviourView = m_Registry.view<BehaviourComponent>();
        // Get DeltaTime and use it to update
        for (auto& entity : behaviourView)
        {
            auto& behaviour = behaviourView.get<BehaviourComponent>(entity);
            behaviour.OnUpdate();
        }
    }

    /**
     * Retrieves all the renderable objects from the scene and render them
     */
    void Scene::OnRender()
    {
        auto group = m_Registry.group<TransformComponent>(entt::get<SpriteComponent>);
        for (auto& entity : group)
        {
            auto& transform = group.get<TransformComponent>(entity);
            auto& sprite = group.get<SpriteComponent>(entity);

            // Render pass
        }
    };
};
