#pragma once

#include "resource.h"
const double g = 9.91;
int t = 25;
int radius=10;
class object
{
public:

    void init(int Xo, int Yo)
	{
		X = Xo, Y = Yo;
		set_coords();
		//draw_object(hdc, Xo, Yo);
	}

	void set_coords()
	{
		shape.top = Y - radius;
		shape.left = X - radius;
		shape.bottom = Y + radius;
		shape.right = X + radius;
	}
	void cought(int arm_X, int arm_Y)
	{
		X = arm_X;
		Y = arm_Y;
		
	}
	void recoil()
	{
		if (Y > 500)speed_Y=-speed_Y+.04;
	}
	void freefall()
	{
		speed_Y = speed_Y + g*time/1000.;
		Y = Y + speed_Y;
	}
	void draw_object(HDC hdc,int Xo,int Yo)
	{
		Graphics graphics(hdc);
		
		Pen pen(Color(255, 0, 0, 255), 5);
		graphics.DrawEllipse(&pen,shape.left,shape.top,shape.left+shape.right,shape.bottom+shape.top);

	}

private:
	int X, Y;
	double speed_Y, speed_X;
	int mass;
	int time;
	RECT shape;
	
};