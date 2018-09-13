//
//  BCUParameter.h
//  RokyinfoBLEDemo
//
//  Created by virgil on 2018/9/4.
//  Copyright © 2018年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaseParameter.h"

@interface BCUParameter : BaseParameter

@property (assign, nonatomic) Byte type;
@property (assign, nonatomic) Byte bcuStatus;
@property (assign, nonatomic) Byte bcuLockControl;

#pragma mark -
#pragma mark BCU故障

//BIT0：短路保护
@property (assign, nonatomic) BOOL BCU_shortCircuitP;
//BIT1：欠压保护
@property (assign, nonatomic) BOOL BCU_UVLFault;
//BIT2：过压保护
@property (assign, nonatomic) BOOL BCU_overVoltageP;
//BIT3：放电过流保护
@property (assign, nonatomic) BOOL BCU_OCDSGFault;
//BIT4：充电过流保护
@property (assign, nonatomic) BOOL BCU_OCCHGFault;
//BIT5：低温保护
@property (assign, nonatomic) BOOL BCU_cryoprotection;
//BIT6：过温保护
@property (assign, nonatomic) BOOL BCU_overTemperatureP;
//BIT7：状态异常保护
@property (assign, nonatomic) BOOL BCU_PInTheAbnormal;
//BIT8：MOS异常
@property (assign, nonatomic) BOOL BCU_MOSOfTheAbnormal;
//BIT9：总电压过压保护
@property (assign, nonatomic) BOOL BCU_overTVoltageP;
//BIT10：总电压欠压保护
@property (assign, nonatomic) BOOL BCU_UTVLFault;
//BIT11: 单芯间压差过大
@property (assign, nonatomic) BOOL BCU_largeDifferentialPressure;
//BIT12：副板失联故障
@property (assign, nonatomic) BOOL BCU_subplateMiss;
//BIT13：power down故障（power down操作未成功）
@property (assign, nonatomic) BOOL BCU_PDFault;
//BIT15: 副板故障
@property (assign, nonatomic) BOOL BCU_subplateFault;

#pragma mark -
#pragma mark BCU告警
//BIT0：单芯电压低告警
@property (assign, nonatomic) BOOL LVOfSingleCoreW;
//BIT1：单芯电压高告警
@property (assign, nonatomic) BOOL HVOfSingleCoreW;
//BIT2：低温告警
@property (assign, nonatomic) BOOL lowTemperatureW;
//BIT3：高温告警
@property (assign, nonatomic) BOOL highTemperatureW;
//BIT4：总电压高告警
@property (assign, nonatomic) BOOL highTVoltageW;
//BIT5：总电压低告警
@property (assign, nonatomic) BOOL lowTVoltageW;
//BIT6：单芯压差过大告警
@property (assign, nonatomic) BOOL largeDifferentialPressureW;


//@property (assign, nonatomic) int bcuFault;
//@property (assign, nonatomic) int bcuWarn;

//+(BCUParameter*)createDefault;

@end
