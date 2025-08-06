#pragma once

#include <entt/entt.hpp>

#include "Entity.h"

namespace Carovan
{
    class Scene
    {
    private:
        entt::registry m_Registry;

    public:
        Scene();
        ~Scene();

        Scene(Scene&&) = default;
        Scene& operator=(Scene&&) = default;

        Entity CreateEntity(const std::string& name = std::string("Anonymous Entity"));
        //Entity CreateRenderableEntity(); ?
        //Entity CreateAudioEntity(); ?

        void OnUpdate();
        void OnRender();
    };

    // Example usage
    // Scene CreateDefaultScene()
    // {
    //     Scene activeScene = Scene();
    //     Entity square = activeScene.CreateEntity("Square");
    //     square.AddComponent<SpriteComponent>(Color{ 1.0f, 0.8f, 0.4f, 1.0f });
    //
    //     auto& behaviour = square.AddComponent<BehaviourComponent>();
    //     behaviour.OnCreate = []()
    //     {
    //         EventManager::AddListener<KeyPressedEvent>([](KeyPressedEvent& e)
    //         {
    //             LOG_INFO("Key pressed {}", e.KeyCode());
    //         });
    //     };
    //
    //     behaviour.OnUpdate = []()
    //     {
    //         LOG_INFO("Updating square");
    //     };
    //
    //     return activeScene;
    // }
};
