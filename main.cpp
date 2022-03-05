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
	puts("please input the pic size you want.(input 0 0 is the original size)");
	if (scanf_s("%d %d", &xx, &yy) != 2)
	{
		puts("read size fail");
		system("pause");
		return -2;
	}
	if (xx && yy)
	{
		Size dssize(xx, yy);
		resize(img, imgdst, dssize);
	}
	int position = file.find_last_of('.');
	file.erase(position);
	file += ".txt";
	if (img.isContinuous())
	{
		FILE* f;
		freopen_s(&f, file.c_str(), "w", stdout);
		int row = imgdst.rows, col = imgdst.cols;
		uchar* str[] = { imgdst.data };
		for (int i = 0; i < row; ++i)
		{
			for (int i = 0; i < col; ++i)printf("0x%04x, ", str[0][i]);
			printf("\n");
		}
		freopen_s(&f, "CON", "w", stdout);
		puts("succeed");
		fclose(f);
	}
	else puts("some error has happen,please try again minutes later");
	system("pause");
	return 0;
}