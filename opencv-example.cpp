#include "markdown.hpp"
#include "markdown-opencv.hpp"

int main()
{
    using namespace markdown;
    
    markdown::document doc(std::cout);
    
    cv::Mat im0 = cv::Mat(200,200, CV_8UC1);
    cv::RNG theRandom;
    
    theRandom.fill(im0, cv::RNG::UNIFORM, cv::Scalar::all(0), cv::Scalar::all(255));

    std::vector<cv::Point2f> pts;
    cv::goodFeaturesToTrack(im0, pts, 100, 0.5, 3);
    
    doc << h1("OpenCV example");
    
    doc << bold("Input image:") << std::endl;
    doc << image(im0, "Input image");
    
    doc << h2("Features");
    doc << code(pts, "pts");
    
    return 0;
}