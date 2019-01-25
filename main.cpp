#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "utils.hpp"

const string operators[3] = {"|", "+", "^"};

using namespace std;

string get_type(string type){
    if(type == "+")
        return "Normal";
    else if(type == "^")
        return "Xor";
    else if(type == "|")
        return "Or";
    return "Normal";
}

bool is_operator(string str){
    for (string op : operators)
        if(str == op)
            return true;
    return false;
}

void make_definition_from_splited_line(vector<string>& definition, vector<string> splited_line){
    for (string str : splited_line)
        if(is_operator(str))
            continue;
        else definition.push_back(str);
}

vector<string> make_definition_from_line (string line){
    vector<string> splited_line = split(line);
    string type = ((int)splited_line.size() > 3) ? splited_line[3] : "Normal";
    type = get_type(type);
    vector<string> definition;
    definition.push_back(type);
    make_definition_from_splited_line(definition, splited_line);
    return definition;
}

void input(vector<vector<vector<string>>> &machine_trees, vector<vector<vector<string>>> &ordered_machines_for_each_test){
    string line;
    bool orders = false;
    vector<vector<string>> machine_tree;
    vector<vector<string>> ordered_machines;
    while(getline(cin, line)){
        if(line == "###")
            break;
        else if(line == "#"){
            orders = true;
            continue;
        }
        else if(line == "##"){
            machine_trees.push_back(machine_tree);
            ordered_machines_for_each_test.push_back(ordered_machines);
            machine_tree.clear();
            ordered_machines.clear();
            continue;
        }
        if(!orders)
            machine_tree.push_back(make_definition_from_line(line));
        else{
            // TODO
        }
    }
}

void proceed(){
    vector<vector<vector<string>>> machine_trees;
    vector<vector<vector<string>>> ordered_machines;
    input(machine_trees, ordered_machines);
}

int main(){
    proceed();
}