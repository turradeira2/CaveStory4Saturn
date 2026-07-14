#pragma once

#include <srl.hpp>

using namespace SRL::Math::Types;

struct Camera
{
    Fxp x;
    Fxp y;
};

extern Camera MainCamera;

void InitCamera();
void CenterCamera(Fxp x, Fxp y);
void ApplyCamera();

Fxp WorldToScreenX(Fxp worldX);
Fxp WorldToScreenY(Fxp worldY);

Fxp ScreenToWorldX(Fxp screenX);
Fxp ScreenToWorldY(Fxp screenY);