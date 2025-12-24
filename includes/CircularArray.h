#ifndef CIRCULAR_ARRAY_H_DEFINED
#define CIRCULAR_ARRAY_H_DEFINED
#include <array>

template <typename T, const int size>
class CircularArray
{

    
    static_assert(size > 0, "Size must be higher than zero");
   public:
    typedef unsigned int IndexType;
    
    std::array<T, size> _array;
 
    IndexType cursor = 0;

    void fixBound()
    {
      if(cursor >= _array.size())
         cursor = 0;
    }

    T operator++(int)
    {
        T v = _array[cursor];
        cursor++;
        fixBound();
        return v;
    }

    T operator[](const IndexType& index)
    {
      if(index > _array.size())
      {
         return _array[0];
      }
      return _array[index];
    }
};

#endif // CIRCULAR_ARRAY_H_DEFINED