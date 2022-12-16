#include <iostream>
#include <array>
#include <vector>
#include <bits/stdc++.h>



std::vector<int> reversed(std::vector<int> my_array){

    int val;
    std::vector<int> new_reversed_vector;
    for (int i = my_array.size()-1; i >= 0 ; i--)
    {
        val = my_array[i];
        new_reversed_vector.push_back(val);

    }

    return new_reversed_vector;
    

};


int main(){

    std::vector<int> myarray{1,2,3,4,5,6,7,8,9,10};
    std::vector<int> result;

    std::cout << "Started..." << std::endl;

    std::string ste = "345"
    int res;
    

    for (int k = 0; k < ste.length(); k++)
    {
        /* code */
        int var = (int) ste[i] - '0';
        res += res*10 + var;
        
        

    }
    

    // stoi("")
    


    result = reversed(myarray);
    // std::cout << result[0] << std::endl;

    for (int i: myarray) std::cout << i << ' ';
    std::cout << std::endl;
    for (int i: result) std::cout << i << ' ';
    std::cout << std::endl;

    return 0;
}