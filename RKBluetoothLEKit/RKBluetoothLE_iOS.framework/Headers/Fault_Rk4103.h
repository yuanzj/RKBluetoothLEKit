//
//  Fault.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/5/5.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RkFieldConverter.h"


@interface Fault_Rk4103 : NSObject<RkFieldConverter>

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
#pragma mark 灯光断路故障

//BIT0：前左转
@property (assign, nonatomic) BOOL BC_headLeftTurn;
//BIT1：后左转
@property (assign, nonatomic) BOOL BC_tailLeftTurn;
//BIT2：前右转
@property (assign, nonatomic) BOOL BC_headRightTurn;
//BIT3：后右转
@property (assign, nonatomic) BOOL BC_tailRightTurn;
//BIT4：近光
@property (assign, nonatomic) BOOL BC_dippedHeadlight;
//BIT5：远光
@property (assign, nonatomic) BOOL BC_distanceLight;
//BIT6：尾灯
@property (assign, nonatomic) BOOL BC_tailLamp;
//BIT7：刹车灯
@property (assign, nonatomic) BOOL BC_brakeLight;
//BIT8：背景灯1
@property (assign, nonatomic) BOOL BC_backlight1;
//BIT9：背景灯2
@property (assign, nonatomic) BOOL BC_backlight2;
//BIT10：背景灯3
@property (assign, nonatomic) BOOL BC_backlight3;
//BIT11: 喇叭故障
@property (assign, nonatomic) BOOL BC_Horn;

#pragma mark -
#pragma mark 灯光短路故障
//BIT0：前左转
@property (assign, nonatomic) BOOL SC_headLeftTurn;
//BIT1：后左转
@property (assign, nonatomic) BOOL SC_tailLeftTurn;
//BIT2：前右转
@property (assign, nonatomic) BOOL SC_headRightTurn;
//BIT3：后右转
@property (assign, nonatomic) BOOL SC_tailRightTurn;
//BIT4：近光
@property (assign, nonatomic) BOOL SC_dippedHeadlight;
//BIT5：远光
@property (assign, nonatomic) BOOL SC_distanceLight;
//BIT6：尾灯
@property (assign, nonatomic) BOOL SC_tailLamp;
//BIT7：刹车灯
@property (assign, nonatomic) BOOL SC_brakeLight;
//BIT8：背景灯1
@property (assign, nonatomic) BOOL SC_backlight1;
//BIT9：背景灯2
@property (assign, nonatomic) BOOL SC_backlight2;
//BIT10：背景灯3
@property (assign, nonatomic) BOOL SC_backlight3;
//BIT11: 喇叭故障
@property (assign, nonatomic) BOOL SC_Horn;

@end
