#include "Sprite.h"

namespace doengine
{

Sprite::Sprite(Texture* texture, const std::vector<Rect>& frames,
               const Point& offset, const ClipType type)
    : texture(texture), frames(frames), offset(offset), clipType(type),
      animId(0U)
{
}

Sprite::~Sprite()
{
    texture = nullptr;
}

void Sprite::Draw(const Point& pos)
{
    Rect srcRect;
    switch (clipType)
    {
    case ClipType::Contiguous:
        // Rect dstRect{pos.x, pos.y, frames.front().w, frames.front().h};
        /* Rect srcRect{this->offset.x + frames.front().x,
                      this->offset.y + frames.front().y, frames.front().w,
                      frames.front().h};*/
        texture->Draw({pos.x, pos.y, frames.front().w, frames.front().h},
                      {this->offset.x + frames.front().x,
                       this->offset.y + frames.front().y, frames.front().w,
                       frames.front().h});
        break;

    case ClipType::Free:
        // Rect dstRect{pos.x, pos.y, frames.at(animId).w, frames.at(animId).h};
        texture->Draw({pos.x, pos.y, frames.at(animId).w, frames.at(animId).h},
                      frames.at(animId));
    default:
        break;
    }
}
void Sprite::Update(const long deltaTime)
{
    animId = animId % 2;
    animId++;
}

void Sprite::SetClipType(const ClipType type)
{
    clipType = type;
}

ClipType Sprite::GetClipType() const
{
    return clipType;
}

Texture* Sprite::GetTexture() const
{
    return texture;
}

} // namespace doengine
