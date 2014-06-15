#include "element.h"
element::element(){
	data = 0;
}
element::~element(){
}
bool element::setdata(int d){
	data=d;
	return true;
}
int element::getdata(){
	return data;
}

