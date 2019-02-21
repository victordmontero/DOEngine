#pragma once

template<class T>
class Vector2d
{
    private:
      Vector2d(){}
};


template<>
class Vector2d<int>
{
   public:
      int x,y;
      const Vector2d operator +=(const Vector2d oth)
      {
          x += oth.x;
          y += oth.y;
          return (*this);
      }
      const Vector2d operator -=(const Vector2d oth)
      {
          x -= oth.x;
          y -= oth.y;
          return (*this);
      }
      const Vector2d operator *=(const Vector2d oth)
      {
          x *= oth.x;
          y *= oth.y;
          return (*this);
      }


};