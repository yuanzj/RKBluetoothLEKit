//
//  FaultEntity.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/6/24.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Fault_Rk4102.h"

@interface YadeaFault : NSObject

/**
 * 0:请求成功
 * 1:请求失败
 */
@property (assign, nonatomic) int status;

/**
 * 电机故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic) int electric;
/**
 * 控制器故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic) int controller;
/**
 * 转把故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic) int turnedHandle;
/**
 * 刹把故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic) int brakeHandle;
/**
 * 氛围灯故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic) int atmosphereLamp;
/**
 * 近光灯故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic) int nearLight;
/**
 * 远光灯故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic) int beam;
/**
 * 行车灯故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic) int drivingLamp;
/**
 * 刹车灯故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic) int brakeLight;
/**
 * 左前转向灯故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic) int frontLeftTurn;
/**
 * 右前转向灯故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic) int frontRightTurn;
/**
 * 左后转向灯故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic) int backLeftTurn;
/**
 * 右后转向灯故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic) int backRightTurn;
/**
 * 喇叭故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic) int horn;
/**
 * 转换器故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic) int converter;
/**
 * 电池过充故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic) int batteryOverCharge;
/**
 * 电芯高温故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic) int elecChipHighTemperature;
/**
 * 电芯低温故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic) int elecChipLowTemperature;
/**
 * 蓝牙通讯故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic) int btCommunication;
/**
 * GPS通讯故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic) int gpsCommunication;
/**
 * GSM网络故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic) int gsmNet;
/**
 * 射频通讯故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic)  int radioFrequencyCommunication;
/**
 * 中控通讯故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic)  int centerControllerCommunication;
/**
 * 控制器通讯故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic)  int controllerCommunication;
/**
 * 电池通讯故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic)  int batteryCommunication;
/**
 * 电源管理器故障
 * 1：故障，0：无故障
 */
@property (assign, nonatomic) int powerManager;

#pragma mark -
#pragma mark 初始化
-(id)initWithFault_Rk4102:(Fault_Rk4102 *)mFault_Rk4102;

@end
