#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

struct Point {
  double x;
  double y;
};

double distance(Point p1, Point p2, Point p3) {
  double a = p3.y - p1.y;
  double b = p1.x - p3.x;
  return abs(a * p3.x - a * p2.x + b * p3.y - b * p2.y) / sqrt(a * a + b * b);
}

int main() {
  int n;
  vector<Point> points;
  cin >> n;
  for (int _ = 0; _ < n; ++_) {
    double x;
    double y;
    cin >> x >> y;
    points.push_back({x, y});
  }
  double dis = numeric_limits<double>::max();
  for (size_t i = 0; i < points.size(); ++i) {
    dis = min(dis, distance(points[i], points[(i + 1) % points.size()],
                            points[(i + 2) % points.size()]) /
                       2);
  }
  printf("%f\n", dis);
  return 0;
}
