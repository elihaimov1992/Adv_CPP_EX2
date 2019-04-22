/*Eli Haimov - 308019306*/

#include "Document.h"

Document::Document() : curr_line{0}
{
    vector <string> other_doc_line(0);
    doc_lines = other_doc_line;
}

// p
void Document::print_curr_line()
{
    if(curr_line <= 0) 
    {
        cerr << "The Document haven't lines" << endl;
        return;
    }
    else
    {
        cout << doc_lines[curr_line-1] << endl;
    }
}

// n
void Document::print_line_num()
{
    if(curr_line <= 0) 
    {
        cerr << "The Document haven't lines" << endl;
        return;
    }
    else
    {
        cout << curr_line << "   " << doc_lines[curr_line-1] << endl;
    }
}

// %p
void Document::print_all_lines()
{
    if(curr_line <= 0) 
    {
        cerr << "The Document haven't lines" << endl;
        return;
    }
    else
    {
        for(int i = 0; i < doc_lines.size(); i++)
        {
            cout << doc_lines[i] << endl;
        }  
    }
}

// exm #7
void Document::make_curr_line(int ind)
{
    if(ind > doc_lines.size())
    {
        cerr << "The Document haven't lines" << endl;
        return;
    }
    else
    {
        curr_line = ind;
        print_curr_line();
    }
}

// a
void Document::append_txt()
{
    string line;
    while(getline(cin,line) && line != ".")
    {
        if(curr_line >= doc_lines.size())
        {
            doc_lines.push_back(line);
        }
        else
        {
            vector <string>::iterator start;
            start = doc_lines.begin();
            doc_lines.insert(start + curr_line , line);
        }
        curr_line = curr_line + 1;   
    }
}

// i
void Document::insert_txt()
{
    curr_line = curr_line - 1;
    string line;
    while(getline(cin,line) && line != ".")
    {
        if(curr_line >= doc_lines.size())
        {
            doc_lines.push_back(line);
        }
        else
        {
            vector <string>::iterator start;
            start = doc_lines.begin();
            doc_lines.insert(start + curr_line , line);
        }
        curr_line = curr_line + 1;   
    }
    curr_line = curr_line + 1;
}

// c
void Document::change_curr_line()
{
    string line;
    while(getline(cin , line) && line != ".")
    {
        doc_lines[curr_line - 1] = line;
    } 
}

// d
void Document::delete_curr_line()
{ 
    vector <string>::iterator start;
    start = doc_lines.begin();
    doc_lines.erase(start + curr_line - 1);
    curr_line = curr_line - 1;
}

// /text
void Document::search_forward_curr_line(string txt)
{
    for(int i = curr_line - 1; i < doc_lines.size(); i++)
    {
        if(doc_lines[i].find(txt) != string::npos)
        {
            curr_line = i + 1;
            cout << doc_lines[i] << endl;
            return;
        }
    }
    for(int i = 0; i < curr_line; i++)
    {
        if(doc_lines[i].find(txt) != string::npos)
        {
            curr_line = i + 1;
            cout << doc_lines[i] << endl;
            return;
        }
    } 
}

// s/old/new
void Document::replace_old_new(string old_str, string new_str) // Need upgrade
{
    if(this->curr_line <= 0)
    {
       cerr << "The old word have'nt exist" << endl;
       return;
    }
    if(doc_lines[curr_line-1].find(old_str) != string::npos)
    {
        int ind = doc_lines[curr_line-1].find(old_str);
        doc_lines[curr_line-1].replace(ind , old_str.size() , new_str);
    }
    else
    {
      cerr << "The old word have'nt exist" << endl;
    } 
}
