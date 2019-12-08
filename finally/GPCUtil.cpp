#include "GPCUtil.h"
void Triangle(CGeoPolygon *polygon,gpc_tristrip* tristrip)
{
	int vertexNum =  polygon->pts.size();

	//将QVector中的顶点转移到gpc_vertex数组中
	gpc_vertex* vertices = new gpc_vertex[vertexNum];
	for (int i = 0; i < vertexNum; i++)
	{
		vertices[i].x = polygon->pts[i].x();
		vertices[i].y = polygon->pts[i].y();
	}
	//生成gpc_vertex_list
	gpc_vertex_list vertexList;
	vertexList.num_vertices = vertexNum;//顶点的个数
	vertexList.vertex = vertices;//顶点序列

	//生成gpc_polygon
	gpc_polygon polygon2;
	polygon2.num_contours = 1;//有一条轮廓
	polygon2.hole = nullptr;//没有孔洞
	polygon2.contour = &vertexList;

	//获取分解后的三角形
	tristrip->num_strips = 0;
	tristrip->strip = nullptr;//分解后的三角形顶点是连续接壤的<0,1,2><1,2,3><2,3,4>...

	//三角剖分多边形
	gpc_polygon_to_tristrip(&polygon2, tristrip);
}