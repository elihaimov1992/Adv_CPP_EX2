/*Eli Haimov - 308019306*/


#include "Editor.h"

// C'tor
Editor::Editor()
{
    document = new Document();
}

// loop function
void Editor::loop()
{
     string str_in; // String Input
    
    while(true)
    {
       getline(cin,str_in);
       if(str_in == "p")
       {
           document->print_curr_line();
       }

       else if(str_in == "n")
       {
           document->print_line_num();
       }

       else if(str_in == "%p")
       {
           document->print_all_lines();
       }

       // For make_curr_line function(Command Meaning):
       // Source 2: www.cplusplus.com/reference/sstream/istringstream/istringstream/
       else if(atoi(str_in.c_str()))
       {
           int num;
           istringstream iss(str_in);
           iss>>num;
           document->make_curr_line(num);
       }
    
       else if(str_in == "a")
       {
           document->append_txt();
       }

       else if(str_in == "i")
       {
           document->insert_txt();
       }

       else if(str_in == "c")
       {
           document->change_curr_line();
       }

       else if(str_in == "d")
       {
           document->delete_curr_line();
       }

       else if(str_in.at(0) == '/')
       {
           document->search_forward_curr_line(str_in.substr(1 , str_in.size()));
       }

       else if(str_in.at(0) == 's')
       {
           if(str_in.substr(2 , str_in.size()).find('/') != string::npos)
           {
               int ind = str_in.substr(2 , str_in.size()).find('/');  // ind = Index
               int ind_3 = (ind + 3); 
               int ind_end_4 = (str_in.size() - (ind + 4));
               document->replace_old_new(str_in.substr(2 , ind) , str_in.substr(ind_3 , ind_end_4));
           }
           else
           {
               cerr << "Old word have'nt exist" << endl; 
           }
       }

       else if(str_in == "Q")
       {
           break;
       } 

    }
}

// D'tor
Editor::~Editor()
{
    delete document;
}

