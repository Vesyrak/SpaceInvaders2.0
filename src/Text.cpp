#include "Text.h"

Text::Text( std::string message, int x, int y){
	this->message=message;
	bounds=new BoundingBox(x,y,message.size()*4, 10);
}
Text::~Text(){
}
void Text::Update(std::string message){
	this->message=message;
}
