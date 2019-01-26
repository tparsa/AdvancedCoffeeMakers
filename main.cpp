#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "utils/utils.hpp"
#include "acmio.hpp"
#include "acm.hpp"

using namespace std;

void proceed(){
    vector<vector<vector<string>>> machine_trees;
    vector<vector<vector<string>>> ordered_machines;
    input_ACM(machine_trees, ordered_machines);
    for (int i = 0; i < (int)machine_trees.size(); i++){
        vector<vector<string>> definitions = machine_trees[i];
        ACM acm (definitions);
        vector<vector<string>> orders = ordered_machines[i];
        for (vector<string> order : orders)
        {
            if(acm.validate_order(order))
                cout << "Valid" << endl;
            else cout << "Invalid" << endl;
        }
        cout << "+++" << endl;
    }
}

int main(){
    proceed();
}