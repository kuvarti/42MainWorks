#include <iostream>

using namespace std;

int	main()
{
	int px = 1, py = 3;
	int ax = 3, ay = 5;
	int bx = 1, by = 1;
	int cx = 5, cy = 1;

	cout << "d1 = " << (px - ax) * (by - ay) - (bx - ax) * (py - ay) << " :(Px - Ax) * (By - Ay) - (Bx - Ax) * (Py - Ay)" << endl;
	cout << "d2 = " << (px - bx) * (cy - by) - (cx - bx) * (py - by) << " :(Px - Bx) * (Cy - By) - (Cx - Bx) * (Py - By)" << endl;
	cout << "d2 = " << (px - cx) * (ay - cy) - (ax - cx) * (py - cy) << " :(Px - Cx) * (Ay - Cy) - (Ax - Cx) * (Py - Cy)" << endl;
}
