#pragma once
#include <string>
#include <vector>
#include <memory>
struct EntryDrawable{
   std::string title;
};




struct Menu{

   bool wrap_menu;
   int  items_in_screen;
   int  current_offset;
   std::vector<std::shared_ptr<EntryDrawable>> items;

   void up();
   void down();
   std::string toString();

};


