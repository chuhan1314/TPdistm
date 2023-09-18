// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// calculateDistancesParallel
NumericMatrix calculateDistancesParallel(NumericMatrix points, IntegerVector indices, int numThreads);
RcppExport SEXP _TPdistm_calculateDistancesParallel(SEXP pointsSEXP, SEXP indicesSEXP, SEXP numThreadsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type points(pointsSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type indices(indicesSEXP);
    Rcpp::traits::input_parameter< int >::type numThreads(numThreadsSEXP);
    rcpp_result_gen = Rcpp::wrap(calculateDistancesParallel(points, indices, numThreads));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_TPdistm_calculateDistancesParallel", (DL_FUNC) &_TPdistm_calculateDistancesParallel, 3},
    {NULL, NULL, 0}
};

RcppExport void R_init_TPdistm(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}