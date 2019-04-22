/*Eli Haimov - 308019306*/

//#pragma once
#include<iostream>
#include<sstream>
#include<vector>
#include"Document.h"

using namespace std;

class Editor
{

private:
Document* document;

public:
Editor();
void loop();
~Editor();

};
