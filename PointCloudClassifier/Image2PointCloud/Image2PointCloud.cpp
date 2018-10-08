/*****************************************************************************
*  OImage2PointCloud                                                         *
*  Copyright (C) 2018  Neverland_LY  Neverland_LY@163.com.                  *
*                                                                            *
*  This program is free software; you can redistribute it and/or modify      *
*  it under the terms of the GNU General Public License version 3 as         *
*  published by the Free Software Foundation.                                *
*                                                                            *
*  You should have received a copy of the GNU General Public License         *
*  along with OST. If not, see <http://www.gnu.org/licenses/>.               *
*                                                                            *
*  Unless required by applicable law or agreed to in writing, software       *
*  distributed under the License is distributed on an "AS IS" BASIS,         *
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  *
*  See the License for the specific language governing permissions and       *
*  limitations under the License.                                            *
*                                                                            *
*  @file     Example.h                                                       *
*  @brief    对文件的简述                                                    *
*  Details.                                                                  *
*                                                                            *
*  @author   Henry.Wen                                                       *
*  @email    renhuabest@163.com                                              *
*  @version  1.0.0.1(版本号)                                                 *
*  @date     renhuabest@163.com                                              *
*  @license  GNU General Public License (GPL)                                *
*                                                                            *
*----------------------------------------------------------------------------*
*  Remark         : Description                                              *
*----------------------------------------------------------------------------*
*  Change History :                                                          *
*  <Date>     | <Version> | <Author>       | <Description>                   *
*----------------------------------------------------------------------------*
*  2014/01/24 | 1.0.0.1   | Henry.Wen      | Create file                     *
*----------------------------------------------------------------------------*
*                                                                            *
*****************************************************************************/

///##############################################################
///
///		Author: Neverland_LY     Date:2018-7-10 22:56
///
///		这部分代码实现了：
///		一、读入控制点坐标
///     二、刺点（仿淘宝查看图片）
///     三、生成二维点云，此时点云的 Z 全部为0，之后可以将其映射到三维空间
///		
///
///##############################################################


///##############################################################
///   CloudCompare Coor         OpneCV XY          OpenCV Row Col
///   Y                        ___________> X     ___________> Cols 
///   ^                       |                  | 
///   |					      |					 |
///   |					      |					 |
///   |					      |					 |
///   |					      V					 V
///   |____________> X	      Y                 Rows
///
///#############################################################

#include "CrossLine.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip> 

using namespace cv;
using namespace std;

/// Input 
#define SRC_PATH "E:/LXT.tif"
#define CONTROL_POINT_PATH "E:/LXT-ControlPoint.txt"

/// Output
#define DST_PATH "E:/CloudPointOfImage.txt"
#define POINT_DESCRIPTION_PATH "E:/CloudPointOfControlPoint.txt"

#define RECT_WIDTH 50   /// 提示框的大小
#define SCALE_COEFFICIENT 1  ///提示框的比例

Mat org, org2, img, dst, dst2;

static int controlPointCount = 0;
std::vector<float> vecControlPoint;
std::vector<int> vecCVPoint;

void addP1(int event, int x, int y, int flags, void *ustc){
	///第三步：实现放大区域
	Point2f p0;
	Point2f p1;
	if (event == CV_EVENT_MOUSEMOVE && !(flags & CV_EVENT_FLAG_LBUTTON))
	{
		CrossLine cl1;
		img = org2.clone();
		if (x < RECT_WIDTH / 2)
		{
			if (y< RECT_WIDTH / 2){
				p0 = Point2f(0, 0);
				p1 = Point2f(RECT_WIDTH, RECT_WIDTH);
			}
			else if (y > img.rows - RECT_WIDTH / 2){
				p0 = Point2f(0, img.rows - RECT_WIDTH);
				p1 = Point2f(RECT_WIDTH, img.rows);
			}
			else
			{
				p0 = Point2f(0, y - RECT_WIDTH / 2);
				p1 = Point2f(RECT_WIDTH, y + RECT_WIDTH / 2);
			}
		}
		else if (x > img.cols - RECT_WIDTH / 2)
		{
			if (y < RECT_WIDTH / 2)
			{
				p0 = Point2f(img.cols - RECT_WIDTH, 0);
				p1 = Point2f(img.cols, RECT_WIDTH);
			}
			else if (y > img.rows - RECT_WIDTH / 2)
			{
				p0 = Point2f(img.cols - RECT_WIDTH, img.rows - RECT_WIDTH);
				p1 = Point2f(img.cols, img.rows);
			}
			else
			{
				p0 = Point2f(img.cols - RECT_WIDTH, y - RECT_WIDTH / 2);
				p1 = Point2f(img.cols, y + RECT_WIDTH / 2);
			}
		}
		else
		{
			if (y < RECT_WIDTH / 2)
			{
				p0 = Point2f(x - RECT_WIDTH / 2, 0);
				p1 = Point2f(x + RECT_WIDTH / 2, RECT_WIDTH);
			}
			else if (y > img.rows - RECT_WIDTH / 2)
			{
				p0 = Point2f(x - RECT_WIDTH / 2, img.rows - RECT_WIDTH);
				p1 = Point2f(x + RECT_WIDTH / 2, img.rows);
			}
			else
			{
				p0 = Point2f(x - RECT_WIDTH / 2, y - RECT_WIDTH / 2);
				p1 = Point2f(x + RECT_WIDTH / 2, y + RECT_WIDTH / 2);
			}
		}

		rectangle(img, p0, p1, Scalar(0, 0, 255), 2);  ///画矩形
		dst = org2(Rect(p0.x, p0.y, p1.x - p0.x, p1.y - p0.y));
		resize(dst, dst2, Size(dst.cols * SCALE_COEFFICIENT, dst.rows * SCALE_COEFFICIENT), 0, 0, INTER_LINEAR);
		Point pp;
		pp.x = (int)dst.rows / 2;  pp.y = (int)dst.rows / 2;
		cl1.drawCircle(dst2, pp);
		imshow("Motherboard", img);
		imshow("Subboard", dst2);
	}

	///第四步：记录图像坐标
	static int clickCount = 0;
	Point2f p;
	p.x = x;  p.y = y;
	CrossLine cl2;  //绘制十字丝
	if (event == CV_EVENT_LBUTTONDBLCLK && controlPointCount != clickCount){
		cout << "Control Point " << clickCount + 1 << " ：  x = " << x << "    y = " << y << endl << endl;
		cl2.drawCrossLine(org2, p, clickCount);
		vecCVPoint.push_back(x); vecCVPoint.push_back(y);
		imshow("Motherboard", img);
		clickCount++;
	}

	if (controlPointCount == clickCount){
		destroyAllWindows();
		cout << "Generating cloud points now, wait for some time ...\n\n";
		///第五步：计算平均像素
		ofstream ofs(DST_PATH, ios::trunc);
		ofstream ofs2(POINT_DESCRIPTION_PATH, ios::trunc);
		float pixelRow = 0.0;
		float pixelCol = 0.0;
		for (int i = 0; i < controlPointCount - 1; i++){
			pixelCol = pixelCol + abs(vecControlPoint[2 * (i + 1)] - vecControlPoint[2 * i]) / abs(vecCVPoint[2 * (i + 1)] - vecCVPoint[2 * i]);
			pixelRow = pixelRow + abs(vecControlPoint[2 * (i + 1) + 1] - vecControlPoint[2 * i + 1]) / abs(vecCVPoint[2 * (i + 1) + 1] - vecCVPoint[2 * i + 1]);
		}

		pixelCol = pixelCol / (controlPointCount - 1);
		pixelRow = pixelRow / (controlPointCount - 1);

		float rowStart = 0.0;
		float colStart = 0.0;
		for (int i = 0; i < controlPointCount; i++){
			colStart += vecControlPoint[2 * i + 0] - vecCVPoint[2 * i + 0] * pixelCol;
			rowStart += vecControlPoint[2 * i + 1] + vecCVPoint[2 * i + 1] * pixelRow;
		}
		rowStart /= controlPointCount; colStart /= controlPointCount;

		///第五步:生成点云

		/*
		*	@ 数据格式
		*	X Y Z R G B 
		*	@注意此时的 Z = 0，因为是在平面上
		*/

		for (int i = 0; i < org.rows; i++){
			for (int j = 0; j < org.cols; j++){
				ofs << setiosflags(ios::fixed) << setprecision(4)
					<< colStart + j * pixelCol << " "
					<< rowStart - i * pixelRow << " "
					<< "0.0000" << " "
					<< (int)org.at<Vec3b>(i, j)[2] << " "
					<< (int)org.at<Vec3b>(i, j)[1] << " "
					<< (int)org.at<Vec3b>(i, j)[0] << "\n";
			}
		}
		///生成柱状线
		for (int i = 0; i < controlPointCount; i++){
			for (int j = -100; j < 300; j++){
				ofs2 << setiosflags(ios::fixed) << setprecision(4)
					<< colStart + vecCVPoint[2 * i + 0] * pixelCol << " "
					<< rowStart - vecCVPoint[2 * i + 1] * pixelRow << " "
					<< j << " "
					<< "255 255 0\n";
			}

			for (float j = -10.0; j < 10.0; j += 0.5){
				ofs2 << setiosflags(ios::fixed) << setprecision(4)
					<< colStart + vecCVPoint[2 * i + 0] * pixelCol + j << " "
					<< rowStart - vecCVPoint[2 * i + 1] * pixelRow << " "
					<< "0.000" << " "
					<< "255 255 0\n";
			}

			for (float j = -10.0; j < 10.0; j += 0.5){
				ofs2 << setiosflags(ios::fixed) << setprecision(4)
					<< colStart + vecCVPoint[2 * i + 0] * pixelCol << " "
					<< rowStart - vecCVPoint[2 * i + 1] * pixelRow - j << " "
					<< "0.000" << " "
					<< "255 255 0\n";
			}

		}
		ofs.close();
		ofs2.close();
		Beep(1000, 1000);
		cout << "The task finished ...\n\n";
		exit(0);
	}
}

int main(int argc, char * argv[]){

	///第一步：读取控制点坐标
	ifstream ifs(CONTROL_POINT_PATH);
	vecControlPoint.clear();
	vecCVPoint.clear();
	if (!ifs){
		cout << "The control point txt is not exist !!!\n";
		return -1;
	}
	float x, y;
	while (!ifs.eof()){
		if (ifs.peek() == '\n'){
			ifs.ignore();
			if (ifs.peek() == '\n')
				break;
		}
		ifs >> x >> y;
		vecControlPoint.push_back(x); vecControlPoint.push_back(y);
		controlPointCount++;
	}
	ifs.close();
	std::cout << "Control point number is : " << vecControlPoint.size() / 2 << endl << endl;

	///第二部：读取图片，添加回调函数
	org = imread(SRC_PATH, 1);
	img = org.clone();
	org2 = org.clone();
	dst = Mat(RECT_WIDTH * 2, RECT_WIDTH * 2, img.depth(), img.channels());
	dst2 = Mat(RECT_WIDTH * 2, RECT_WIDTH * 2, img.depth(), img.channels());

	namedWindow("Motherboard", CV_WINDOW_NORMAL);
	setMouseCallback("Motherboard", addP1, 0);
	imshow("Motherboard", img);

	namedWindow("Subboard", CV_WINDOW_NORMAL);

	std::cout << "Xmax = " << img.cols
		<< "  Ymax = " << img.rows << endl << endl;

	waitKey(0);
	destroyAllWindows();

	return 0;
}
