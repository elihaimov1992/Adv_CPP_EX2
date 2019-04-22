/*Eli Haimov - 308019306*/

#ifndef EDITOR_H
#define EDITOR_H

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

#endif
