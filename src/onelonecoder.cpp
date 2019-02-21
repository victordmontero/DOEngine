#include "Window.h"
#include "onelonecoder.h"
#include "GeometricRender.h"
#include <math.h>
#include <vector>
using std::vector;

namespace 
{
struct ve3d{
    float x,y,z;
};

struct  triangle{
    ve3d p[3];
};

struct mesh{
   vector<triangle> tris;
};
struct mat4x4
{
	float m[4][4] = { 0 };
};

    mesh meshCube;
    mat4x4 matProj;
    float fNear = 0.1f;
    float fFar  = 1000.0f;
    float fFov  = 90.0f;
    float aspect_ratio;
    float fFovRad;
 
	void MultiplyMatrixVector(ve3d &i, ve3d &o, mat4x4 &m)
	{
        extern Window *window;
        // int w;
        // int h;
        // w = window->getWindowRect().w;
        // h = window->getWindowRect().h;
		o.x = i.x * m.m[0][0] + i.y * m.m[1][0] + i.z * m.m[2][0] + m.m[3][0];
		o.y = i.x * m.m[0][1] + i.y * m.m[1][1] + i.z * m.m[2][1] + m.m[3][1];
		o.z = i.x * m.m[0][2] + i.y * m.m[1][2] + i.z * m.m[2][2] + m.m[3][2];
		float w = i.x * m.m[0][3] + i.y * m.m[1][3] + i.z * m.m[2][3] + m.m[3][3];

		if (w != 0.0f)
		{
			o.x /= w; o.y /= w; o.z /= w;
		}
  }

};

void OneLoneCoder::onEnter()
{
    extern Window *window;
    aspect_ratio = window->getWindowRect().h/window->getWindowRect().w;
    fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * 3.14159f);


    meshCube.tris=
    {
		// SOUTH
		{ 0.0f, 0.0f, 0.0f,    0.0f, 1.0f, 0.0f,    1.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,    1.0f, 0.0f, 0.0f },

		// EAST                                                      
		{ 1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f },
		{ 1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f, 1.0f },

		// NORTH                                                     
		{ 1.0f, 0.0f, 1.0f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f, 1.0f },
		{ 1.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,    0.0f, 0.0f, 1.0f },

		// WEST                                                      
		{ 0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,    0.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 0.0f,    0.0f, 0.0f, 0.0f },

		// TOP                                                       
		{ 0.0f, 1.0f, 0.0f,    0.0f, 1.0f, 1.0f,    1.0f, 1.0f, 1.0f },
		{ 0.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 1.0f, 0.0f },

		// BOTTOM                                                    
		{ 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f },
        { 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f,    1.0f, 0.0f, 0.0f },
    };

     matProj.m[0][0] = aspect_ratio * fFovRad;
     matProj.m[1][1] = fFovRad;
     matProj.m[2][2] = fFar/(fFar - fNear);
     matProj.m[3][2] = (-fFar * fNear) / (fFar - fNear);
     matProj.m[2][3] = 1.0f;
     matProj.m[3][3] = 0.0f;

}
void OneLoneCoder::onExit(){}
void OneLoneCoder::Update()
{
}

void OneLoneCoder::Render()
{
    extern Window *window;
    int ScreenWidth = window->getWindowRect().w;
    int ScreenHeight = window->getWindowRect().h;
   for(auto tri : meshCube.tris)
    {
           triangle triProjected;
           MultiplyMatrixVector(tri.p[0], triProjected.p[0], matProj);
           MultiplyMatrixVector(tri.p[1], triProjected.p[1], matProj);
           MultiplyMatrixVector(tri.p[2], triProjected.p[2], matProj);

			triProjected.p[0].x += 1.0f; triProjected.p[0].y += 1.0f;
			triProjected.p[1].x += 1.0f; triProjected.p[1].y += 1.0f;
            triProjected.p[2].x += 1.0f; triProjected.p[2].y += 1.0f;
		   triProjected.p[0].x *= 0.5f * (float)ScreenWidth ;
		   triProjected.p[0].y *= 0.5f * (float)ScreenHeight ;
		   triProjected.p[1].x *= 0.5f * (float)ScreenWidth ;
		   triProjected.p[1].y *= 0.5f * (float)ScreenHeight;
		   triProjected.p[2].x *= 0.5f * (float)ScreenWidth;
           triProjected.p[2].y *= 0.5f * (float)ScreenHeight;



          DrawTriangle
          (
              Point(triProjected.p[0].x, triProjected.p[0].y),
              Point(triProjected.p[1].x, triProjected.p[1].y),
              Point(triProjected.p[2].x, triProjected.p[2].y),
              Color()
          );
    }

}

void OneLoneCoder::onKeyDown(std::map<SDL_Keycode, bool>keys){}
void OneLoneCoder::onKeyUp(std::map<SDL_Keycode, bool>keys){}