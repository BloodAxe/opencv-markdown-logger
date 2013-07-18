#OpenCV Markdown logger

A lightweight easy-to-use markdown-based logger for OpenCV library. 
The goal is to provide easy and ligthweight mechanism to log OpenCV data and into human-friendly form. 
It's aimed for easy logging of OpenCV types to produce Markdown documents which can be then converted to HTML for further analysis.

# What this library is 

 * This is the library than can create compact and self-contained log reports with binary data, text information and images.
 * This is the library than can help you to reproduce a crash, unexpected behaviour of algorithm you develop.
 * This is the library that can give visual explanation of your algorithm workflow (see examples). 
 
# What this library isn't 

 * This isn't a replacement of application-wise logging library
 * This isn't a general-purpose Markdown writer library
 
#Features

This library tries to make logging tasks more easy. 
Logging does matter since it's often the only way to see what exactly happens in your algorithm. 
This library is aimed for developers who are using OpenCV library.

## Easy syntax

    std::ofstream log("simple.md");
    log << h1("First heading");
    log << "Initialization of the application" << std::endl;    
    log << bold("OpenCV Build Information:") << std::end;
    log << pre(cv::getBuildInformation()) << std::endl;

## Logging images

    cv::Mat img = cv::imread("lena.png");
    std::ofstream log("simple.md");
    log << image(img, "Caption text"));

## Developer-friendly output

Makes developer life easier by printing OpenCV data ready for copy-paste use: 

**Code**:

    cv::ORB orb;
    cv::Mat img = cv::imread("lena.png");
    std::vector<cv::KeyPoint> keypoints;
    orb.detect(img, keypoints);
    
    std::ofstream log("simple.md");
    log << code(keypoints);

**Produces**:
 
    std::vector<cv::KeyPoint> keypoints(543);
    keypoints[0] = cv::KeyPoint(....);
    keypoints[0] = cv::KeyPoint(....);
    keypoints[0] = cv::KeyPoint(....);
    keypoints[0] = cv::KeyPoint(....);

# Support 

This library is written and supported by Ievgen Khvedchenia [ekhvedchenya@gmail.com][1]. 
Feel free to write me an email or visit [Computer Vision Talks][2] website for support.

# Disclaimer

This software is provided "as is" and any expressed or implied warranties, including, but not limited to, the implied warranties of merchantability and fitness for a particular purpose are disclaimed. 
In no event shall the regents or contributors be liable for any direct, indirect, incidental, special, exemplary, or consequential damages (including, but not limited to, procurement of substitute goods or services; loss of use, data, or profits; or business interruption) however caused and on any theory of liability, whether in contract, strict liability, or tort (including negligence or otherwise) arising in any way out of the use of this software, even if advised of the possibility of such damage.

[1]: ekhvedchenya@gmail.com
[2]: computer-vision-talks.com
