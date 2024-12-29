
#include "issue_common.h"

#ifdef _MSC_VER
int main(const int argc, const char * argv[/* cl no can do static argc*/]) 
#else
int main(const int argc, const char * argv[argc])
#endif
{
    return issue_common_main(argc,argv);
}