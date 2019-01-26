#include "utils.hpp"

#define SPACE 32
#define TAB 9

std::string eliminate_white_spaces(std::string str){
    std::string ret;
    for (int i = 0; i < (int)str.size(); i++)
        if((int)str[i] != SPACE && (int)str[i] != TAB)
            ret += str[i];
    return ret;
}

std::vector<std::string> split (std::string str){
    std::vector<std::string> ret;
    str = eliminate_white_spaces(str);
    int str_size = (int)str.size();
    std::string curr_part = "";
    for (int i = 0; i < str_size; i++){
        if(!isalpha(str[i]) && str[i] != '?'){
            if((int)curr_part.size() != 0)
                ret.push_back(curr_part);
            if((int)str[i] != SPACE && int(str[i]) != TAB){
                curr_part = str[i];
                ret.push_back(curr_part);
            }
            curr_part = "";
        }
        else curr_part += str[i];
    }
    if((int)curr_part.size() != 0)
        ret.push_back(curr_part);
    return ret;
}
