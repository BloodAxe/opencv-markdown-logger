#include "markdown.hpp"

#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/insert_linebreaks.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <boost/archive/iterators/ostream_iterator.hpp>

namespace markdown
{
    std::string base64(const std::vector<unsigned char>& buf)
    {
        using namespace std;
        using namespace boost::serialization;
        using namespace boost::archive::iterators;
        
        std::stringstream os;
        
        typedef
        base64_from_binary<    // convert binary values ot base64 characters
        transform_width<   // retrieve 6 bit integers from a sequence of 8 bit bytes
        const char *,
        6,
        8
        >
        >
        base64_text; // compose all the above operations in to a new iterator
        
        std::copy(
                  base64_text(&buf[0]),
                  base64_text(&buf[0] + buf.size()),
                  std::ostream_iterator<char>(os)
                  );
        
        return os.str();
    }
    
    string_printer image(const std::vector<unsigned char>& buf, const std::string& alt, const std::string& mimeType)
    {
        std::ostringstream os;
        
        os << "![" << alt << "][" << alt << "]" << std::endl;
        os << "[" << alt << "]: data:" << mimeType << ";base64," << base64(buf) << std::endl;
        
        return string_printer("", "\n", os.str());
    }
}