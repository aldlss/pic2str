#include<string>
#include<iostream>
#include<fstream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	//string file = "F:\\za\\left.jpg";
	string file;
	puts("please input file route");
	cin >> file;
	Mat img = imread(file);
	if (img.empty())
	{
		puts("open file fail");
		system("pause");
		return -1;
	}
	Mat imgdst = img;
	int xx, yy;
	puts("please input the pic size you want.(0 0 is the original size)");
	if (scanf_s("%d %d", &xx, &yy) != 2)
	{
		puts("read size fail");
		system("pause");
		return -2;
	}
	if (!xx)xx = img.rows;
	if (!yy)yy = img.cols;
	Size dssize(xx, yy);
	resize(img, imgdst, dssize);
	int position = file.find_last_of('.');
	cvtColor(imgdst, img, COLOR_BGR2BGR565);
	file.erase(position);
	file += ".txt";
	if (img.isContinuous())
	{
		FILE* f;
		freopen_s(&f, file.c_str(), "w", stdout);
		int row = img.rows, col = img.cols, step = img.step,channel=img.channels();
		int size = row * col;
		ushort bitt;
		for (int i = 0; i < row; ++i)
		{
			for(int j = 0; j < col; ++j)
			{
			/*	ʵ���ϣ�����ͨ������һ��ͨ���ǵͰ�λ���ڶ���ͨ���Ǹ߰�λ��Ȼ���ǰ���RGB565���Ų���
				������������ת��д��ת����BGR565���ƴ���������	*/
				bitt = ushort(img.data[i * step + j * channel]);
				bitt |= ushort(img.data[i * step + j * channel + 1])<<8;

				printf("0x%04x, ", bitt);
			}
			printf("\n");
		}
		freopen_s(&f, "CON", "w", stdout);
		puts("succeed");
	}
	else puts("some error has happen,please try again minutes later");
	system("pause");
	return 0;
}