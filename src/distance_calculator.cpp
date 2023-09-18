// [[Rcpp::depends(RcppParallel)]]
#include <Rcpp.h>
#include <RcppParallel.h>
using namespace Rcpp;
using namespace RcppParallel;

// 计算两个点之间的欧氏距离
double calculateDistance(const RcppParallel::RMatrix<double>::Row& point1, const RcppParallel::RMatrix<double>::Row& point2) {
  int numDimensions = point1.length();
  double distance = 0.0;
  
  for (int i = 0; i < numDimensions; i++) {
    double diff = point1[i] - point2[i];
    distance += diff * diff;
  }
  
  return sqrt(distance);
}

// 并行计算任务
struct DistanceCalculator : public Worker {
  const RMatrix<double> points;
  const IntegerVector indices;
  RMatrix<double> distances;
  
  DistanceCalculator(const NumericMatrix points, const IntegerVector indices, NumericMatrix distances)
    : points(points), indices(indices), distances(distances) {}
  
  void operator()(std::size_t begin, std::size_t end) {
    for (std::size_t i = begin; i < end; i++) {
      int selectedIndex = indices[i] - 1; // R的索引从1开始
      
      for (int j = 0; j < points.nrow(); j++) {
        double distance = calculateDistance(points.row(selectedIndex), points.row(j));
        distances(i, j) = distance;
      }
    }
  }
};

// 主函数，计算指定点与其他所有点的距离并行
// [[Rcpp::export]]
NumericMatrix calculateDistancesParallel(NumericMatrix points, IntegerVector indices, int numThreads) {
  int numSelectedPoints = indices.size();
  NumericMatrix distances(numSelectedPoints, points.nrow());
  
  DistanceCalculator distanceCalculator(points, indices, distances);
  
  if (numThreads > 1) {
    parallelFor(0, numSelectedPoints, distanceCalculator, numThreads);
  } else {
    parallelFor(0, numSelectedPoints, distanceCalculator);
  }
  
  return distances;
}
