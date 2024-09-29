#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;

int main()
    {
        cv::Mat image = cv::imread("1.png");
        cv::VideoCapture cap(0);
        if(!cap.isOpened()) 
        {
            cout<< "hello";
            return -1;

        }
        cv::Mat frame , edges;
        cv::namedWindow("edges", cv::WINDOW_AUTOSIZE);

        while (1)
            {
                cap >> frame;
                //cv::Canny(edges,edges,0,30,3);
                //cv::imshow("edges", frame);
                for (int i = 0; i < 100000 && i < frame.rows * frame.cols; ++i) 
                    {
                        int y = i / frame.cols;  // Row index
                        int x = i % frame.cols;  // Column index
                        frame.at<cv::Vec3b>(y, x) = cv::Vec3b(255, 255, 255);  // Set pixel to white
                    }
                if(cv::waitKey(30) >= 0) break;
                cv::imshow("Display Image", frame);
            }
        
        
        cout << "Image Size: " << image.size() << endl;
        cout << "Image Type: " << image.type() << endl;

        // Print pixel values (for a small area, e.g., top-left corner)
        

        cv::waitKey(0);
        return 0;
    }