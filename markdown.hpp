#pragma once
#ifndef MARKDOWN_DOCUMENT_HPP
#define MARKDOWN_DOCUMENT_HPP

#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <utility>

namespace markdown
{
    struct string_printer
    {
        string_printer(const std::string& _prefix, const std::string& _suffix)
            : prefix(_prefix)
            , suffix(_suffix)
        {
        }

        string_printer(const std::string& _prefix, const std::string& _suffix, const std::string& x)
            : prefix(_prefix)
            , suffix(_suffix)
        {
            str << x;
        }

        template<typename T>
        string_printer(const std::string& _prefix, const std::string& _suffix, const T& x)
            : prefix(_prefix)
            , suffix(_suffix)
        {
            str << x;
        }

        string_printer(const string_printer& that)
            : prefix(that.prefix)
            , suffix(that.suffix)
        {
            str << that.str.str();
        }

        string_printer& operator=(string_printer& that)
        {
            prefix = that.prefix;
            suffix = that.suffix;
            str << that.str.str();
            
            return * this;            
        }

        template <class T>
        string_printer& operator<<(const T &x)
        {
            str << x;
            return *this;
        }
        
        string_printer& operator<<(const string_printer& other)
        {
            str << other.string();
            return * this;
        }
        
        // this is the type of std::cout
        typedef std::basic_ostream<char, std::char_traits<char> > CoutType;
        
        // this is the function signature of std::endl
        typedef CoutType& (*StandardEndLine)(CoutType&);
        
        // define an operator< < to take in std::endl
        string_printer& operator<<(StandardEndLine  manip)
        {
            manip(str);
            return *this;
        }
        
        std::string string() const
        {
            return prefix + str.str() + suffix;
        }

        
    protected:
        std::string        prefix;
        std::string        suffix;
        std::ostringstream str;
    };
    
    inline std::ostream& operator<<(std::ostream& str, const string_printer& x)
    {
        return str << x.string();
    }

    // Tags:
    
    template <typename T>
    inline string_printer h1(const T& x) { return string_printer("#", "\n", x); }

    inline string_printer h1() { return string_printer("#", "\n"); }

    inline string_printer h1(const std::string& str) { return string_printer("#",      "\n", str); }
    inline string_printer h2(const std::string& str) { return string_printer("##",     "\n", str); }
    inline string_printer h3(const std::string& str) { return string_printer("###",    "\n", str); }
    inline string_printer h4(const std::string& str) { return string_printer("####",   "\n", str); }
    inline string_printer h5(const std::string& str) { return string_printer("#####",  "\n", str); }
    inline string_printer h6(const std::string& str) { return string_printer("######", "\n", str); }

    inline string_printer ordered_list()                         { return string_printer("1. ", "\n");      }
    inline string_printer ordered_list(const std::string& str)   { return string_printer("1. ", "\n", str); }

    inline string_printer unordered_list()                       { return string_printer("* " , "\n");      }
    inline string_printer unordered_list(const std::string& str) { return string_printer("* ",  "\n", str); }

    inline string_printer quote(const std::string& str)          { return string_printer("> ", "\n", str);  }

    inline string_printer horizontal_line()                      { return string_printer("---", "\n");      }

    template<typename T>
    inline string_printer italic(const T& x)      { return string_printer("*", "*", x); }
    inline string_printer italic()                { return string_printer("*", "*"); }

    template<typename T>
    inline string_printer underline(const T& x)   { return string_printer("_", "_", x); }
    inline string_printer underline()             { return string_printer("_", "_"); }

    template<typename T>
    inline string_printer striked(const T& x)   { return string_printer("~", "~", x); }
    inline string_printer striked()             { return string_printer("~", "~"); }

    template<typename T>
    inline string_printer bold(const T& x)      { return string_printer("**", "**", x); }
    inline string_printer bold()                { return string_printer("**", "**"); }

    template<typename T>
    inline string_printer pre(const T& x)             { return string_printer("<pre>\n", "\n</pre>\n", x); }
    inline string_printer pre()                       { return string_printer("<pre>\n", "\n</pre>\n");    }

    template <typename T>
    inline string_printer code(const T& x)            { return string_printer("```\n", "\n```\n", x);      }
    inline string_printer code()                      { return string_printer("```\n", "\n```\n");     }

    template <typename T>
    inline string_printer inline_code(const T& x)            { return string_printer("`", "`", x);      }
    inline string_printer inline_code()                      { return string_printer("`", "`");     }

    inline string_printer image(const std::string& href, const std::string& alt)
    {
        std::ostringstream os;
        os << "![" << href << "][" << alt << "]";
        return string_printer("", "\n", os.str());
    }
    
    string_printer image(const std::vector<unsigned char>& buf, const std::string& alt, const std::string& mimeType = "image/png");
}

#endif