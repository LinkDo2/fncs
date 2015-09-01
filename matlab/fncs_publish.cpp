#include "mex.h"

#include <fncs.hpp>

void mexFunction( int nlhs, mxArray *plhs[],
        int nrhs, const mxArray *prhs[] )
{
    /* Check for proper number of arguments. */
    if(nrhs!=2) {
        mexErrMsgIdAndTxt( "MATLAB:fncs:publish:nrhs",
                "This function takes two strings.");
    }
    if(nlhs!=0) {
        mexErrMsgIdAndTxt( "MATLAB:fncs:publish:nlhs",
                "This function does not have output arguments.");
    }

    /* inputs must be strings */
    if (!mxIsChar(prhs[0])) {
        mexErrMsgIdAndTxt( "MATLAB:fncs:publish:inputNotString",
                "Input 1 must be a string.");
    }
    if (!mxIsChar(prhs[1])) {
        mexErrMsgIdAndTxt( "MATLAB:fncs:publish:inputNotString",
                "Input 2 must be a string.");
    }

    /* copy the string data from prhs into a C string */
    char *key = mxArrayToString(prhs[0]);
    if (key == NULL) {
        mexErrMsgIdAndTxt("MATLAB:fncs:publish:conversionFailed",
                "Could not convert input to string.");
    }

    char *val = mxArrayToString(prhs[1]);
    if (val == NULL) {
        mexErrMsgIdAndTxt("MATLAB:fncs:publish:conversionFailed",
                "Could not convert input to string.");
    }

    /* Call the fncs::publish subroutine. */
    fncs::publish(key, val);

    /* clean up temporary strings */
    mxFree(key);
    mxFree(val);
}

