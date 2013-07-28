#pragma once
#ifndef MARKDOWN_DOCUMENT_OPENCV_HPP
#define MARKDOWN_DOCUMENT_OPENCV_HPP

#include <opencv2/opencv.hpp>
#include "markdown.hpp"

namespace markdown
{

    inline string_printer code(const cv::Mat_<float>& x, const char * variableName)
    {
        std::ostringstream os;
        
        int rows = x.rows;
        int cols = x.cols;
        int type = x.type();
        
        os << "cv::Mat" << variableName << " = (cv::Mat(" << rows << "," << cols << "," << type << ") << " << std::endl;
        for (int i = 0; i < rows; i++)
        {
            os << "\t";
            for (int j = 0; j < cols; j++)
            {
                os << x(i,j) << ", ";
            }
            os << std::endl;
        }
        os << ");" << std::endl;
        return pre(os.str());
    }
    
    inline string_printer code(const cv::Matx33f& x, const char * variableName)
    {
        std::ostringstream os;
        os << "cv::Matx33f " << variableName << " = (cv::Mat_<float>(3,3) << " << std::endl;
        os << x(0,0) << ", " << x(0,1) << ", " << x(0,2) << "," << std::endl;
        os << x(1,0) << ", " << x(1,1) << ", " << x(1,2) << "," << std::endl;
        os << x(2,0) << ", " << x(2,1) << ", " << x(2,2) << "," << std::endl;
        os << ");";
        
        return pre(os.str());
    }
    
    inline string_printer code(std::vector<unsigned char>& x, const char * variableName)
    {
        std::ostringstream os;
        os << "std::vector<unsigned char> " << variableName << "(" << x.size() << ");" << std::endl;
        
        size_t count = x.size();
        
        for (size_t i = 0; i < count; i++)
        {
            bool hasMoreElements = i < (count - 1);
            
            os << variableName << "[" << i << "] = " << (int) x[i] << "; ";
            
            if (hasMoreElements)
            {
                if ((i + 1) % 4 == 0)
                {
                    os << std::endl;
                }
            }
        }
        
        return pre(os.str());
    }
    
    inline string_printer code(const std::vector<cv::Point2f>& x, const char * variableName)
    {
        std::ostringstream os;
        
        size_t count = x.size();
        
        os << "cv::Point2f " << variableName << "[" << count << "] = " << std::endl;
        os << "{" << std::endl;
        
        os << "\t";
        
        for (size_t i = 0; i < count; i++)
        {
            bool hasMoreElements = i < (count - 1);
            
            os << "cv::Point2f(" << std::setw(10) << std::right << std::fixed << x[i].x << "f," << std::setw(10) << std::right << std::fixed << x[i].y << "f)";
            
            if (hasMoreElements)
            {
                os << ", ";
                
                if ((i + 1) % 4 == 0)
                {
                    os << std::endl;
                    os << "\t";
                }
            }
        }
        
        os << std::endl;
        os << "};"; 
        
        return pre(os.str());
    }
    
    inline string_printer image(const cv::Mat& img, const char * imageAlt)
    {
        std::vector<unsigned char> buf;
        cv::imencode(".png", img, buf);
        
        return image(buf, imageAlt);
    }
}

#endif