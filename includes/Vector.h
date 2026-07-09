/*
 * ============================================================================
 * DOEngine
 * Copyright (c) 2026 Victor D. Montero, Aneury Perez
 * All Rights Reserved.
 *
 * Licensed under the MIT License.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * 1. The above copyright notice, this license notice, and this disclaimer
 *    MUST be included in all copies or substantial portions of the Software.
 *
 * 2. This notice may not be removed from the original source files distributed
 *    as part of this project.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * ============================================================================
 */


#pragma once
namespace doengine
{
template <class T>
class Vector
{
    T x;
    T y;
};

template <>
class Vector<float>
{
  public:
    float x;
    float y;

    Vector<float>(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    Vector<float>()
    {
        this->x = 0.0f;
        this->y = 0.0f;
    }
    Vector<float> operator*(Vector<float> f)
    {
        Vector<float> ret;
        ret.x *= f.x;
        ret.y *= f.y;
        return ret;
    }
    Vector<float> operator*(float f)
    {
        Vector<float> ret;
        ret.x *= f;
        ret.y *= f;
        return ret;
    }
    Vector<float> operator+(Vector<float> f)
    {
        Vector<float> ret;
        ret.x += f.x;
        ret.y += f.y;
        return ret;
    }
    Vector<float> operator+(float f)
    {
        Vector<float> ret;
        ret.x += f;
        ret.y += f;
        return ret;
    }
};

template <>
class Vector<int>
{
  public:
    int x;
    int y;
};
#if 0
Vector2<T>::Vector2()
{
    this->x = this->y = 0;
}

Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Vector2::add(Vector2 v)
{
    this->x += v.x;
    this->y += v.y;
}

void Vector2::add(float x, float y)
{
    this->x += x;
    this->y += y;
}

void Vector2::sub(Vector2 v)
{
    this->x -= v.x;
    this->y -= v.y;
}

void Vector2::sub(float x, float y)
{
    this->x -= x;
    this->y -= y;
}

void Vector2::mul(float f)
{
    this->x *= f;
    this->y *= f;
}

Vector2 Vector2::mul_N(float f)
{
    Vector2 ret;
    ret.x = this->x * f;
    ret.y = this->y * f;
    return ret;
}

float Vector2::length()
{
    return sqrt(x * x + y * y);
}

void Vector2::normalize()
{
    float l = length();
    x = x / l;
    y = y / l;
}

double Vector2::angle(Vector2 v)
{ // Note that this function returns DEG
    double dot = this->x * v.x + this->y * v.y;
    double det = this->x * v.y - this->y * v.x;
    double ret = atan2(det, dot);
    ret *= (180.0 / PI);
    while (ret < 0)
        ret += 360;
    while (ret > 360)
        ret -= 360;
    return ret;
}

void Vector2::set(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Vector2::fromAngle(double angle)
{ // Note that this function takes DEG arguments
    this->x = round_3dec(sin(angle * (PI / 180.0)));
    this->y = round_3dec(
        cos((180 - angle) *
            (PI / 180.0))); // I honestly have no clue why I have to do
                            // 180-angle here, but it only works that way :D
    this->normalize();
}

void Vector2::rotate(double angle)
{ // takes deg argument
    angle = angle * (PI / 180.0);
    float newX, newY;
    newX = x * cos(angle) - y * sin(angle);
    newY = x * sin(angle) + y * cos(angle);
    x = newX;
    y = newY;
}

// This is just a basic bezier function:
// http://answers.unity3d.com/questions/12689/moving-an-object-along-a-bezier-curve.html
Vector2 Bezier(Vector2 start, Vector2 control, Vector2 end, float t)
{
    start.mul(((1 - t) * (1 - t)));
    control.mul(2 * t * (1 - t));
    end.mul((t * t));
    start.add(control);
    start.add(end);
    return start;
}

// Interpolates a Vector by value t
Vector2 Lerp(Vector2 start, Vector2 end, float t)
{
    if (t <= 0)
        return start;
    if (t >= 1)
        return end;
    end.sub(start); // Vector from start to end
    end.mul(t);
    end.add(start);
    return end;
}

// Interpolates a float by value t
float Lerp(float start, float end, float t)
{
    if (t <= 0)
        return start;
    if (t >= 1)
        return end;
    return (end - start) * t + start;
}
#endif
} // namespace doengine