#include <Dstypes.h>

/* Variables for CAN monitoring with RTI CAN MultiMessage block set */
volatile UInt32 RTICANMM_MonitorData[4];
dsfloat RTICANMM_DataFetchTime[16]= { -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
  -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0 };
