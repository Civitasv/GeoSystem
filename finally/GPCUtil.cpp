#include "GPCUtil.h"
void Triangle(CGeoPolygon *polygon,gpc_tristrip* tristrip)
{
	int vertexNum =  polygon->pts.size();

	//��QVector�еĶ���ת�Ƶ�gpc_vertex������
	gpc_vertex* vertices = new gpc_vertex[vertexNum];
	for (int i = 0; i < vertexNum; i++)
	{
		vertices[i].x = polygon->pts[i].x();
		vertices[i].y = polygon->pts[i].y();
	}
	//����gpc_vertex_list
	gpc_vertex_list vertexList;
	vertexList.num_vertices = vertexNum;//����ĸ���
	vertexList.vertex = vertices;//��������

	//����gpc_polygon
	gpc_polygon polygon2;
	polygon2.num_contours = 1;//��һ������
	polygon2.hole = nullptr;//û�п׶�
	polygon2.contour = &vertexList;

	//��ȡ�ֽ���������
	tristrip->num_strips = 0;
	tristrip->strip = nullptr;//�ֽ��������ζ���������������<0,1,2><1,2,3><2,3,4>...

	//�����ʷֶ����
	gpc_polygon_to_tristrip(&polygon2, tristrip);
}