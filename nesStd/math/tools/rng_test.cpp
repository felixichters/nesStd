#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#define KEY_X 120
#define endl std::cout << std::endl;
#define cut seed &= 0xFF;

void get_rn(short &seed);
void write_to_file(std::vector<short> gens, int iteration);

int main()
{
    char key;
    int key_value; 
    short seed = 0;
    short iteration = 256;
    std::vector<short> gens;

    while(key_value != KEY_X)
    {
        std::cout << "set seed between 0 and 255: "; 
        std::cin >> seed; endl cut
        std::cout << "iteration: ";
        std::cin >> iteration; endl 
        for (iteration; iteration; iteration--)
        {  
            get_rn(seed);
            seed = seed % 16;
            std::cout << std::hex << seed; endl
            gens.push_back(seed);
            // write_to_file(gens, iteration);
        } 
        key = getch();
        key_value = key;
    } 
    return 1;
}

void get_rn(short &seed)
{
    if (seed == 0) seed ^= 0x1d;
    else if ((seed << 1) == 0 || (seed << 1) < 256)  seed = seed << 1;
    else seed = (seed << 1) ^ 0x1d;
    cut 
}
void write_to_file(std::vector<short> gens, int iteration)
{
    std::fstream file;
    file.open("out.txt", std::ios::out);

    for(short i = 0;i < gens.size(); i++)
    {
        //file << i << " ";
        file << gens[i] << '\n';
    } 
    file.close();
}