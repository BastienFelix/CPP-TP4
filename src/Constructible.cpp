#include "../headers/Constructible.hpp"

using namespace std;

Constructible::Constructible()
{
    surfaceConstructible = 0;
}

Constructible::~Constructible()
{
}

void Constructible::genererSurfaceConstructible()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 100);

    dis(gen);

    Constructible::setSurfaceConstructible(dis(gen));
}

int Constructible::getSurfaceConstructible() const
{
    return surfaceConstructible;
}

void Constructible::setSurfaceConstructible(int surface)
{
    surfaceConstructible = surface;
}