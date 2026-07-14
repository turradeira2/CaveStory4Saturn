#include <srl.hpp>

#include "camera.h"

Camera MainCamera;

void InitCamera()
{
    MainCamera.x = Fxp(0);
    MainCamera.y = Fxp(0);
}

void CenterCamera(Fxp x, Fxp y)
{
    MainCamera.x = x;
    MainCamera.y = y;
}

void SetCameraPosition(Fxp x, Fxp y)
{
    MainCamera.x = x;
    MainCamera.y = y;
}

void ApplyCamera()
{
    Vector2D pos(MainCamera.x,MainCamera.y);
    SRL::VDP2::NBG0::SetPosition(pos);
}

Fxp WorldToScreenX(Fxp worldX)
{
    return worldX - MainCamera.x;
}

Fxp WorldToScreenY(Fxp worldY)
{
    return worldY - MainCamera.y;
}

Fxp ScreenToWorldX(Fxp screenX)
{
    return screenX + MainCamera.x;
}

Fxp ScreenToWorldY(Fxp screenY)
{
    return screenY + MainCamera.y;
}