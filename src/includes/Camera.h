#pragma once
#include <Vector.h>
#include <Window.h>

enum class CameraMovement{
	CameraUp,
	CameraDown,
	CameraLeft,
	CameraRight,
	CameraNotMovement
};


class Camera
{
	Vector<int> camera_pos;
public:

	Camera(Window* window);
	Camera(Window* window,const Vector<int>& current_pos);
	~Camera();
  
	virtual Camera* Update(CameraMovement where);


};

