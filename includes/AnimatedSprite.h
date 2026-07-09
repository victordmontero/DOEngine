#pragma once
#include <vector>
#include <map>
#include <GameObject.h>
#include <Rect.h>
#include <DS.h>
#include <Texture.h>
namespace doengine{
template<typename FaceIdentifier>
struct AnimatedSprite : public GameObject{
    
    struct FaceData
    {
        int spriteCount;
        std::vector<Rect> clips;
    };
    
    FaceIdentifier current;
    int index;

    std::map<FaceIdentifier, FaceData> faces;
    Rect position;
    Texture *spriteTexture;
    DS::LimitInteger currentOffset;


    bool setTexture(int id){
        DS::LimitInteger currentFrame(0,0,0);
        spriteTexture = TextureManager::getTextureManager()->getTexture(id);
        return spriteTexture && spriteTexture->validTexture();
    }

    AnimatedSprite& setPosition(const Rect& offset){
        position = offset;
        return *this;
    }

    AnimatedSprite& setCurrentFace(FaceIdentifier id){
        current = id;
         return *this;
    }
    
    virtual void Update(float timer)
    {

    }
    
    virtual void Render()
    {
        if(spriteTexture){
          
        }
    }

    bool setFace(const FaceIdentifier& id)
    {
        auto find = faces.find(id);
        if(find==faces.end())return false;
        currentOffset.setLimits(0, find->second.clips.size()).reset();  
        return true;
    }

    AnimatedSprite& addFace(FaceIdentifier face, std::vector<Rect> clipsetSetList, bool merge)
    {
        auto find = faces.find(face);
        if(find != faces.end() && !merge)return *this;
        else if(find != faces.end() ){
            for(auto it : clipsetSetList)
            {
                find->second.clips.emplace_back(it);
                find->second.spriteCount += clipsetSetList.size();
            }
        }else{
            FaceData data;
            data.clips = clipsetSetList;
            data.spriteCount = clipsetSetList.size();
            faces[face];
        }
        return *this;
    }    
};
}