//
//  Fault.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/5/5.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RkFieldConverter.h"


@interface Fault : NSObject<RkFieldConverter>
//YES : 有故障 NO: 没有故障

//电机控制器/电机类
//MOS故障
@property (assign, nonatomic) BOOL MOS;
//运放故障
@property (assign, nonatomic) BOOL OPAMP;
//缺相故障
@property (assign, nonatomic) BOOL phase;
//霍尔故障
@property (assign, nonatomic) BOOL hall;
//堵转故障
@property (assign, nonatomic) BOOL lockRotor;
//总线故障
@property (assign, nonatomic) BOOL bus;
//短路故障
@property (assign, nonatomic) BOOL shortCircuit ;
//过流故障
@property (assign, nonatomic) BOOL overcurrent;

//中控类
//EDR故障
@property (assign, nonatomic) BOOL EDR;
//BLE故障
@property (assign, nonatomic) BOOL BLE;
//GSENSOR故障
@property (assign, nonatomic) BOOL gSensor;

//外设故障
//转把故障
@property (assign, nonatomic) BOOL rollingHandle;
//刹把故障
@property (assign, nonatomic) BOOL brakeHandle;
//电池电压过低
@property (assign, nonatomic) BOOL voltage;

//通信故障
//接收误码
@property (assign, nonatomic) BOOL errorCode;
//发送无回应(ECU无响应)
@property (assign, nonatomic) BOOL nonResponseECU;
//外接遥控器无回应
@property (assign, nonatomic) BOOL nonResponseRC;
//GPS设备无响应
@property (assign, nonatomic) BOOL nonResponseGPS;

//其他故障
//左右转向按键同时按下会上报此故障
@property (assign, nonatomic) BOOL pressDown_L_R;


@end
