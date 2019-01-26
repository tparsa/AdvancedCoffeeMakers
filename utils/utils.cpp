#include "utils.hpp"

std::vector<std::string> split (std::string str){
    std::vector<std::string> ret;

    int str_size = (int)str.size();
    std::string curr_part = "";
    for (int i = 0; i < str_size; i++){
        if(!isalpha(str[i]) && str[i] != '?'){
            if((int)curr_part.size() != 0)
                ret.push_back(curr_part);
            if(str[i] != ' '){
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
