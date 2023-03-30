#ifndef __IFR_SCOPE_DEVICE_H__
#define __IFR_SCOPE_DEVICE_H__

#include "main.h"

enum _IFRScopeRunState
{
	Unconnected,
	ConnectedNoData,
	ConnectedDataSend,
};

enum _IFRScopeFrameID
{
	FrameID_DCY = 0x30,
	FrameID_REPDCY = 0x31,
	FrameID_SimpHandShake = 0x5F,
	FrameID_SimpHandOK = 0x60,
	FrameID_SimpHandFail = 0x61,
	FrameID_StartData = 0x36,
	FrameID_Data = 0x37,
	FrameID_Heartbeat = 0x38,
};

void IFR_Scope_Main(void);


#pragma pack(push)
#pragma pack(1)
union _floatchar
{
	uint8_t byte[4];
	float point;
};

struct _datalink_upframedata
{
	uint8_t head[7];
	uint8_t seq;
	uint8_t link;
	union _floatchar data[20];
	uint8_t end[5];
};



#pragma pack(pop)



#endif /* __IFR_SCOPE_DEVICE_H__ */
