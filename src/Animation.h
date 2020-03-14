#pragma once
#include <string>
#include <vector>
#include "GeometricRender.h"

using std::string;
using std::vector;

class Animation{

   vector<Rect> image_clip;
   string       image_id;
   int          current_frame= 0;
   bool         pause =true;
   bool         end=false;
   public:

   Rect getCurrentAnimationFrame(){
        return image_clip[current_frame];
   }
   void next(){
       if(current_frame < image_clip.size())
        { 
           current_frame++;
        }
       else
       {
          current_frame;
       }
   }
   bool hasNext(){
      return current_frame < image_clip.size();
   }
   
   void addAnimationFrame(Rect rect){
        image_clip.emplace_back(rect);
   }

   virtual void update(float a){
       if(hasNext()&& !pause && !end)
           next();
   }


};