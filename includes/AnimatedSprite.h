
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