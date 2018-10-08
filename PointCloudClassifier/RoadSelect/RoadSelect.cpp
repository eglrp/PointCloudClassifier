#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\opencv.hpp>
#include<opencv2\highgui\highgui.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat Image = imread("E:/theme.png", 0);
	Mat CannyImg;
	Canny(Image, CannyImg, 140, 250, 3);
	imshow("CannyImg", CannyImg);

	Mat DstImg;
	cvtColor(Image, DstImg, CV_GRAY2BGR);

	vector<Vec4i> Lines;
	HoughLinesP(CannyImg, Lines, 1, CV_PI / 360, 170, 30, 15);
	for (size_t i = 0; i < Lines.size(); i++)
	{
		line(DstImg, Point(Lines[i][0], Lines[i][1]), Point(Lines[i][2], Lines[i][3]), Scalar(0, 0, 255), 2, 8);
	}
	imshow("HoughLines_Detect", DstImg);
	imwrite("E:/dest.jpg", DstImg);
	waitKey(0);
	return 0;
}