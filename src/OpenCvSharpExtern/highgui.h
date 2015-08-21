#ifndef _CPP_HIGHGUI_H_
#define _CPP_HIGHGUI_H_

#include "include_opencv.h"

CVAPI(void) highgui_namedWindow(const char *winname, int flags)
{
	cv::namedWindow(winname, flags);
}
CVAPI(void) highgui_destroyWindow(const char *winName)
{
	cv::destroyWindow(winName);
}
CVAPI(void) highgui_destroyAllWindows()
{
	cv::destroyAllWindows();
}
CVAPI(void) highgui_imshow(const char *winname, cv::Mat *mat)
{
	cv::imshow(winname, *mat);
}





CVAPI(int) highgui_startWindowThread()
{
	return cv::startWindowThread();
}
CVAPI(int) highgui_waitKey(int delay)
{
	return cv::waitKey(delay);
}

CVAPI(void) highgui_resizeWindow(const char *winName, int width, int height)
{
	cv::resizeWindow(winName, width, height);
}
CVAPI(void) highgui_moveWindow(const char *winName, int x, int y)
{
	cv::moveWindow(winName, x, y);
}

CVAPI(void) highgui_setWindowProperty(const char *winName, int propId, double propValue)
{
	cv::setWindowProperty(winName, propId, propValue);
}
CVAPI(double) highgui_getWindowProperty(const char *winName, int propId)
{
	return cv::getWindowProperty(winName, propId);
}

CVAPI(void) highgui_setMouseCallback(const char *winName, cv::MouseCallback onMouse, void* userData)
{
	cv::setMouseCallback(winName, onMouse, userData);
}
CVAPI(int) highgui_createTrackbar(const char *trackbarName, const char *winName,
	int* value, int count, cv::TrackbarCallback onChange, void* userData)
{
	return cv::createTrackbar(trackbarName, winName, value, count, onChange, userData);
}
CVAPI(int) highgui_getTrackbarPos(const char *trackbarName, const char *winName)
{
	return cv::getTrackbarPos(trackbarName, winName);
}
CVAPI(void) highgui_setTrackbarPos(const char *trackbarName, const char *winName, int pos)
{
	cv::setTrackbarPos(trackbarName, winName, pos);
}

#pragma region VideoCapture

CVAPI(cv::VideoCapture*) highgui_VideoCapture_new()
{
	return new cv::VideoCapture();
}
CVAPI(cv::VideoCapture*) highgui_VideoCapture_new_fromFile(const char *fileName)
{
	return new cv::VideoCapture(fileName);
}
CVAPI(cv::VideoCapture*) highgui_VideoCapture_new_fromDevice(int device)
{
	return new cv::VideoCapture(device);
}
CVAPI(void) highgui_VideoCapture_delete(cv::VideoCapture *obj)
{
	delete obj;
}

CVAPI(void) highgui_VideoCapture_open_fromFile(cv::VideoCapture *obj, const char *fileName)
{
	obj->open(fileName);
}
CVAPI(void) highgui_VideoCapture_open_fromDevice(cv::VideoCapture *obj, int device)
{
	obj->open(device);
}
CVAPI(int) highgui_VideoCapture_isOpened(cv::VideoCapture *obj)
{
	return obj->isOpened();
}
CVAPI(void) highgui_VideoCapture_release(cv::VideoCapture *obj)
{
	obj->release();
}

CVAPI(int) highgui_VideoCapture_grab(cv::VideoCapture *obj)
{
	return obj->grab() ? 1: 0;
}
CVAPI(int) highgui_VideoCapture_retrieve(cv::VideoCapture *obj, cv::Mat *image, int channel)
{
	return obj->retrieve(*image, channel) ? 1 : 0;
}
CVAPI(int) highgui_VideoCapture_read(cv::VideoCapture *obj, cv::Mat *image)
{
	return obj->read(*image) ? 1 : 0;
}

CVAPI(int) highgui_VideoCapture_set(cv::VideoCapture *obj, int propId, double value)
{
	return obj->set(propId, value) ? 1 : 0;
}
CVAPI(double) highgui_VideoCapture_get(cv::VideoCapture *obj, int propId)
{
	return obj->get(propId);
}

#pragma endregion

#pragma region VideoWriter
CVAPI(cv::VideoWriter*) highgui_VideoWriter_new1()
{
	return new cv::VideoWriter;
}
CVAPI(cv::VideoWriter*) highgui_VideoWriter_new2(const char *fileName, int fourcc,
	double fps, CvSize frameSize, int isColor)
{
	return new cv::VideoWriter(fileName, fourcc, fps, frameSize, isColor != 0);
}
CVAPI(void) highgui_VideoWriter_delete(cv::VideoWriter *obj)
{
	delete obj;
}
CVAPI(int) highgui_VideoWriter_open(cv::VideoWriter *obj, const char *fileName, int fourcc, double fps,
	CvSize frameSize, int isColor)
{	
	return obj->open(fileName, fourcc, fps, frameSize, isColor != 0) ? 1 : 0;
}
CVAPI(int) highgui_VideoWriter_isOpened(cv::VideoWriter *obj)
{
	return obj->isOpened() ? 1 : 0;
}
CVAPI(void) highgui_VideoWriter_release(cv::VideoWriter *obj)
{
	obj->release();
}
CVAPI(void) highgui_VideoWriter_write(cv::VideoWriter *obj, cv::Mat *image)
{
	obj->write(*image);
}

#pragma endregion

#endif