#pragma once

namespace Carovan
{
    template<typename T>
    class Singleton
    {
    protected:
        Singleton() = default;

    public:
        Singleton(const Singleton* obj) = delete;
        Singleton* operator=(const Singleton*) = delete;

        static T* Instance() { static T Instance; return &Instance; }
    };;
};
