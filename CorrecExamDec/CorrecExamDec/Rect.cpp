#include "Rect.h"

#pragma region Constructor

Rect::Rect(int _x, int _y, int _width, int _height)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
}

Rect::Rect(const Rect& _copy)
{
    x = _copy.x;
    y = _copy.y;
    width = _copy.width;
    height = _copy.height;
}

#pragma endregion

#pragma region Methods

int Rect::X() const
{
    return x;
}

int Rect::Y() const
{
    return y;
}

int Rect::Width() const
{
    return width;
}

int Rect::Height() const
{
    return height;
}

#pragma endregion


