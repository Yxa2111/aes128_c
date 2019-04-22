#include <iostream>
#include <fstream>
#include "aes.c"
#include <string>
int main() {
    std::ofstream f("table.txt");
    int a[9] = {2,3,4,8,9,11,12,13,14};
    for(int i = 0; i < 9; ++i) {
        f<<a[i]<<": "<<std::endl;
        for(int j = 0; j <= 0xff; ++j) {
            if(j % 16 == 0)
            f<<std::endl;
            byte res = mult2(j,a[i]);
            f<<std::to_string(res)<<",";
        }
        f<<std::endl;
    }
    return 0;
}