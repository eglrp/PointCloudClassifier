
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/nonfree/nonfree.hpp>
#include<opencv2/legacy/legacy.hpp>

#include <fstream>
#include <iostream>
#include <windows.h>

using namespace cv;
using namespace std;

Mat img;

void add(int event, int x, int y, int flags, void *ustc){
	if (event == CV_EVENT_LBUTTONDOWN){
		cout << (int)img.at<Vec3b>(y, x)[2] << "  ";
		cout << (int)img.at<Vec3b>(y, x)[1] << "  ";
		cout << (int)img.at<Vec3b>(y, x)[0] << "  \n";
	}
}

int main()
{
	//新建 txt 文件，用于存放点云
	std::ofstream ofs("PCL2.txt", ios::trunc);
	if (!ofs)
		return 0;

	img = imread("PCL2.png", 1);

	//namedWindow("PCL", CV_WINDOW_NORMAL);
	//setMouseCallback("PCL", add, 0);
	//imshow("PCL", img);

	cout << "rows = " << img.rows << endl << endl;
	cout << "cols = " << img.cols << endl << endl;

	//点云偏移量，将点云位于空间中心
	int deltaX = img.rows / 2;
	int deltaY = img.cols / 2;

	//生成点云
	for (int i = 0; i < img.rows; i++){
		if (i == 0)
			continue;
		for (int j = 0; j < img.cols; j++){
			if (j == 0)
				continue;
			if ((int)img.at<Vec3b>(i, j)[1] < 255 && i > 50  ){
				for (int h = -30; h < 30; h += 100)
					ofs << j - deltaY << " "
					<< -(i - deltaX) << " "
					<< h << " "
					<< /*"0"*/(int)img.at<Vec3b>(i, j)[2] << " "
					<< /*"204"*/ (int)img.at<Vec3b>(i, j)[1]<< " "
					<< /*"102"*/(int)img.at<Vec3b>(i, j)[0] << "\n";
			}
		}
	}

	ofs.close();

	Beep(500, 500);

	cout << "finish.........." << endl;

	system("pause");

	return 0;
}

