#include "markdown.hpp"

int main()
{
    using namespace markdown;
    
    markdown::document doc(std::cout);
    
    doc << (h1() << "Hello, world!");
    doc << h2("Hi, all");
    doc << (bold() << "And" << " thanks " << 4 << " all the fish!") << std::endl;
    doc << horizontal_line();
    
    doc << h1("Code");
    doc << "This is a regular text" << std::endl;
    doc << code("int a = 42;");
    doc << "Example of inline code " << inline_code("int b = 17") << " to demonstrate how awesome this library is." << std::endl;
    
    doc << h1("Tag formatting");
    doc << (unordered_list() << bold("This line should be bold"));
    doc << (unordered_list() << italic("This line should be bold"));
    doc << (unordered_list() << underline("This line should be underlined"));
    doc << (unordered_list() << striked("This line should be striked"));
    
    return 0;
}