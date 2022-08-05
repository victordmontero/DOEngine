#include "Menu.h"
#include <sstream>

void Menu::up()
{
  if(current_offset==0 && wrap_menu==true)
     current_offset = this->items.size()-1;
  else if (current_offset > 0)
       current_offset -= 1;
}
void Menu::down()
{
  if(current_offset==this->items.size() && wrap_menu==true)
     current_offset = 0;
  else if (current_offset < this->items.size())
       current_offset += 1;
}
std::string Menu::toString()
{
   std::stringstream stream;
   int temp_current_offset = current_offset;
   for(int i=0;i<this->items_in_screen;i++)
   {
       if(i >= this->items.size() && wrap_menu)
         temp_current_offset = 0;
       stream << i <<" -> "<< this->items[temp_current_offset].get()->title;
      temp_current_offset++;
   }
}