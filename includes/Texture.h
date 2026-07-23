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
#include <functional>
#include <map>
#include <string>
#include <variant>

using std::map;
using std::string;

#include "Color.h"
#include "Geometric.h"
#include "NativeStructs.h"
#include "TTFText.h"

namespace doengine
{
class TTFText;
class NativeTexture;

class Texture
{
    NativeTexture* realNativeTexture;

  public:
    Texture();
    Texture(std::string path);
    Texture(std::string path, const Color& color);
    Texture(std::string path, NativeTexture* nativeTexture);
    ~Texture();

    void SetTransparentColor(const Color& color);
    void Draw(int x, int y);
    void Draw(const Rect& offset);
    void Draw(const Rect& offset, const Rect& clipset);
    virtual void Draw(const Rect& offset, const Rect& clipset,
                      const double angle);
    virtual void Draw(const Rect& offset, const Rect& clipset,
                      const double angle, const Point& center);
    void ModulateColor(const Color& color);
    int getWidth();
    int getHeight();
    bool validTexture();
    Texture* setNativeTexture(void*);
    Texture* subTexture(const Rect& clipset);

    void* getNativeBuffer();
};

class TextureManager
{

    TextureManager()
    {
    }

    static TextureManager* instance;

    std::map<std::variant<std::string, int>, Texture*> textures;
    std::map<std::variant<std::string, int>, TTFText*> fonts;

  public:
    static TextureManager* getTextureManager();

    void loadTextureFromFile(const std::variant<std::string, int>& key,
                             string src, const Color trans = {0, 0, 0, 0});
    void loadFont(const std::variant<std::string, int>& key, string src,
                  int pts);
    TTFText* getFont(const std::variant<std::string, int>& id);

    void loadTextureFromTexture(string id, Texture* texture,
                                const Rect& clipset);

    void addTexture(string id, Texture* texture);
    void addTexture(const std::variant<std::string, int>& key,
                    Texture* texture);

    void removeTexture(string id);

    Texture* getTexture(const std::variant<std::string, int>& id);
    Texture* getTextureOr(const std::variant<std::string, int>& id,
                          std::function<void()> orCall);

    enum class TextureStatus
    {
        Success,
        Error,
        TextureIdInvalid
    };
    TextureStatus drawTexture(const std::string, const Rect offset,
                              const Rect clipset);
    TextureStatus drawTexture(const std::string id, const Rect offset);
};

} // namespace doengine
