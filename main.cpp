#include <memory>
#include "Sandbox.h"

int main()
{
    const auto sandbox = std::make_unique<Sandbox>();
    sandbox->Run();
}