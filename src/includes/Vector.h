#pragma once

template<class T>
class Vector
{
	T x;
	T y;
};


template< >
class Vector<float>
{
public:

	float x;
	float y;
};

template< >
class Vector<int>
{
public:

	int x;
	int y;
};



