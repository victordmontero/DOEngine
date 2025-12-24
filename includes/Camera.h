#pragma once
#include <algorithm>
#include "Camera.h"
#include "Geometric.h"

namespace doengine
{


class Camera : public GameObject
{
public:
    enum class CameraMovement
    {
        CameraUp,
        CameraDown,
        CameraLeft,
        CameraRight
    };

private:

public:
    Camera(int viewportW, int viewportH, int tileSize, float smoothing = 0.1f)
    {

    }

    virtual void Update(float elapsed){}
    virtual void Render()
    {
        /// TBI
    }

private:

};

 

} // namespace doengine
