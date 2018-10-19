#include<opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void main() {
	Mat original = imread("C:\\Users\\lenovo\\Desktop\\1-1.jpg");
	namedWindow("My original");
	imshow("My original", original);
	Mat gray = original;
	cv::cvtColor(gray, gray, CV_RGB2GRAY);//�ҶȻ�

	int thresh_size = (100 / 4) * 2 + 1; //����Ӧ��ֵ����ֵ
	adaptiveThreshold(gray, gray, 255, CV_ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY_INV, thresh_size, thresh_size / 3);


	vector<vector<Point> > contours;
	cv::findContours(gray, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE); //������
	vector<vector<Point>> contours1;
	for (int i = 0; i < contours.size(); ++i)
	{
	
			contours1.push_back(contours[i]);
	
	}
	
	Mat hole(gray.size(), CV_8U, Scalar(0)); //����ͼ��
 cv::drawContours(hole, contours1, -1, Scalar(255), CV_FILLED); //������ͼ���ϣ��ð�ɫ�����������
	namedWindow("My hole");
	imshow("My hole", hole);
	Mat crop(original.rows, original.cols, CV_8UC3);
	original.copyTo(crop, hole);//��ԭͼ�񿽱�������ͼ��
	namedWindow("My warpPerspective");
	imshow("My warpPerspective", crop);
	waitKey(0);
}
