# Generated by using Rcpp::compileAttributes() -> do not edit by hand
# Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

mergePeaks <- function(data, maxGap) {
    .Call('DiffBind_mergePeaks', PACKAGE = 'DiffBind', data, maxGap)
}

mergeScores <- function(sMerged, sScore, sPeaks) {
    .Call('DiffBind_mergeScores', PACKAGE = 'DiffBind', sMerged, sScore, sPeaks)
}

peakOrder <- function(schrom, sleft, sright) {
    .Call('DiffBind_peakOrder', PACKAGE = 'DiffBind', schrom, sleft, sright)
}

