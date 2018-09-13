//
//  Fault_Rk44xx.h
//  RokyinfoBLEDemo
//
//  Created by virgil on 2018/9/3.
//  Copyright © 2018年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RkFieldConverter.h"

@interface Fault_Rk44xx : NSObject<RkFieldConverter>

//0：请求OK
//1：请求失败
@property (assign, nonatomic) int status;
#pragma mark -
#pragma mark 电机控制器/电机类

//Bit 0-MOS故障 1：故障，0：无故障
@property (assign, nonatomic) BOOL MOS;
//Bit 1-转把故障 1：故障，0：无故障
@property (assign, nonatomic) BOOL rollingHandle;
//Bit 2-缺相故障 1：故障，0：无故障
@property (assign, nonatomic) BOOL phase;
//Bit 3-霍尔故障 1：故障，0：无故障
@property (assign, nonatomic) BOOL hall;
//BIT4:刹把故障  1：故障，0：无故障
@property (assign, nonatomic) BOOL brakeHandle;
//BIT5：电机故障
@property (assign, nonatomic) BOOL motorTrouble;
//BIT7：ECU通信异常
@property (assign, nonatomic) BOOL nonResponseECU;

#pragma mark -
#pragma mark 中控故障
//BIT0：GSENSOR故障
@property (assign, nonatomic) BOOL GSENSOR;
//BIT3：BLE故障
@property (assign, nonatomic) BOOL BLE;

#pragma mark -
#pragma mark 电池故障

//BIT0：BMS通信故障
@property (assign, nonatomic) BOOL nonResponseBMS;
//BIT1：过充故障
@property (assign, nonatomic) BOOL overshoot;
//BIT2：电芯高温故障
@property (assign, nonatomic) BOOL overTemperature;
//BIT3：电芯低温故障
@property (assign, nonatomic) BOOL lowTemperature ;
//BIT4：电池欠压
@property (assign, nonatomic) BOOL undervoltage;

#pragma mark -
#pragma mark GPS故障

//BIT0: GPS通信故障
@property (assign, nonatomic) BOOL nonResponseGPS;
//BIT1：GPS信号异常
@property (assign, nonatomic) BOOL signalGPS;
//BIT2：GSM信号异常
@property (assign, nonatomic) BOOL signalGSM;
//BIT3：没有SIM卡
@property (assign, nonatomic) BOOL noSim;
//BIT4：外电断开故障
@property (assign, nonatomic) BOOL powerDisconnect;

#pragma mark -
#pragma mark 其他故障
//BIT0：RS485通信异常
@property (assign, nonatomic) BOOL nonResponse485;
//BIT3：RC异常
@property (assign, nonatomic) BOOL nonResponseRC;

#pragma mark -
#pragma mark PCU故障
//BIT0：短路故障
@property (assign, nonatomic) BOOL shortCircuit;
//BIT1：硬件故障
@property (assign, nonatomic) BOOL hardware;
//BIT2：DC使能控制
@property (assign, nonatomic) BOOL DCEnable;
//BIT3：DC输出过压
@property (assign, nonatomic) BOOL DCoutput;
//BIT4：DC输出欠压
@property (assign, nonatomic) BOOL DCundervoltage;
//BIT7：电源管理通信故障
@property (assign, nonatomic) BOOL nonResponsePCU;


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


@end
