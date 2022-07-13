#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    std::vector<int> vec{0, 1, 2};
    std::vector<int>::iterator it = std::max_element(vec.begin(), vec.end());
    // for(int i=0;i<3;i++)
    //     cout<<*it<<endl;
    std::vector<int> vec2{3, 4, 5};
    vec.insert(vec.end(), vec2.begin(), vec2.end());
    vec.erase(it);
    for (auto &n : vec){
        std::cout << n << std::endl;
    }
}