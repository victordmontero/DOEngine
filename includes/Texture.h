#pragma once
#include <map>
#include <string>

using std::map;
using std::string;

#include "Color.h"
#include "Geometric.h"
#include "NativeStructs.h"

namespace doengine
{

class NativeTexture;

class Texture
{
    NativeTexture* realNativeTexture;

  public:
    Texture();
    Texture(std::string path);
    Texture(std::string path, NativeTexture* nativeTexture);
    ~Texture();

    void SetTransparentColor(const Color& color);
    Texture* setNativeTexture(void*);
    virtual void Draw(const Rect& offset);
    virtual void Draw(const Rect& offset, const Rect& clipset);
    virtual void Draw(const Rect& offset, const Rect& clipset,
                      const double angle);
    virtual void Draw(const Rect& offset, const Rect& clipset,
                      const double angle, const Point& center);
    virtual void ModulateColor(const Color& color);
    virtual int getWidth();
    virtual int getHeight();
    virtual bool validTexture();

    virtual Texture* subTexture(const Rect& clipset);
};

class TextureManager
{

    TextureManager()
    {
    }

    static TextureManager* instance;

    std::map<string, Texture*> textures;

  public:
    static TextureManager* getTextureManager();

    void loadTextureFromFile(string id, string src);

    void loadTextureFromTexture(string id, Texture* texture,
                                const Rect& clipset);

    void addTexture(string id, Texture* texture);

    void removeTexture(string id);

    Texture* getTexture(string id);
};

} // namespace doengine
