///##############################################################
///
///		Author: Neverland_LY     Date:2018-7-10 16:49
///
///		定义了一个工具类，用于在图片上画十字丝
///		
///		
///
///##############################################################

#pragma once

#ifndef _CROSSLINE_H_
#define _CROSSLINE_H_

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/nonfree/nonfree.hpp>
#include<opencv2/legacy/legacy.hpp>


using namespace cv;

class CrossLine
{
public:
	CrossLine();
	~CrossLine();

	void drawCrossLine(Mat &, Point2f &, int count = 0); //一般的十字丝
	void drawCircle(Mat &, Point &);  //画圆形

private:
	Point2f _p;  //中心点
};


#endif  //_CROSSLINE_H_



