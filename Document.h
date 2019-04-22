/*Eli Haimov - 308019306*/

//#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Document{
private:
vector <string> doc_lines; // Document's lines.
int curr_line; // Current line.

public:
//C'tor:
Document();

//All functions (Command Meaning):
void print_curr_line(); // p - Prints the current line (ed maintains a current line).
void print_line_num(); // n - Prints line number of current line followed by TAB followed by current line.
void print_all_lines(); // %p - Prints all lines.
void make_curr_line(int i); // 7 - Makes line #7 the current line.
void append_txt(); // a - Appends new text after the current line.
void insert_txt(); // i - Inserts new text before the current line.
void change_curr_line(); // c - Changes the current line for text that follows.
void delete_curr_line(); // d - Deletes the current line.
void search_forward_curr_line(string txt); // /text - Searches forward after current line for the specified text.
//The search wraps to the beginning of the buffer and continues down to the current line, if necessary .
void replace_old_new(string old_str, string new_str); // s/old/new - Replaces old string with new in current line (google: C++ split or token).
};