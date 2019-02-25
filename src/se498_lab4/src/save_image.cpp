#include <stdio.h>
#include <highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;
 
int main( )
{
 
       Mat image;
       Mat gray_image;
       // LOAD image
       image = imread("/home/ros/catkin_rsomer2/src/se498_lab4/images/tennisball.jpg", CV_LOAD_IMAGE_COLOR);  

       if(!image.data)  // Check for invalid input
       {
              cout <<  "Could not open or find the image" << std::endl ;
              return -1;
       }

       //DISPLAY image
       namedWindow( "window", CV_WINDOW_AUTOSIZE );   // Create a window for display.
        cvtColor(image, gray_image, COLOR_BGR2GRAY);
        GaussianBlur(gray_image,gray_image, Size(7,7), 0,0); 
        Canny(gray_image,gray_image,100,300,3);

       imshow("window", gray_image);                       // Show our image inside it.
       imwrite("/home/ros/catkin_rsomer2/src/se498_lab4/images/copy_image.jpg",gray_image);
       //SAVE image to "/home/ros/catkin_netid/src/se498_lab4/images/copy_image.jpg"

       

       waitKey(0);                       // Wait for a keystroke in the window
       
       return 0;
}