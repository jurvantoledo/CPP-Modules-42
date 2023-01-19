#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{

    if (argc < 4 || argc > 5)
    {
        std::cout << "Please use 4 arguments" << std::endl;
        return (EXIT_FAILURE);
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    // Open infile and check if infile is found
    std::ifstream infile;
    infile.open(filename);
    if (!infile)
    {
        std::cout << "No infile found" << std::endl;
        return (EXIT_FAILURE);
    }
    
    // Create outfile and check outfile
    std::ofstream outfile;
    std::string outfileName = filename + ".replace";
    outfile.open(outfileName);
    if (!outfile)
    {
        std::cout << "Outfile not created" << std::endl;
        return (EXIT_FAILURE);
    }
    
    // Set infile in string
    std::string write;
    std::string content;
    while (!infile.eof())
    {
        getline(infile, write);
        content = content + write;
        content = content + '\n';
    }
    
    // Check string for size and replace word
    int pos = 0;
    for (int i = 0; i < (int)content.size(); i++)
    {
        pos = (int)content.find(s1, i);
        if (pos != -1 && pos == i)
        {
            outfile << s2;
            i = i + s1.size() - 1;
        }
        else
            outfile << content[i];
    }

    // Close files
    infile.close();
    outfile.close();
    return (EXIT_SUCCESS);
}