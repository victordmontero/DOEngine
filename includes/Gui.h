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
#include "Color.h"
#include "Geometric.h"
#include <list>
#include <string>
namespace doengine
{
struct Style
{
    Color backgroundColor;
    Color foregroundColor;
    Color disableColor;
    int PrimaryfontSize;
    int secondaryFontSize;
    int padding;
    int margin;
    int borderWidth;
    Color borderColor;
    int borderRadius; /// unused
    std::string fontFamily;
};

struct UIObject
{
  protected:
    Point position;
    Rect size;
    bool _focus;
    bool disable;

  public:
    virtual void setStyle(const Style& style) = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void focus() = 0;
    virtual void unFocus() = 0;
    virtual void activate() = 0;
    virtual void deactivate() = 0;
    virtual int type() = 0;
};

enum class WidgetLayoutDirection : int
{
    Horizontal,
    Vertical,
    Grid,
    List,
    Absolute
};

class WidgetElement;
struct WidgetContainer : public UIObject
{

  protected:
    virtual void focus() = 0;
    virtual void unFocus() = 0;
    virtual void activate() = 0;
    virtual void deactivate() = 0;
    virtual void update() = 0;

    WidgetLayoutDirection layout;

    UIObject* parent;

    std::list<WidgetElement*> children;

  public:
    virtual void setStyle(const Style& style) = 0;

    virtual void render() = 0;

    void addChild(WidgetElement* element);

    void removeChild(WidgetElement* element);

    void setLayoutDirection(const WidgetLayoutDirection& direction);
};

} // namespace doengine