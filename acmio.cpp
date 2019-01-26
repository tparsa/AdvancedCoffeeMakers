#include "acmio.hpp"

std::string get_type(std::string type){
    if(type == "+")
        return "Normal";
    else if(type == "^")
        return "Xor";
    else if(type == "|")
        return "Or";
    return "Normal";
}

bool is_operator(std::string str){
    for (std::string op : operators)
        if(str == op)
            return true;
    return false;
}

bool is_splitter(std::string str){
    for (std::string spl : splitters)
        if(str == spl)
            return true;
    return false;
}

void make_definition_from_splited_line(std::vector<std::string>& definition, std::vector<std::string> splited_line){
    for (std::string str : splited_line)
        if(is_operator(str))
            continue;
        else definition.push_back(str);
}

std::vector<std::string> make_definition_from_line (std::string line){
    std::vector<std::string> splited_line = split(line);
    std::string type = ((int)splited_line.size() > 3) ? splited_line[3] : "Normal";
    type = get_type(type);
    std::vector<std::string> definition;
    definition.push_back(type);
    make_definition_from_splited_line(definition, splited_line);
    return definition;
}

std::vector<std::string> extract_machine_from_line(std::string line){
    std::vector<std::string> splited_line = split(line);
    std::vector<std::string> ret;
    for (int i = 0; i < (int)splited_line.size(); i++)
        if(!is_splitter(splited_line[i]))
            ret.push_back(splited_line[i]);
    return ret;
}

void input_ACM(std::vector<std::vector<std::vector<std::string>>> &machine_trees, std::vector<std::vector<std::vector<std::string>>> &ordered_machines_for_each_test){
    std::string line;
    bool orders = false;
    std::vector<std::vector<std::string>> machine_tree;
    std::vector<std::vector<std::string>> ordered_machines;
    while(std::getline(std::cin, line)){
        if(line == "###")
            break;
        else if(line == "##"){
            machine_trees.push_back(machine_tree);
            ordered_machines_for_each_test.push_back(ordered_machines);
            machine_tree.clear();
            ordered_machines.clear();
            orders = false;
            continue;
        }
        else if(line == "#"){
            orders = true;
            continue;
        }
        if(!orders)
            machine_tree.push_back(make_definition_from_line(line));
        else
            ordered_machines.push_back(extract_machine_from_line(line));
    }
}

void print_test_vvvs(std::vector<std::vector<std::vector<std::string>>> vec){
    for (int i = 0; i < (int)vec.size(); i++){
        for (int j = 0; j < (int)vec[i].size(); j++){
            for (int k = 0; k < (int)vec[i][j].size(); k++)
                std::cout << vec[i][j][k] << " ";
            std::cout << std::endl;
        }
        std::cout << "+++" << std::endl;
    }
}