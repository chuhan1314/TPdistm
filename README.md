# TPdistm
P package: RCPP for distance between traget points and all points \n
## Install
devtools::install_github("chuhan1314/TPdistm")
## Useage
calculateDistancesParallel(points, index, numThreads = 1) <\br>
points: matrix, coords of points <\br>
index: vector, Index of target points to calculate distances with all points.
