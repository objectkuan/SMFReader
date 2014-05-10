
#ifndef __HJQ_ELEMENTS__
#define  __HJQ_ELEMENTS__

class point
{
public:
	double x, y, z;
	point();
protected:
private:
};


struct PolygonYListElement
{
	int IP;
	double Ymax;
};

struct ETElement
{
	double Ymax;
	double dx;
	double x, z;
};
typedef CArray<CList<ETElement*>*> ET;
struct AETElement
{
	double xl, dxl, ylmax, xr, dxr, yrmax, zl, dzx, dzy;
	int IP;
	point left, right;
};

typedef CList<AETElement*> AET;

class face
{
public:
	ET et;
	byte r, g, b;
	long p1, p2, p3;

	double minx, miny, minz, maxx, maxy, maxz;

	face();
protected:
private:
};

class shape
{
public:
	face* faces;
	point* points;

	double minx, miny, minz, maxx, maxy, maxz;

	long pointAmount, faceAmount;
	shape();

protected:
private:
};

#endif