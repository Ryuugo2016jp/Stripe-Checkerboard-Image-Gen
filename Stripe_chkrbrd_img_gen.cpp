#include "opencv2\\opencv.hpp"

int main(void)
{

	int mode;
	int interval;
	cv::Mat img = cv::Mat::zeros(cv::Size(640, 640), CV_8UC1);

	std::cout << "Stripe Image/Checker Board Tool" << std::endl;
	std::cout << "Image SizeFFixed to 640x640" << std::endl;
	std::cout << "Mode: Vertical Stripe(0) Horizontal Stripe(1) Checkerboard(2)" << std::endl;
	std::cin >> mode;

		if (mode == 0 || mode == 1)
		{
			std::cout << "Identify the stripe interval(2-320)" << std::endl;
		}

		else
		{
			std::cout << "Identify the lattice width(2-320)" << std::endl;
		}

	do
	{
		std::cin >> interval;
	} while (interval < 0 || interval >320);



	if (mode == 0)
	{
		for (int i = 0; i < 640; i++)
		{
			for (int j = 0;j < 640; j++)
			{
				if ((i / interval) % 2 == 1)
				{
					img.at<uchar>(j, i) = 0;
				}

				else
				{
					img.at<uchar>(j, i) = 255;
				}
			}//j

		}//i
	}

	else if (mode == 1)
	{
		for (int j = 0; j < 640; j++)
		{
			for (int i = 0;i < 640; i++)
			{
				if ((j / interval) % 2 == 1)
				{
					img.at<uchar>(j, i) = 0;
				}

				else
				{
					img.at<uchar>(j, i) = 255;
				}
			}//i
		}//j
	}


	else
	{
		for (int j = 0; j < 640; j++)
		{
			for (int i = 0;i < 640; i++)
			{
				if ((j / interval) % 2 == 1 && (i / interval) % 2 == 1)
				{
					img.at<uchar>(j, i) = 0;
				}

				else if ((j / interval) % 2 == 0 && (i / interval) % 2 == 0)
				{
					img.at<uchar>(j, i) = 0;
				}

				else
				{
					img.at<uchar>(j, i) = 255;
				}
			}//i
		}//j
	}
	
	cv::imshow("Img", img);
	cv::waitKey(0);
	cv::imwrite("image.bmp", img);

	return 0;
}